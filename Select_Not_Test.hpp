#ifndef SELECT_NOT_TEST_HPP
#define SELECT_NOT_TEST_HPP

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"
#include "Select_Contains.hpp"
#include "Select_Not.hpp"


TEST(NotTest,Exists) {
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

   Select_Not* x = new Select_Not(new Select_Contains(&sheet, "Last", "Becker"));
   sheet.set_selection(x);
   EXPECT_EQ(x->select(&sheet, 1),false);
}

TEST(NotTest,NotExist) {
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

   Select_Not* x = new Select_Not(new Select_Contains(&sheet, "Last", "Golwalla"));
   sheet.set_selection(x);
   EXPECT_EQ(x->select(&sheet, 0),true);
}


TEST(NotTest,EmptyString) {
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

   Select_Not* x = new Select_Not(new Select_Contains(&sheet, "Last", ""));
   sheet.set_selection(x);
   EXPECT_EQ(x->select(&sheet, 0),false);
}

TEST(NotTest,PartialWord) {
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

   Select_Not* x = new Select_Not(new Select_Contains(&sheet, "Last", "son"));
   sheet.set_selection(x);
   EXPECT_EQ(x->select(&sheet, 3),false);
}
#endif
