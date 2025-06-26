/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:45:16 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/04 20:04:19 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) 
    : AForm("Robotomy Request Form", 72, 45), _target("Default") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target) {

    }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) 
    : AForm(copy) {
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    if (this != &copy) {
        this->_target = copy._target;
    }
    return *this; 
}

void RobotomyRequestForm::executeAction(void) const {
    static bool seeded = false;
    if (!seeded) {
        std::srand(time(0));
        seeded = true;
    }

    std::cout << "*DRILLING NOISES*" << std::endl;
    
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
    }       
}