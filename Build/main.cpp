#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>

void intro();
void about();
void menu();
void help();
int menu1();
int game();
int game1(int count);
int game2(int count);

using namespace std;

int main()
{
    int count = 1;
    printf("Run Happily\n");
    initwindow(1000, 600, "Run by Saumik & Shantim");
    //intro();
    cleardevice();
    delay(200);
    menu();

    delay(109);

    while(1)
    {
        //count = 0;
        count = menu1();
        if(count == 1)
            about();
        else if(count == 2)
        {
            count = game();
            if(count)
            {
                cleardevice();
                readimagefile("Files//Images//background//Level 2.jpg", 0, 0, 1000, 600);
                getch();
                //printf("%d\n", count);
                count = game1(count);
            }
            if(count)
            {
                cleardevice();
                readimagefile("Files//Images//background//Level 3.jpg", 0, 0, 1000, 600);
                getch();
                count = game2(count);

            }
            if(count)
            {
                readimagefile("Files//Images//background//Winner.jpg", 0, 0, 1000, 600);
                delay(3000);
                count = 0;
            }
            else if(count == 0)
            {
                readimagefile("Files//Images//background//Lost.jpg", 0, 0, 1000, 600);
                delay(3000);
            }

        }
        else if(count == 3)
        {
            delay(2000);
            return 0;
        }
        else
            help();
    }

    return 0;
}
