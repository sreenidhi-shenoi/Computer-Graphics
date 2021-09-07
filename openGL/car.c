#include <graphics.h>
int main()
{
   int i, j = 0, gd = DETECT, gm;  // gd - graph driver,  gm - graph mode
	
// if gd = DETECT, then initgraph autodetect the attached video adapter at run time and pick the corresponding driver. initgraph calls detectgraph to select a graphics driver and mode.

 
// graphics driver initialization 
// arguments - graphdriver, graph mode, path

   initgraph(&gd,&gm,NULL);  // loads a graphics driver and change into graphics mode.
 
 
   outtextxy(25,240,"Press any key to view the moving car");
 
   getch();
 
   for( i = 0 ; i <= 420 ; i = i + 10, j++ )                      
   {
      rectangle(50+i,275,150+i,400);  // draw rectangle
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(175+i,410,10); // draw circle
      setcolor(j);  // set the drawing color
      delay(100);
 
      if( i == 420 )
         break;
      if ( j == 15 )
         j = 2;
 
      cleardevice(); // clear screen
   }
 
   getch();
   closegraph();
   return 0;
}
