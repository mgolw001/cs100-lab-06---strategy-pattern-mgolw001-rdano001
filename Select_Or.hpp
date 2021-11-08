#ifndef SELECT_OR_HPP
#define SELECT_OR_HPP

#include "select.hpp"

class Select_Or: public Select{

	private:

	public:

		~Select_Or()
		bool select(const Spreadsheet* sheet, int row);
};

#endif
