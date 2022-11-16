#include "operator.h"

Operator::Operator(string op)
{
    this->_operator = op;
    this->set_associativity();
}

Operator::~Operator(){}   

const int Operator::tokenType() const
{
    return OPERATOR;
}

void Operator::set_associativity()
{
    if(this->_operator == "^")
    {
        this->_associativity = false;
        return;
    }
    this->_associativity = true;
}

const int Operator::precedence() const
{
    if(this->_operator == "^") return PRECEDENCE_3;
    if(this->_operator == "+" || this->_operator == "-") return PRECEDNECE_1;
    return PRECEDENCE_2;
}



void Operator::Print(ostream& outs) const
{
    outs << this->_operator; 
}

string Operator::get_operator() const
{
    return this->_operator;
}


ostream& operator <<(ostream &outs, const Operator &op)
{
    outs << op._operator;
    return outs;
}

ostream& operator <<(ostream& outs, const Operator* op)
{
    outs << op->_operator;
    return outs;
}
