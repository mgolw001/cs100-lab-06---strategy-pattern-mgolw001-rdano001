#ifndef SELECT_AND_TEST_HPP
#define SELECT_AND_TEST_HPP


#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"
#include "Select_Contains.hpp"
#include "Select_And.hpp"
//#include <iostream>
//#include "Select_And.cpp"
//#include "spreadsheet.cpp"

TEST(AndTest,BothTrue) {
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

    Select_And* x = new Select_And(new Select_Contains(&sheet, "Last", "Summers"), new Select_Contains(&sheet, "Age", "21"));
    sheet.set_selection(x);

    EXPECT_TRUE(x->select(&sheet, 4));
}

TEST(AndTest,BothFalse) {
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

    Select_And* x = new Select_And(new Select_Contains(&sheet, "Last", "Golwalla"), new Select_Contains(&sheet, "First", "Mariam"));
    sheet.set_selection(x);

    EXPECT_FALSE(x->select(&sheet, 2));
}
TEST(AndTest,OneTrueOneFalse) {
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

    Select_And* x = new Select_And(new Select_Contains(&sheet, "Last", "Jackson"), new Select_Contains(&sheet, "First", "Michael"));
    sheet.set_selection(x);

    EXPECT_FALSE(x->select(&sheet, 3));
}

TEST(AndTest,EmptyString) {
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

    Select_And* x = new Select_And(new Select_Contains(&sheet, "Last", ""), new Select_Contains(&sheet, "Age", ""));
    sheet.set_selection(x);

    EXPECT_TRUE(x->select(&sheet, 2));
}
TEST(AndTest,PartialWord) {
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

    Select_And* x = new Select_And(new Select_Contains(&sheet, "Last", "Gen"), new Select_Contains(&sheet, "Major", "physics"));
    sheet.set_selection(x);

    EXPECT_TRUE(x->select(&sheet, 8));
}

#endif
