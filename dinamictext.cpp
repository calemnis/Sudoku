#include "dinamictext.hpp"

dinamictext::dinamictext(int pos_x, int pos_y, int size_x, int size_y, bool click, bool change, int number):Widget(pos_x, pos_y, size_x, size_y, click)
    {
        num=number;
        changeable=change;
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
    if (this->wrong)
    {
        gout << move_to(x_coord+7, y_coord+2) << color(255,0,0) << line_to(x_coord+x_size-7, y_coord+y_size-7);
        gout << move_to(x_coord+x_size-7, y_coord+2) << line_to(x_coord+7, y_coord+y_size-7);
    }
    if (this->clicked || this->chosen) gout << color(0,0,0);
    else gout << color(255,255,255);
    gout << move_to(x_coord, y_coord+gout.cascent());

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
    if (this->changeable) num=n;
}

void dinamictext::Change_chosen(bool f)
{
    chosen=f;
}

int dinamictext:: Getnum(){return num;}

void dinamictext::Check(bool mate)
{
    if (this->changeable) wrong=mate;
}

string dinamictext::NumberToString(int n)
{
     ostringstream ss;
     ss << n;
     return ss.str();
}
