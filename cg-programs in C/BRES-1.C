/*-Bresenham algo. -*/
/*************************************************************/

#include<stdio.h>
#include <graphics.h>

main()
{
	int dx,dy,x,y,p,x1,y1,x2,y2;
	int k,gd,gm;

	clrscr();

	printf("\n\n\tEnter the co-ordinates of first point : ");
	scanf("%d %d",&x1,&y1);
	printf("\n\n\tEnter the co-ordinates of second point : ");
	scanf("%d %d",&x2,&y2);

	dx = (x2 - x1);
	dy = (y2 - y1);

	p = 2 * (dy) - (dx);

	x = x1;
	y = y1;

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");

	putpixel(x,y,WHITE);

	for(k=0; k<=abs(dx); k++)
	{
		x++;
		if(p < 0)
			p = p + 2 * (dy);
		else
		{
			y++;
			p = p + 2 * (dy - dx);
		}
		putpixel(x,y,WHITE);
	}

	getch();
	closegraph();

}/*-main()-*/
/***************************** 	BRESENHAM.C ****************************/

