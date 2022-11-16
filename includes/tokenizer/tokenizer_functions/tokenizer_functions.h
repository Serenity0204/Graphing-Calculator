#ifndef TOKENIZER_FUNCTIONS_H
#define TOKENIZER_FUNCTIONS_H
#include <bits/stdc++.h>
#include "../../lib/queue/MyQueue.h"
#include "../../lib/stack/MyStack.h"
#include "../../lib/token/token.h"
#include "../../lib/token/function.h"
#include "../../lib/token/integer.h"
#include "../../lib/token/operator.h"
#include "../../lib/token/leftparen.h"
#include "../../lib/token/rightparen.h"
using namespace std;



// function declaration

// get a queue of string of tokenized data
void _tokenize(string input,Queue<string>& tokens, bool& error);

// get a token at a certain index of input string


void _get_token(string input, int& index, string& token, bool& error);


// validators
bool _is_operator(string input, int pos, string& op);
bool _is_left_paren(string input, int pos, string& left_paren);
bool _is_right_paren(string input, int pos, string& right_paren);
bool _is_function(string str, int pos, string& func);
bool _is_digit(char c);
bool _is_number(string str, int pos, string& number, bool& is_error);

#endif // !TOKENIZER_FUNCTIONS_H


