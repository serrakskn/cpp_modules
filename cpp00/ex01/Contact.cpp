/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:01:25 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/09 16:05:50 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookContact.hpp"
#include <iomanip>

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

bool Contact::checkPrintable(const std::string& str) {
    size_t i = 0;
    while (i < str.size()) {
        if (!std::isprint(static_cast<unsigned char>(str[i]))) {
            return false;
        }
        i++;
    }
    return true;
}

void Contact::setFirstName(void) {
    while (true) {
        std::cout << "Enter first name > ";
        if (!std::getline(std::cin, this->firstName)) {
            std::cerr << "Input error or EOF detected. Please try again!" << std::endl;
			std::cin.clear(); 
			continue;
        }
        if (this->firstName.empty()) {
            std::cerr << "This field can't be empty!" << std::endl;
        }
        else if (!this->checkPrintable(this->firstName)) {
            std::cerr << "Only printable characters!" << std::endl;
        }
        else {
            break;
        }
	}
}

void Contact::setLastName(void) {
    while (true) {
        std::cout << "Enter last name > ";
        if (!std::getline(std::cin, this->lastName)) {
            std::cerr << "Input error or EOF detected. Please try again!" << std::endl;
			std::cin.clear(); 
			continue;
        }
        if (this->lastName.empty()) {
            std::cerr << "This field can't be empty!" << std::endl;
        }
        else if (!this->checkPrintable(this->lastName)) {
            std::cerr << "Only printable characters!" << std::endl;
        }
        else {
            break;
        }
	}
}

void Contact::setNickname(void) {
    while (true) {
        std::cout << "Enter nickname > ";
        if (!std::getline(std::cin, this->nickname)) {
            std::cerr << "Input error or EOF detected. Please try again!" << std::endl;
			std::cin.clear(); 
			continue;
        }
        if (this->nickname.empty()) {
            std::cerr << "This field can't be empty!" << std::endl;
        }
        else if (!this->checkPrintable(this->nickname)) {
            std::cerr << "Only printable characters!" << std::endl;
        }
        else {
            break;
        }
	}
}

void Contact::setPhoneNumber(PhoneBook& phoneBook) {
    while (true) {
        std::cout << "Enter phone number > ";
        if (!std::getline(std::cin, this->phoneNumber)) {
            std::cerr << "Input error or EOF detected. Please try again!" << std::endl;
			std::cin.clear(); 
			continue;
        }
        if (this->phoneNumber.empty()) {
            std::cerr << "This field can't be empty!" << std::endl;
        }
        else if (!phoneBook.isNumber(this->phoneNumber)) {
            std::cerr << "Only numeric characters!" << std::endl;
        }
        else {
            break;
        }
	}
}

void Contact::setSecret(void) {
    while (true) {
        std::cout << "Enter darkest secret > ";
        if (!std::getline(std::cin, this->secret)) {
            std::cerr << "Input error or EOF detected. Please try again!" << std::endl;
			std::cin.clear(); 
			continue;
        }
        if (this->secret.empty()) {
            std::cerr << "This field can't be empty!" << std::endl;
        }
        else if (!this->checkPrintable(this->secret)) {
            std::cerr << "Only printable characters!" << std::endl;
        }
        else {
            break;
        }
	}
}

std::string	Contact::truncate(std::string str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void    Contact::displayContacts(int i) {

	std::cout << "|" << std::setw(10) << static_cast<int>(i + 1);
	std::cout << "|" << std::setw(10) << this->truncate(this->firstName);
	std::cout << "|" << std::setw(10) << this->truncate(this->lastName);
	std::cout << "|" << std::setw(10) << this->truncate(this->nickname);
	std::cout << "|" << std::endl;

}

void	Contact::getContact(void) {
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->secret << std::endl;
}

std::string	Contact::getFirstName(void) {
	return (this->firstName);
}

std::string	Contact::getLastName(void) {
	return (this->lastName);
}

std::string	Contact::getNickname(void) {
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->phoneNumber);
}

std::string	Contact::getSecret(void) {
	return (this->secret);
}
