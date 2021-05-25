/*-Modified Bresenham algo. Right Handed system -*/
/*************************************************************/

#include<stdio.h>
#include <graphics.h>

main()
{
	int k,dx,dy,x,y,p,x1,y1,x2,y2;
	int gd,gm,xincre,yincre ;

	clrscr();

	printf("\n\n\tEnter the co-ordinates of first point : ");
	scanf("%d %d",&x1,&y1);
	printf("\n\n\tEnter the co-ordinates of second point : ");
	scanf("%d %d",&x2,&y2);

	dx = (x2 - x1);
	dy = (y2 - y1);

	p = 2 * abs(dy) - abs(dx);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");


	x = x1;  y = y1;

	putpixel(x, y, WHITE);

	xincre = dx/abs(dx);
	yincre = dy/abs(dy);

	if(abs(dy) < abs(dx))
	{
	   for(k=0; k<=abs(dx); k++)
	   {
		x = x + xincre;

		if(p < 0)
			p = p + 2 * abs(dy);
		else
		{
			y = y + yincre;
			p = p + 2 * (abs(dy) - abs(dx));
		}

		putpixel(x, y, WHITE);
	   }
	}
	else
	{
	   for(k=0; k<=abs(dy); k++)
	   {
		y = y + yincre;

		if(p < 0)
			p = p + 2 * abs(dx);
		else
		{
			x = x + xincre;
			p = p + 2 * (abs(dx) - abs(dy));
		}

		putpixel(x, y, WHITE);
	   }
	}

	getch();
	closegraph();

}/*-main()-*/

/***************************** 	BRESENHAM.C ****************************/

