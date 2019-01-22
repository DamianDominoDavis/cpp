#ifndef C_CLASS_HPP
# define C_CLASS_HPP
# include <string>

class P {
	private:
		std::string fields[11];

	public:
		std::string getfield(int i);
		void setfield(int i, std::string);
		static const std::string prompts[11];
		static P names[8];
		void searchreport(void);
};

#endif
