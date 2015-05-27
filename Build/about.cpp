#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>

void about()
{
    cleardevice();
    int i;
    char about[500];
    //readimagefile("Buttons//About.jpg", 0, 0, 1000, 600);
    for(i = 3; i < 38; i++)
    {
        sprintf(about, "Files//Images//about//A %0.2d.jpg", i);
        readimagefile(about, 0, 0, 1000, 600);
        delay(8);
        if(kbhit())
            getch();
    }
    sprintf(about, "Files//Images//about//A %0.2d.jpg", i);
    readimagefile(about, 0, 0, 1000, 600);
    //printf("%d", i);
    delay(1000);
    if(kbhit())
        getch();


    while(i < 90)
    {
        sprintf(about, "Files//Images//about//A %0.2d.jpg", i);
        readimagefile(about, 0, 0, 1000, 600);
        delay(8);
        i++;
        if(kbhit())
            getch();
    }
    if(kbhit)
    {

        getch();
        return;
    }
}
