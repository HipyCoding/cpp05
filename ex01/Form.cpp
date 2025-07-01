/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:51 by candrese          #+#    #+#             */
/*   Updated: 2025/07/01 23:05:35 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//d efault constructor
Form::Form() : name("Form"), isSigned(false), signGrade(150), execGrade(150)
{}

// parameter constructor for name and grade
Form::Form(const std::string& name, int signGrade, int execGrade)
			: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

// copy constructor
Form::Form(const Form& other)
: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{}

// assignment operator
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

// destructor
Form::~Form()
{
	std::cout << name << " destructor called" << std::endl;
}

// getter name
const std::string& Form::getName() const
{
	return (name);
}

// getter to check if signed or not
bool Form::getIsSigned() const
{
	return isSigned;
}

// getter signing grade
int Form::getSignGrade() const
{
	return signGrade;
}

// getter execution grade
int Form::getExecGrade() const
{
	return execGrade;
}

// new functino for signing
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
		isSigned = true;
}


// exception for grade too how
const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Grade Too High");
}

// exception for grade too low
const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Grade Too Low");
}


// overload output stream operator, printing a Form
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << (form.getIsSigned() ? "Signed\n" : "Not Signed\n")
		<< "Grade required to sign: " << form.getSignGrade() << " \n"
		<< "Grade required to execute: " << form.getExecGrade() << " \n";
	return (os);
}
