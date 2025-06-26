/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:17:33 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/10 15:01:55 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Clyde");
	ScavTrap scavtrap("Scarlet");
	FragTrap fragtrap("Fred");
	std::cout << std::endl;

	fragtrap.attack("Scarlet");
	claptrap.attack("Scarlet");
	scavtrap.attack("Clyde");
	std::cout << std::endl;

	fragtrap.attack("Scarlet");
	fragtrap.attack("Scarlet");
	fragtrap.attack("Scarlet");
	fragtrap.attack("Scarlet");
	std::cout << std::endl;

	fragtrap.highFivesGuys();
	std::cout << std::endl;

	fragtrap.beRepaired(18);

	fragtrap.takeDamage(50);

	fragtrap.takeDamage(50);

	fragtrap.beRepaired(20);
	fragtrap.attack("Scarlet");

	std::cout << std::endl;
	return (0);
}