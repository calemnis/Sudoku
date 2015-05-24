#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <fstream>

using namespace genv;

class Widget{

protected:
    bool clicked;
    int x_coord, y_coord, x_size, y_size;

public:

    Widget(int pos_x, int pos_y, int size_x, int size_y, bool click);
    virtual void Draw();
    virtual void Focus(bool f);
    virtual void Target(int mouse_x, int mouse_y);
    bool Is_clicked();

    int bottom() const;
    int left() const;
    int right() const;
    int top() const;
};


#endif // WIDGET_HPP_INCLUDED
