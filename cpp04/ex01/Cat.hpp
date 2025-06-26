/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:36 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 17:06:34 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
		
	public:
		Cat();
		Cat(Cat const &copy);
		~Cat();

		Cat &operator=(Cat const &copy);

		void makeSound() const;
		void getIdeas(void)const;
		void setIdea(size_t i, std::string idea);
};

#endif