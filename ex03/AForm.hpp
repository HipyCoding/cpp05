/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:54 by candrese          #+#    #+#             */
/*   Updated: 2025/07/08 02:41:34 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool 				isSigned;
	const int			signGrade;
	const int			execGrade;
	

public:
	AForm();
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

	const std::string& getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif
