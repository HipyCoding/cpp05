/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:49:58 by candrese          #+#    #+#             */
/*   Updated: 2025/07/07 23:47:14 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//d efault constructor
Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

// parameter constructor for name and grade
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

// destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << name << " destructor called" << std::endl;
}

// getter grade
int Bureaucrat::getGrade() const
{
	return (grade);
}
// getter name
const std::string& Bureaucrat::getName() const
{
	return (name);
}

// exception for grade too how
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade Too High");
}

// exception for grade too low
const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade Too Low");
}

// increment grade by 1
void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

// decrement grade by 1
void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

// overload output stream operator, printing a bureaucrat
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
