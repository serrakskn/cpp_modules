/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:04:50 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 16:20:09 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(Brain const &copy) {
    std::cout << "Brain copy constructor called." << std::endl;
	*this = copy;
}

Brain::~Brain() {
    std::cout << "Brain destructor called." << std::endl;
}

Brain &Brain::operator=(Brain const &copy) {
    std::cout << "Brain copy assignment operator called." << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; ++i) {
            this->_ideas[i] = copy._ideas[i];
        }
    }
    return *this;
}

const std::string	Brain::getIdea(size_t i)const {
	if (i < 100)
		return(this->_ideas[i]);
	else
		return ("There is only 100 ideas per brain.");
}

const std::string *Brain::getIdeaAddress(size_t i)const {
	if (i < 100)
	{
		const std::string	&stringREF = this->_ideas[i];
		return(&stringREF);
	}
	else
		return (NULL);
}

void	Brain::setIdea(size_t i, std::string idea) {
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "There is only 100 ideas per brain." << std::endl;
}