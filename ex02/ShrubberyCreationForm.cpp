/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 03:52:10 by christian         #+#    #+#             */
/*   Updated: 2025/07/07 23:44:34 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{}

// parameter constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{}

// assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << " ShrubberyCreationForm destructor called" << std::endl;
}

// function calls parent execute for checks
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
}

// action implementation
void ShrubberyCreationForm::executeAction() const
{
	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not create file " << filename << std::endl;
		return;
	}
	
file << "        ___         ___        " << std::endl;
file << "      /     \\     /    \\     " << std::endl;
file << "     /       \\  /       \\    " << std::endl;
file << "    (         )(         )    " << std::endl;
file << "    (         )(         )    " << std::endl;
file << "     \\       /  \\       /    " << std::endl;
file << "      \\_____/    \\_____/     " << std::endl;
file << "         ||          ||        " << std::endl;
file << "         ||          ||        " << std::endl;
	file.close();
	std::cout << "trees in file: " << filename << std::endl;
}
