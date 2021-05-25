/* This is Line Clipping Algorithm  using midpoint subdivision  -*/


/*

   Kiran T. Talele.
   MGM College of Engg.
   New Bombay - 410 206

*/
/*************************************************************/




#include <stdio.h>
#include <graphics.h>
#include <math.h>





main()
{


	int 	gd,gm;
	int 	a[10][10],x,y,i,j;
	int	xmin,ymin,xmax,ymax;
	int 	x1,y1,x2,y2;
	float 	m,dy,dx;


	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");


	printf("\n\n\tEnter the co-ordinates of Line :");

	for(i=0;i<2;i++)
	{
		printf("\n\n\tX%d  Y%d  :  ",i,i);
		scanf("%d %d",&a[i][0],&a[i][1]);
	}

	printf("\n\tEnter the co_ordinates of window  :\n ");
	printf("\n\txmin , ymin  : ");
	scanf("%d %d",&xmin,&ymin);
	printf("\n\txmax , ymax  : ");
	scanf("%d %d",&xmax,&ymax);


	cleardevice();
	setcolor(35);

	line(a[0][0],a[0][1],a[1][0],a[1][1]);

	setcolor(35);
	rectangle(xmin,ymin,xmax,ymax);


	dy = y2 - y1;
	dx = x2 - x1;

	if((dx!=0)&&(dy!=0))
	{
		m=(dy/dx);
	}



/*- xmin -*/

	if( (a[0][0]<xmin)&&(a[1][0]>xmin) )
	{

	   x1 = a[0][0];
	   y1 = a[0][1];

	   x2 = a[1][0];
	   y2 = a[1][1];


	   do
	   {
		x = (int)( x1 + x2 ) / 2;
		y = (int)( y1 + y2 ) / 2;


		if( x < xmin)
		{
		    x1 = x;
		    y1 = y;
		}
		else
		{
		   x2 = x;
		   y2 = y;
		}

	   }while(x != xmin);

	   a[0][0] = x;
	   a[0][1] = y;

	}


	getch();
	cleardevice();
	setcolor(35);
	rectangle(xmin,ymin,xmax,ymax);
	setcolor(63);
	line(a[0][0],a[0][1],a[1][0],a[1][1]);


/*-xmax-*/

	if( (a[0][0]<xmax)&&(a[1][0]>xmax) )
	{

	   x1 = a[0][0];
	   y1 = a[0][1];

	   x2 = a[1][0];
	   y2 = a[1][1];

	   do
	   {
		x = (int)( x1 + x2 ) / 2;
		y = (int)( y1 + y2 ) / 2;


		if( x < xmax)
		{
		    x1 = x;
		    y1 = y;
		}
		else
		{
		   x2 = x;
		   y2 = y;
		}

	   }while(x != xmax);

	   a[1][0] = x;
	   a[1][1] = y;

	}


	getch();
	cleardevice();
	setcolor(35);
	rectangle(xmin,ymin,xmax,ymax);
	setcolor(63);
	line(a[0][0],a[0][1],a[1][0],a[1][1]);

	getch();
	getch();


}/*-main()-*/

/*-***********************************************************-*/


