/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:17:37 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/07 15:40:29 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap	&operator=(ClapTrap const &copy);

		std::string const	&getName(void) const;
		int const			&getHitpoints(void) const;
		int const			&getEnergyPoints(void) const;
		int const			&getAttackDamage(void) const;
		void				setName(std::string const &name);
		void				setHitpoints(int const &value);
		void				setEnergyPoints(int const &value);
		void				setAttackDamage(int const &value);
};

#endif