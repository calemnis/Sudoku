#include "dinamictext.hpp"

dinamictext::dinamictext(int pos_x, int pos_y, int size_x, int size_y, bool click, int number):Widget(pos_x, pos_y, size_x, size_y, click)
    {
        num=number;
    }


void dinamictext::Draw(){

    if (this->clicked)
    {
        gout << move_to(x_coord+1, y_coord+1) << color(20,255,20) << box(x_size-2, y_size-2);
    }
    else if(this->chosen)
    {
        gout << move_to(x_coord+1, y_coord+1) << color(255,255,20) << box(x_size-2, y_size-2);
    }
    gout << move_to(x_coord, y_coord+gout.cascent()) << color(255,255,255);
    if (num==0)
    {
        gout << text("  ");
    }
    else
    {
        gout << text(" "+this->NumberToString(num));
    }



}

void dinamictext::Focus(bool f)
{
    clicked=f;
}

void dinamictext::Changenum(int n)
{
    num=n;
}

void dinamictext::Change_chosen(bool f)
{
    chosen=f;
}

int dinamictext:: Getnum(){return num;}

string dinamictext::NumberToString(int n)
{
     ostringstream ss;
     ss << n;
     return ss.str();
}
