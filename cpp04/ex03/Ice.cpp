/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:09:16 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/26 13:48:33 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice materia created!" << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy) {
	std::cout << "Ice materia copied!" << std::endl;
	*this = copy;
}

Ice::~Ice() {
	std::cout << "Ice materia destroyed!" << std::endl;
}

Ice	&Ice::operator=(Ice const &copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}

Ice* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
