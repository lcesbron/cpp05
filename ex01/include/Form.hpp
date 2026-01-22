#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <cstddef>
# include <iostream>
# include <ostream>

class Form
{
	private:
		std::string const	name_;
		bool				signed_;
		size_t const		requiredSigningGrade_;
		size_t const		requiredExecuteGrade_;

	public:
		Form(void);
		Form(std::string name, size_t signing, size_t execute);
		Form(Form const& toCopy);
		~Form(void);

		Form&	operator=(Form const& toCopy);

		std::string const&	getName(void) const;
		bool				getSigned(void) const;
		size_t const&		getRequiredSigning(void) const;
		size_t const&		getRequiredExecute(void) const;

		void				beSigned(Bureaucrat const& bureaucrat);
		void				signForm(Bureaucrat const& bureaucrat);

		class		GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
		class		GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Form const& form);

#endif //FORM_HPP
