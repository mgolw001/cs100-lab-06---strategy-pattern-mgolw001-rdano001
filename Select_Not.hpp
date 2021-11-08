#ifndef SELECT_NOT_HPP
#define SELECT_NOT_HPP

#include "select.hpp"

class Select_Not: public Select{

	private:

	public:

		~Select_Not()
		bool select(const Spreadsheet* sheet, int row);
};

#endif
