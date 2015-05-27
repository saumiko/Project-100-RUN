#include <stdio.h>
#include <graphics.h>

void intro()
{
    char image[500], press[100] = {"Files//Images//img//2.jpg"};
    int count, i, time = 0, check;
    sprintf(image, "Files//Images//img//Man Run 095.jpg");
    readimagefile(image, 0, 0, 1000, 600);
    delay(1000);

    sndPlaySound("Files//Sound//Nostalgia.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    for(i = 95; ; i++)
    {
        if(kbhit())
           check =  getch();
        sprintf(image, "Files//Images//img//Man Run %0.3d.jpg", i);
        readimagefile(image, 0, 0, 1000, 600);
        delay(2);
        if(i == 440)
            break;
    }


    for(i =280; i < 501; i++)
    {
        sprintf(image, "Files//Images//img//Man Run %0.3d.jpg", i);
        readimagefile(image, 0, 0, getmaxx(), getmaxy());
        readimagefile("Files//Images//img//2.jpg", 350, 525, 650, 600);

        delay(2);
        if(i == 440)
        {
            i = 280;
        }
        else if (kbhit())
            return;
    }

    return;
}
