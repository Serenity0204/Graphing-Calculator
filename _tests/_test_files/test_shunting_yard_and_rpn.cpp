#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
//Files we are testing:
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


// testing greater precedence operator popping from operator stack
bool test_sy_edge_greater_precedence_operator(bool debug = false)
{
  // queue input: 3 + 3 * 3 ^ 3 / 3
  Queue<Token*> postfix;
  Queue<Token*> infix2;
  Queue<Token*> infix_q;
  infix2.push(new Integer(3));
  infix2.push(new Operator("+"));
  infix2.push(new Integer(3));
  infix2.push(new Operator("*"));
  infix2.push(new Integer(3));
  infix2.push(new Operator("^"));
  infix2.push(new Integer(3));
  infix2.push(new Operator("/"));
  infix2.push(new Integer(3));
  infix_q = infix2;
  ShuntingYard sy(infix_q);

  postfix = sy.postfix();
  if(debug)
  {
    cout << "3 + 3 * 3 ^ 3 / 3: " << postfix << endl;
    cout << "should be: " << "3 3 3 3 ^ * 3 / + " << endl;
  }

  RPN rpn(postfix);
  double val = rpn();
  if(val != 30)
  {
    cout << "Expected 30 but found " << val << endl;
    return false;
  }
  return true;

}



// testing equal precedence operator and left associative
bool test_sy_edge_equal_precedence_operator_left_associative(bool debug = false)
{
  // queue input: 3 + 3 * 3 / 3 
  Queue<Token*> postfix;
  Queue<Token*> infix2;
  Queue<Token*> infix_q;
  infix2.push(new Integer(3));
  infix2.push(new Operator("+"));
  infix2.push(new Integer(3));
  infix2.push(new Operator("*"));
  infix2.push(new Integer(3));
  infix2.push(new Operator("/"));
  infix2.push(new Integer(3));
  infix_q = infix2;
  ShuntingYard sy(infix_q);

  postfix = sy.postfix();
  if(debug)
  {
    cout << "3 + 3 * 3 ^ 3 / 3: " << postfix << endl;
    cout << "should be: " << "3 3 3 * 3 / + " << endl;
  }

  RPN rpn(postfix);
  double val = rpn();
  if(val != 6)
  {
    cout << "Expected 6 but found " << val << endl;
    return false;
  }
  return true;

}

// testing equal precedence operator and right associative
bool test_sy_edge_equal_precedence_operator_right_associative(bool debug = false)
{
  // queue input: 2 + 2 ^ 2 ^ 2 
  Queue<Token*> postfix;
  Queue<Token*> infix2;
  Queue<Token*> infix_q;
  infix2.push(new Integer(2));
  infix2.push(new Operator("+"));
  infix2.push(new Integer(2));
  infix2.push(new Operator("^"));
  infix2.push(new Integer(2));
  infix2.push(new Operator("^"));
  infix2.push(new Integer(2));
  infix_q = infix2;
  ShuntingYard sy(infix_q);

  postfix = sy.postfix();
  if(debug)
  {
    cout << "2 + 2 ^ 2 ^ 2 : " << postfix << endl;
    cout << "should be: " << "2 2 2 2 ^ ^ + " << endl;
  }

  RPN rpn(postfix);
  double val = rpn();
  if(val != 18)
  {
    cout << "Expected 18 but found " << val << endl;
    return false;
  }
  return true;

}

// 2 - ( 2 + 2 ) ^ 2 * 2
// 2 2 2 + 2 ^ 2 * -

// testing equal precedence operator and but with parentheses
bool test_sy_edge_equal_precedence_operator_parentheses(bool debug = false)
{
  // queue input: 2 - ( 2 + 2 ) ^ 2 * 2
  Queue<Token*> postfix;
  Queue<Token*> infix2;
  Queue<Token*> infix_q;
  infix2.push(new Integer(2));
  infix2.push(new Operator("-"));
  infix2.push(new LeftParen());
  infix2.push(new Integer(2));
  infix2.push(new Operator("+"));
  infix2.push(new Integer(2));
  infix2.push(new RightParen());
  infix2.push(new Operator("^"));
  infix2.push(new Integer(2));
  infix2.push(new Operator("*"));
  infix2.push(new Integer(2));
  
  infix_q = infix2;
  ShuntingYard sy(infix_q);

  postfix = sy.postfix();
  if(debug)
  {
    cout << "2 - ( 2 + 2 ) ^ 2 * 2 : " << postfix << endl;
    cout << "should be: " << "2 2 2 + 2 ^ 2 * - " << endl;
  }

  RPN rpn(postfix);
  double val = rpn();
  if(val != -30)
  {
    cout << "Expected -30 but found " << val << endl;
    return false;
  }
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




//------------------------------------------------------------------------------
//@TODO: add more test sets to call test functions here:

TEST(TEST_SY_EDGE, TestSYEdgeGreaterPrecedenceOp)
{
  bool success = test_sy_edge_greater_precedence_operator(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_SY_EDGE, TestSYEdgeEqualPrecedenceOpLeftAssociative)
{
  bool success = test_sy_edge_equal_precedence_operator_left_associative(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_SY_EDGE, TestSYEdgeEqualPrecedenceOpRightAssociative)
{
  bool success = test_sy_edge_equal_precedence_operator_right_associative(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_SY_EDGE, TestSYEdgeEqualPrecedenceOpParen)
{
  bool success = test_sy_edge_equal_precedence_operator_parentheses(debug);
  EXPECT_EQ(success, true);
}
//------------------------------------------------------------------------------


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
