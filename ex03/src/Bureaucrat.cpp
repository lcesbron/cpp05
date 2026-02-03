#include "Bureaucrat.hpp"
#include <cstddef>
#include <exception>

Bureaucrat::Bureaucrat(void): name_("default bureaucrat name")
{
	this->grade_ = LOWEST_GRADE;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade): name_(name), grade_(grade)
{
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& toCopy): name_(toCopy.getName())
{
	this->grade_ = toCopy.getGrade();
	if (this->grade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	if (this->grade_ < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& toCopy)
{
	if (this != &toCopy)
	{
		this->grade_ = toCopy.getGrade();
		if (this->grade_ > LOWEST_GRADE)
			throw GradeTooLowException();
		if (this->grade_ < MAX_GRADE)
			throw GradeTooHighException();
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name_);
}
size_t	Bureaucrat::getGrade(void) const
{
	return(this->grade_);
}

void	Bureaucrat::incrementGrade(size_t increment)
{
	if (increment + MAX_GRADE > this->grade_)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_ -= increment;
}
void	Bureaucrat::decrementGrade(size_t decrement)
{
	if (this->grade_ + decrement > LOWEST_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_ += decrement;
}

void		Bureaucrat::signForm(AForm& toSign) const
{
	try
	{
		toSign.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout << this->name_ << " couldn't sign " << toSign.getName() << " because his grade is too low." << std::endl;
		return ;
	}
	std::cout << this->name_ << " signed " << toSign.getName() << std::endl;
}

void		Bureaucrat::executeForm(AForm const& toExecute) const
{
	try
	{
		toExecute.execute(*this);
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute form " << toExecute.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " executeded form " << toExecute.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const &toPrint)
{
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade() << ".";
	return (os);
}
