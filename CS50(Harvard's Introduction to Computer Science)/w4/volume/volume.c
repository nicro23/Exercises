// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;

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
    // if b = 2 byte then Header can equal 22
    BYTE b[HEADER_SIZE];
    fread(&b, sizeof(b), 1, input);
    fwrite(&b, sizeof(b), 1, output);

    // TODO: Read samples from input file and write updated data to output file

    // int16_t c[2];
    int16_t c;
    while (fread(&c, sizeof(int16_t), 1, input))
    {
        c *= factor;
        // alt way(remove(&))
        //  c[0] *= factor;
        //  c[1] *= factor;
        fwrite(&c, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
