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
    if(this->_function == "sin") return sin(num);
    
    if(this->_function == "cos") return cos(num);
    
    if(this->_function == "tan") return tan(num);
    
    if(this->_function == "arcsin") return asin(num);
    
    if(this->_function == "arccos") return acos(num);
    
    if(this->_function == "arctan") return atan(num);
    
    if(this->_function == "sinh") return sinh(num);
    
    if(this->_function == "cosh") return cosh(num);
    
    if(this->_function == "tanh") return tanh(num);
    
    if(this->_function == "ln") return log(num);
    
    if(this->_function == "log") return log10(num);
    
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