/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:11:30 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/25 18:53:16 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
	std::cout << "HumanB "<< name << " created without weapon" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "HumanB " << this->name << " destroyed" << std::endl;
}


void HumanB::attack(void) {
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with!" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	std::cout << this->name << " grabbed a " << this->weapon->getType() << " to fight with" << std::endl;
}