#include <sstream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cerrno>
#include <cstdlib>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return *this;}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input) {
	char cValue;
	long iValue;
	float fValue;
	double dValue;

    if (input.empty()) {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: 0" << std::endl;
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
        return;
	}

	if (input.length() == 1 && !isdigit(input[0])){
		cValue = input[0];
		iValue = static_cast<int>(cValue);;
		fValue = static_cast<float>(cValue);
		dValue = static_cast<double>(cValue);
		std::cout << "char: '" << cValue << "'" << std::endl;
		std::cout << "int: " << iValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
		return;
	}

	bool isInt = true;
	char* endI;
	errno = 0;
	iValue = strtol(input.c_str(), &endI, 10);
	if (*endI != '\0' || errno == ERANGE || iValue < std::numeric_limits<int>::min() || iValue > std::numeric_limits<int>::max()) {
    	isInt = false; }

	bool isFloat = true;
	if (input[input.length() - 1] != 'f') {
	    isFloat = false;
	} else {
	    char* endF;
	    errno = 0;
	    fValue = strtof(input.c_str(), &endF);
	    if (*endF != 'f' || *(endF + 1) != '\0' || errno == ERANGE) {
	        isFloat = false;
	    }
	}

	bool isDouble = true;
	char* endD;
	errno = 0;
    dValue = strtod(input.c_str(), &endD);
    if (*endD != '\0') {
		isDouble = false;}

	if (isInt) {
		fValue = static_cast<float>(iValue);
		dValue = static_cast<double>(iValue);
		if (iValue >= 32 && iValue < 127) {
			cValue = static_cast<char>(iValue);
			std::cout << "char: '" << cValue <<"'"<< std::endl;
		}
		else if(iValue >= 0 && iValue <= 31) {
			std::cout << "char: " << "Non displayable" <<  std::endl;
		}
		else {
			std::cout << "char: " << "impossible" <<  std::endl;
		}
		std::cout << "int: " << iValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
		return;
	}
	
	if (isFloat) {
		if (std::isnan(fValue)) {
        	std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
        	return;
    	}
		dValue = static_cast<double>(fValue);
		if (fValue < static_cast<float>(std::numeric_limits<int>::min()) ||
    			fValue > static_cast<float>(std::numeric_limits<int>::max())) {
           	std::cout << "char: impossible\nint: impossible" << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
			return;
		}
		iValue = static_cast<int>(fValue);
		if (iValue >= 32 && iValue < 127) {
			cValue = static_cast<char>(iValue);
			std::cout << "char: '" << cValue <<"'"<< std::endl;
		}
		else if(iValue >= 0 && iValue <= 31) {
			std::cout << "char: " << "Non displayable" <<  std::endl;
		}
		else 
			std::cout << "char: " << "impossible" <<  std::endl;
		std::cout << "int: " << iValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
			return;
	}


	if (isDouble) {
		if (std::isnan(dValue)) {
        	std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
        	return;
    	}
		if (dValue > std::numeric_limits<double>::max()) {
           	std::cout << "char: impossible\nint: impossible\nfloat: inff\ndouble: inf" << std::endl;
			return;
		}
		else if (dValue < -std::numeric_limits<double>::max()) {
           	std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
			return;
		}
		if (dValue > std::numeric_limits<float>::max()) {
           	std::cout << "char: impossible\nint: impossible\nfloat: inff" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
			return;
		}
		else if (dValue < -std::numeric_limits<float>::max()) {
           	std::cout << "char: impossible\nint: impossible\nfloat: -inff" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
			return;
		}
		fValue = static_cast<float>(dValue);
		if (dValue < std::numeric_limits<int>::min() || dValue > std::numeric_limits<int>::max()) {
           	std::cout << "char: impossible\nint: impossible" << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
			return;
		}
		iValue = static_cast<int>(dValue);
		if (iValue >= 32 && iValue < 127) {
			cValue = static_cast<char>(iValue);
			std::cout << "char: '" << cValue <<"'"<< std::endl;
		}
		else if(iValue >= 0 && iValue <= 31) {
			std::cout << "char: " << "Non displayable" <<  std::endl;
		}
		else
			std::cout << "char: " << "impossible" <<  std::endl;
		std::cout << "int: " << iValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
		return;
		}
	std::cout << "Conversion is impossible!\n";
	}