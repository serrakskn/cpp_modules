/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:48 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/13 19:57:41 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &copy);
		~WrongAnimal();

		WrongAnimal &operator=(WrongAnimal const &copy);

		void makeSound() const;
		
		std::string getType() const;
};

#endif