#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>


char img_game_chr2[500], img_obstacle2[500];
int i2, random2 = 1000,  obstacle2 = 00,  a2, r2, jump_stay2, dlay2 = 70, scores2, score_count2 = 0;
char score2[5] = {'0', '0','0'}, road2[40];


int jump2(int i2, int random2);
bool jump_check();
int game2(int count)
{
    scores2 = count;
    int life2 = 3, obstacle_num2 = 1, life_bar2 = 800;
    cleardevice();
    outtextxy(50, 200, "Score:");
    sndPlaySound("Files//Sound//Background.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    readimagefile("Files//Images//background//Road.jpg", 0, 553, 1000, 561);
    readimagefile("Files//Images//background//aurora1.jpg", 0, 0, 1000, 192);
    readimagefile("Files//Images//background//Life.jpg", 800, 200, 830, 225);
    readimagefile("Files//Images//background//Life.jpg", 860, 200, 890, 225);
    readimagefile("Files//Images//background//Life.jpg", 920, 200, 950, 225);
    for(i2 = 1; life2; i2++, r2++)
    {
        sprintf(score2, "%d", scores2);
        outtextxy(100, 200, score2);
        if((kbhit()))
        {
            a2 = getch();
            if(a2 == ' ')
            {
                random2 = jump2(i2, random2);
                readimagefile("Files//Images//game character//black.jpg", 25, 270, 175, 442); // make jump image black
            }
        }
        else
        {
            if( random2 > -60 && random2 < 150)  // character er size
            {
                life2--;
                readimagefile("Files//Images//obstacle//black.jpg", 175, 485, 305, 552);
                readimagefile("Files//Images//obstacle//black.jpg", 0, 485, 25, 552);
                readimagefile("Files//Images//game character//collided.jpg", 25, 380, 175, 552);
                readimagefile("Files//Images//background//Life end.jpg", life_bar2, 200, life_bar2 + 30, 225);
                life_bar2 += 60;
                delay(700);
                // sound of crashing
                random2 -= 300;
            }
            sprintf(img_obstacle2, "Files//Images//obstacle//Obstacle %02d.jpg", obstacle2);
            readimagefile(img_obstacle2, random2, 485, random2 + 130, 552);
            sprintf(img_game_chr2, "Files//Images//game character//Untitled-%d.jpg", i2);
            readimagefile(img_game_chr2, 25, 380, 175, 552);
            sprintf(road2, "Files//Images//road//sidebar%d.jpg", r2);
            readimagefile(road2, 0, 553, 1000, 561);
            i2 %= 14;
            r2 %= 6;
            random2 -= 20;
            if((random2 < - 600))
            {
                random2 = 1000;
                obstacle2 = rand() % 10;
                obstacle_num2++;
                if( !(obstacle_num2 % 3))
                {

                    if(obstacle_num2 == 18) // level up er jonno korsi.
                        break;
                    dlay2 -= 10;
                }
            }
            delay(dlay2);
        }
    }
    // loop for walking the man from the screen
    if(life2)
    {
        sndPlaySound("Files//Sound//Tada.wav", SND_FILENAME | SND_ASYNC);
        readimagefile("Files//Images//background//home.jpg", 750, 380, 1000, 553);
        delay(1000);
        for(random2 = 25, i2 = 1; random2 < 600; random2 += 10, i2++)
        {
            sprintf(img_game_chr2, "Files//Images//game character//Untitled-%d.jpg", i2);
            readimagefile(img_game_chr2, random2, 380, random2 + 150, 552);
            readimagefile("Files//Images//game character//black.jpg",random2 - 151 , 380, random2 - 1, 552);
            i2 %= 14;
            delay(60);
        }
        return 1;
    }
    else
    {
        //scores2 = 0;
        sndPlaySound("Files//Sound//Game Over.wav", SND_FILENAME | SND_ASYNC);
        readimagefile("Files//Images//game character//collided.jpg", 25, 380, 175, 552);
        delay(1000);
        return 0;
    }
}


int jump2(int i2, int random2)
{
    readimagefile("Files//Images//game character//black.jpg", 25, 380, 175, 552);
    sprintf(img_game_chr2, "Files//Images//game character//Untitled-%d.jpg", i2);
    readimagefile(img_game_chr2, 25, 270, 175, 442);
    // readimagefile("obstacle//black.jpg", random, 485, random + 130, 552);
    for(jump_stay2 = 1; jump_stay2 < 14; ++jump_stay2, r2++ )
    {
        if(kbhit())
            a2 = getch();
        sprintf(img_obstacle2, "Files//Images//obstacle//Obstacle %02d.jpg", obstacle2);
        readimagefile(img_obstacle2, random2, 485, random2 + 130, 552);
        sprintf(road2, "Files//Images//road//sidebar%d.jpg", r2);
        readimagefile(road2, 0, 553, 1000, 561);
        random2 -= 20;
        r2 %= 6;
        if( random2 == -80)
            scores2 += 1500;
        else if((random2 == - 900))
        {
            random2 = 1000;
            obstacle2 = rand() % 11;
        }
        delay(dlay2);
    }
    a2 = 0;
    return random2 + 20;

}
