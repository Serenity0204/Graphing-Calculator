#include "tokenizer.h"

void Tokenizer::tokenize(string input)
{
    this->_tokens.clear();
    this->_input.clear();
    this->_types = _tokenize(input, this->_tokens);
}
Tokenizer::Tokenizer(string input)
{
    this->_input = input;
    if(this->_input != "") this->tokenize(this->_input);
}
void Tokenizer::set_input(string input)
{
    this->_input = input;
    if(this->_input != "") this->tokenize(this->_input);
}

Queue<Token*> Tokenizer::infix()
{
    Queue<Token*> infix;
    while(!this->_tokens.empty())
    {
        string tk = this->_tokens.pop();
        int type = this->_types.pop();
        Token* token;
        if(type == INTEGER)
        {
            double num_temp = stod(tk);
            token = new Integer(num_temp);
            //cout << token << " is an integer" << endl;
            infix.push(token);
            continue;
        }
        if(type == FUNCTION)
        {
            token = new Function(tk);
            //cout << token << " is a function" << endl;
            infix.push(token);
            continue;
        }
        if(type == LPAREN)
        {
            token = new LeftParen();
            //cout << token << " is a Left Paren" << endl;
            infix.push(token);
            continue;
        }

        if(type == RPAREN)
        {
            token = new RightParen();
            //cout << token << " is a Right Paren" << endl;
            infix.push(token);
            continue;
        }

        if(type == OPERATOR)
        {
            token = new Operator(tk);
            //cout << token << " is an Operator" << endl;
            infix.push(token);
            continue;
        }
    }
        
        
    return infix;
}
