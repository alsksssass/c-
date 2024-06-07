#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

#define TREE                                                          \
"                                              .         ;  \\\n" \
"                 .              .              ;%     ;;   \\\n" \
"                   ,           ,                :;%  %;   \\\n" \
"                    :         ;                   :;%;'     .,   \\\n" \
"           ,.        %;     %;            ;        %;'    ,; \\\n" \
"             ;       ;%;  %%;        ,     %;    ;%;    ,%' \\\n" \
"              %;       %;%;      ,  ;       %;  ;%;   ,%;'  \\\n" \
"               ;%;      %;        ;%;        % ;%;  ,%;' \\\n" \
"                `%;.     ;%;     %;'         `;%%;.%;' \\\n" \
"                 `:;%.    ;%%. %@;        %; ;@%;%' \\\n" \
"                    `:%;.  :;bd%;          %;@%;' \\\n" \
"                      `@%:.  :;%.         ;@@%;'   \\\n" \
"                        `@%.  `;@%.      ;@@%;         \\\n" \
"                          `@%%. `@%%    ;@@%;        \\\n" \
"                            ;@%. :@%%  %@@%;       \\\n" \
"                              %@bd%%%bd%%:;     \\\n" \
"                                #@%%%%%:;; \\\n" \
"                                %@@%%%::; \\\n" \
"                                %@@@%(o);  . '         \\\n" \
"                                %@@@o%;:(.,'         \\\n" \
"                            `.. %@@@o%::;         \\\n" \
"                               `)@@@o%::;         \\\n" \
"                                %@@(o)::;        \\\n" \
"                               .%@@@@%::;         \\\n" \
"                               ;%@@@@%::;.          \\\n" \
"                              ;%@@@@%%:;;;. \\\n" \
"                          ...;%@@@@@%%:;;;;,..    Gilo97"


class ShrubberyCreationForm : public AForm{
private:
	std::string target;
	ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
public:
	class FileOpenFail : public std::exception {
		public:
			FileOpenFail(){}
			virtual const char * what() const throw(){return "File create error!!";}
	};
	ShrubberyCreationForm(const std::string _target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &a);
	virtual void execute(Bureaucrat const & executor) const;
	const std::string getTarget() const;
};

#endif // SHRUBBERYCREATIONFORM_HPP