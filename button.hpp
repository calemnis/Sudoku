#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "widget.hpp"
#include <functional>
#include <iostream>

using namespace std;

template <typename T>
class Button: public Widget{
    protected:
    std::function<T> f;
    std::string s_text;

public:
    Button(int pos_x, int pos_y, int size_x, int size_y, bool click, std::string label, function<T>fv):Widget(pos_x, pos_y, size_x, size_y, click)
    {
        f=fv;
        s_text=label;
    };

    virtual void Draw()
    {
        if (this->clicked)
        {
            gout << move_to(x_coord, y_coord) << color(190,190,190) << box(x_size, y_size);
            gout << move_to(x_coord+2, y_coord+2) << color(255,0,0) << box(x_size-4, y_size-4);

            gout << move_to(x_coord,y_coord+3*y_size/4) << color(255,255,255) << text(s_text);
        }
        else
        {
            gout << move_to(x_coord, y_coord) << color(190,190,190) << box(x_size, y_size);
            gout << move_to(x_coord+2, y_coord+2) << color(0,0,0) << box(x_size-4, y_size-4);

            gout << move_to(x_coord,y_coord+3*y_size/4) << color(255,255,255) << text(s_text);
        }


    }

    virtual void Focus(bool getf)
    {
        clicked=getf;
        if (this->clicked) f();
    };

};
#endif // BUTTON_HPP_INCLUDED
