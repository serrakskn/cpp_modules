/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:18:10 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/09 16:05:36 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookContact.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void){
	this->contactNumber = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

void	PhoneBook::cmdAdd(PhoneBook& phoneBook){
	this->contacts[this->contactNumber % 8].setFirstName();
	this->contacts[this->contactNumber % 8].setLastName();
	this->contacts[this->contactNumber % 8].setNickname();
	this->contacts[this->contactNumber % 8].setPhoneNumber(phoneBook);
	this->contacts[this->contactNumber % 8].setSecret();
	this->contactNumber++;
}

void    PhoneBook::cmdSearch(void){

	std::string	input;
	int	number;
	int	entries = (this->contactNumber > 7) ? 8 : this->contactNumber;

	if (entries == 0) {	
		std::cerr << "The Phone Book is empty!" << std::endl;
		return ;
	}
	std::cout << "┌───────────────────────────────────────────┐" << std::endl;
	std::cout << "|                 PHONE BOOK                |" << std::endl;
	std::cout << "├──────────┬──────────┬──────────┬──────────┤" << std::endl;
	std::cout << "│     Index│First name| Last name│  Nickname│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i < entries; i++)
		this->contacts[i].displayContacts(i);
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	
	while (true){
		std::cout << "Enter index number > ";
		std::getline(std::cin, input);
		if (input.empty()){
			std::cerr << "Input cannot be empty. Please try again!" << std::endl;
			continue;
		}
		else if (!isNumber(input)) 
        	std::cerr << "Invalid input. Digits only!" << std::endl;
		else if ((number= atoi(input.c_str())) < 1 || number > entries)
			std::cerr << "Please enter a value between 1 and " << entries << "!" << std::endl;
        else
			break;
		std::cin.clear();
	}
	this->contacts[number - 1].getContact();
}

void PhoneBook::cmdExit(){
	std::cout << "The phone book has been closed!" << std::endl;
	exit(0);
}

bool PhoneBook::isNumber(const std::string& str) {
    size_t i = 0;
    while (i < str.size()) {
        if (!isdigit(static_cast<unsigned char>(str[i]))) {
            return false;
        }
        i++;
    }
    return true;
}
