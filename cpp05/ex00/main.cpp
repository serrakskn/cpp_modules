/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:04:41 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 16:30:00 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "✅ Creating Bureaucrats" << std::endl;
        Bureaucrat alice("Alice", 42);
        Bureaucrat bob("Bob", 2);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;

        std::cout << "\n🔽 Decrementing Alice's grade (should succeed)" << std::endl;
        alice.decrementGrade();
        std::cout << alice << std::endl;
		
        std::cout << "\n🔼 Incrementing Bob's grade (should succeed)" << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        std::cout << "\n📝 Copy Assignment Test" << std::endl;
        alice = bob;
        std::cout << "Alice after assignment: " << alice << std::endl;
    } catch (const std::exception& e) {
        std::cout << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }
		
		std::cout << "\n❌ EXCEPTION EXAMPLES\n" << std::endl;
	try {
        Bureaucrat lowest("John", 150);
        std::cout << lowest << std::endl;
        lowest.decrementGrade();
    } catch (const std::exception& e) {
        std::cout << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }
	try {
        Bureaucrat highest("Sophia", 1);
        std::cout << highest << std::endl;
        highest.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }

    try {
        Bureaucrat illegal("Michael", 0);
    } catch (const std::exception& e) {
        std::cout << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }

    try {
        Bureaucrat illegal("David", 151);
    } catch (const std::exception& e) {
        std::cout << "⚠️ Exception caught: " << e.what() << "\n" << std::endl;
    }


    std::cout << "\n✅ All tests completed successfully!" << std::endl;
    return 0;
}
