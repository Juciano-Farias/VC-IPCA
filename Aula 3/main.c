#include <stdio.h>
#include "vc.h"
#include <stdlib.h>

// // gray to
int main1()
{
    IVC *image;
    int x, y, resposta;
    long int pos;

    image = vc_read_image("../Images/FLIR/flir-01.pgm");
    if (image == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    vc_gray_negative(image);

    vc_write_image("teste_gray.ppm", image);

    // Windows
    system("cmd /c start  FilterGear ../Images/FLIR/flir-01.pgm"); // Input
    system("FilterGear teste_gray.ppm");                           // Output

    vc_image_free(image);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}

// // //RBG_TO_GRAY
int main2()
{
    IVC *image;
    int x, y, resposta;
    long int pos;

    image = vc_read_image("../Images/Classic/airplane.ppm");
    if (image == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    vc_rbg_negative(image);

    vc_write_image("teste_colorido.ppm", image);

    // Windows
    system("cmd /c start  FilterGear ../Images/Classic/airplane.ppm"); // Input
    system("FilterGear teste_colorido.ppm");                               // Output

    vc_image_free(image);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}

// red to gray
int main3()
{
    IVC *image;
    int x, y;
    long int pos;

    image = vc_read_image("../Images/Classic/baboon.ppm");
    if (image == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    // red to gray
    vc_rgb_get_red_gray(image);

    vc_write_image("red_to_gray.ppm", image);

    vc_image_free(image);

    // green to gray
    image = vc_read_image("../Images/Classic/baboon.ppm");

    vc_rgb_get_green_gray(image);

    vc_write_image("green_to_gray.ppm", image);

    vc_image_free(image);

    // blue to gray
    image = vc_read_image("../Images/Classic/baboon.ppm");

    vc_rgb_get_blue_gray(image);

    vc_write_image("blue_to_gray.ppm", image);

    vc_image_free(image);

    // blue to blue
    image = vc_read_image("../Images/Classic/baboon.ppm");

    vc_rgb_get_blue(image);

    vc_write_image("blue_to_blue.ppm", image);

    vc_image_free(image);

    // blue to green
    image = vc_read_image("../Images/Classic/baboon.ppm");

    vc_rgb_get_green(image);

    vc_write_image("green_to_green.ppm", image);

    vc_image_free(image);

    // blue to red
    image = vc_read_image("../Images/Classic/baboon.ppm");

    vc_rgb_get_red(image);

    vc_write_image("red_to_red.ppm", image);

    vc_image_free(image);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}

// // rbg para tons de cinza
int main4()
{
    IVC *src, *dst;
    int x, y, resposta;
    long int pos;

    src = vc_read_image("../Images/Additional/fruits.ppm");
    dst = vc_image_new(src->width, src->height, 1, src->levels);
    if (src == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    resposta = vc_rgb_to_gray(src, dst);

    if (resposta == 0)
    {
        printf("ERROR -> vc_rgb_to_gray(): \n\tAlgo correu mal na execucao\n");
        return 0;
    }
    vc_write_image("red_to_gray.pgm", dst);

    // Windows
    system("cmd /c start  FilterGear ../Images/Additional/fruits.ppm"); // Input
    system("FilterGear red_to_gray.pgm");                               // Output

    vc_image_free(src);
    vc_image_free(dst);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}

// converte RGB em HSV
int main5()
{
    IVC *src, *dst;
    int x, y, resposta;
    long int pos;

    src = vc_read_image("../Images/Classic/airplane.ppm");
    dst = vc_image_new(src->width, src->height, 3, 255);
    if (src == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    resposta = vc_rgb_to_hsv(src, dst);

    if (resposta == 1)
    {
        vc_write_image("rgb_to_hsv.ppm", dst);
    }

    // Windows
    system("cmd /c start FilterGear ../Images/Classic/airplane.ppm"); // Input
    system("FilterGear hrgb_to_hsv.ppm");               // Output

    vc_image_free(src);
    vc_image_free(dst);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}

/*Construa uma fun????o que receba uma imagem HSV e retorne uma
imagem com 1 canal (admitindo valores entre 0 e 255 por pixel).
Essa fun????o dever?? receber ainda os intervalos de valores da Matiz
(H), Satura????o (S) e Brilho (V) da cor que se pretende segmentar. A
imagem de sa??da dever?? apresentar a branco (255) os pix??is que
est??o dentro desse intervalo, e a preto (0) todos os outros.*/
int main()
{
    IVC *src, *dst;
    int x, y, resposta;
    long int pos;

    src = vc_read_image("../Images/HSVTestImage01.ppm");
    dst = vc_image_new(src->width, src->height, 1, src->levels);
    if (src == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    resposta = vc_hsv_segmentation(src, dst, 0, 255, 0, 255, 0, 100);

    if (resposta == 1)
    {
        vc_write_image("hsv_degmentation.pgm", dst);
    }

    // Windows
    system("cmd /c start FilterGear ../Images/HSVTestImage01.ppm"); // Input
    system("FilterGear hsv_degmentation.pgm");         // Output

    vc_image_free(src);
    vc_image_free(dst);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}

int main7()
{
    IVC *src, *dst;
    int x, y, resposta;
    long int pos;

    src = vc_read_image("../Images/FLIR/flir-01.pgm");
    dst = vc_image_new(src->width, src->height, 3, src->levels);
    if (src == NULL)
    {
        printf("ERROR -> vc_image_new(): \n\tOut of memory!\n");
        getchar();
        return 0;
    }

    resposta = vc_scale_gray_to_rgb(src, dst);

    if (resposta == 1)
    {
        vc_write_image("new_rbg.ppm", dst);
    }

    // Windows
    system("cmd /c start FilterGear ../Images/FLIR/flir-01.pgm"); // Input
    system("FilterGear new_rbg.ppm");                             // Output

    vc_image_free(src);
    vc_image_free(dst);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}