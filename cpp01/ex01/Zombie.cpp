/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:49:25 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/23 16:37:19 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {
    std::cout << "Zombie object created" << std::endl; 
}

Zombie::~Zombie( void ) {
    std::cout << "Zombie object " << this->name << " destroyed" << std::endl;
}

void Zombie::setName( std::string name ) {
    this->name = name;
}

void Zombie::announce (void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}