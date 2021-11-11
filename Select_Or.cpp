#include "Select_Or.hpp"

bool Select_Not::select(const Spreadsheet* sheet, int row) const{

	return (selection1->select(sheet,row))||(selection2->select(sheet,row));

}
