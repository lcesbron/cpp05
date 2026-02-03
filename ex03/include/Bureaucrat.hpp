#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <ostream>

# ifndef MAX_GRADE
#  define MAX_GRADE 1
# endif // MAX_GRADE

# ifndef LOWEST_GRADE
#  define LOWEST_GRADE 150
# endif // LOWEST_GRADE

class AForm;

class Bureaucrat
{
	private:
		std::string const	name_;
		size_t				grade_;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, size_t grade);
		Bureaucrat(Bureaucrat const& toCopy);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat const& toCopy);

		std::string	getName(void) const;
		size_t		getGrade(void) const;

		void		incrementGrade(size_t increment);
		void		decrementGrade(size_t decrement);

		void		signForm(AForm& toSign) const;
		void		executeForm(AForm const& toExecute) const;

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

std::ostream&	operator<<(std::ostream& os, Bureaucrat const &toPrint);

# include "AForm.hpp"

#endif //BUREAUCRAT_HPP
