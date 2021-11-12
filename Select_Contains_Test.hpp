#ifndef SELECT_CONTAINS_TEST_HPP
#define SELECT_CONTAINS_TEST_HPP

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"

TEST(ContainsTest, Exists){
	Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
	sheet.add_row({"Amanda","Andrews","22","business"});
        sheet.add_row({"Brian","Becker","21","computer science"});
        sheet.add_row({"Carol","Conners","21","computer science"});
        sheet.add_row({"Joe","Jackson","21","mathematics"});
        sheet.add_row({"Sarah","Summers","21","computer science"});
        sheet.add_row({"Diane","Dole","20","computer engineering"});
        sheet.add_row({"David","Dole","22","electrical engineering"});
        sheet.add_row({"Dominick","Dole","22","communications"});
        sheet.add_row({"George","Genius","9","astrophysics"});
	
	Select_Contains* x = new Select_Contains(&sheet, "Last", "Genius");
	sheet.set_selection(x);
	EXPECT_EQ(x->select(&sheet, 8), true);
}

TEST(ContainsTest, NotExist){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
        sheet.add_row({"Brian","Becker","21","computer science"});
        sheet.add_row({"Carol","Conners","21","computer science"});
        sheet.add_row({"Joe","Jackson","21","mathematics"});
        sheet.add_row({"Sarah","Summers","21","computer science"});
        sheet.add_row({"Diane","Dole","20","computer engineering"});
        sheet.add_row({"David","Dole","22","electrical engineering"});
        sheet.add_row({"Dominick","Dole","22","communications"});
        sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* x = new Select_Contains(&sheet, "Last", "Danover");
        sheet.set_selection(x);
        EXPECT_EQ(x->select(&sheet, 8), false;
}

TEST(ContainsTest, EmptyString){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
        sheet.add_row({"Brian","Becker","21","computer science"});
        sheet.add_row({"Carol","Conners","21","computer science"});
        sheet.add_row({"Joe","Jackson","21","mathematics"});
        sheet.add_row({"Sarah","Summers","21","computer science"});
        sheet.add_row({"Diane","Dole","20","computer engineering"});
        sheet.add_row({"David","Dole","22","electrical engineering"});
        sheet.add_row({"Dominick","Dole","22","communications"});
        sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* x = new Select_Contains(&sheet, "Last", "");
        sheet.set_selection(x);
        EXPECT_EQ(x->select(&sheet, 8), true);
}

TEST(ContainsTest, PartialWord){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
        sheet.add_row({"Brian","Becker","21","computer science"});
        sheet.add_row({"Carol","Conners","21","computer science"});
        sheet.add_row({"Joe","Jackson","21","mathematics"});
        sheet.add_row({"Sarah","Summers","21","computer science"});
        sheet.add_row({"Diane","Dole","20","computer engineering"});
        sheet.add_row({"David","Dole","22","electrical engineering"});
        sheet.add_row({"Dominick","Dole","22","communications"});
        sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* x = new Select_Contains(&sheet, "Last", "Gen");
        sheet.set_selection(x);
        EXPECT_EQ(x->select(&sheet, 8), true);
}
#endif
