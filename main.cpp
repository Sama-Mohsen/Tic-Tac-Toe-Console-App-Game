#include <bits/stdc++.h>
//#include<string>
//#include <iostream>
//#include<algorithm>
//#include <csignal>
//#include <thread>

using namespace std;
short int X_Score=0, O_Score=0, P_VS_Bot_Score=0, Bot_Score=0;
string board [3][3]={"1","2","3","4","5","6","7","8","9"},option,choose=" ",s,play,bot_letter;
bool bot_win= false,gaps= false,chance_to_win= false,play_anywhere_is_finished= false,wl=false,
        intro_s= false,intro_s_b= false;

void welcome_sound(){system("canberra-gtk-play -f wtg.wav");}
void intro_sound()
{
    if (!intro_s)
        system("canberra-gtk-play -f Rainbow.wav"),intro_s= true;
    else
        system("canberra-gtk-play -f Brick_Game.wav");
}
void intro_sound_bot()
{
    if (!intro_s_b)
        system("canberra-gtk-play -f Rainbow.wav"),intro_s_b= true;
    else
        system("canberra-gtk-play -f Brick_Game.wav");
}

void correct_sound(){system("canberra-gtk-play -f correct.wav");}
void error_sound(){system("canberra-gtk-play -f error.wav");}
void success_sound(){system("canberra-gtk-play -f success.wav");}
void game_over_sound(){system("canberra-gtk-play -f game_over.wav");}

void start_game_interface()
{
    for (int color = 0; color <= 22; color++)
    {
        system("clear");

        cout<<"\t\t\t\t\t\t   \x1B[1;38;2;230;219;116mWelcome to  \x1B[1;38;2;255;0;0mX\x1B[1;38;2;0;168;0mO \x1B[1;38;2;230;219;116m Game\x1B[0m"<<endl;
        if (option=="1") cout<<"\t\t\t\t\t\t\t \x1B[1;38;2;255;0;0mX  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;0;168;0mO\n";
        else
        {
            if (choose=="X") cout<<"\t\t\t\t\t\t    \x1B[1;38;2;255;0;0mYOU  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;0;168;0mCOMPUTER\n";
            else cout<<"\t\t\t\t\t\t    \x1B[1;38;2;0;168;0mYOU  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;255;0;0mCOMPUTER\n";
        }
        cout<<"\x1b[0m";
        if (color==0)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---+---+\n"
                    "\t\t\t\t\t\t      | "<< "\x1B[0m";
            cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\n"
                    "\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }
        else if (color==1||color==9||color==17)
        {
            cout << "\x1B[1;38;2;230;219;116m\t\t\t\t\t\t      +---+\x1B[1;38;2;117;113;94m---+---+\n\t\t\t\t\t\t      \x1b[1;38;2;230;219;116m| "<< "\x1B[0m";
            cout << board[0][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m | \x1b[0m";
            cout<<"\n\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m+---+\x1b[1;38;2;117;113;94m---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \x1b[0m";
            cout<<"\n\t\t\t\t\t\t      \x1b[1;38;2;117;113;94m+---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }

        else if(color==2||color==8||color==10||color==16||color==18)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---\x1B[1;38;2;230;219;116m+---+\x1B[1;38;2;117;113;94m---+\n\t\t\t\t\t\t      | "<< "\x1B[0m";
            cout << board[0][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            cout << board[0][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m+---+---+\x1b[1;38;2;117;113;94m---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m| \x1B[0m";
            cout << board[1][0];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      "
                    "\x1B[1;38;2;230;219;116m+---+\x1b[1;38;2;117;113;94m---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }

        else if(color==3||color==7||color==11||color==15||color==19)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---\x1B[1;38;2;230;219;116m+---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| "<< "\x1B[0m";
            cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            cout << board[0][2];
            cout << "\x1B[1;38;2;230;219;116m |"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---\x1b[1;38;2;230;219;116m+---+---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| \x1B[0m";
            cout << board[1][0];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            cout << board[1][1];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      "
                    "\x1B[1;38;2;230;219;116m+---+---+\x1b[1;38;2;117;113;94m---+\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m| \x1B[0m";
            cout << board[2][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n"
                  "\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m+---+\x1b[1;38;2;117;113;94m---+---+\n\n"<< "\x1B[0m";
        }
        else if (color==4||color==6||color==12||color==14||color==20)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | "<< "\x1B[0m";
            cout << board[0][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---+---\x1b[1;38;2;230;219;116m+---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| \x1B[0m";
            cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][1];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            cout << board[1][2];
            cout << "\x1b[1;38;2;230;219;116m | \n\t\t\t\t\t\t      "
                    "\x1B[1;38;2;117;113;94m+---\x1b[1;38;2;230;219;116m+---+---+\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| \x1B[0m";
            cout << board[2][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            cout << board[2][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n"
                  "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---\x1B[1;38;2;230;219;116m+---+\x1B[1;38;2;117;113;94m---+\n\n"<< "\x1B[0m";
        }
        else if (color==5||color==13||color==21)
        {
            cout << "\t\t\t\t\t\t      \x1b[1;38;2;117;113;94m+---+---+---+\n"
                    "\t\t\t\t\t\t      | "<< "\x1B[0m";
            cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m |\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---+---\x1b[1;38;2;230;219;116m+---+\n"
                    "\t\t\t\t\t\t      \x1b[1;38;2;117;113;94m| \x1B[0m";
            cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][1];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            cout << board[2][2];
            cout<<"\x1b[1;38;2;230;219;116m |\n"
                  "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---\x1B[1;38;2;230;219;116m+---+\n\n"<< "\x1B[0m";
        }
        else
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---+---+\n"
                    "\t\t\t\t\t\t      | "<< "\x1B[0m";
            cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\x1B[0m\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
            else
            {
                if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
            }
            cout<<"\n\t\t\t\t\t\t\x1b[1;38;2;117;113;94m      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
            else
            {
                if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
            }
            cout<<"\n\t\t\t\t\t\t\x1b[1;38;2;117;113;94m      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }
        usleep(50100);
    }
}
void interface()
{
    for (int color = 0; color <= 4; color++)
    {
        system("clear");
        cout<<"\t\t\t\t\t\t   \x1B[1;38;2;230;219;116mWelcome to  \x1B[1;38;2;255;0;0mX\x1B[1;38;2;0;168;0mO \x1B[1;38;2;230;219;116m Game\x1B[0m"<<endl;
        if (option=="1") cout<<"\t\t\t\t\t\t\t \x1B[1;38;2;255;0;0mX  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;0;168;0mO\n\n";
        else
        {
            if (choose=="X") cout<<"\t\t\t\t\t\t    \x1B[1;38;2;255;0;0mYOU  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;0;168;0mCOMPUTER\n";
            else cout<<"\t\t\t\t\t\t    \x1B[1;38;2;0;168;0mYOU  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;255;0;0mCOMPUTER\n";
        }
        cout<<"\x1b[0m";
        if(color==1 || color==3)
        {
            cout << "\t\t\t\t\t\t        ";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
            else
            {
                if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
            }
            cout << "\x1B[1;38;2;230;219;116m \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
            else
            {
                if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
            }
            cout << "\x1B[1;38;2;230;219;116m  \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<" \n\n";
        }

        else if (color==2)
        {
            cout << "\t\t\t\t\t\t        ";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;255;182;25m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;255;182;25m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
            else
            {
                if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
            }
            cout << "\x1B[1;38;2;255;182;25m \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1B[1;38;2;255;182;25m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1B[1;38;2;255;182;25m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
            else
            {
                if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
            }
            cout << "\x1B[1;38;2;255;182;25m  \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1B[1;38;2;255;182;25m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1B[1;38;2;255;182;25m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<" \n\n";
        }

        else
        {
            cout << "\t\t\t\t\t\t        ";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
            else
            {
                if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
            }
            cout << "\x1B[1;38;2;117;113;94m \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
            else
            {
                if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
            }
            cout << "\x1B[1;38;2;117;113;94m  \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<" \n\n";
        }
        usleep(50100);
    }
}
void errors_interface()
{
    for (int color = 0; color <= 6; color++)
    {
        system("clear");

        cout<<"\t\t\t\t\t\t   \x1B[1;38;2;230;219;116mWelcome to  \x1B[1;38;2;255;0;0mX\x1B[1;38;2;0;168;0mO \x1B[1;38;2;230;219;116m Game\x1B[0m"<<endl;
        if (option=="1") cout<<"\t\t\t\t\t\t\t \x1B[1;38;2;255;0;0mX  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;0;168;0mO\n\n";
        else
        {
            if (choose=="X") cout<<"\t\t\t\t\t\t    \x1B[1;38;2;255;0;0mYOU  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;0;168;0mCOMPUTER\n";
            else cout<<"\t\t\t\t\t\t    \x1B[1;38;2;0;168;0mYOU  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;255;0;0mCOMPUTER\n";
        }
        cout<<"\x1b[0m";
        if (color==1||color==3||color==5)
        {
            cout << "\t\t\t\t\t\t        ";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;255;0;0m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;255;0;0m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
            else
            {
                if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
            }
            cout << "\x1B[1;38;2;255;0;0m \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1B[1;38;2;255;0;0m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1B[1;38;2;255;0;0m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
            else
            {
                if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
            }
            cout << "\x1B[1;38;2;255;0;0m  \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1B[1;38;2;255;0;0m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1B[1;38;2;255;0;0m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<" \n\n";
        }

        else
        {
            cout << "\t\t\t\t\t\t        ";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
            else
            {
                if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
            }
            cout << "\x1B[1;38;2;117;113;94m \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout<<"\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
            else
            {
                if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
            }
            cout << "\x1B[1;38;2;117;113;94m  \n\t\t\t\t\t\t       -----------\n\t\t\t\t\t\t        \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<" \n\n";
        }
        usleep(50200);
    }
}
void end_game_interface()
{
    for (int color = 0; color <= 22; color++)
    {
        system("clear");

        cout<<"\t\t\t\t\t\t\t\x1B[1;38;2;174;129;255mGAME OVER\x1b[0m"<<endl;
        if (color==0)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---+---+\n"
                    "\t\t\t\t\t\t      | "<< "\x1B[0m";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\n"
                    "\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }
        else if (color==1||color==9||color==17)
        {
            cout << "\x1B[1;38;2;230;219;116m\t\t\t\t\t\t      +---+\x1B[1;38;2;117;113;94m---+---+\n\t\t\t\t\t\t      \x1b[1;38;2;230;219;116m| "<< "\x1B[0m";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m+---+\x1b[1;38;2;117;113;94m---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }

        else if(color==2||color==8||color==10||color==16||color==18)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---\x1B[1;38;2;230;219;116m+---+\x1B[1;38;2;117;113;94m---+\n\t\t\t\t\t\t      | "<< "\x1B[0m";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m+---+---+\x1b[1;38;2;117;113;94m---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m| \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      "
                    "\x1B[1;38;2;230;219;116m+---+\x1b[1;38;2;117;113;94m---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }

        else if(color==3||color==7||color==11||color==15||color==19)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---\x1B[1;38;2;230;219;116m+---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| "<< "\x1B[0m";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout << "\x1B[1;38;2;230;219;116m |"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---\x1b[1;38;2;230;219;116m+---+---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      "
                    "\x1B[1;38;2;230;219;116m+---+---+\x1b[1;38;2;117;113;94m---+\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m| \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n"
                  "\t\t\t\t\t\t      \x1B[1;38;2;230;219;116m+---+\x1b[1;38;2;117;113;94m---+---+\n\n"<< "\x1B[0m";
        }
        else if (color==4||color==6||color==12||color==14||color==20)
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | "<< "\x1B[0m";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---+---\x1b[1;38;2;230;219;116m+---+"
                    "\n\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout << "\x1b[1;38;2;230;219;116m | \n\t\t\t\t\t\t      "
                    "\x1B[1;38;2;117;113;94m+---\x1b[1;38;2;230;219;116m+---+---+\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m| \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1B[1;38;2;230;219;116m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n"
                  "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---\x1B[1;38;2;230;219;116m+---+\x1B[1;38;2;117;113;94m---+\n\n"<< "\x1B[0m";
        }
        else if (color==5||color==13||color==21)
        {
            cout << "\t\t\t\t\t\t      \x1b[1;38;2;117;113;94m+---+---+---+\n"
                    "\t\t\t\t\t\t      | "<< "\x1B[0m";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m | \n\t\t\t\t\t\t      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m |\n"
                    "\t\t\t\t\t\t      \x1B[1;38;2;117;113;94m+---+---\x1b[1;38;2;230;219;116m+---+\n"
                    "\t\t\t\t\t\t      \x1b[1;38;2;117;113;94m| \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;95;140;138m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1b[1;38;2;230;219;116m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<"\x1b[1;38;2;230;219;116m |\n"
                  "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---\x1B[1;38;2;230;219;116m+---+\n\n"<< "\x1B[0m";
        }
        else
        {
            cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---+---+\n"
                    "\t\t\t\t\t\t      | "<< "\x1B[0m";
            if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
            else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
            else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
            cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
            if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
            else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
            cout << "\x1b[1;38;2;117;113;94m |\x1B[0m\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
            else
            {
                if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
            }
            cout<<"\n\t\t\t\t\t\t\x1b[1;38;2;117;113;94m      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
            else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
            else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
            else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m\t";
            if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
            else
            {
                if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
                else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
            }
            cout<<"\n\t\t\t\t\t\t\x1b[1;38;2;117;113;94m      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
            if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
            else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
            else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
            cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
            if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
            else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
            cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
        }
        usleep(50100);
    }
}
void play_again_or_end_interface()
{
    cout<<"\t\t\t\t\t\t\t\x1B[1;38;2;174;129;255mGAME OVER\x1b[0m"<<endl;
    cout << "\x1B[1;38;2;117;113;94m\t\t\t\t\t\t      +---+---+---+\n"
            "\t\t\t\t\t\t      | "<< "\x1B[0m";
    if (board[0][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][0] << "\x1B[0m";
    else if (board[0][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][0] << "\x1B[0m";
    else if (board[0][0] != "X" && board[0][0] != "O") cout << board[0][0];
    cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
    if (board[0][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][1] << "\x1B[0m";
    else if (board[0][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][1] << "\x1B[0m";
    else if (board[0][1] != "X" && board[0][1] != "O") cout << board[0][1];
    cout << "\x1B[1;38;2;117;113;94m | \x1B[0m";
    if (board[0][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[0][2] << "\x1B[0m";
    else if (board[0][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[0][2] << "\x1B[0m";
    else if (board[0][2] != "X" && board[0][2] != "O") cout << board[0][2];
    cout << "\x1b[1;38;2;117;113;94m |\x1B[0m\t";
    if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1b[38;2;255;0;0mX\x1b[38;2;117;113;94m) Score: \x1b[38;2;255;0;0m"<<X_Score;
    else
    {
        if (bot_letter=="X") cout<<"\x1b[38;2;117;113;94mComputer Score: \x1b[38;2;255;0;0m"<<Bot_Score;
        else cout<<"\x1b[38;2;117;113;94mComputer Score: \x1B[38;2;0;168;0m"<<Bot_Score;
    }
    cout<<"\n\t\t\t\t\t\t\x1b[1;38;2;117;113;94m      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
    if (board[1][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][0] << "\x1B[0m";
    else if (board[1][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][0] << "\x1B[0m";
    else if (board[1][0] != "X" && board[1][0] != "O") cout << board[1][0];
    cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
    if (board[1][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][1] << "\x1B[0m";
    else if (board[1][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][1] << "\x1B[0m";
    else if (board[1][1] != "X" && board[1][1] != "O") cout << board[1][1];
    cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
    if (board[1][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[1][2] << "\x1B[0m";
    else if (board[1][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[1][2] << "\x1B[0m";
    else if (board[1][2] != "X" && board[1][2] != "O") cout << board[1][2];
    cout << "\x1b[1;38;2;117;113;94m | \x1B[0m\t";
    if (option=="1") cout<<"\x1b[38;2;117;113;94mPlayer (\x1B[38;2;0;168;0mO\x1b[38;2;117;113;94m) Score: \x1B[1;38;2;0;168;0m"<<O_Score;
    else
    {
        if (choose=="X") cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1b[38;2;255;0;0m"<<P_VS_Bot_Score;
        else cout<<"\x1b[38;2;117;113;94mPlayer Score: \x1B[38;2;0;168;0m"<<P_VS_Bot_Score;
    }
    cout<<"\n\t\t\t\t\t\t\x1b[1;38;2;117;113;94m      +---+---+---+\n\t\t\t\t\t\t      | \x1B[0m";
    if (board[2][0] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][0] << "\x1B[0m";
    else if (board[2][0] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][0] << "\x1B[0m";
    else if (board[2][0]!= "X" && board[2][0] != "O") cout << board[2][0];
    cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
    if (board[2][1] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][1] << "\x1B[0m";
    else if (board[2][1] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][1] << "\x1B[0m";
    else if (board[2][1]!= "X" && board[2][1] != "O") cout << board[2][1];
    cout << "\x1b[1;38;2;117;113;94m | \x1B[0m";
    if (board[2][2] == "X") cout << "\x1B[1;38;2;255;0;0m" << board[2][2] << "\x1B[0m";
    else if (board[2][2] == "O") cout << "\x1B[1;38;2;0;168;0m" << board[2][2] << "\x1B[0m";
    else if (board[2][2]!= "X" && board[2][2] != "O") cout << board[2][2];
    cout<<"\x1b[1;38;2;117;113;94m |\n\t\t\t\t\t\t      +---+---+---+\n\n"<< "\x1B[0m";
}

int play_again();

string computer_Letter(const string &Letter1){
    string letter2 ;
    if (Letter1=="X")
        letter2="O";
    else
        letter2="X";

    return letter2;}
void first_play (string &player1_position)
{

    if (player1_position=="5")
        board [0][0] = bot_letter;
    else
        board[1][1] = bot_letter;
}
void bot_will_win (string &letter1)
{
    string  a=board[0][0], b=board[0][1], c=board[0][2],
            d=board[1][0], e=board[1][1], f=board[1][2],
            g=board[2][0], h=board[2][1], i=board[2][2];

    //row 0
    if      (  ((c==b&& b==bot_letter)
                || (d==g&& g==bot_letter)
                || (e==i&& i==bot_letter))
               && a!=letter1 && a!=bot_letter)
        board[0][0]=bot_letter, bot_win= true;

    else if (  ((c==a&& a==bot_letter)
                || (e==h&& h==bot_letter))
               && b!=letter1 && b!=bot_letter)
    {
        board[0][1]=bot_letter;
        bot_win= true;
    }

    else if (  ((a==b&& b==bot_letter)
                || (f==i&& i==bot_letter)
                || (e==g&& g==bot_letter))
               && c!=letter1&& c!=bot_letter)
        board[0][2]=bot_letter, bot_win= true;

        //row 1
    else if (  ((e==f&& f==bot_letter)
                || (a==g&& a==bot_letter))
               && d!=letter1 && d!=bot_letter)
        board[1][0]=bot_letter, bot_win= true;

    else if (((b==h&& b==bot_letter)
              ||(d==f&& d==bot_letter)
              ||(a==i&& a==bot_letter)
              ||(c==g&& g==bot_letter))
             && e==bot_letter)
        bot_win= true;

    else if (  ((c==i&& c==bot_letter)
                || (d==e&& d==bot_letter))
               && f!=letter1 && f!=bot_letter)
        board[1][2]=bot_letter, bot_win= true;

        //row 2
    else if (  ((e==c&& e==bot_letter)
                || (a==d&& a==bot_letter)
                || (h==i&& h==bot_letter))
               && g!=letter1 && g!=bot_letter)
        board[2][0]=bot_letter, bot_win= true;

    else if (  ((e==b&& e==bot_letter)
                || (i==g&& i==bot_letter))
               && h!=letter1 && h!=bot_letter)
        board[2][1]=bot_letter, bot_win= true;

    else if (  ((g==h&& g==bot_letter)
                || (c==f&& c==bot_letter)
                || (a==e&& a==bot_letter))
               && i!=letter1 && i!=bot_letter)
        board[2][2]=bot_letter, bot_win= true;

    else
        bot_win= false;
}
void fill_the_gaps (string &letter1)
{
    if (bot_win==0)
    {
        string  a=board[0][0], b=board[0][1], c=board[0][2],
                d=board[1][0], e=board[1][1], f=board[1][2],
                g=board[2][0], h=board[2][1], i=board[2][2];

        //row 0
        if ( ( (c == b && c == letter1)
               || (d == g && g == letter1)
               || (e == i && i == letter1))
             && a != letter1 && a != bot_letter)
            board[0][0] = bot_letter, gaps= true;

        else if ( ((c == a && a == letter1) || (e == h && h == letter1) || (g==f&&f==letter1&&e==bot_letter))
                  && b != letter1 && b != bot_letter)
            board[0][1] = bot_letter, gaps= true;

        else if (((a == b && b == letter1)
                  || (((f == i)||(i==b && g!=letter1 && i!=h)) && i == letter1)
                  || (e == g && g == letter1)
                  ||(e==i && e==letter1))
                 && c != letter1 && c != bot_letter)
            board[0][2] = bot_letter, gaps= true;

            //row 1
        else if (((e == f && f == letter1)
                  || (a == g && a == letter1))
                 && d != letter1 && d != bot_letter)
            board[1][0] = bot_letter, gaps= true;

        else if (((c == i && c == letter1)
                  || (d == e && d == letter1))
                 && f != letter1 && f != bot_letter)
            board[1][2] = bot_letter, gaps= true;

            //row 2
        else if (((e == c && e == letter1)
                  || (a == d && a == letter1)
                  || (((h == i)||(a==h)) && h == letter1))
                 && g != letter1 && g != bot_letter)
            board[2][0] = bot_letter, gaps= true;

        else if (((e == b && b == letter1)
                  || (i == g && g == letter1))
                 && h != letter1 && h != bot_letter)
            board[2][1] = bot_letter, gaps= true;

        else if (((g == h && g == letter1)
                  || (((c == f)||(c==h)) && c == letter1)
                  || (a == e && a == letter1))
                 && i != letter1 && i != bot_letter)
            board[2][2] = bot_letter, gaps= true;

        else
            gaps = false;
    }
}
void try_to_win (string &letter1)
{
    if (gaps==0 && bot_win==0)
    {
        string  a=board[0][0], b=board[0][1], c=board[0][2],
                d=board[1][0], e=board[1][1], f=board[1][2],
                g=board[2][0], h=board[2][1], i=board[2][2];

        //row 0
        if (a!=letter1 && a!=bot_letter)
        {
            if (  (b==bot_letter && c!=letter1 && c!=bot_letter)
                  || (c==bot_letter && b!=letter1 && b!=bot_letter)
                  || (d==bot_letter && g!=letter1 && g!=bot_letter)
                  || (g==bot_letter && d!=letter1 && d!=bot_letter)
                  || (e==bot_letter && i!=letter1 && i!=bot_letter)
                  || (i==bot_letter && e!=letter1 && e!=bot_letter)
                    )
                board[0][0]=bot_letter, chance_to_win= true;
        }

        else if (b!=letter1 && b!=bot_letter)
        {
            if (  (a==bot_letter && c!=letter1 && c!=bot_letter)
                  || (c==bot_letter && a!=letter1 && a!=bot_letter)
                  || (e==bot_letter && h!=letter1 && h!=bot_letter)
                  || (h==bot_letter && e!=letter1 && e!=bot_letter)
                    )
                board[0][1]=bot_letter, chance_to_win= true;
        }

        else if (c!=letter1 && c!=bot_letter)
        {
            if (     (a==bot_letter && b!=letter1 && b!=bot_letter)
                     || (b==bot_letter && a!=letter1 && a!=bot_letter)
                     || (e==bot_letter && g!=letter1 && g!=bot_letter)
                     || (g==bot_letter && e!=letter1 && e!=bot_letter)
                     || (f==bot_letter && i!=letter1 && i!=bot_letter)
                     || (i==bot_letter && f!=letter1 && f!=bot_letter)
                    )
                board[0][2]=bot_letter, chance_to_win= true;
        }

            //row 1
        else if (d!=letter1 && d!=bot_letter)
        {
            if (     (a==bot_letter && g!=letter1 && g!=bot_letter)
                     || (g==bot_letter && a!=letter1 && a!=bot_letter)
                     || (e==bot_letter && f!=letter1 && f!=bot_letter)
                     || (f==bot_letter && e!=letter1 && e!=bot_letter)
                    )
                board[1][0]=bot_letter, chance_to_win= true;
        }

        else if (e!=letter1 && e!=bot_letter)
        {
            if (     (b==bot_letter && h!=letter1 && h!=bot_letter)
                     || (h==bot_letter && b!=letter1 && b!=bot_letter)
                     || (d==bot_letter && g!=letter1 && g!=bot_letter)
                     || (f==bot_letter && d!=letter1 && d!=bot_letter)
                     || (a==bot_letter && i!=letter1 && i!=bot_letter)
                     || (i==bot_letter && a!=letter1 && a!=bot_letter)
                     || (g==bot_letter && c!=letter1 && c!=bot_letter)
                     || (c==bot_letter && g!=letter1 && g!=bot_letter)
                    )
                board[1][1]=bot_letter, chance_to_win= true;
        }

        else if (f!=letter1 && f!=bot_letter)
        {
            if (     (c==bot_letter && i!=letter1 && i!=bot_letter)
                     || (i==bot_letter && c!=letter1 && c!=bot_letter)
                     || (e==bot_letter && d!=letter1 && d!=bot_letter)
                     || (d==bot_letter && e!=letter1 && e!=bot_letter)
                    )
                board[1][2]=bot_letter, chance_to_win= true;
        }

            //row 2
        else if (g!=letter1 && g!=bot_letter)
        {
            if (     (e==bot_letter && c!=letter1 && c!=bot_letter)
                     || (c==bot_letter && e!=letter1 && e!=bot_letter)
                     || (d==bot_letter && a!=letter1 && g!=bot_letter)
                     || (a==bot_letter && d!=letter1 && d!=bot_letter)
                     || (h==bot_letter && i!=letter1 && i!=bot_letter)
                     || (i==bot_letter && h!=letter1 && h!=bot_letter)
                    )
                board[2][0]=bot_letter, chance_to_win= true;
        }

        else if (h!=letter1 && h!=bot_letter)
        {
            if (     (g==bot_letter && i!=letter1 && i!=bot_letter)
                     || (i==bot_letter && g!=letter1 && g!=bot_letter)
                     || (e==bot_letter && b!=letter1 && b!=bot_letter)
                     || (b==bot_letter && e!=letter1 && e!=bot_letter)
                    )
                board[2][1]=bot_letter, chance_to_win= true;
        }
        else if (i!=letter1 && i!=bot_letter)
        {
            if  (    (a==bot_letter && e!=letter1 && e!=bot_letter)
                     || (e==bot_letter && a!=letter1 && a!=bot_letter)
                     || (h==bot_letter && g!=letter1 && g!=bot_letter)
                     || (g==bot_letter && h!=letter1 && h!=bot_letter)
                     || (f==bot_letter && c!=letter1 && c!=bot_letter)
                     || (c==bot_letter && f!=letter1 && f!=bot_letter)
                    )
                board[2][2]=bot_letter, chance_to_win= true;
        }

            //continue (play anywhere)
        else
            chance_to_win= false;
    }
}
void play_anywhere (string &letter1)
{
    if (bot_win==0 && gaps==0 && chance_to_win==0)
    {
        for (int i : {0,1,2})
        {
            for (int j : {0,1,2})
            {
                if (board[i][j]!=letter1 && board[i][j]!=bot_letter)
                    board[i][j]=bot_letter,play_anywhere_is_finished= true;
                if (play_anywhere_is_finished==1)
                    break;
            }
            if (play_anywhere_is_finished==1)
                break;
        }
    }
}
void check_win(int i)
{
    int xc=0 , oc=0 , end_counter=0 ;
    for (int r=0 ; r < 3 ; r++)
    {for (int c=0 ; c < 3 ; c++)
        {
            if (board [r][c] != "X" && board [r][c] != "O" ) end_counter++;
            if (board [r][c] == "X") xc++;
            else
            if (board [r][c] == "O") oc++;
            if ( xc == 3 || oc==3)
            {  if (xc > oc)
                {
                    if(choose==" ")
                    {
                        X_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;255;0;0mX\x1B[0m \x1B[38;2;253;255;185mis"
                                "\x1B[1;38;2;255;0;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
                    }
                    else {
                        if (choose=="X") P_VS_Bot_Score++;
                        else Bot_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        if (choose=="X")
                            cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
                        else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
                    }
                    play_again();
                }
                else if (oc > xc)
                {
                    if(choose==" ")
                    {
                        O_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;0;168;0mO\x1B[0m \x1B[38;2;253;255;185mis"
                                "\x1B[1;38;2;0;168;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
                    }
                    else
                    {
                        if (choose=="O") P_VS_Bot_Score++;
                        else Bot_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        if (choose=="O")
                            cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
                        else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
                    }
                    play_again();
                }
            }
        }
        xc=0,oc=0;
    }
    for (int r=0 ; r < 3 ; r++)
    {
        for (int c=0 ; c < 3 ; c++)
        {
            if (board [c][r] == "X") xc++;
            else
            if (board [c][r] == "O") oc++;
            if ( xc == 3 || oc==3)
            { if (xc > oc)
                {
                    if(choose==" ")
                    {
                        X_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;255;0;0mX\x1B[0m \x1B[38;2;253;255;185mis"
                                "\x1B[1;38;2;255;0;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
                    }
                    else {
                        if (choose=="X") P_VS_Bot_Score++;
                        else Bot_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        if (choose=="X")
                            cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
                        else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
                    }
                    play_again();
                }
                else if (oc > xc)
                {
                    if(choose==" ")
                    {
                        O_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;0;168;0mO\x1B[0m \x1B[38;2;253;255;185mis"
                                "\x1B[1;38;2;0;168;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
                    }

                    else
                    {
                        if (choose=="O") P_VS_Bot_Score++;
                        else Bot_Score++;
                        thread egi(end_game_interface);
                        thread ss(success_sound);
                        egi.join();
                        ss.join();
                        if (choose=="O")
                            cout << "\t\t\t\t\t\t\t\t\t\t\t     \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
                        else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
                    }
                    play_again();
                }
            }
        }
        xc=0,oc=0;
    }
    if (board[0][0]=="X" && board[1][1]=="X" && board[2][2]=="X" )
    {
        if(choose==" ")
        {
            X_Score++;
            thread egi(end_game_interface);
            thread ss(success_sound);
            egi.join();
            ss.join();
            cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;255;0;0mX\x1B[0m \x1B[38;2;253;255;185mis"
                    "\x1B[1;38;2;255;0;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
        }
        else
        {
            if (choose=="X") P_VS_Bot_Score++;
            else Bot_Score++;
            thread egi(end_game_interface);
            thread ss(success_sound);
            egi.join();
            ss.join();
            if (choose=="X")
                cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
            else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
        }
        play_again();
    }
    else if (board[0][0]=="O" && board[1][1]=="O" && board[2][2]=="O" )
    {
        if(choose==" ")
        {
            O_Score++;
            thread egi(end_game_interface);
            thread ss(success_sound);
            egi.join();
            ss.join();
            cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;0;168;0mO\x1B[0m \x1B[38;2;253;255;185mis"
                    "\x1B[1;38;2;0;168;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
        }
        else
        {
            if (choose=="O") P_VS_Bot_Score++;
            else Bot_Score++;
            thread egi(end_game_interface);
            thread ss(success_sound);
            egi.join();
            ss.join();
            if (choose=="O")
                cout << "\t\t\t\t\t         \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
            else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
        }
        play_again();
    }
    else if (board[0][2]=="O" && board[1][1]=="O" && board[2][0]=="O" )
    {
        if(choose==" ")
        {
            O_Score++;
            thread egi(end_game_interface);
            thread ss(success_sound);
            egi.join();
            ss.join();
            cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;0;168;0mO\x1B[0m \x1B[38;2;253;255;185mis"
                    "\x1B[1;38;2;0;168;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
        }
        else {
            if (choose=="O") P_VS_Bot_Score++;
            else Bot_Score++;
            thread egi(end_game_interface);
            thread ss(success_sound);
            egi.join();
            ss.join();
            if (choose=="O")
                cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
            else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
        }
        play_again();
    }
    else if (board[0][2]=="X" && board[1][1]=="X" && board[2][0]=="X" )
    {
        if(choose==" ") X_Score++;
        else if (choose=="X") P_VS_Bot_Score++;
        else Bot_Score++;
        thread egi(end_game_interface);
        thread ss(success_sound);
        egi.join();
        ss.join();
        if(choose==" ")
            cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mXx Player \x1B[1;38;2;255;0;0mX\x1B[0m \x1B[38;2;253;255;185mis"
                    "\x1B[1;38;2;255;0;0m THE WINNER \x1B[38;2;255;181;32m✯ᴗ✯ \x1B[0m\x1B[38;2;253;255;185mxX\x1B[0m"<<endl;
        else
        {
            if (choose=="X")
                cout << "\t\t\t\t\t     \x1B[38;2;253;255;185mCongratulations! \x1B[1;38;2;255;181;32mYOU WIN ✯ᴗ✯\n\x1B[0m";
            else cout << "\t\t\t\t\t\t     \x1B[1;38;2;255;181;32mCOMPUTER WIN ✯ᴗ✯\x1B[0m\n";
        }
        play_again();
    }
    if (end_counter == 0 && i==9)
    {
        thread gos(game_over_sound);
        thread egi(end_game_interface);
        egi.join();
        gos.join();
        cout << "\t\t\t\t\t\t\t  \x1B[1;38;2;0;168;0mD\x1B[1;38;2;255;0;0mR\x1B[1;38;2;0;168;0mA\x1B[1;38;2;255;0;0mW\x1B[1;38;2;0;168;0m!\x1B[0m"<<endl;
        play_again();
    }
    else return;
}
void error(string &pos1, int i,string p1_letter)
{
    if (pos1.size()==1&&(pos1[0]>=49&&pos1[0]<=57))
    {
        if(pos1!="0"){
            if(pos1<"4")
            {
                if(board[0][(pos1[0]-49)]==pos1) return;
                else
                {
                    thread es(error_sound);
                    thread ei(errors_interface);
                    es.join();
                    ei.join();
                    cout<<"\t\t\t\t\x1b[1;38;2;255;0;0mThis position is already marked\n";
                    cout<<"\x1b[0m";
                    cout<<"\t\t\t\t\x1B[38;2;253;255;185mEnter another position : \x1B[0m";
                    if ((option=="1"&&i%2==0) || (option=="2"&&p1_letter=="X"))
                        cout<<"\x1b[1;38;2;255;0;0m";
                    else if ((option=="1"&&i%2!=0) || (option=="2"&&p1_letter=="O"))
                        cout<<"\x1B[1;38;2;0;168;0m";
                    getline(cin,pos1),error(pos1,i,p1_letter);
                    cout<<"\x1b[0m";
                }
            }

            else if (pos1<"7")
            {
                if(board[1][pos1[0]-52]==pos1) return;
                else
                {
                    thread es(error_sound);
                    thread ei(errors_interface);
                    es.join();
                    ei.join();
                    cout<<"\t\t\t\t\x1b[1;38;2;255;0;0mThis position is already marked\n";
                    cout<<"\x1b[0m";
                    cout<<"\t\t\t\t\x1B[38;2;253;255;185mEnter another position : \x1B[0m";
                    if ((option=="1"&&i%2==0) || (option=="2"&&p1_letter=="X"))
                        cout<<"\x1b[1;38;2;255;0;0m";
                    else if ((option=="1"&&i%2!=0) || (option=="2"&&p1_letter=="O"))
                        cout<<"\x1B[1;38;2;0;168;0m";
                    getline(cin,pos1),error(pos1,i,p1_letter);
                    cout<<"\x1b[0m";
                }

            }

            else if (pos1<="9")
            {
                if(board[2][pos1[0]-55]==pos1) return;
                else
                {
                    thread es(error_sound);
                    thread ei(errors_interface);
                    es.join();
                    ei.join();
                    cout<<"\t\t\t\t\x1b[1;38;2;255;0;0mThis position is already marked\n";
                    cout<<"\x1b[0m";
                    cout<<"\t\t\t\t\x1B[38;2;253;255;185mEnter another position : \x1B[0m";
                    if ((option=="1"&&i%2==0) || (option=="2"&&p1_letter=="X"))
                        cout<<"\x1b[1;38;2;255;0;0m";
                    else if ((option=="1"&&i%2!=0) || (option=="2"&&p1_letter=="O"))
                        cout<<"\x1B[1;38;2;0;168;0m";
                    getline(cin,pos1),error(pos1,i,p1_letter);
                    cout<<"\x1b[0m";
                }
            }
        }
        else
        {
            thread es(error_sound);
            thread ei(errors_interface);
            es.join();
            ei.join();
            cout<<"\t\t\t\t\x1b[1;38;2;255;0;0mThis position doesn't exist\n";
            cout<<"\x1b[0m";
            cout<<"\t\t\t\t\x1B[38;2;253;255;185mEnter another position : \x1B[0m";
            if ((option=="1"&&i%2==0) || (option=="2"&&p1_letter=="X"))
                cout<<"\x1b[1;38;2;255;0;0m";
            else if ((option=="1"&&i%2!=0) || (option=="2"&&p1_letter=="O"))
                cout<<"\x1B[1;38;2;0;168;0m";
            getline(cin,pos1),error(pos1,i,p1_letter);
            cout<<"\x1b[0m";
        }
    }
    else if(pos1[0]==' '||pos1[0]=='0')pos1.erase(0,1),error(pos1,i,p1_letter);
    else if(pos1.size()!=1&&((pos1[0]>=49&&pos1[0]<58)&&pos1[1]==' '))
        pos1.erase(1,1),error(pos1,i,p1_letter);
    else
    {
        thread es(error_sound);
        thread ei(errors_interface);
        es.join();
        ei.join();
        cout<<"\t\t\t\t\x1b[1;38;2;255;0;0mThis position doesn't exist\n";
        cout<<"\x1b[0m";
        cout<<"\t\t\t\t\x1B[38;2;253;255;185mEnter another position : \x1B[0m";
        if ((option=="1"&&i%2==0) || (option=="2"&&p1_letter=="X"))
            cout<<"\x1b[1;38;2;255;0;0m";
        else if ((option=="1"&&i%2!=0) || (option=="2"&&p1_letter=="O"))
            cout<<"\x1B[1;38;2;0;168;0m";
        getline(cin,pos1),error(pos1,i,p1_letter);
        cout<<"\x1b[0m";
    }
}
void ag(string &again)
{
    if(again[0]==' '||again[0]=='0')again.erase(0,1),ag(again);
    if(again.size()!=1&&((again[0]=='1'||again[0]=='2'||again[0]=='3')&&again[1]==' '))
        again.erase(1,1),ag(again);
    else if(again=="1"||again=="2"||again=="3")
        return;
    else
    {
        system("clear");
        play_again_or_end_interface();
        cout << "\t\t\t\t\t\t      \x1B[1;38;2;255;0;0mINVALID OPTION! \x1b[0m\n";
        error_sound();
        // cout << "\t\t\t\t\t\x1B[38;2;253;255;185mDo you Want to Play Again ? Y or N : ";
        cout<<"\t\t\t\t\x1B[1;38;2;174;129;255mOptions : \x1B[0m"<<endl;
        cout<<"\t\t\t\t1. Main Menu"<<endl;
        cout<<"\t\t\t\t2. Play again"<<endl;
        cout<<"\t\t\t\t3. Exit"<<endl;
        cout<<"\t\t\t\t\x1B[38;2;253;255;185mChoose one option: ";
        getline(cin,again);
        cout<<"\x1b[0m";
        ag(again);
    }
}
void cho()
{
    transform(choose.begin(),choose.end(),choose.begin(),::toupper);
    if(choose[0]==' ')choose.erase(0,1),cho();
    if(choose.size()!=1&&((choose[0]=='X'||choose[0]=='O'||choose[0]=='0')&&choose[1]==' ')) choose.erase(1,1),cho();
    else if(choose=="X")return;
    else if (choose=="O"||choose=="0"){choose="O";
        return;}
    else
    {
        system("clear");
        cout<<"\t\t\t\t\t\t   \x1B[1;38;2;230;219;116mWelcome to  \x1B[1;38;2;255;0;0mX\x1B[1;38;2;0;168;0mO \x1B[1;38;2;230;219;116m Game\x1B[0m"<<endl;
        if (choose=="X") cout<<"\t\t\t\t\t\t    \x1B[1;38;2;255;0;0mYOU  \x1B[1;38;2;230;219;116mVS  \x1B[1;38;2;0;168;0mCOMPUTER\n";
        else cout<<"\t\t\t\t\t\t    \x1B[1;38;2;230;219;116mYOU  VS  COMPUTER\n\n\n";
        cout<<"\t\t\t\t\x1B[1;38;2;255;0;0mINVALID OPTION! \x1b[0m\n";
        error_sound();
        cout<<"\t\t\t\t\x1B[38;2;253;255;185mPlease enter \x1B[1;38;2;255;0;0mX\x1B[0m \x1B[38;2;253;255;185mor \x1B[1;38;2;0;168;0mO\x1B[0m\x1B[38;2;253;255;185m :"
              " \x1B[38;2;253;255;185m";
        getline(cin,choose);
        cout<<"\x1b[0m";
        cho();
    }
}
void op()
{
    if(option[0]==' '||option[0]=='0')option.erase(0,1),op();
    if(option.size()!=1&&((option[0]=='1'||option[0]=='2')&&option[1]==' '))
        option.erase(1,1),op();
    else if (option == "1" || option == "2")
        return;
    else
    {
        system("clear");
        cout<<"\t\t\t\t\t\t     \x1B[1;38;2;230;219;116mWelcome to \x1B[1;38;2;255;0;0mX\x1B[1;38;2;0;168;0mO \x1B[1;38;2;230;219;116mGame\x1B[0m"<<endl;
        cout<<"\t\t\t\t\x1B[1;38;2;174;129;255mOptions : \x1B[0m"<<endl;
        cout<<"\t\t\t\t1. Play with another player"<<endl;
        cout<<"\t\t\t\t2. Play with Computer"<<endl<<endl;
        cout<<"\t\t\t\t\x1B[1;38;2;255;0;0mINVALID OPTION! \x1b[0m\n";
        error_sound();
        cout<<"\t\t\t\t\x1B[38;2;253;255;185mPlease enter 1 or 2 : ";
        getline(cin,option);
        cout<<"\x1b[0m";
        op();
    }
}

void Play_with_another_player()
{
    if(option=="1")
    {
        for(int i=0;i<10;i++)
        {
            if (i==0)
            {
                thread is(intro_sound);
                thread sgi(start_game_interface);
                sgi.join();
                is.join();
            }
            if(i!=9)
            {
                if (i!=0) interface();
                if(i%2==0)
                {
                    cout<<"\t\t\t\t\x1B[38;2;253;255;185mThe player 1's turn (\x1B[1;38;2;255;0;0mX\x1B[0m\x1B[38;2;253;255;185m) "<<endl<<"\t\t\t\tEnter the position : \x1B[1;38;2;255;0;0m";
                    play="X";
                }
                else
                {
                    cout<<"\t\t\t\t\x1B[38;2;253;255;185mThe player 2's turn (\x1B[1;38;2;0;168;0mO\x1B[0m\x1B[38;2;253;255;185m) "<<endl<<"\t\t\t\tEnter the position : \x1B[1;38;2;0;168;0m";
                    play="O";
                }
                getline(cin,s);
                cout<<"\x1b[0m";
                error(s,i,choose);
                correct_sound();
                if(s=="1")board[0][0]=play;
                else if(s=="2")board[0][1]=play;
                else if(s=="3")board[0][2]=play;
                else if(s=="4")board[1][0]=play;
                else if(s=="5")board[1][1]=play;
                else if(s=="6")board[1][2]=play;
                else if(s=="7")board[2][0]=play;
                else if(s=="8")board[2][1]=play;
                else board[2][2]=play;
            }
            check_win(i);
        }
    }
}
void Play_with_Computer()
{
    if (option=="2")
    {
        cout<<"\t\t\t\t\x1B[38;2;253;255;185mChoose \x1B[1;38;2;255;0;0mX\x1B[0m\x1b[0m\x1B[38;2;253;255;185m or \x1B[1;38;2;0;168;0mO \x1B[38;2;253;255;185m:"
              " \x1B[1;38;2;253;255;185m";
        getline(cin,choose);
        cout<<"\x1B[0m";
        cho();
        correct_sound();
        bot_letter=computer_Letter(choose);
        for(int i=0;i<10;i++)
        {
            if(i!=9)
            {
                if(i%2==0)
                {
                    if(i==0)
                    {
                        thread isb(intro_sound_bot);
                        thread sgi(start_game_interface);
                        isb.join();
                        sgi.join();
                    }
                    if (choose=="X") cout<<"\x1B[1;38;2;225;0;0m";
                    else cout<<"\x1B[1;38;2;0;168;0m";
                    cout<<"\t\t\t\tYour turn \x1b[0m"<<endl;
                    cout<<"\t\t\t\t\x1B[38;2;253;255;185mChoose the position : ";
                    if (choose=="X") cout<<"\x1B[1;38;2;225;0;0m";
                    else cout<<"\x1B[1;38;2;0;168;0m";
                    getline(cin,s);
                    cout<<"\x1B[0m";
                    error(s,i,choose);
                    correct_sound();
                    if(s=="1")board[0][0]=choose;
                    else if(s=="2")board[0][1]=choose;
                    else if(s=="3")board[0][2]=choose;
                    else if(s=="4")board[1][0]=choose;
                    else if(s=="5")board[1][1]=choose;
                    else if(s=="6")board[1][2]=choose;
                    else if(s=="7")board[2][0]=choose;
                    else if(s=="8")board[2][1]=choose;
                    else board[2][2]=choose;
                }
                else if (i==1) {
                    first_play(s);
                    interface();
                }
                else
                {
                    bot_will_win(choose);
                    fill_the_gaps(choose);
                    try_to_win(choose);
                    play_anywhere(choose);
                    interface();
                }
            }
            check_win(i);
        }
    }
}

int main()
{
    system("clear");
    system("clear");
    choose=" ";
    bot_win= false,gaps= false,chance_to_win= false,play_anywhere_is_finished= false;
    X_Score=0, O_Score=0, P_VS_Bot_Score=0, Bot_Score=0;
    cout<<"\t\t\t\t\t\t     \x1B[1;38;2;230;219;116mWelcome to \x1B[1;38;2;255;0;0mX\x1B[1;38;2;0;168;0mO \x1B[1;38;2;230;219;116mGame\x1B[0m"<<endl;
    if (wl==0) welcome_sound(),wl= true;
    cout<<"\t\t\t\t\x1B[1;38;2;174;129;255mOptions : \x1B[0m"<<endl;
    cout<<"\t\t\t\t1. Play with another player"<<endl;
    cout<<"\t\t\t\t2. Play with Computer"<<endl<<endl;
    cout<<"\t\t\t\t\x1B[38;2;253;255;185mChoose one option 1 or 2 : ";
    getline(cin,option);
    if(option!="1"||option!="2")
        op();
    correct_sound();
    Play_with_another_player();
    Play_with_Computer();
}
int play_again()
{
    string again;
    int we=49;

    cout<<"\t\t\t\t\x1B[1;38;2;174;129;255mOptions : \x1B[0m"<<endl;
    cout<<"\t\t\t\t1. Main Menu"<<endl;
    cout<<"\t\t\t\t2. Play again"<<endl;
    cout<<"\t\t\t\t3. Exit"<<endl;
    cout<<"\t\t\t\t\x1B[38;2;253;255;185mChoose one option: ";
    getline(cin,again);
    cout<<"\x1b[0m";
    ag(again);


    if(again=="1"||again=="2")
    {
        for(int i : {0,1,2})
            for(int z : {0,1,2})
                board[i][z]=we,we++;
        if(again=="1") return main();
        else
        {
            if(option=="1") Play_with_another_player();
            else Play_with_Computer();
        }

    }
    else
    {
        system("clear");
        cout<<"\t\t\t\t\t\t\t\x1B[1;38;2;174;129;255mGAME OVER\x1b[0m"<<endl;
        game_over_sound();
        exit(EXIT_SUCCESS);
    }
}
