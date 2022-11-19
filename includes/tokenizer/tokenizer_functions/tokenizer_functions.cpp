#include "tokenizer_functions.h"





Queue<int> _tokenize(string input, Queue<string>& tokens, bool& error)
{
    int index = 0;  
    error = false;
    Queue<int> token_types;
    while(index < input.length())
    {   
        //cout << "index: " << index << endl;
        string token = "";
        int token_type = 0;
        // if it's space, skip
        if(input[index] == ' ' || input[index] == ',')
        {
            index++;
            continue;
        }
        int idx_hold = index;
        int prev_type = (!token_types.empty()) ? token_types.back() : -1;
        _get_token(input, index, token, token_type, prev_type, error);

        if(error) break;

        tokens.push(token);
        token_types.push(token_type);
    }
    return token_types;
}




void _get_token(string input, int& index, string& token, int& token_type, int previous_type, bool& error)
{
    token = "";
    string tk1, tk2, tk3, tk4, tk5, tk6;



    bool is_num = _is_number(input, index, tk5, previous_type, error);
    if(error) return;


    bool is_func = _is_function(input, index, tk4, previous_type, error);
    if(is_func) 
    {
        token = tk4;
        //cout <<"token is: " <<token << " and length is: "<< token.length()<< endl;
        index += token.length();
        token_type = FUNCTION;
        return;
    }


    if(is_num) 
    {
        token = tk5;
        //cout <<"token is: " <<token << " and length is: "<< token.length()<< endl;
        index += token.length();
        token_type = INTEGER;
        return;
    }


    bool is_lp = _is_left_paren(input, index, tk2);
    if(is_lp)
    {
        token = tk2;
        //cout <<"token is: " <<token << " and length is: "<< token.length()<< endl;
        index += token.length();
        token_type = LPAREN;
        return;
    } 

    bool is_rp = _is_right_paren(input, index, tk3);
    if(is_rp) 
    {
        token = tk3;
        //cout <<"token is: " <<token << " and length is: "<< token.length()<< endl;
        index += token.length();
        token_type = RPAREN;
        return;
    }


    bool is_op = _is_operator(input, index, tk1);
    if(is_op)
    {
        
        token = tk1;
        //cout <<"token is: " <<token << " and length is: "<< token.length()<< endl;
        index += token.length();
        token_type = OPERATOR;
        return;
    }


    if(token.length() == 0)
    {
        error = true;
        return;
    }
}






// check if is operator
bool _is_operator(string input, int pos, string& op)
{
    op = "";
    if(input[pos] == '+')
    {
        op = "+";
        return true;
    }
    if(input[pos] == '-')
    {
        op = "-";
        return true;
    }
    if(input[pos] == '*')
    {
        op = "*";
        return true;
    }
    if(input[pos] == '/')
    {
        op = "/";
        return true;
    }
    if(input[pos] == '^')
    {
        op = "^";
        return true;
    }
    return false;
}


// check if is left paren
bool _is_left_paren(string input, int pos, string& left_paren)
{
    left_paren = "";
    if(input[pos] == '(')
    {
        left_paren = "(";
        return true;
    }
    return false;
}



// check if is right paren
bool _is_right_paren(string input, int pos, string& right_paren)
{
    right_paren = "";
    if(input[pos] == ')')
    {
        right_paren = ")";
        return true;
    }
    return false;
}



// check if at a certain position has a function token
bool _is_function(string str, int pos, string& func, int prev_type, bool& error)
{

    func = "";

    if(_is_unary_minus(str, pos, prev_type))
    {
        func += "-";
        pos++;
    }

    // if(str.substr(pos, 3) == "max()")
    // {
    //     func += "max";
    //     return true;
    // }



    if(str.substr(pos, 6) == "sin(x)")
    {
        func += "sin(x)";
        return true;   
    }
    if(str.substr(pos, 6) == "cos(x)")
    {
        func += "cos(x)";
        return true;
    }
    
    if(str.substr(pos, 6) == "tan(x)")
    {
        func += "tan(x)";
        return true;
    }

    if(str.substr(pos, 9) == "arcsin(x)")
    {
        func += "arcsin(x)";
        return true;
    }
    

    if(str.substr(pos, 9) == "arccos(x)")
    {
        func += "arccos(x)";
        return true;
    }

    if(str.substr(pos, 9) == "arctan(x)")
    {
        func += "arctan(x)";
        return true;
    }
    
    if(str.substr(pos, 7) == "sinh(x)")
    {
        func += "sinh(x)";
        return true;
    }
    
    if(str.substr(pos, 7) == "cosh(x)")
    {
        func += "cosh(x)";
        return true;
    }
    
    if(str.substr(pos, 7) == "tanh(x)")
    {
        func += "tanh(x)";
        return true;
    }
    
    if(str.substr(pos, 5) == "ln(x)")
    {
        func += "ln(x)";
        return true;
    }
    
    if(str.substr(pos, 6) == "log(x)")
    {
        func += "log(x)";
        return true;
    }
    if(str.substr(pos, 1) == "x")
    {
        func += "x";
        return true;
    }
    return false;
}


// check if it's a digit or a dot or not
bool _is_digit(char c)
{
    if(c <= 57 && c >= 48) return true;
    return false;
}


// check for negative sign
bool _is_unary_minus(string input, int pos, int prev_type)
{
    bool is_unary_check = ((pos == 0) || (prev_type == LPAREN) || (prev_type == OPERATOR));
    if(input[pos] == '-' && is_unary_check) return true;
    return false;
}




// check if it's number or not
bool _is_number(string str, int pos, string& number, int prev_type, bool& is_error)
{

    if(!_is_digit(str[pos]) && !_is_unary_minus(str, pos, prev_type)) return false;
       

    number = "";
    if(str[pos] == '-')
    {
        number += str[pos];
        pos++;
    }
    for(int i = pos; i < str.length(); ++i)
    {
        if(!_is_digit(str[i]) && str[i] != '.') break;
        
        number += str[i];
        pos++;
    }
    if(number[number.length() - 1] == '.') is_error = true;
        
    return true;
}