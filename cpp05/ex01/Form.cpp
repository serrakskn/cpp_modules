/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:43:37 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/04 20:11:42 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string name)
    : _name(name), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string name, size_t signGrade, size_t execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &copy)
    : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
    *this = copy;
}

Form::~Form() {}

Form &Form::operator=(Form const &copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

size_t Form::getSignGrade() const {
    return _signGrade;
}

size_t Form::getExecGrade() const {
    return _execGrade;
}

void Form::beSigned(Bureaucrat &b) {
    if ( b.getGrade() <= this->getSignGrade() )
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low!";
}

std::ostream	&operator<<(std::ostream& os, const Form& f) {
     os << "Form " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", required sign grade: " << f.getSignGrade()
       << ", required execute grade: " << f.getExecGrade();
       return os;
}
