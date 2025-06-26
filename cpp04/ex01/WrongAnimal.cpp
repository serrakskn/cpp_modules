/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:45 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 16:59:07 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongDefault") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = copy;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &copy) {
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "***WrongAnimal sound***" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}