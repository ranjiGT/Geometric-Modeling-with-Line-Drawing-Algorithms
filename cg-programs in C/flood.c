/*- Test program

flood fill algo. using user defined function
(incomplete programme  -*/
/******************************************************/

	#include<stdio.h>
	#include<graphics.h>
	#include<dos.h>

	void fill(x,y)
	int x , y ;
	{
	   if((getpixel(x,y) == 0))
	   {
		delay(1);
		putpixel(x,y,RED);
		fill(x,y+1);
		fill(x-1,y);
		fill(x,y-1);
		fill(x+1,y+1);

	   }
	}

/*------------------------------------------------------*/

	void main()
	{
		int x , y ,a[10][10];
		int gd, gm ,n,i;

		detectgraph(&gd,&gm);
		initgraph(&gd,&gm," ");

		rectangle(150,150,210,210);

		x =205, y=205;

		fill(x,y);

		getch();
	}

/*******************************************************/