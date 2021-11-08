#ifndef SELECT_CONTAINS_HPP
#define SELECT_CONTAINS_HPP

#include "select.hpp"

class Select_Contains: public Select{

	private:

	public:

		~Select_Contains()
		bool select(const Spreadsheet* sheet, int row);
};

#endif
