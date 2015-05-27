#include <stdio.h>
#include <graphics.h>


void menu()
{
    char img_dog[500], img_chr[500];
    int dog, chr;
    int cordinate = 1000;
    sndPlaySound("Files//Sound//Scream_04.wav", SND_FILENAME | SND_ASYNC);
    delay(1500);
    sndPlaySound("Files//Sound//07 Dog barking For ajaira intro.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);

    for(dog = 1, chr = 1; cordinate > -350; dog++, chr++)
    {
        sprintf(img_chr, "Files//Images//Final R-L//Untitled-%d.jpg", chr);
        readimagefile(img_chr, cordinate - 300, 100, cordinate, 500);
        if(chr == 14)
        {
            chr %= 14;
        };
        delay(20);
        sprintf(img_dog, "Files//Images//Cropped Dog R-L//%d.jpg", dog);
        dog %= 9;
        readimagefile(img_dog, cordinate + 100, 320, cordinate + 300, 520);
        //delay(30);
        cordinate -= 5;
    }

    return;
}
