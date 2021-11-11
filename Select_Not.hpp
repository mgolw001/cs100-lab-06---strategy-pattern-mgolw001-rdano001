#ifndef SELECT_NOT_HPP
#define SELECT_NOT_HPP

#include "select.hpp"

class Select_Not: public Select{

	private:
		Select* selection;
	public:
		Select_Not(Select* s){//not only needs one because it only takes in one at a time;
			selection = s;
		}
		~Select_Not(){

			delete selection;
		}

		bool select(const Spreadsheet* sheet, int row)const;
};

#endif
