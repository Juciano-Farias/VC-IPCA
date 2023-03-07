#include <stdio.h>
#include "vc.h"

// Abrir imagem, alterar e gravar em um novo ficheiro
int main()
{
    IVC *image;
    int i;

    image = vc_read_image("teste.pbm");
    if (image == NULL)
    {
        printf("ERROR -> vc_read_image(): \n\tFile not found!\n");
        getchar();
        return 0;
    }

    for (i=0; i<image->bytesperline*image->height; i+=image->channels)
    {
        if(image->data[i] == 1) image->data[i] = 0;
        else image->data[i] = 1;
    }

    vc_write_image("teste2.pbm", image);

    vc_image_free(image);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}