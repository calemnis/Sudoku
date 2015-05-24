#include "widget.hpp"

Widget::Widget(int pos_x, int pos_y, int size_x, int size_y, bool click): x_coord(pos_x), y_coord(pos_y), x_size(size_x), y_size(size_y), clicked(click){}
void Widget::Draw(){};
void Widget::Focus(bool f){};
void Widget::Target(int mouse_x, int mouse_y){};
bool Widget::Is_clicked(){return clicked;};

int Widget::bottom() const{return y_coord+y_size;};
int Widget::left() const{return x_coord;};
int Widget::right() const{return x_coord+x_size;};
int Widget::top() const{return y_coord;};

