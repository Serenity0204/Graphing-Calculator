#ifndef INTEGER_H
#define INTEGER_H


#include "token.h"
#include "constants.h"
#include <bits/stdc++.h>
using namespace std;


class Integer : public Token
{
private:
    int _integer;
public:
    Integer(int num);
    ~Integer();
    const int tokenType() const override;
    const int get_integer() const;
    void Print(ostream &outs) const override;
    friend ostream& operator <<(ostream &outs, const Integer &num);
    friend ostream& operator <<(ostream& outs, const Integer* num);
    
};

#endif // !LeftParen