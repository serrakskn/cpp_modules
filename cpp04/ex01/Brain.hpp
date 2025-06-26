/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:04:52 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/13 20:46:54 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
	private:
		std::string _ideas[100];
		
	public:
		Brain();
		Brain(Brain const &copy);
		virtual ~Brain();

		Brain &operator=(Brain const &copy);

		const std::string getIdea(size_t i)const;
		const std::string *getIdeaAddress(size_t i)const;

		void setIdea(size_t i, std::string idea);
};

#endif