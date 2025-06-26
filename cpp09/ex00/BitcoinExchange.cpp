#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {this->exchangeRates = other.exchangeRates;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if(this != &other) {
		this->exchangeRates = other.exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if(!file) {
		std::cerr << "Error: could not open file." << filename << std::endl;
		return false;
	}
	std::string line;
	while(std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, priceStr;
		if(std::getline(ss, date, ',') && std::getline(ss, priceStr)){
			float price = std::atof(priceStr.c_str());
			exchangeRates[date] = price;
		}
	}
	file.close();
	return true;
}

void BitcoinExchange::proccessInfile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if(!file) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, valueStr;
		if(std::getline(ss, date, '|') && std::getline(ss, valueStr)){
			date.erase(date.find_last_not_of(" ") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" "));
			if (!isValidQuentity(valueStr)) {
				std::cerr << "Error: invalid value format => " << valueStr << std::endl;
				continue;
			}
			float value = std::atof(valueStr.c_str());
			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			float rate = getBtcValue(date);
			if (rate != -1) {
				std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	file.close();
}

float BitcoinExchange::getBtcValue(const std::string& date) {
	if (!isValidDate(date)) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return -1.0f;
	}

	std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
	if(it == exchangeRates.end() || it->first != date)
		if(it != exchangeRates.begin())
			--it;
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false; }

	int year, month, day;
	char dash1, dash2;
	std::istringstream ss(date);
	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || dash1 != '-' || dash2 != '-') {
		return false; }

	if (year < 2009 || (year == 2009 && month == 1 && day < 2)) {
		return false; }

	if (month < 1 || month > 12) {
		return false; }

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		daysInMonth[2] = 29; }

	if (day < 1 || day > daysInMonth[month]) {
		return false; }

	return true;
}

bool BitcoinExchange::isValidQuentity(const std::string& quentity) {
	int i = 0;
	int dot = 0;
	if (quentity.size() == 1 && quentity[0] == '.')
		return false;
	if (quentity[0] == '-' && quentity.size() >= 2)
		i = 1;
	while (quentity[i]) {
		if (quentity[i] == '.')
			dot++;
		if (!isdigit(quentity[i]) && quentity[i] != '.') {
			return false;
		}
		i++;
	}
	if (dot > 1)
		return false;
	return true;
}
