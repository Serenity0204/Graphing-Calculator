#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/tokenizer/tokenizer_functions/tokenizer_functions.h"


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
  string temp = "";
  vector<string> res;
  int pos = 0;
  bool is_error = false;
  while(pos < num.length())
  {
    if(_is_number(num, pos, temp, is_error))
    {
      pos += temp.length();
      res.push_back(temp);
      continue;
    }
    pos++;
  }
  if(res[0] != "123.555") return false;
  if(res[1] != "123") return false;

  return true;
}

bool test_isNumber2(bool debug=false)
{
  string num = "XXX123.X123";
  int pos = 0;
  string temp = "";
  bool is_error = false;
  while(pos < num.length())
  {
    if(_is_number(num, pos, temp, is_error))
    {
      pos += temp.length();
      continue;
    }
    pos++;
    if(is_error) return true;
  }


  return false;
}



bool test_tokenize1(bool debug=false)
{
  string num = "123.55+6.5";
  Queue<string> q;
  bool error = false;
  _tokenize(num, q, error);
  cout << q << endl;
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

TEST(TEST_TOKENIZE, TestTokenize1)
{
  bool success = test_tokenize1(debug);
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
