#include "Select_And.hpp"

bool Select_And::select(const Spreadsheet* sheet, int row) const{

	return (selection1->select(sheet,row))&&(selection2->select(sheet,row));

}
