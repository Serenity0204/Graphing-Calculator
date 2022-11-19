#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <bits/stdc++.h>
#include "../../lib/queue/MyQueue.h"
#include "../../lib/stack/MyStack.h"
#include "../../lib/token/token.h"
#include "../../lib/token/function.h"
#include "../../lib/token/integer.h"
#include "../../lib/token/operator.h"
#include "../../lib/token/leftparen.h"
#include "../../lib/token/rightparen.h"
#include "../tokenizer_functions/tokenizer_functions.h"

class Tokenizer
{
private:
    // state var
    bool _error;
    // holders
    Queue<string> _tokens;
    Queue<int> _types;
    // input
    string _input;
    
    // output queue infix
    Queue<Token*> output;
    // private helper
    void tokenize(string input)
    {
        this->_tokens.clear();
        this->_input.clear();
        this->_types = _tokenize(input, this->_tokens, this->_error);
    }
public:
    Tokenizer(string input)
    {
        this->_input = input;
        this->_error = false;
        this->tokenize(this->_input);
    }
    void set_input(string input)
    {
        this->_input = input;
        this->_error = false;
        this->tokenize(this->_input);
    }
    Queue<Token*> infix()
    {
        Queue<Token*> infix;
        if(this->_error) return infix;
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
  
};


#endif // !TOKENIZER_H
