#ifndef RPN_H
#define RPN_H

#include <string>
#include <iostream>
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token_header.h"



using namespace std;

class RPN
{
public:
  // CTOR
  RPN();
  RPN(const Queue<Token*>& input_q);
  ~RPN(){} 
  // save input_q to member variable queue
  void set_input(const Queue<Token *> &input_q);
  bool is_error(){return this->_error;}
  // return result from member variable queue
  double operator()(double value = 0);
  // called by operator ()
  double rpn(double value = 0);
  
private:
  // private helper functions
  double evaluate(double num1, double num2, string operation);

  // private member vars
  bool _error;
  Queue<Token*> _queue;
};

#endif //RPN_H