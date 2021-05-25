/*- Modified DDA algo -*/
/****************************************************************/

#include<math.h>
#include<stdio.h>
#include<graphics.h>

main()
{

	int   gd,gm;
	float xi,yi,x,y;
	int   x1,y1,x2,y2,dx,dy,steps,k;
	int   xo,yo,xmax,ymax;

	clrscr();

	printf("\n\n\tEnter the co-ordinates of first point : ");
	scanf("%d %d",&x1,&y1);
	printf("\n\n\tEnter the co-ordinates of second point : ");
	scanf("%d %d",&x2,&y2);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");

	xmax = 640; ymax = 480;
	xo = xmax/2; yo = ymax/2;

	line(320,0,320,480);
	line(0,240,640,240);

	dx = (x2 - x1);
	dy = (y2 - y1);

	if(abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xi = (float)dx/steps;
	yi = (float)dy/steps;

	x = x1;
	y = y1;

	for(k=0;k<=steps;k++)
	{
		putpixel(xo+x, ymax-(yo+y), WHITE);

		x = x + xi;
		y = y + yi;
	}

	getch();
	closegraph();

}/*-main()-*/

/***************************** 	DDAline ****************************/

