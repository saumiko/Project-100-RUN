#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>

void help()
{
    cleardevice();
    int i;
    char help[500];
    //readimagefile("Buttons//Help.jpg", 0, 0, 1000, 600);
    for(i = 1; i < 114; i++)
    {
        sprintf(help, "Files//Images//Help//H %0.3d.jpg", i);
        readimagefile(help, 0, 0, 1000, 600);
        delay(10);
        if(kbhit())
            getch();
    }

    if(kbhit)
    {
        getch();
        return;
    }
}
