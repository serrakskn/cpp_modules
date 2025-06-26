/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:43:35 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/04 19:04:02 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
	private:
		const std::string  _name;
		bool _isSigned;
		const size_t _signGrade;
		const size_t _execGrade;
	public:
		Form();
		Form(std::string name);
		Form(std::string name, size_t signGrade, size_t execGrade);
		Form(Form const &copy);
		~Form();

		Form &operator=(Form const &copy);

		std::string getName() const;
		bool getIsSigned() const;
		size_t getSignGrade() const;
		size_t getExecGrade() const;
		
		void beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& os, const Form& f);

#endif