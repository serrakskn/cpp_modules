/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:28 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 16:58:29 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <cstdlib>

Cat::Cat(): Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cerr << "Cat brain allocation failed." << std::endl;
		exit(1);
	}
}

Cat::Cat(Cat const &copy): Animal()  {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete _brain;
}

Cat &Cat::operator=(Cat const &copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
    if (this != &copy) {
        this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
    }

	return *this;
}

void Cat::makeSound() const {
	std::cout << "***Meow meow***" << std::endl;
}

void	Cat::getIdeas(void)const {
	for (int i = 0; i < 100; i++)
		std::cout << "\tIdea " << i << " of the Cat is: * " << this->_brain->getIdea(i) << " * at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

void	Cat::setIdea(size_t i, std::string idea) {
		this->_brain->setIdea(i, idea);
}