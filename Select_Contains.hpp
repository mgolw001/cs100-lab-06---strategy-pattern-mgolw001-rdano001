#ifndef SELECT_CONTAINS_HPP
#define SELECT_CONTAINS_HPP

#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>

using namespace std;


class Select_Contains: public Select_Column{

	private:
		string word; 
	public:
		Select_Contains(Spreadsheet* sheet, string c, string w);
		~Select_Contains(){}
		bool select(const std::string& s)const;
};

#endif
