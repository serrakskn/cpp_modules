/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:39 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 17:06:13 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"


class Dog : public AAnimal {
	private:
		Brain *_brain;
		
	public:
		Dog();
		Dog(Dog const &copy);
		~Dog();
        
        Dog &operator=(Dog const &copy);

		void makeSound() const;
		void getIdeas(void)const;
		void setIdea(size_t i, std::string idea);
};

#endif