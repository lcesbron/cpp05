#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const& toCopy);
		~Intern(void);

		Intern&	operator=(Intern const& toCopy);

		AForm*	makeForm(std::string name, std::string target) const;
};

#endif //INTERN_HPP
