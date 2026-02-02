#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target_;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const& toCopy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm&	operator=(RobotomyRequestForm const& toCopy);

		virtual void	execute(Bureaucrat const& executor) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
