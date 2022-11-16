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



bool test_tokenize1(bool debug=false)
{
  string num = "5x^2+(-6.59-sinx)*cosx";
  Queue<string> tokens;
  bool error = false;
  Queue<int> types = _tokenize(num, tokens, error);
  cout << tokens << endl;
  cout << types << endl;
  return true;
}


bool test_tokenize2(bool debug=false)
{
  string num = "6x^2^2+(9+x^3)^9";
  Queue<string> tokens;
  bool error = false;
  Queue<int> types = _tokenize(num, tokens, error);
  cout << tokens << endl;
  cout << types << endl;
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



TEST(TEST_TOKENIZE, TestTokenize1)
{
  bool success = test_tokenize1(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_TOKENIZE, TestTokenize2)
{
  bool success = test_tokenize2(debug);
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
