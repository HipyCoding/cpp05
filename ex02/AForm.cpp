/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:51 by candrese          #+#    #+#             */
/*   Updated: 2025/07/08 03:29:14 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//d efault constructor
AForm::AForm() : name("AForm"), isSigned(false), signGrade(150), execGrade(150)
{}

// parameter constructor for name and grade
AForm::AForm(const std::string& name, int signGrade, int execGrade)
			: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

// copy constructor
AForm::AForm(const AForm& other)
: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{}

// assignment operator
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

// destructor
AForm::~AForm()
{
	std::cout << name << " destructor called" << std::endl;
}

// getter name
const std::string& AForm::getName() const
{
	return (name);
}

// getter to check if signed or not
bool AForm::getIsSigned() const
{
	return isSigned;
}

// getter signing grade
int AForm::getSignGrade() const
{
	return signGrade;
}

// getter execution grade
int AForm::getExecGrade() const
{
	return execGrade;
}

// function for signing
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
	{
		throw GradeTooLowException();
	}
	isSigned = true;
}

// exception for grade too high
const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade Too High");
}

// exception for grade too low
const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade Too Low");
}

// exception for form not signed
const char* AForm::FormNotSignedException::what() const noexcept
{
	return ("Form Not Signed");
}

// overload output stream operator, printing a aform
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << (form.getIsSigned() ? " Signed\n" : " Not Signed\n")
		<< "Grade required to sign: " << form.getSignGrade() << " \n"
		<< "Grade required to execute: " << form.getExecGrade() << " \n";
	return (os);
}
