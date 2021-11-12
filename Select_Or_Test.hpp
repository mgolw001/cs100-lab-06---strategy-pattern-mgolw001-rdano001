#ifndef SELECT_OR_TEST_HPP
#define SELECT_OR_TEST_HPP


#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"
#include "Select_Contains.hpp"
#include "Select_Or.hpp"

TEST(OrTest,BothTrue) {
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

   Select_Or* x = new Select_Or(new Select_Contains(&sheet, "Last", "Becker"), new Select_Contains(&sheet, "Age", "21"));
   sheet.set_selection(x);
   EXPECT_TRUE(x->select(&sheet, 1));
}

TEST(OrTest,BothFalse) {
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

   Select_Or* x = new Select_Or(new Select_Contains(&sheet, "Last", "Danover"), new Select_Contains(&sheet, "First", "Rachel"));
   sheet.set_selection(x);
   EXPECT_FALSE(x->select(&sheet, 2));
}
TEST(OrTest,OneTrueOneFalse) {
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

   Select_Or* x = new Select_Or(new Select_Contains(&sheet, "Last", "Andrews"), new Select_Contains(&sheet, "Age", "21"));
   sheet.set_selection(x);
   EXPECT_FALSE(x->select(&sheet, 0));
}

TEST(OrTest,EmptyString) {
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

   Select_Or* x = new Select_Or(new Select_Contains(&sheet, "Last", ""), new Select_Contains(&sheet, "Age", ""));
   sheet.set_selection(x);
   EXPECT_TRUE(x->select(&sheet, 2));
}

TEST(OrTest,PartialWord) {
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

   Select_Or* x = new Select_Or(new Select_Contains(&sheet, "Last", "Con"), new Select_Contains(&sheet, "Age", "1"));
   sheet.set_selection(x);
   EXPECT_TRUE(x->select(&sheet, 2));
}

#endif                                                       
