#include "raster.h"

void plot_bitmap_16 (UINT16 *base, int x, int y, const UINT16 *bitmap,
                     unsigned int height)

{

int offset = (y *40 ) + (x >>4);
int remainder = x % 16;

unsigned int right;

unsigned int left;

int counter = 0;

if( (y >=0) && (y + height < 400) && (x >=0) && (x + 16 < 640))
{

     if (remainder == 0){

           while (counter < height){

            *(base + offset + 40 * counter) = bitmap[counter];
             counter++;
             
         }
       }

     else
{
 
          while (counter < height){
          
          right = bitmap[counter];
          right = right << (16-remainder);
          *(base + offset + 40 * counter + 1) = right;

          left = bitmap[counter];
          left = left >> remainder;
          *(base +offset + 40 * counter ) = left;
          counter ++;         


        }

     }  
 
  }	
}

void plot_bitmap_8 (char *base, int x , int y, const UINT8 *bitmap,
                   unsigned int height)
{

int offset = (y * 80) + ( x >> 3);

int remainder = x % 8;

unsigned int right;

unsigned int left;

int counter = 0;

if ( (y >=0) && (y + height < 400) && (x >=0) && (x + 8 < 640))
   {

     if (remainder == 0 ){
            while (counter < height){

            *(base + offset + 80 * counter) = bitmap[counter];
            counter++;
          }
       }

     else
{
          while (counter < height){

          right = bitmap[counter];
          right = right << (8-remainder);
          *(base + offset + 80 * counter + 1) = right;

          left = bitmap[counter];
          left = left >> remainder;
          *(base + offset + 80 * counter ) = left;
          counter++;      
   
          }
       }

     }
 }
     

void plot_pixel (char *base, int x, int y)
{

     if (x >= 0 && x < 640 && y >= 0 && y < 400)
            *(base + y * 80 + (x >> 3)) |= 1 << (7- (x & 7));

                  
}





void plot_line (char *base, int x1, int y1, int x2, int y2)
{

     int x = x1;
     int y = y1;
     int dx = x2-x1;
     int dy = y2- y1;

     int p = 2*dy - dx;


     while (x < x2 || y < y2 )

     {

        plot_pixel(base, x , y);

        if(dx != 0)
        {
          x++;
        }

        if (p < 0)
         {
           p = p + 2 * dy;
         }

        else
       {
         p = p +2 *dy - 2*dx;

         if(dy != 0)
        {
           y++;

            }


        }    

    
      }
} 


void plot_rectangle (char * base, int x, int y, int width, int length)
{

   plot_line(base,x, y, x + width, y);

   plot_line(base,x + width, y, x +width, y +length);

   plot_line(base,x , y + length, x + width, y + length);

   plot_line(base,x , y, x, y + length);
}

void clear_line( UINT16 *base, int x, int y, int width)
{
  int counter =0;
  int x1 = width >> 4;

   *(base + (y * 40) + ( x >> 4));
   
   while(counter < x1)
   {
     *(base++) = 0x0000;
     counter++;
   }
   
}

void clear_screen( UINT16 *base,int width, int height)
{
  int counter =0;
  while(counter < height)
  {
   clear_line(base,0,0,width);
   base = base + 40;
   counter++;
  }
}
 
 
