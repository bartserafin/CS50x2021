#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: /recovoer image");
        return 1;
    }

    // open memory card
    FILE *file = fopen(argv[1], "r");
    FILE *image = NULL;

    // check if valid command line argument
    if (file == 0)
    {
        printf("File cannot be open.");
        return 1;
    }

    int counter = 0;
    BYTE buffer[512];
    char name[8];

    // read every 512 byte chunks
    while (fread(buffer, sizeof(BYTE), 512, file))
    {
        //check header if jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //check if this is first jpeg found
            if (counter == 0)
            {
                // write jpeg
                sprintf(name, "%03i.jpg", counter);
                image = fopen(name, "w");
                counter++;
            }
            else
            {
                // close and look for new jpeg
                fclose(image);
                sprintf(name, "%03i.jpg", counter);
                image = fopen(name, "w");
                counter++;
            }
            fwrite(buffer, sizeof(BYTE), 512, image);
        }

        // if another jpeg found
        else if (counter != 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, image);
        }
    }
    fclose(image);
}