#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <bits/stdc++.h>
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/function.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"


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
