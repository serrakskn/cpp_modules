/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:18:54 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/17 17:59:03 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria {
	protected:
		std::string _type;
		
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
		virtual ~AMateria();

		AMateria	&operator=(AMateria const &copy);
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		std::string const &getType() const;
};

#endif