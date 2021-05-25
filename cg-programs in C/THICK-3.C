/*-Thick line drawing- 2  -*/
/*************************************************************/




#include<math.h>
#include<stdio.h>
#include<graphics.h>

main()
{

	int i,gd,gm,w;
	int x,y, x1,y1,x2,y2;
	int xa,ya,xb,yb,xc,yc,xd,yd;
	double theta,m1,m;
	float tx,ty;

	clrscr();

	printf("Enter the co-ordinates of first point (x1 y1) : ");
	scanf("%d %d",&x1,&y1);
	printf("Enter the co-ordinates of second point (x2 y2): ");
	scanf("%d %d",&x2,&y2);

	printf("Enter width of line : ");
	scanf("%d",&w);

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");


	m = (double)(y2-y1)/(x2-x1);
	m1 = -(1.0/m);

	theta = atan(abs(m1));
	tx = (w/2)* cos(theta);
	ty = (w/2)* sin(theta);

	xa = x1 - tx;       ya = y1 + ty;
	xb = x1 + tx;       yb = y1 - ty;
	xc = x2 - tx;       yc = y2 + ty;
	xd = x2 + tx;       yd = y2 - ty;


	ddaline( xa, ya, xb, yb );
	ddaline( xc, yc, xd, yd );
	ddaline( xa, ya, xc, yc );
	ddaline( xb, yb, xd, yd );

	x = x1+2;
	y = y1+2;

	fill_right( x, y );
	fill_left( x-1, y );

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
		putpixel(x, y, RED);

		x = x + xi;
		y = y + yi;

	}

}

/*----------------------------------------------------------*/

	fill_right(x,y)
	int x , y ;
	{
	   if(getpixel(x,y) == 0)
	   {
		putpixel(x,y,RED);
		fill_right(++x,y);
		x = x - 1 ;
		fill_right(x,y-1);
		fill_right(x,y+1);

	   }
	}

	fill_left(x,y)
	int x , y ;
	{
	   if(getpixel(x,y) == 0)
	   {
		putpixel(x,y,RED);

		fill_left(--x,y);
		x = x + 1 ;
		fill_left(x,y-1);
		fill_left(x,y+1);

	   }
	}

/***********************************************************/



