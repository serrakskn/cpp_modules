/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:14:38 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/25 13:24:03 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie( std::string name );
void randomChump( std::string name );

int main() {
    Zombie *z = newZombie("Foo");
    z->announce();
    delete z;
    
    randomChump("Boo");
    return 0;
}
