/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:33 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/13 19:24:34 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(Animal const &copy);
		virtual ~Animal();

		Animal &operator=(Animal const &copy);

		virtual void makeSound() const;
		
		std::string getType() const;
};

#endif