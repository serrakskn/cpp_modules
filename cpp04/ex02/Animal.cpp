/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:25 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 17:09:00 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(): _type("Default") {
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = copy;
}
AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &copy) {
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void	AAnimal::makeSound() const {
	std::cout << this->getType() << "says: ***Default AAnimal sound***" << std::endl;
}

std::string AAnimal::getType() const {
	return this->_type;
}