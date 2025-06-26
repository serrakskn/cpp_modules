/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:17:35 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/10 15:00:27 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("NULL"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "ClapTrap " << this->_name << " copied." << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{ 
	if (this->_hitPoints > 0 && this->_energyPoints)	
	{
		std::cout << "ClapTrap " << this->_name << " attacked " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_hitPoints--;
	}
	else if (!this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	else if (!this->_energyPoints)
		std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
		this->_hitPoints = (amount >= (static_cast<unsigned int>(this->_hitPoints))) ? 0 : this->_hitPoints - amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " repaired itself " << amount << " points." << std::endl;
		this->_energyPoints--;
	}
	
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &copy) {
	std::cout << "Copy assignment operator for ClapTrap called." << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return *this;
}

std::string const	&ClapTrap::getName(void) const
{
	return (this->_name);
}

int const	&ClapTrap::getHitpoints(void) const
{
	return (this->_hitPoints);
}

int const	&ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int const	&ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string const &name)
{
	this->_name = name;
}

void	ClapTrap::setHitpoints(int const &value)
{
	this->_hitPoints = value;
}

void	ClapTrap::setEnergyPoints(int const &value)
{
	this->_energyPoints = value;
}

void	ClapTrap::setAttackDamage(int const &value)
{
	this->_attackDamage = value;
}