#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>


char img_game_chr1[500], img_obstacle1[500];
int i1, random1 = 1000,  obstacle1 = 00, a1, r1, jump_stay1, dlay1 = 80, scores1, score_count1 = 0;
char score1[5], road1[40];


int jump1(int i, int random);
bool jump_check();
int game1(int count)
{
    scores1 = count;
    int life1 = 3, obstacle_num1 = 1, life_bar1 = 800;
    cleardevice();
    outtextxy(50, 200, "Score:");
    sndPlaySound("Files//Sound//Background.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    readimagefile("Files//Images//background//Road.jpg", 0, 553, 1000, 561);
    readimagefile("Files//Images//background//moon.jpg", 0, 0, 1000, 192);
    readimagefile("Files//Images//background//Life.jpg", 800, 200, 830, 225);
    readimagefile("Files//Images//background//Life.jpg", 860, 200, 890, 225);
    readimagefile("Files//Images//background//Life.jpg", 920, 200, 950, 225);
    for(i1 = 1; life1; i1++, r1++)
    {
        sprintf(score1, "%d", scores1);
        outtextxy(100, 200, score1);
        if((kbhit()))
        {
            a1 = getch();
            if(a1 == ' ')
            {
                random1 = jump1(i1, random1);
                readimagefile("Files//Images//game character//black.jpg", 25, 270, 175, 442); // make jump image black
            }
        }


        else
        {
            if( random1 > -60 && random1 < 150)  // character er size
            {
                life1--;
                readimagefile("Files//Images//obstacle//black.jpg", 175, 485, 305, 552);
                readimagefile("Files//Images//obstacle//black.jpg", 0, 485, 25, 552);
                readimagefile("Files//Images//game character//collided.jpg", 25, 380, 175, 552);
                readimagefile("Files//Images//background//Life end.jpg", life_bar1, 200, life_bar1 + 30, 225);
                life_bar1 += 60;
                delay(700);
                // sound of crashing
                random1 -= 300;
            }
            sprintf(img_obstacle1, "Files//Images//obstacle//Obstacle %02d.jpg", obstacle1);
            readimagefile(img_obstacle1, random1, 485, random1 + 130, 552);
            sprintf(img_game_chr1, "Files//Images//game character//Untitled-%d.jpg", i1);
            readimagefile(img_game_chr1, 25, 380, 175, 552);
            sprintf(road1, "Files//Images//road//sidebar%d.jpg", r1);
            readimagefile(road1, 0, 553, 1000, 561);
            i1 %= 14;
            r1 %= 6;
            random1 -= 20;
            if((random1 < - 600))
            {
                random1 = 1000;
                obstacle1 = rand() % 10;
                obstacle_num1++;
                if( !(obstacle_num1 % 3))
                {

                    if(obstacle_num1 == 12) // level up er jonno korsi.
                        break;
                    dlay1 -= 10;
                }
            }
            delay(dlay1);
        }
    }
    // loop for walking the man from the screen
    if(life1)
    {
        sndPlaySound("Files//Sound//Tada.wav", SND_FILENAME | SND_ASYNC);
        delay(1000);
        for(random1 = 25, i1 = 1; random1 < 1100; random1 += 10, i1++)
        {
            sprintf(img_game_chr1, "Files//Images//game character//Untitled-%d.jpg", i1);
            readimagefile(img_game_chr1, random1, 380, random1 + 150, 552);
            readimagefile("Files//Images//game character//black.jpg",random1 - 151 , 380, random1 - 1, 552);
            i1 %= 14;
            delay(60);
        }
        return scores1;
    }
    else
    {
        //scores1 = 0;
        sndPlaySound("Files//Sound//Game Over.wav", SND_FILENAME | SND_ASYNC);
        readimagefile("Files//Images//game character//collided.jpg", 25, 380, 175, 552);
        delay(1000);

        return 0;
    }
}


int jump1(int i1, int random1)
{
    readimagefile("Files//Images//game character//black.jpg", 25, 380, 175, 552);
    sprintf(img_game_chr1, "Files//Images//game character//Untitled-%d.jpg", i1);
    readimagefile(img_game_chr1, 25, 270, 175, 442);
    // readimagefile("obstacle//black.jpg", random, 485, random + 130, 552);
    for(jump_stay1 = 1; jump_stay1 < 14; ++jump_stay1, r1++ )
    {
        if(kbhit())
            a1 = getch();
        sprintf(img_obstacle1, "Files//Images//obstacle//Obstacle %02d.jpg", obstacle1);
        readimagefile(img_obstacle1, random1, 485, random1 + 130, 552);
        sprintf(road1, "Files//Images//road//sidebar%d.jpg", r1);
        readimagefile(road1, 0, 553, 1000, 561);
        random1 -= 20;
        r1 %= 6;
        if( random1 == -80)
            scores1 += 1000;
        else if((random1 == - 900))
        {
            random1 = 1000;
            obstacle1 = rand() % 11;
        }
        delay(dlay1);
    }
    a1 = 0;
    return random1 + 20;

}
