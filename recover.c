#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./recover IMAGE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL)
    {
        printf("Não foi possível abrir o arquivo %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int jpeg_count = 0;
    FILE *output_file = NULL;
    char filename[8];

    while (fread(buffer, 1, BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            sprintf(filename, "%03i.jpg", jpeg_count);
            jpeg_count++;

            output_file = fopen(filename, "wb");
        }

        if (output_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output_file);
        }
    }

    if (output_file != NULL)
    {
        fclose(output_file);
    }

    fclose(input_file);

    return 0;
}
