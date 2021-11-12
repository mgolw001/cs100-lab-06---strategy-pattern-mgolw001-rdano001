#include "spreadsheet.hpp"

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "Select_Or_Test.hpp"
#include "Select_And_Test.hpp"
#include "Select_Contains_Test.hpp"
#include "Select_Not_Test.hpp"
#include "select.hpp"
#include "Select_Contains.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
