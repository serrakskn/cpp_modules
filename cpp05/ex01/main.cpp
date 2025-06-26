/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:04:41 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 18:29:14 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "✅ Successfull signature attempt:\n" << std::endl;
        Bureaucrat bob("Bob", 30);
        Form taxForm("Tax Form", 40, 50);
        std::cout << taxForm  << std::endl;
        std::cout << bob.getName() << " attempts to sign " << taxForm.getName() << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << "\n" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }

    try {
        std::cout << "❌ Failed signature attempt:\n" << std::endl;
        Bureaucrat alice("Alice", 30);
        Form secretForm("Secret Form", 25, 50);
        std::cout << secretForm  << std::endl;
        std::cout << alice.getName() << " attempts to sign " << secretForm.getName() << std::endl;
        alice.signForm(secretForm);
        std::cout << secretForm << "\n" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }

    try {
        std::cout << "❌ Invalid form grade:\n" << std::endl;
        std::cout << "Creating form with too high sign grade..." << std::endl;
        Form invalidForm("Invalid Form", 0, 50);
    } catch (const std::exception& e) {
        std::cerr << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }

    try {
        std::cout << "❌ Invalid form grade:\n" << std::endl;
        std::cout << "Creating form with too low sign grade..." << std::endl;
        Form invalidForm("Invalid Form", 151, 50);
    } catch (const std::exception& e) {
        std::cerr << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }
    return 0;
}
