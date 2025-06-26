/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:25 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/13 19:51:39 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Default") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const &copy) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = copy;
}
Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

Animal	&Animal::operator=(Animal const &copy) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void	Animal::makeSound() const {
	std::cout << this->getType() << "says: ***Default Animal sound***" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}