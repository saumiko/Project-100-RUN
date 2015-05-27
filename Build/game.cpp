#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>


char img_game_chr[500], img_obstacle[500];
int i, b, random = 1000,  obstacle = 00,  a, r = 1, jump_stay, dlay = 90, scores = 0;
char score[5] = {'0', '0','0'}, road [40];


int jump(int i, int random);
bool jump_check();
int game()
{
    scores = 0;
    int life = 3, obstacle_num = 1, life_bar = 800;
    //initwindow(1000, 600, "Man run cycle");
    cleardevice();
    outtextxy(50, 200, "Score:");
    //readimagefile("background//Road.jpg", 0, 553, 1000, 561);
    sndPlaySound("Files//Sound//Background.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    readimagefile("Files//Images//background//aurora.jpg", 0, 0, 1000, 192);
    readimagefile("Files//Images//background//Life.jpg", 800, 200, 830, 225);
    readimagefile("Files//Images//background//Life.jpg", 860, 200, 890, 225);
    readimagefile("Files//Images//background//Life.jpg", 920, 200, 950, 225);
    for(i = 1; life; i++, r++)
    {
        sprintf(score, "%d", scores);
        outtextxy(100, 200, score);
        if((kbhit()))
        {
            a = getch();
            if(a == ' ')
            {
                random = jump(i, random);
                readimagefile("Files//Images//game character//black.jpg", 25, 270, 175, 442); // make jump image black
            }
        }

        else
        {
            if( random > -40 && random < 150)  // character er size
            {
                life--;
                readimagefile("Files//Images//obstacle//black.jpg", 175, 485, 305, 552);
                readimagefile("Files//Images//obstacle//black.jpg", 0, 485, 25, 552);
                readimagefile("Files//Images//game character//collided.jpg", 25, 380, 175, 552);
                readimagefile("Files//Images//background//Life end.jpg", life_bar, 200, life_bar + 30, 225);
                life_bar += 60;
                delay(700);
                random -= 300;
            }
            sprintf(img_obstacle, "Files//Images//obstacle//Obstacle %02d.jpg", obstacle);
            readimagefile(img_obstacle, random, 485, random + 130, 552);
            sprintf(img_game_chr, "Files//Images//game character//Untitled-%d.jpg", i);
            readimagefile(img_game_chr, 25, 380, 175, 552);
            sprintf(road, "Files//Images//road//sidebar%d.jpg", r);
            readimagefile(road, 0, 553, 1000, 561);
            i %= 14;
            r %= 6;
            random -= 20;
            if((random < - 600))
            {
                random = 1000;
                obstacle = rand() % 16;
                obstacle_num++;
                //printf("%d    %d\n", obstacle, dlay);
                if( !(obstacle_num % 3))
                {

                    if(obstacle_num == 6) // level up er jonno korsi.
                        break;
                    dlay -= 10;
                }
            }
            delay(dlay);
        }
    }
    // loop for walking the man from the screen
    if(life)
    {
        sndPlaySound("Files//Sound//Tada.wav", SND_FILENAME | SND_ASYNC);
        delay(1000);
        for(random = 25, i = 1; random < 1100; random += 10, i++)
        {
            sprintf(img_game_chr, "Files//Images//game character//Untitled-%d.jpg", i);
            readimagefile(img_game_chr, random, 380, random + 150, 552);
            readimagefile("Files//Images//game character//black.jpg",random - 151 , 380, random - 1, 552);
            i %= 14;
            delay(60);
        }
        return scores;
    }
    else
    {
        //scores = 0;
        sndPlaySound("Files//Sound//Game Over.wav", SND_FILENAME | SND_ASYNC);
        readimagefile("Files//Images//game character//collided.jpg", 25, 380, 175, 552);
        delay(1000);
        return 0;
    }
}


int jump(int i, int random)
{
    readimagefile("Files//Images//game character//black.jpg", 25, 380, 175, 552);
    sprintf(img_game_chr, "Files//Images//game character//Untitled-%d.jpg", i);
    readimagefile(img_game_chr, 25, 270, 175, 442);
    for(jump_stay = 1; jump_stay < 14; ++jump_stay, r++ )
    {
        if(kbhit())
            a = getch();
        sprintf(img_obstacle, "Files//Images//obstacle//Obstacle %02d.jpg", obstacle);
        readimagefile(img_obstacle, random, 485, random + 130, 552);
        sprintf(road, "Files//Images//road//sidebar%d.jpg", r);
        readimagefile(road, 0, 553, 1000, 561);
        random -= 20;
        r %= 6;
        if( random == -80)
            scores += 500;
        else if((random == - 900))
        {
            random = 1000;
            obstacle = rand() % 11;
        }
        delay(dlay);
    }
    a = 0;
    return random + 20;

}
