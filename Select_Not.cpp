#include "Select_Not.hpp"

bool Select_Not::select(const Spreadsheet* sheet, int row) const{

	return !(selection.select(sheet,row));

}
