/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:41:26 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/23 20:16:37 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name){
    std::cout << "Zombie object " << this->name << " created" << std::endl;
}

Zombie::~Zombie( void ) {
    std::cout << "Zombie object " << this->name << " destroyed" << std::endl;
}

void Zombie::announce (void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

