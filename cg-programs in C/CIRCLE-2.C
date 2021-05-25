/*- Circle -*/
/*************************************************************/

#include<math.h>
#include<stdio.h>
#include <graphics.h>


void main(void)
{

	int xc,yc,i,x,y,r,p,x1,y1;
	int gd,gm;
	float theta;

	clrscr();
	printf("\n\n\tEnter the center of circle : ");
	scanf("%d %d",&xc,&yc);
	printf("\n\n\tEnter the radius of circle : ");
	scanf("%d",&r);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");

	for(i=0;i<=360;i++)
	{
	   theta=(i*3.14)/180;

	   x = (int)(xc+(r*cos(theta)));
	   y = (int)(yc+(r*sin(theta)));

	   putpixel(x,y,WHITE);

	}

	getch();

}/*-main()-*/

/**************************************************************/




