#ifndef SELECT_AND_HPP
#define SELECT_AND_HPP

#include "select.hpp"

class Select_And: public Select{

	private:
		Select* selection1;
		Select* selection2;
	public:
		Select_And(Select* s, select t){//not only needs one because it only takes in one at a time;
			selection1 = s;
			selection2 = t;
		}
		~Select_And(){

			delete selection1;
			delete selection2;
		}

		bool select(const Spreadsheet* sheet, int row)const;
};

#endif
