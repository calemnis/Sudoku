#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Widget.hpp"
#include "dinamictext.hpp"
#include "button.hpp"
#include "sudoku.hpp"
using namespace genv;
using namespace std;

const int width = 300;
const int height = 400;

typedef Button <void()> Btn;

template <class XY> bool Clicked (XY & classname, int mouse_x, int mouse_y){
    return (mouse_x>classname->left() && mouse_x<classname->right() && mouse_y>classname->top() && mouse_y<classname->bottom());
}

event ev;

int main(){

    ifstream f("sudoku.txt");
    if (!f.good())
    {
        cerr << "Hiba, nincs meg a file" << endl;
        exit(1);
    }

    vector <vector<int>> cell(9, vector<int>(9,0));
    vector <int> starting_numbers;
    for (int i=0; i<81; i++)
    {
        int numz; f >> numz;
        starting_numbers.push_back(numz);
    }


    sudoku* Sudoku=new sudoku(40, 40, 220, 220, false, starting_numbers);
    Btn* Btn_one=new Btn(40,280,40,20,false,"  1",[&]()
            {Sudoku->Change_chosen(1);});
    Btn* Btn_two=new Btn(90,280,40,20,false,"  2",[&]()
            {Sudoku->Change_chosen(2);});
    Btn* Btn_three=new Btn(140,280,40,20,false,"  3",[&]()
            {Sudoku->Change_chosen(3);});

    Btn* Btn_four=new Btn(40,305,40,20,false,"  4",[&]()
            {Sudoku->Change_chosen(4);});
    Btn* Btn_five=new Btn(90,305,40,20,false,"  5",[&]()
            {Sudoku->Change_chosen(5);});
    Btn* Btn_six=new Btn(140,305,40,20,false,"  6",[&]()
            {Sudoku->Change_chosen(6);});

    Btn* Btn_seven=new Btn(40,330,40,20,false,"  7",[&]()
            {Sudoku->Change_chosen(7);});
    Btn* Btn_eight=new Btn(90,330,40,20,false,"  8",[&]()
            {Sudoku->Change_chosen(8);});
    Btn* Btn_nine=new Btn(140,330,40,20,false,"  9",[&]()
            {Sudoku->Change_chosen(9);});

    Btn* Btn_clear=new Btn(200,280,60,20,false," clear ",[&]()
            {Sudoku->Change_chosen(0);});
    Btn* Btn_check=new Btn(200,305,60,20,false," check ",[&]()
            {});

    vector <Widget*> Widgets{Sudoku, Btn_one, Btn_two, Btn_three, Btn_four, Btn_five, Btn_six, Btn_seven, Btn_eight, Btn_nine, Btn_clear, Btn_check};

    gout.open(width,height);

    event ev;
    gin.timer(100);

while (gin >> ev && ev.keycode!=key_escape){
gout << move_to(0,0) << color(0,0,0) << box_to(width-1, height-1);

    if (ev.button==btn_left){
        for (auto w:Widgets){
            if (Clicked(w, ev.pos_x, ev.pos_y)){
                w->Target(ev.pos_x, ev.pos_y);
                w->Focus(true);
            }else{
                w->Focus(false);
            }
        }
    }

    for (auto w:Widgets){
        w->Draw();
    }

    gout << refresh;
}
    return 0;
}
