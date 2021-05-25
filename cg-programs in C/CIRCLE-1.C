/*- Circle -*/
/*************************************************************/

#include<stdio.h>
#include<graphics.h>


void plotpoints(int, int, int, int );

void main(void)
{

	int x,y,r,p,x1,y1;
	int gd,gm;

	clrscr();
	printf("\n\n\tEnter the center of circle : ");
	scanf("%d %d",&x,&y);
	printf("\n\n\tEnter the radius of circle : ");
	scanf("%d",&r);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");

	x1=0; y1=r;
	p = 1 - r;


	while (x1<=y1)
	{
		plotpoints(x,y,x1,y1);
		if(p<0)
		{
			p = p + 2 * x1 + 3;
		}
		else
		{
			p = p + 2 * (x1-y1) + 5;
			y1--;
		}

		x1++;
	}
	getch();
	closegraph();

}/*-main()-*/

/**************************************************************/

void plotpoints(int a,int b,int c,int d)
{

	putpixel(a+c,b+d,WHITE);
	putpixel(a-c,b+d,WHITE);
	putpixel(a+c,b-d,WHITE);
	putpixel(a-c,b-d,WHITE);

	putpixel(a+d,b+c,WHITE);
	putpixel(a-d,b+c,WHITE);
	putpixel(a+d,b-c,WHITE);
	putpixel(a-d,b-c,WHITE);

	getch();
}
/*--------------------------------------------------------*/

