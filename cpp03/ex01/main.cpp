/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:17:33 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/07 15:07:19 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Clyde");
	ScavTrap scavtrap("Scarlet");

	std::cout << std::endl;
	claptrap.attack("Scarlet");
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(18);
	std::cout << std::endl;
	scavtrap.attack("Clyde");
	claptrap.takeDamage(20);
	scavtrap.attack("Clyde");
	claptrap.takeDamage(20);
	scavtrap.attack("Clyde");
	claptrap.beRepaired(64);
	std::cout << std::endl;
	scavtrap.guardGate();
	scavtrap.attack("Clyde");
	std::cout << std::endl;
	scavtrap.takeDamage(100);
	scavtrap.takeDamage(1);
	scavtrap.attack("Scarlet");
	scavtrap.beRepaired(200);
	
	std::cout << std::endl;
	return (0);
}