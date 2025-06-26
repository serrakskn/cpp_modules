/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:28 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/13 19:48:38 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {
	this->_type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(Cat const &copy): Animal()  {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

Cat &Cat::operator=(Cat const &copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
    if (this != &copy) {
        this->_type = copy._type;
    }
	return *this;
}

void Cat::makeSound() const {
	std::cout << this->getType() << " says: ***Meow meow***" << std::endl;
}