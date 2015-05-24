#ifndef DINAMICTEXT_HPP_INCLUDED
#define DINAMICTEXT_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;

class dinamictext: public Widget{
protected:
    int num;
    bool chosen, wrong{false}, changeable;

public:
    dinamictext(int pos_x, int pos_y, int size_x, int size_y, bool click, bool change, int number);
    virtual void Draw();
    virtual void Focus(bool f);
    void Changenum(int n);
    void Change_chosen(bool f);
    int Getnum();
    void Check(bool mate);
    string NumberToString(int n);
};

#endif // DINAMICTEXT_HPP_INCLUDED
