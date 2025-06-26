/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:43:37 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 19:09:47 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

AForm::AForm(std::string name): _name(name), _isSigned(false), _signGrade(150), _execGrade(150) {
}

AForm::AForm(std::string name, size_t signGrade, size_t execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &copy): _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
    *this = copy;
}

AForm::~AForm(
) {
}

AForm &AForm::operator=(AForm const &copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

size_t AForm::getSignGrade() const {
    return _signGrade;
}

size_t AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(Bureaucrat &b) {
    if ( b.getGrade() <= this->getSignGrade() )
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " << _name << std::endl;
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form not signed.";
}

std::ostream	&operator<<(std::ostream& os, const AForm& f) {
     os << "AForm " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", required sign grade: " << f.getSignGrade()
       << ", required execute grade: " << f.getExecGrade();
       return os;
}
