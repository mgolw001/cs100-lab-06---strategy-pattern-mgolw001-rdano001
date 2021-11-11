#include "Select_Contains.hpp"
#include <string> 
using namespace std;

Select_Contains::Select_Contains(Spreadsheet* s, string c, string w) : Select_Column(s,c){
	word = w;
}


bool Select_Contains::select(const string& s)const{
	//this function works by itterating through the data in the cell string  by character and comparing it at each step to the first letter in word
	//if the first letter matches one in the cell string it moves onto the next character and keeps comparing
	//once the loop has reached the end of the passed in word it sees if the correct_counter is equal to the length of the word it returns true
	
	int l = s.length();
	int correct_counter =0;
	
	for( int i = 0; i < l; i++){
		if(s[i]==word[correct_counter]){
			correct_counter++;
			if(correct_counter==word.length()){
				return true;
			}
		}
		else{
			correct_counter=0;
		}
		
	}
	if(correct_counter==word.length()){
		return true;
	}
	return false;
}

