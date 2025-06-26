/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:30 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 16:46:51 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(), _brain(new Brain) {
	this->_type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(Dog const &copy): Animal() {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

Dog &Dog::operator=(Dog const &copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
    if (this != &copy) {
        this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
    }
	return *this;
}

void Dog::makeSound() const {
	std::cout << "***Woof woof***" << std::endl;
}

void	Dog::getIdeas(void)const {
	for (int i = 0; i < 100; i++)
		std::cout << "\tIdea " << i << " of the Dog is: * " << this->_brain->getIdea(i) << " * at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

void	Dog::setIdea(size_t i, std::string idea) {
		this->_brain->setIdea(i, idea);
}