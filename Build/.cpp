#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>

char img_game_chr[100];
int i, b, random = 1000, obstracle_num = 1, a, jump_stay, score_count = 0;
char score[5] = {'0', '0','0'};


int jump(int i, int random);
bool jump_check();
int collision(random );
int game()
{
    int life = 3, life_bar = 800;
    initwindow(1000, 600, "Man run cycle");
    cleardevice();
    outtextxy(50, 200, "Score:");
    readimagefile("background//Road.jpg", 0, 553, 1000, 561);
    readimagefile("background//moon.jpg", 0, 0, 1000, 192);
    readimagefile("background//Life1.jpg", 800, 200, 830, 225);
    readimagefile("background//Life1.jpg", 860, 200, 890, 225);
    readimagefile("background//Life1.jpg", 920, 200, 950, 225);
    for(i = 1; life; i++)
    {
        outtextxy(100, 200, score);
        if((kbhit()))
        {
            a = getch();
            {
                random = jump(i, random);
                readimagefile("game character//black.jpg", 25, 270, 175, 442); // make jump image black
            }

        }


        else
        {
            if( random > -90 && random < 150)  // character er size
            {
                life--;
                printf("%d\n", life);
                readimagefile("obstacle//black.jpg", 175, 485, 305, 552);
                readimagefile("obstacle//black.jpg", 0, 485, 25, 552);
                readimagefile("game character//collided.jpg", 25, 380, 175, 552);
                readimagefile("background//Life end.jpg", life_bar, 200, life_bar + 30, 225);
                life_bar += 60;
                delay(700);
                // sound of crashing
                random -= 300;
            }
            //getch();
            b = 0;
            sprintf(img_game_chr, "game character//Untitled-%d.jpg", i);
            readimagefile("obstacle//Dog1.jpg", random, 485, random + 130, 552);
            readimagefile(img_game_chr, 25, 380, 175, 552);
            i %= 14;
        random -= 20;
        if((random == - 900))
        {
            printf("%s", score);
            random = 1000;
            obstracle_num++;
        }
        delay(50);
        }

        //readimagefile("Dog1 - Copy.jpg", rand, 450, rand + 150, 552);

    }
    getchar();
    return 0;
}


int jump(int i, int random)
{
        readimagefile("game character//black.jpg", 25, 380, 175, 552);
        sprintf(img_game_chr, "game character//Untitled-%d.jpg", i);
        readimagefile(img_game_chr, 25, 270, 175, 442);
        for(jump_stay = 1; jump_stay < 20; ++jump_stay )
        {
            if(kbhit())
            a = getch();
            readimagefile("obstacle//Dog1.jpg", random, 485, random + 130, 552);
            random -= 20;
            if( random == -80)
            {
                score[1] += 2;
                if(score[1] == '8' + 2)
                {
                    score[0] += 1 ;
                    score[1] = '0';
                }
            }
            else if((random == - 900))
            {
                //score += 30;
                random = 1000;
                obstracle_num++;
            }
            delay(80);
        }
//        readimagefile(())
        a = 0;
        b = 1;
        return random + 20;

}
