#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token_header.h"
#include "../tokenizer_functions/tokenizer_functions.h"




class Tokenizer
{
private:
    // holders
    Queue<string> _tokens;
    Queue<int> _types;
    // input
    string _input;

    // output
    Queue<Token*> _output;

    // private helper
    void tokenize(string input);
    string remove_space(string str);

public:
    Tokenizer(string input);
    ~Tokenizer();
    void set_input(string input);
    Queue<Token*> infix();
   
  
};


#endif // !TOKENIZER_H
