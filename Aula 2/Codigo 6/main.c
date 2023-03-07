#include <stdio.h>
#include "vc.h"

// Cria imagem, preenche e salva.
int main()
{
    IVC *image;
    int x, y;
    long int pos;

    image = vc_image_new(256, 256, 1, 255);
    if (image == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    for (x = 0; x < image->width; x++)
    {
        for (y = 0; y < image->height; y++)
        {
            pos = y * image->bytesperline + x * image->channels;

            image->data[pos] = 0 + (unsigned char)(x + y)/2;
        }
    }

    vc_write_image("gradiente3.pbm", image);

    vc_image_free(image);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}