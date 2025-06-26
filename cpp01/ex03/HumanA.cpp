/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:11:25 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/25 18:53:35 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
    std::cout << "HumanA "<< name << " created with " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA(void) {
    std::cout << "HumanA " << this->name << " destroyed" << std::endl;
}

void HumanA::attack(void) {
    std::cout << this->name << " attacks with their " << this->weapon.getType() <<std::endl;
}
