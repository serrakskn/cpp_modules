/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:43:24 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 19:14:34 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) 
    : AForm("Presidential Pardon Form", 25, 5), _target("Default") {
        
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) 
    : AForm(copy) {
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    if (this != &copy) {
        this->_target = copy._target;
    }
    return *this; 
}

void PresidentialPardonForm::executeAction(void) const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}