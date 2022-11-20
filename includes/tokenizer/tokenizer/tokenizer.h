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
    // holders
    Queue<string> _tokens;
    Queue<int> _types;
    // input
    string _input;

    // private helper
    void tokenize(string input);
public:
    Tokenizer(string input);
    void set_input(string input);
    Queue<Token*> infix();
   
  
};


#endif // !TOKENIZER_H
