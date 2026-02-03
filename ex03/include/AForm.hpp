#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <cstddef>
#include <exception>
# include <iostream>
# include <ostream>

class AForm
{
	private:
		std::string const	name_;
		bool				signed_;
		size_t const		requiredSigningGrade_;
		size_t const		requiredExecuteGrade_;

	public:
		AForm(void);
		AForm(std::string name, size_t signing, size_t execute);
		AForm(AForm const& toCopy);
		virtual ~AForm(void);

		AForm&	operator=(AForm const& toCopy);

		std::string const&	getName(void) const;
		bool				getSigned(void) const;
		size_t const&		getRequiredSigning(void) const;
		size_t const&		getRequiredExecute(void) const;

		void				beSigned(Bureaucrat const& bureaucrat);
		void				checkExecutable(size_t const executorGrade) const;
		virtual void		execute(Bureaucrat const& executor) const = 0;

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
		class				NotSignedException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, AForm const& AForm);

#endif //AForm_HPP
