#ifndef SUDOKU_HPP_INCLUDED
#define SUDOKU_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>

class sudoku:public Widget
{
protected:
    vector<vector<dinamictext*>> numz;
    vector<vector<int>> solz;
    int current_x{0}, current_y{0};
    int num_type;

public:


    sudoku(int pos_x, int pos_y, int size_x, int size_y, bool click, vector<int>incoming_numz, vector<int>solution):Widget(pos_x, pos_y, size_x, size_y, click)
    {
        for (unsigned int i=0; i<9; i++)
        {
            vector<dinamictext*> rows;
            vector<int> solrows;
            for (unsigned int j=0; j<9; j++)
            {
                static int k=0;
                bool changeable=false;
                if (incoming_numz[k]==0) changeable=true;
                rows.push_back(new dinamictext(pos_x+(j*25), pos_y+(i*25), 25, 25, false, changeable, incoming_numz[k]));
                solrows.push_back(solution[k]);
                k++;
            }
            numz.push_back(rows);
            solz.push_back(solrows);
        }
    }

    void Draw()
    {
        gout << move_to(x_coord, y_coord) << color(20,20,20) << box(x_size, y_size);
        gout << move_to(x_coord+x_size/3, y_coord) << color(40,40,40) << box(x_size/3, y_size/3);
        gout << move_to(x_coord, y_coord+y_size/3) << box(x_size/3, y_size/3);
        gout << move_to(x_coord+2*x_size/3, y_coord+y_size/3) << box(x_size/3, y_size/3);
        gout << move_to(x_coord+x_size/3, y_coord+2*y_size/3) << box(x_size/3, y_size/3);

        for (unsigned int i=0; i<9; i++)
        {
            for (unsigned int j=0; j<9; j++)
            {
                if (numz[i][j]->Is_clicked())
                {
                    if (numz[i][j]->Getnum()!=0)num_type=numz[i][j]->Getnum();
                }

                if (numz[i][j]->Getnum()==num_type)
                {
                    numz[i][j]->Change_chosen(true);
                }
                else
                {
                    numz[i][j]->Change_chosen(false);
                }

                if (numz[i][j]->Getnum()==solz[i][j] || numz[i][j]->Getnum()==0)
                {
                    numz[i][j]->Check(false);
                }

                numz[i][j]->Draw();
            }
        }

    }

    void Target(int mouse_x, int mouse_y)
    {
        for (unsigned int i=0; i<9; i++)
        {
            for (unsigned int j=0; j<9; j++)
            {
                if (mouse_x>numz[i][j]->left() && mouse_x<numz[i][j]->right() && mouse_y>numz[i][j]->top() && mouse_y<numz[i][j]->bottom())
                {
                    numz[i][j]->Focus(true);
                    current_x=i; current_y=j;
                }else
                {
                    numz[i][j]->Focus(false);
                }
            }

        }
    }

    void Change_chosen(int numvalue)
    {
        numz[current_x][current_y]->Changenum(numvalue);
    }

    void Check_sudoku()
    {
        int counter{0};
        for (unsigned int i=0; i<9; i++)
        {
            for (unsigned int j=0; j<9; j++)
            {
                int t_i=i; int t_j=j;
                int tested=numz[t_i][t_j]->Getnum();
                int endsolution=solz[t_i][t_j];

                if (tested==numz[i][j]->Getnum()) counter++;
                if (tested!=endsolution) numz[t_i][t_j]->Check(true);
            }

        }
    }


    bool Is_solved()
    {
    bool solved=false;
    int total_solved{0};
    for (unsigned int i=0; i<9; i++)
        {
            for (unsigned int j=0; j<9; j++)
            {
                if (numz[i][j]->Getnum()==solz[i][j]) total_solved+=1;
            }

        }
    if (total_solved==81) solved=true;
    return solved;
    }
};




#endif // SUDOKU_HPP_INCLUDED
