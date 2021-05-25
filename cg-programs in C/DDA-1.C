/*-DDA Algo -*/
/*************************************************************/


#include<math.h>
#include<stdio.h>
#include<graphics.h>

main()
{

	int gd,gm;
	float xi,yi,x,y;
	int x1,y1,x2,y2,dx,dy,steps,k;

	clrscr();

	printf("Enter the co-ordinates of first point (x1 y1) : ");
	scanf("%d %d",&x1,&y1);
	printf("Enter the co-ordinates of second point (x2 y2): ");
	scanf("%d %d",&x2,&y2);

	dx = x2 - x1;
	dy = y2 - y1;

	if(abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xi = (float)dx/steps;
	yi = (float)dy/steps;

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");

	x = x1;
	y = y1;

	for(k=0;k<=steps;k++)
	{
		putpixel(x, y, WHITE);

		x = x + xi;
		y = y + yi;

	}

	getch();
	closegraph();

}/*-main()-*/

/***************************** DDALINE.C *************************/



