/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:49:58 by candrese          #+#    #+#             */
/*   Updated: 2025/06/04 16:19:11 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {
		name = other.name;
		grade = other.grade
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << name << "destructor called" << std::endl;
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

const std::string& Bureaucrat::getName() const {
	return (name);
}
