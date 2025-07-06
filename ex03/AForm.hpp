/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:54 by candrese          #+#    #+#             */
/*   Updated: 2025/07/03 04:10:37 by christian        ###   ########.fr       */
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

protected:
	virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif