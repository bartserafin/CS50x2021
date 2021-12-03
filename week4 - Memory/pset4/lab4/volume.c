// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    
    // make arry for header
    // data type name[amount of bytes]
    uint8_t header[HEADER_SIZE];
    
    // read(to variable header, , headersize bytes, how many headersuze bytes? - 1, from input file)
    fread(header, HEADER_SIZE, 1, input);
    //write (contentes of varialbe header, headersize bytes, how many headersuze bytes? - 1, to outputfile)
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    
    // variable that stores integer with 16 bits
    int16_t buffer;
    
    // loop to read and write
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // update volume
        buffer *= factor;
        
        //write(path to buffer, int16_t, 1 byte, to file output)
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
