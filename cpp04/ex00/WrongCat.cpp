/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:26:52 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/13 19:29:01 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal()  {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
    if (this != &copy) {
        this->_type = copy._type;
    }
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << this->getType() << "says: ***WrongCat sound***" << std::endl;
}