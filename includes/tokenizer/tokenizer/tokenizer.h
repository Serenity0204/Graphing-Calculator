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
    bool _error;
    Queue<string> _tokens;
    Queue<int> _precedences;
    string _input;
    void tokenize(string input)
    {
        this->_tokens.clear();
        this->_input.clear();
        this->_precedences = _tokenize(input, this->_tokens, this->_error);
    }
public:
    Tokenizer()
    {
        this->_input == "";
        this->_error = false;
    }
    Tokenizer(string input)
    {
        this->_input = input;
        this->_error = false;
    }
    void set_input(string input)
    {
        this->_input = input;
    }

    void operator()(string input)
    {
        if(input == "" && this->_input == "") 
        {
            this->_error = false;
            return;
        }
        this->set_input(input);
        this->tokenize(this->_input);
    }

  
};


#endif // !TOKENIZER_H
