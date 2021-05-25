/*-Thick line drawing- 2  -*/
/*************************************************************/


#include<math.h>
#include<stdio.h>
#include<graphics.h>

main()
{

	int i,gd,gm;
	int x1,y1,x2,y2,w;


	clrscr();

	printf("Enter the co-ordinates of first point (x1 y1) : ");
	scanf("%d %d",&x1,&y1);
	printf("Enter the co-ordinates of second point (x2 y2): ");
	scanf("%d %d",&x2,&y2);

	printf("Enter width of line : ");
	scanf("%d",&w);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");

	for(i=1; i<=w; i++)
	{
	  ddaline(x1,y1++,x2,y2++);
	}
	getch();
	closegraph();

 }

/*------------------------------------------------------*/

 ddaline(x1,y1,x2,y2)
 int x1,y1,x2,y2;
 {
	float xi,yi,x,y;
	int dx,dy,steps,k;

	dx = x2 - x1;
	dy = y2 - y1;

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
		putpixel(x, y, WHITE);

		x = x + xi;
		y = y + yi;

	}

}

/***********************************************************/



