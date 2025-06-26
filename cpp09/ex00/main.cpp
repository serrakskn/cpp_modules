#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btcExchange;
	if(!btcExchange.loadDatabase("data.csv"))
		return 1;
	
	btcExchange.proccessInfile(argv[1]);
	return 0;
}