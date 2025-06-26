/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:18:55 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/17 20:35:23 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"


AMateria::AMateria() {

}

AMateria::AMateria(std::string const &type) : _type(type) {
	
}

AMateria::AMateria(AMateria const &copy) {
	*this = copy;
}

AMateria::~AMateria() {
	
}

AMateria	&AMateria::operator=(AMateria const &copy) {
	if (this != &copy) {
		_type = copy._type;
	}
	return *this;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "Using Amateria!"  << std::endl;
}

std::string const & AMateria::getType() const {
	return _type;
}