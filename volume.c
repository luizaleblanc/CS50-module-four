#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // <-- ADICIONADO AQUI

const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Uso: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Não foi possível criar o arquivo de saída.\n");
        fclose(input);
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE];

    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Linha principal corrigida com round()
        buffer = round(buffer * factor);
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}