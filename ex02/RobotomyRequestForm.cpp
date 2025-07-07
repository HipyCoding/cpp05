/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 03:52:05 by christian         #+#    #+#             */
/*   Updated: 2025/07/07 23:45:04 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{}

// parameter constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{}

// assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << " RobotomyRequestForm destructor called" << std::endl;
}

// execute function that calls parent execute for checks
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
}

// actual action implementation
void RobotomyRequestForm::executeAction() const
{
	std::cout << "* drilling noises *" << std::endl;
	std::cout << "BZZZZZZT! WRRRRRR! CLANK CLANK!" << std::endl;
	
	// seed random with current time for better randomness
	srand(time(NULL));
	
	// 50% chance of success
	if (rand() % 2 == 0)
	{
		std::cout << target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "robotomy failed on " << target << std::endl;
	}
}
