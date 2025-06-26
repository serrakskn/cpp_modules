/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:47:30 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/04 20:07:05 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) 
    : AForm("Shrubbery Creation Form", 145, 137), _target("Default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) 
    : AForm(copy) {
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if (this != &copy) {
        this->_target = copy._target;
    }
    return *this; 
}

void ShrubberyCreationForm::executeAction(void) const {
    std::ofstream file((_target + "_shrubbery").c_str());

    if (!file) {
        std::cerr << "Error: Could not open file " << _target << "_shrubbery" << std::endl;
        return;
    }

        file <<
        "        *        \n"
        "       ***       \n"
        "      *****      \n"
        "     *******     \n"
        "    *********    \n"
        "   ***********   \n"
        "  *************  \n"
        " *************** \n"
        "*****************\n"
        "       |||       \n"
        "       |||       \n";

    file.close();
    std::cout << "ASCII tree has been created in " << _target << "_shrubbery file!" << std::endl;
}
