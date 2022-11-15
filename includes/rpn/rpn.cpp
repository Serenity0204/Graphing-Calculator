#include "rpn.h"


RPN::RPN()
{
    this->_error = false;
}

RPN::RPN(const Queue<Token*>& input_q)
{
    this->_error = false;
    this->queue = input_q;
}

  
// save input_q to member variable queue
void RPN::set_input(const Queue<Token *> &input_q)
{
    this->queue = input_q;
}


// return result from member variable queue
double RPN::operator()(double value)
{
    return this->rpn(value);
}

// called by operator ()
double RPN::rpn(double value)
{
    Stack<double> output;
    while(!this->queue.empty())
    {
        Token* token = this->queue.pop();
        if(token->tokenType() == INTEGER)
        {
            Integer* int_temp = static_cast<Integer*>(token);
            double val = int_temp->get_integer();
            output.push(val);
            continue;
        }
        if(token->tokenType() == OPERATOR)
        {
            if(output.size() < OPERATOR_NUM_NEEDED) this->_error = true;
            double secondNum = output.pop();
            double firstNum = output.pop();
            Operator* operator_temp = static_cast<Operator*>(token);
            double result = this->evaluate(firstNum, secondNum, operator_temp->get_operator());
            output.push(result);
            continue;
        }
        if(token->tokenType() == FUNCTION)
        {
            Function* function_temp = static_cast<Function*>(token);
            double val = function_temp->evaluate(value);
            output.push(val);
            continue;
        }
    }
    if(output.size() != 1) this->_error = true;
    return output.top();
}

double RPN::evaluate(double num1, double num2, string operation)
{
    if(operation == "+") return num1 + num2;
    if(operation == "-") return num1 - num2;
    if(operation == "*") return num1 * num2;
    if(operation == "/") return num1 / num2;
    return pow(num1, num2);
}




























