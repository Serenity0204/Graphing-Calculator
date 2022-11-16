#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <bits/stdc++.h>
#include "../lib/queue/MyQueue.h"
#include "../lib/stack/MyStack.h"
#include "../lib/token/token.h"
#include "../lib/token/function.h"
#include "../lib/token/integer.h"
#include "../lib/token/operator.h"
#include "../lib/token/leftparen.h"
#include "../lib/token/rightparen.h"


class Tokenizer
{
private:
    bool _error;
public:
    Tokenizer()
    {
        this->_error = false;
    }
};


#endif // !TOKENIZER_H
