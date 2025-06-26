/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:15:04 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/07 13:21:19 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_attackDamage = 20;
	std::cout << "Default constructor called for ScavTrap from ClapTrap." << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_attackDamage = 20;
	std::cout << "ScavTrap from ClapTrap" << this->_name << " created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy){
	std::cout << "ScavTrap from ClapTrap" << this->_name << " copied." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap from ClapTrap" << this->_name << " destroyed." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy) {
	std::cout << "Copy assignment operator called for ScavTrap ." << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}