/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:54 by candrese          #+#    #+#             */
/*   Updated: 2025/07/07 23:42:15 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool 				isSigned;
	const int			signGrade;
	const int			execGrade;
	

public:
	Form();
	Form(const std::string& name, int signGrade, int execGrade);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();

	void beSigned(const Bureaucrat& bureaucrat);

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

	const std::string& getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif
