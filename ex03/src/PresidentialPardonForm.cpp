#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(void):
AForm("Presidential Pardon Form", 25, 5),
target_("default_target") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& toCopy):
AForm(toCopy.getName(), toCopy.getRequiredSigning(), toCopy.getRequiredExecute()),
target_(toCopy.target_) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("Presidential Pardon Form", 25, 5),
target_(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& toCopy)
{
	this->target_ = toCopy.target_;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	this->AForm::execute(executor);
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
