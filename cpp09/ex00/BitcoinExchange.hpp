#ifndef BITCOINEXCHANCE_HPP
#define BITCOINEXCHANCE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, float> exchangeRates;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		void proccessInfile(const std::string& filename);
		float getBtcValue(const std::string& date);
		bool isValidDate(const std::string& date);
		bool isValidQuentity(const std::string& quentity);
		
};

#endif