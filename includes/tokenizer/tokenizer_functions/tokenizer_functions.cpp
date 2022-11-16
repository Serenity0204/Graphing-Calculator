#include "tokenizer_functions.h"





void _tokenize(string input, Queue<string>& tokens, bool& error)
{
    int index = 0;  
    error = false;
    while(index < input.length())
    {
        string token = "";
        if(input[index] == ' ')
        {
            index++;
            continue;
        }
        _get_token(input, index, token, error);
        if(error) break;
        tokens.push(token);
    }
}




void _get_token(string input, int& index, string& token, bool& error)
{
    token = "";
    bool is_op = _is_operator(input, index, token);
    bool is_lp = _is_left_paren(input, index, token);
    bool is_rp = _is_right_paren(input, index, token);
    bool is_func = _is_function(input, index, token);
    bool is_num = _is_number(input, index, token, error);
    if(error) return;
    index += token.length();
    if(token.length() == 0)
    {
        error = true;
        return;
    }
}



// check if is operator
bool _is_operator(string input, int pos, string& op)
{
    char tk = input[pos];
    switch (tk)
    {
    case '+':
        op = "+";
        break;
    case '-':
        op = "-";
        break;
    case '*':
        op = "*";
        break;
    case '/':
        op = "/";
        break;
    case '^':
        op = "^";
        break;
    default:
        op = "";
        break;
    }
    return (op != "") ? true : false;
}


// check if is left paren
bool _is_left_paren(string input, int pos, string& left_paren)
{
    if(input[pos] == '(')
    {
        left_paren = "(";
        return true;
    }
    left_paren = "";
    return false;
}



// check if is right paren
bool _is_right_paren(string input, int pos, string& right_paren)
{
    if(input[pos] == '(')
    {
        right_paren = "(";
        return true;
    }
    right_paren = "";
    return false;
}



// check if at a certain position has a function token
bool _is_function(string str, int pos, string& func)
{

    if(str.substr(pos, 3) == "sin")
    {
        func = "sin";
        return true;   
    }
    
    if(str.substr(pos, 3) == "tan")
    {
        func = "tan";
        return true;
    }
    
    if(str.substr(pos, 3) == "tan")
    {
        func = "tan";
        return true;
    }

    if(str.substr(pos, 6) == "arcsin")
    {
        func = "arcsin";
        return true;
    }
    

    if(str.substr(pos, 6) == "arccos")
    {
        func = "arccos";
        return true;
    }

    if(str.substr(pos, 6) == "arctan")
    {
        func = "arctan";
        return true;
    }
    
    if(str.substr(pos, 4) == "sinh")
    {
        func = "sinh";
        return true;
    }
    
    if(str.substr(pos, 4) == "cosh")
    {
        func = "cosh";
        return true;
    }
    
    if(str.substr(pos, 4) == "tanh")
    {
        func = "tanh";
        return true;
    }
    
    if(str.substr(pos, 2) == "ln")
    {
        func = "ln";
        return true;
    }
    
    if(str.substr(pos, 3) == "log")
    {
        func = "log";
        return true;
    }
    if(str.substr(pos, 1) == "x")
    {
        func = "x";
        return true;
    }
    func = "";
    return false;
}


// check if it's a digit or a dot or not
bool _is_digit(char c)
{
    bool is_digit = ((c <= 57 && c >= 48) || (c == '.'));
    if(is_digit) return true;
    return false;
}

// check if it's number or not
bool _is_number(string str, int pos, string& number, bool& is_error)
{

    if(!_is_digit(str[pos])) 
    {
        number = "";
        return false;
    }


    for(int i = pos; i < str.length(); ++i)
    {
        if(!_is_digit(str[i])) break;
        
        number += str[i];
        pos++;
    }
    if(number[number.length() - 1] == '.') is_error = true;
        
    return true;
}