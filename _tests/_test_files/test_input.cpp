#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/tokenizer/tokenizer.h"


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

bool test_isNumber1(bool debug=false)
{
  string num = "XXX123.555X123";
  vector<string> res;
  int pos = 0;
  bool is_error = false;
  while(pos < num.length())
  {
    string temp = "";
    bool isNum =_isNumber(num, pos, temp, is_error);
    if(isNum) res.push_back(temp);
  }
  if(res[0] != "123.555") return false;
  if(res[1] != "123") return false;

  return true;
}

bool test_isNumber2(bool debug=false)
{
  string num = "XXX123.X123";
  int pos = 0;
  bool is_error = false;
  while(pos < num.length())
  {
    string temp = "";
    bool isNum =_isNumber(num, pos, temp, is_error);
    if(is_error) break;
  }
  if(pos != 7) return false;

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

TEST(TEST_IS_NUMBER, TestIsNumber1)
{
  bool success = test_isNumber1(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_IS_NUMBER, TestIsNumber2)
{
  bool success = test_isNumber2(debug);
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
