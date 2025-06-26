/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:33 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 17:08:48 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal {
	protected:
		std::string _type;
	
	public:
		AAnimal();
		AAnimal(AAnimal const &copy);
		virtual ~AAnimal();

		AAnimal &operator=(AAnimal const &copy);

		virtual void makeSound() const = 0;
		
		std::string getType() const;
};

#endif