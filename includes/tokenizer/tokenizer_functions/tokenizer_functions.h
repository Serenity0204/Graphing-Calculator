#ifndef TOKENIZER_FUNCTIONS_H
#define TOKENIZER_FUNCTIONS_H
#include <bits/stdc++.h>
#include "../../lib/queue/MyQueue.h"
#include "../../lib/stack/MyStack.h"
#include "../../lib/token/constants.h"
using namespace std;



// function declaration

// get a queue of string of tokenized data into tokens, and return the token type queue
Queue<int> _tokenize(string input, Queue<string>& tokens, bool& error);

// get a token at a certain index of input string
void _get_token(string input, int& index, string& token, int& token_type, int previous_type, bool& error);


// validators
bool _is_operator(string input, int pos, string& op);
bool _is_left_paren(string input, int pos, string& left_paren);
bool _is_right_paren(string input, int pos, string& right_paren);
bool _is_function(string str, int pos, string& func, int prev_type, bool& error);
bool _is_digit(char c);
bool _is_number(string str, int pos, string& number, int prev_type, bool& is_error);
bool _is_unary_minus(string input, int pos, int prev_type);

#endif // !TOKENIZER_FUNCTIONS_H


