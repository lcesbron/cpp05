#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cassert>
#include <cstddef>
#include <string>

AForm::AForm(void):
name_("default AForm name"),
signed_(false),
requiredSigningGrade_(1),
requiredExecuteGrade_(1)
{
	if (this->requiredExecuteGrade_ > LOWEST_GRADE || this->requiredSigningGrade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	if (this->requiredExecuteGrade_ < MAX_GRADE || this->requiredSigningGrade_ < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm(AForm const& toCopy):
name_(toCopy.name_),
signed_(toCopy.signed_),
requiredSigningGrade_(toCopy.requiredSigningGrade_),
requiredExecuteGrade_(toCopy.requiredExecuteGrade_)
{
	if (this->requiredExecuteGrade_ > LOWEST_GRADE || this->requiredSigningGrade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	if (this->requiredExecuteGrade_ < MAX_GRADE || this->requiredSigningGrade_ < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm(std::string name, size_t signing, size_t execute):
name_(name),
signed_(false),
requiredSigningGrade_(signing),
requiredExecuteGrade_(execute)
{
	if (this->requiredExecuteGrade_ > LOWEST_GRADE || this->requiredSigningGrade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	if (this->requiredExecuteGrade_ < MAX_GRADE || this->requiredSigningGrade_ < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::~AForm(void) {}

AForm&	AForm::operator=(AForm const& toCopy)
{
	if (this != &toCopy)
	{
		this->signed_ = toCopy.signed_;
	}
	return (*this);
}

std::string const&	AForm::getName(void) const
{
	return (this->name_);
}

bool	AForm::getSigned(void) const
{
	return (this->signed_);
}

size_t const&		AForm::getRequiredSigning(void) const
{
	return (this->requiredSigningGrade_);
}

size_t const&		AForm::getRequiredExecute(void) const
{
	return (this->requiredExecuteGrade_);
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

const char*	AForm::NotSignedException::what(void) const throw()
{
	return ("Form isn't signed.");
}

void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->requiredSigningGrade_)
	{
		this->signed_ = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

void		AForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
	{
		throw NotSignedException();
	}
	if (executor.getGrade() > this->getRequiredExecute())
	{
		throw GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, AForm const& AForm)
{
	os << "AForm name : " << AForm.getName() << std::endl;
	os << "AForm has signature : " << AForm.getSigned() << std::endl;
	os << "AForm required signing grade : " << AForm.getRequiredSigning() << std::endl;
	os << "AForm required execute grade : " << AForm.getRequiredExecute() << std::endl;
	return (os);
}
