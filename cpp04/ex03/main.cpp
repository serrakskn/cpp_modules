/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:18:58 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/26 13:51:56 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << std::endl;
	
	AMateria *Ice1 = new Ice();
	AMateria *Ice2 = new Ice();
	AMateria *Cure1 = new Ice();
	AMateria *Cure2 = new Ice();

	me->equip(Ice1);
	me->equip(Ice2);
	me->equip(Cure1);
	me->equip(Cure2);
	
	me->unequip(3);
	
	delete Ice2;
	
	delete Cure1;
	delete Cure2;

	delete bob;
	delete me;
	delete src;
	return 0;
}