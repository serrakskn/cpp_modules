/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:52:38 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/07 16:05:28 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 100;
	ClapTrap::_attackDamage = 30;
	std::cout << "Default constructor called for FragTrap from ClapTrap." << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 100;
	ClapTrap::_attackDamage = 30;
	std::cout << "FragTrap from ClapTrap" << this->_name << " created." << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy){
	std::cout << "FragTrap from ClapTrap" << this->_name << " copied." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap from ClapTrap" << this->_name << " destroyed." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy) {
	std::cout << "Copy assignment operator called for FragTrap ." << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap here, ready to light up your day with an explosive HIGH FIVE! " << std::endl;
}