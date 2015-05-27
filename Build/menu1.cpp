#include<stdio.h>
#include<graphics.h>

int check = 1;
int menu1()
{
    char img_dog[520], buttons[500];
    int i = 110,  count = 1, dog, green = 135;
    cleardevice();
    readimagefile("Files//Images//Game Logo.jpg", 400, 445, 570, 525);
    delay(800);
    readimagefile("Files//Images//background//Road.jpg", 0, 553, 1000, 561);
    readimagefile("Files//Images//background//moon.jpg", 0, 0, 1000, 192);
    readimagefile("Files//Images//buttons//1 g.jpg", 135, 340, 230, 400);
    readimagefile("Files//Images//buttons//2 y.jpg", 335, 340, 430, 400);
    readimagefile("Files//Images//buttons//3 y.jpg", 535, 340, 630, 400);
    readimagefile("Files//Images//buttons//4 y.jpg", 735, 340, 830, 400);
    readimagefile("Files//Images//Cropped Dog L-R//9.jpg", i, 260, i + 140, 340);
    sndPlaySound("Files//Sound//nosound.wav", SND_FILENAME | SND_ASYNC);

    while(1)
    {
        if(kbhit())
        {
            check = getch();
            if(check == 13)
            {
                sprintf(buttons, "Files//Images//buttons//%d r.jpg", count);
                readimagefile(buttons, green, 340, green + 95, 400);
                delay(1000);
                sprintf(buttons, "Files//Images//buttons//%d g.jpg", count);
                readimagefile(buttons, green, 340, green + 95, 400);


                return count;
            }
            if(check == 77)   //right arrow
            {
                if(count == 4)
                    continue;
                sndPlaySound("Files//Sound//07 Dog barking for menu.wav", SND_FILENAME | SND_ASYNC);
                for(dog = 1; dog < 10; dog++)
                {
                    sprintf(img_dog, "Files//Images//Cropped Dog L-R//%d.jpg", dog);
                    readimagefile(img_dog, i, 260, i + 140, 340); // i = 120
                    readimagefile("Files//Images//Cropped Dog L-R//black.jpg", i - 150, 260, i, 340);
                    i += 22;
                    delay(50);
                }
                sprintf(buttons, "Files//Images//buttons//%d y.jpg", count);
                readimagefile(buttons, green, 340, green + 95, 400);
                count++;
                green += 200;
                sprintf(buttons, "Files//Images//buttons//%d g.jpg", count);
                readimagefile(buttons, green, 340, green + 95, 400);
            }
            if(check == 75) // left arrow
            {
                if(count == 1)
                    continue;
                sndPlaySound("Files//Sound//07 Dog barking for menu.wav", SND_FILENAME | SND_ASYNC);
                for(dog = 1; dog < 10; dog++)
                {
                    sprintf(img_dog, "Files//Images//Cropped Dog R-L//%d.jpg", dog);
                    readimagefile(img_dog, i, 260, i + 140, 340); // i = 120
                    readimagefile("Files//Images//Cropped Dog L-R//black.jpg", i + 141, 260, i + 281, 340);
                    i -= 22;
                    delay(50);
                }
                sprintf(buttons, "Files//Images//buttons//%d y.jpg", count);
                readimagefile(buttons, green, 340, green + 95, 400);
                count--;
                green -= 200;
                sprintf(buttons, "Files//Images//buttons//%d g.jpg", count);
                readimagefile(buttons, green, 340, green + 95, 400);
            }
        }
    }
    return count;
}
