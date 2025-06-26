/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:09:14 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 19:38:35 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(Cure const &copy);
		~Cure();

		Cure	&operator=(Cure const &copy);

		Cure* clone() const;
		void use(ICharacter& target);
	
};


#endif