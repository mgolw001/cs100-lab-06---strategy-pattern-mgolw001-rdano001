#include "Select_Not.hpp"

bool Select_Not::select(const std::string& s)const{
	return !(selection.select(s));

}
