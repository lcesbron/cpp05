#include "Bureaucrat.hpp"
#include <cstddef>


Bureaucrat::Bureaucrat(void)
{
	this->name_ = "default bureaucrat name";
	this->grade_ = 150;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade): name_(name), grade_(grade) {}

Bureaucrat::Bureaucrat(Bureaucrat const& toCopy)
{
	this->name_ = toCopy.getName();
	this->grade_ = toCopy.getGrade();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& toCopy)
{
	this->name_ = toCopy.getName();
	this->grade_ = toCopy.getGrade();
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
	if (this->grade_ + increment > LOWEST_GRADE)
	{
		throw
	}
	this->grade_ += increment;
}
Bureaucrat::void		decrementGrade(size_t decrement);
