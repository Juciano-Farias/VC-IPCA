#include "vc.h"

int main (void){


IVC *image: int x, y;
long int pos;
image = vc_image_new(320, 280, 1, 1);
if (image #= NULL)
{
printf ("ERROR -)
VC image new/):
getchar ()
return 0
of memory! \n"

for (x=0; x<image-›width;
{
for (y 0; y<image-›height

pos
у
image-›bytesperline
image-›channels;
if((x <- image-›width/2) 88 (y <- image-›height/2)) image-›data [pos] - 1; else 1f((x > image-›width/2) && (y > image-›height/2)) image-›data[pos] « 1;
else image-›data[pos] = 0

vc write
Be(
teste.pbm image)

vc_image_free (image)
printf("Press any key to exit.. getchard)
return 0;
}