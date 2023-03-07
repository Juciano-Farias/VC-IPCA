#include <stdio.h>
#include "vc.h"

// Abrir imagem, alterar inverte as cores e salva
int main()
{
    IVC *image;
    int i;

    image = vc_read_image("Images/FLIR/flir-01.pgm");
    if (image == NULL)
    {
        printf("ERROR -> vc_read_image(): \n\tFile not found!\n");
        getchar();
        return 0;
    }

    for (i = 0; i < image->bytesperline * image->height; i += image->channels)
    {
        image->data[i] = 255 - image->data[i];
    }

    vc_write_image("vc-0001.pgm", image);

    vc_image_free(image);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}