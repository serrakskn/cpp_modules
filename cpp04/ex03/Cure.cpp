/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:09:18 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/26 13:48:28 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure materia created!" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy) {
    std::cout << "Cure materia copied!" << std::endl;
	*this = copy;
}

Cure::~Cure() {
    std::cout << "Cure materia destroyed!" << std::endl;
}

Cure	&Cure::operator=(Cure const &copy) {
    if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}

Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}