#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target_;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& toCopy);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm&	operator=(PresidentialPardonForm const& toCopy);

		virtual void		execute(Bureaucrat const& executor) const;
};

#endif //PRESIDENTIALPARDON_HPP
