#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
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

void Time_passed(chrono::time_point<chrono::system_clock> s)
{
    auto endc = chrono::system_clock::now();
    auto elapsed = chrono::duration_cast<chrono::seconds>(endc-s);
    gout << move_to(40,350) << color(0,0,0) << box(150,20);

    ostringstream ss;
    ss << elapsed.count();

    gout << move_to(40,370) << color(255,255,255) << text("Run time (s): " + ss.str());
}

void Blackscreen(){
        gout << move_to(0,0) << color(0,0,0) << box_to(width-1, height-1);
    }

void Endgame()
{
    gout << color(255,255,255) << move_to(20, 200) << text("Congratulations, brave soldier!");
    gout << move_to(70, 220) << text("Let's have a beer!");
}

event ev;

int main(){

    bool game_is_on{true};
    int game_mode{0};
    string whichgame;
    cout << "Welcome wanderer! Which difficulty of combat would you prefer?" << endl;
    cout << "For *easy* type: 1" << endl;
    cout << "For *medium* type: 2" << endl;
    cout << "For *difficult* type: 3" << endl;


    cin >> game_mode;

    if (game_mode==1) whichgame="easy_sudoku.txt";
    else if (game_mode==2) whichgame="medium_sudoku.txt";
    else if (game_mode==3) whichgame="difficult_sudoku.txt";
    else
    {
        do{
            cout << "Sorry. You must choose a difficulty. Type 1-2-3." << endl;
            cin >> game_mode;
        }while (game_mode!=1 && game_mode!=2 && game_mode!=3);

        if (game_mode==1) whichgame="easy_sudoku.txt";
        else if (game_mode==2) whichgame="medium_sudoku.txt";
        else if (game_mode==3) whichgame="difficult_sudoku.txt";
    }

    ifstream f(whichgame);
    if (!f.good())
    {
        cerr << "Hiba, nincs meg a file" << endl;
        exit(1);
    }

    vector <vector<int>> cell(9, vector<int>(9,0));
    vector <int> starting_numbers; vector <int> solutions;
    for (int i=0; i<81; i++)
    {
        int numz; f >> numz;
        starting_numbers.push_back(numz);
    }

    for (int i=0; i<81; i++)
    {
        int sol; f >> sol;
        solutions.push_back(sol);
    }


    sudoku* Sudoku=new sudoku(40, 40, 220, 220, false, starting_numbers, solutions);
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
            {Sudoku->Check_sudoku();});

    vector <Widget*> Widgets{Sudoku, Btn_one, Btn_two, Btn_three, Btn_four, Btn_five, Btn_six, Btn_seven, Btn_eight, Btn_nine, Btn_clear, Btn_check};

    gout.open(width,height);

    event ev;
    gin.timer(100);
    auto start = chrono::system_clock::now();

while (gin >> ev && ev.keycode!=key_escape){

Blackscreen();

 if (game_is_on)
 {
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
    Time_passed(start);

    if (Sudoku->Is_solved()) game_is_on=false;
 }
 else
 {
    Endgame();
 }

    gout << refresh;
}
    f.close();
    return 0;
}
