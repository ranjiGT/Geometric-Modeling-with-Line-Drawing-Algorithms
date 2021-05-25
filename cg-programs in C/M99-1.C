#include<stdio.h>
#include<graphics.h>



void main(void)
{
	int xc,yc;
	int gd,gm,r;

	clrscr();
	printf("\n\n\tEnter the center : ");
	scanf("%d %d",&xc,&yc);
	printf("\n\n\tEnter the radius : ");
	scanf("%d",&r);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");

	line(xc-r,yc, xc+r,yc);
	line(xc,yc-r, xc,yc+r);

	line(xc,yc-r,xc+r,yc-r);
	line(xc+r,yc-r,xc+r,yc);

	line(xc,yc, xc-r,yc);
	line(xc-r,yc,xc-r,yc+r);
	line(xc-r,yc+r,xc,yc+r);


	circular(xc,yc,r);

	setfillstyle(SOLID_FILL, RED);
	floodfill(xc+10,yc+10,WHITE);
	floodfill(xc-10,yc-10,WHITE);

	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(xc+10,yc-10,WHITE);
	floodfill(xc-10,yc+10,WHITE);

	getch();


}

circular(int xc, int yc, int r)
{

	int x1, y1,p;

	x1=0; y1=r;
	p = 1 - r;

	while (x1<=y1)
	{
		 putpixel(xc+x1,yc+y1,WHITE);
		 putpixel(yc+y1,xc+x1,WHITE);
		 putpixel(xc-x1,yc-y1,WHITE);
		 putpixel(yc-y1,xc-x1,WHITE);


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
}

/************************ M99-1.C **************************************/
