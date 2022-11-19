#include "function.h"

Function::Function(string func)
{
    this->_function = func;
    this->set_args();
}

Function::~Function(){}   

const int Function::tokenType() const
{
    return FUNCTION;
}



const int Function::precedence() const
{
    return PRECEDENCE_4;
}



void Function::set_args()
{
    this->_args = 1;   
}

double Function::evaluate(double num)
{
    if(this->_function == "sin(x)") return sin(num);
    
    if(this->_function == "cos(x)") return cos(num);
    
    if(this->_function == "tan(x)") return tan(num);
    
    if(this->_function == "arcsin(x)") return asin(num);
    
    if(this->_function == "arccos(x)") return acos(num);
    
    if(this->_function == "arctan(x)") return atan(num);
    
    if(this->_function == "sinh(x)") return sinh(num);
    
    if(this->_function == "cosh(x)") return cosh(num);
    
    if(this->_function == "tanh(x)") return tanh(num);
    
    if(this->_function == "ln(x)") return log(num);
    
    if(this->_function == "log(x)") return log10(num);
    
    if(this->_function == "X" || this->_function == "x") return num;
    
    return 0;
}
     


void Function::Print(ostream& outs) const
{
    outs << this->_function; 
}


ostream& operator <<(ostream &outs, const Function &func)
{
    outs << func._function;
    return outs;
}

ostream& operator <<(ostream& outs, const Function* func)
{
    outs << func->_function;
    return outs;
}
