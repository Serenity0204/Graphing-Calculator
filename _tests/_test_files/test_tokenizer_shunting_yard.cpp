#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/tokenizer/tokenizer/tokenizer.h"
#include "../../includes/lib/queue/MyQueue.h"
#include "../../includes/lib/token/function.h"
#include "../../includes/lib/token/integer.h"
#include "../../includes/lib/token/leftparen.h"
#include "../../includes/lib/token/operator.h"
#include "../../includes/lib/token/rightparen.h"
#include "../../includes/lib/token/token.h"
#include "../../includes/lib/shunting_yard/shunting_yard.h"
#include "../../includes/lib/rpn/rpn.h"

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



bool test_tokenize_to_sy1(bool debug=false)
{
  string num = "3 + 3 * 3 ^ 3 / 3";
  Tokenizer tokenizer(num);
  Queue<Token*> infix_q = tokenizer.infix();
  ShuntingYard sy(infix_q);
  Queue<Token*> postfix = sy.postfix();
  cout << "infix: " << infix_q << endl;
  cout << "postfix: " << postfix << endl;
  return true;
}



bool test_tokenize_to_sy2(bool debug=false)
{
  string num = "2 - ( 2 + 2 ) ^ 2 * 2";
  Tokenizer tokenizer(num);
  Queue<Token*> infix_q = tokenizer.infix();
  ShuntingYard sy(infix_q);
  Queue<Token*> postfix = sy.postfix();
  cout << "infix: " << infix_q << endl;
  cout << "postfix: " << postfix << endl;
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



TEST(TEST_TOKENIZER_SY, TestTokenSy1)
{
  bool success = test_tokenize_to_sy1(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_TOKENIZER_SY, TestTokenSy2)
{
  bool success = test_tokenize_to_sy2(debug);
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
