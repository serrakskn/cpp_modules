/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:14:46 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/17 20:45:32 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() {
	
}

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(Character const & copy) : _name(copy._name) {
	for (int i = 0; i < 4; i++) {
		if (copy._inventory[i]) {
			_inventory[i] = copy._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i]; 
		}
	}
}

Character& Character::operator=(Character const & copy) {
	if (this != &copy) {
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
			}
		}
		
		_name = copy._name;
		for (int i = 0; i < 4; i++) {
			if (copy._inventory[i]) {
				_inventory[i] = copy._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	}
}
