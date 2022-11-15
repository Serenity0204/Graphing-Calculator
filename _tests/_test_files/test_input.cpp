#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../library/tokenizer/tokenizer.h"


//------------------------------------------------------------------------------

using namespace std;

bool test_stub(bool debug=false)
{
  if (debug) {
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

//------------------------------------------------------------------------------
//@TODO: add more test functions here:

bool test_lib(bool debug)
{
    test();
    return true;
}





//------------------------------------------------------------------------------


// Lord help me! 
const bool debug = false;

TEST(TEST_STUB, TestStub)
{
  bool success = test_stub(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_T, TestT)
{
    bool success = test_lib(debug);
    EXPECT_EQ(success, true);
}


//------------------------------------------------------------------------------
//@TODO: add more test sets to call test functions here:




//------------------------------------------------------------------------------


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running test_input.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
