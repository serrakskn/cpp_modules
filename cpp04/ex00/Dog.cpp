/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:30 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/13 19:48:55 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() {
	this->_type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(Dog const &copy): Animal() {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

Dog &Dog::operator=(Dog const &copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
    if (this != &copy) {
        this->_type = copy._type;
    }
	return *this;
}

void Dog::makeSound() const {
	std::cout << this->getType() << " says: ***Woof woof***" << std::endl;
}