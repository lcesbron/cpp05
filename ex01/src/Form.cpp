#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cassert>
#include <cstddef>
#include <string>

Form::Form(void): name_("default form name"),
				  signed_(false),
				  requiredSigningGrade_(1),
				  requiredExecuteGrade_(1)
{
	if (this->requiredExecuteGrade_ > LOWEST_GRADE || this->requiredSigningGrade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	if (this->requiredExecuteGrade_ < MAX_GRADE || this->requiredSigningGrade_ < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(Form const& toCopy): name_(toCopy.name_),
						signed_(toCopy.signed_),
						requiredSigningGrade_(toCopy.requiredSigningGrade_),
						requiredExecuteGrade_(toCopy.requiredExecuteGrade_)
{
	if (this->requiredExecuteGrade_ > LOWEST_GRADE || this->requiredSigningGrade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	if (this->requiredExecuteGrade_ < MAX_GRADE || this->requiredSigningGrade_ < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(std::string name, size_t signing, size_t execute): name_(name),
						signed_(false),
						requiredSigningGrade_(signing),
						requiredExecuteGrade_(execute)
{
	if (this->requiredExecuteGrade_ > LOWEST_GRADE || this->requiredSigningGrade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	if (this->requiredExecuteGrade_ < MAX_GRADE || this->requiredSigningGrade_ < MAX_GRADE)
		throw GradeTooHighException();
}

Form::~Form(void) {}

Form&	Form::operator=(Form const& toCopy)
{
	if (this != &toCopy)
	{
		this->signed_ = toCopy.signed_;
	}
	return (*this);
}

std::string const&	Form::getName(void) const
{
	return (this->name_);
}

bool	Form::getSigned(void) const
{
	return (this->signed_);
}

size_t const&		Form::getRequiredSigning(void) const
{
	return (this->requiredSigningGrade_);
}

size_t const&		Form::getRequiredExecute(void) const
{
	return (this->requiredExecuteGrade_);
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->requiredSigningGrade_)
	{
		this->signed_ = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, Form const& form)
{
	os << "Form name : " << form.getName() << std::endl;
	os << "Form has signature : " << form.getSigned() << std::endl;
	os << "Form required signing grade : " << form.getRequiredSigning() << std::endl;
	os << "Form required execute grade : " << form.getRequiredExecute() << std::endl;
	return (os);
}
