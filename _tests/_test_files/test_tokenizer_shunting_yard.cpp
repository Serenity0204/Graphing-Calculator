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
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/token_header.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"

//------------------------------------------------------------------------------

using namespace std;


//------------------------------------------------------------------------------
//@TODO: add more test functions here:



bool test_tokenize_to_sy1(bool debug=false)
{
  string num = "3 + 3 * 3 ^ 3 / 3";
  Tokenizer tokenizer(num);
  Queue<Token*> infix_q = tokenizer.infix();
  ShuntingYard sy(infix_q);
  Queue<Token*> postfix = sy.postfix();
  if(debug)
  {
    cout << "infix: " << infix_q << endl;
    cout << "postfix: " << postfix << endl;
  }
  RPN rpn(postfix);
  double val = rpn();
  if(val != 30) return false;
  return true;
}



bool test_tokenize_to_sy2(bool debug=false)
{
  string num = "2 * ( 2 + 27 / ( 5 - 3 * 4 / 6 ) ^ 2 )";
  Tokenizer tokenizer(num);
  Queue<Token*> infix_q = tokenizer.infix();
  ShuntingYard sy(infix_q);
  Queue<Token*> postfix = sy.postfix();
  if(debug)
  {
    cout << "infix: " << infix_q << endl;
    cout << "postfix: " << postfix << endl;
  }
  RPN rpn(postfix);
  double val = rpn();
  if(val != 10) return false;
  return true;
}



bool test_sy_function1(bool debug)
{
  string num = "sin(0) + 5";
  Tokenizer tokenizer(num);
  Queue<Token*> infix_q = tokenizer.infix();
  ShuntingYard sy(infix_q);
  Queue<Token*> postfix = sy.postfix();
  if(debug)
  {
    cout << "infix: " << infix_q << endl;
    cout << "postfix: " << postfix << endl;
  }

  RPN rpn(postfix);
  double val = rpn();
  if(val != 5) return false;
  return true;
}

bool test_sy_function2(bool debug)
{
  string num = "sin(x) + 5 + cos(x)";
  Tokenizer tokenizer(num);
  Queue<Token*> infix_q = tokenizer.infix();
  ShuntingYard sy(infix_q);
  Queue<Token*> postfix = sy.postfix();
  if(debug)
  {
    cout << "infix: " << infix_q << endl;
    cout << "postfix: " << postfix << endl;
  }

  RPN rpn(postfix);
  double val = rpn(0);
  if(val != 6) return false;
  return true;
}


bool test_sy_function3(bool debug)
{
  string num = "sin(x^2 + 0 * x^x) + cos(x)";
  Tokenizer tokenizer(num);
  Queue<Token*> infix_q = tokenizer.infix();
  ShuntingYard sy(infix_q);
  Queue<Token*> postfix = sy.postfix();
  if(debug)
  {
    cout << "infix: " << infix_q << endl;
    cout << "postfix: " << postfix << endl;
  }

  RPN rpn(postfix);
  double val = rpn(0);
  if(val != 1) return false;
  return true;
}



//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//@TODO: add more test sets to call test functions here:

// Lord help me! 
const bool debug = false;



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

TEST(TEST_TOKENIZER_SY, TestTokenSyFunc1)
{
  bool success = test_sy_function1(debug);
  EXPECT_EQ(success, true);
}


TEST(TEST_TOKENIZER_SY, TestTokenSyFunc2)
{
  bool success = test_sy_function2(debug);
  EXPECT_EQ(success, true);
}


TEST(TEST_TOKENIZER_SY, TestTokenSyFunc3)
{
  bool success = test_sy_function3(debug);
  EXPECT_EQ(success, true);
}





//------------------------------------------------------------------------------


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running test_input.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
