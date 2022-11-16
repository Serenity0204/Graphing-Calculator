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
using namespace std;

// Queue<string> tokenize(string input)
// {
//     Queue<string> tokens;
//     int index = 0;
//     string token;
//     while(index < input.length())
//     {
//         get_token(input, index, token);
    
//     }
//     return tokens;
// }

// void get_token(string input, int& index, string& token)
// {

// }


// string get_token_helper(string input, int& index)
// {

// }


// int get_token_type(char c, string optional = "")
// {
//     if(isOperator(c)) return OPERATOR;
//     if(isLeftParen(c)) return LPAREN;
//     if(isRightParen(c)) return RPAREN;
//     if(isVar(c)) return VARIABLE;

// }


// bool isOperator(char c)
// {
//     if(c == '+') return true;
//     if(c == '-') return true;
//     if(c == '*') return true;
//     if(c == '/') return true;
//     if(c == '^') return true;
//     return false;
// }

// bool isLeftParen(char c)
// {
//     return (c == '(') ? true : false;
// }

// bool isRightParen(char c)
// {
//     return (c == ')') ? true : false;
// }

// bool isVar(char c)
// {
//     return (c == 'X' || c == 'x') ? true : false;
// }


// bool isFunction(string str, int& pos, string& func)
// {

//     if(str.substr(pos, 3) == "sin")
//     {
//         func = "sin";
//         pos += 3;
//         return true;   
//     }
    
//     if(str.substr(pos, 3) == "tan")
//     {
//         func = "tan";
//         pos += 3;
//         return true;
//     }
    
//     if(str.substr(pos, 3) == "tan")
//     {
//         func = "tan";
//         pos += 3;
//         return true;
//     }

//     if(str.substr(pos, 6) == "arcsin")
//     {
//         func = "arcsin";
//         pos += 6;
//         return true;
//     }
    

//     if(str.substr(pos, 6) == "arccos")
//     {
//         func = "arccos";
//         pos += 6;
//         return true;
//     }

//     if(str.substr(pos, 6) == "arctan")
//     {
//         func = "arctan";
//         pos += 6;
//         return true;
//     }
    
//     if(str.substr(pos, 4) == "sinh")
//     {
//         func = "sinh";
//         pos += 4;
//         return true;
//     }
    
//     if(str.substr(pos, 4) == "cosh")
//     {
//         func = "cosh";
//         pos += 4;
//         return true;
//     }
    
//     if(str.substr(pos, 4) == "tanh")
//     {
//         func = "tanh";
//         pos += 4;
//         return true;
//     }
    
//     if(str.substr(pos, 2) == "ln")
//     {
//         func = "ln";
//         pos += 2;
//         return true;
//     }
    
//     if(str.substr(pos, 3) == "log")
//     {
//         func = "log";
//         pos += 3;
//         return true;
//     }
//     return false;
// }


bool _isDigit(char c)
{
    bool is_digit = ((c <= 57 && c >= 48) || (c == '.'));
    if(is_digit) return true;
    return false;
}

bool _isNumber(string str, int& pos, string& number, bool& is_error)
{

    if(!_isDigit(str[pos]))
    {
        pos++;
        return false;
    }

    for(int i = pos; i < str.length(); ++i)
    {
        if(!_isDigit(str[i])) break;
        
        number += str[i];
        pos++;
    }
    if(number[number.length() - 1] == '.') is_error = true;
    return true;
}

#endif // !TOKENIZER_H


