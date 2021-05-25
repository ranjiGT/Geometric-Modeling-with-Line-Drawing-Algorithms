
/* This is new polygon clipping algo.  */
/******************************************************************/

#include <math.h>
#include <stdio.h>
#include <graphics.h>



int 	n,p,x,y,i,j;
int 	xwmin,ywmin,xwmax,ywmax;
int 	x1,y1,x2,y2,xmax,ymax;
float 	m;
char 	flag;
float 	dy,dx;

main()
{


	int gd,gm;
	int a[10][10],b[10][10],c[10][10],d[10][10],e[10][10];

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");


	printf("\n\n\tEnter the no. of edges of polygon :  ");
	scanf("%d",&n);

	printf("\n\n\tEnter the cordinates  of  polygon :\n\n\n ");

	for(i=0;i<n;i++)
	{
		printf("\tX%d  Y%d  :  ",i,i);
		scanf("%d %d",&a[i][0],&a[i][1]);
	}

	a[n][0]=a[0][0];
	a[n][1]=a[0][1];


	printf("\n\tEnter the co_ordinates of window  :\n ");
	printf("\n\txwmin , ywmin  : ");
	scanf("%d %d",&xwmin,&ywmin);
	printf("\n\txwmax , ywmax  : ");
	scanf("%d %d",&xwmax,&ywmax);


	xmax = 640; ymax = 480;

	cleardevice();

	setcolor(35);
	for(i=0;i<n;i++)
	{
		line(a[i][0],ymax-a[i][1],a[i+1][0],ymax-a[i+1][1]);
	}
	rectangle(xwmin,ymax-ywmin,xwmax,ymax-ywmax);
	getch();
	setcolor(35);

	clip_left(a,b);
	clip_right(b,c);
	clip_bottom(c,d);
	clip_top(d,e);

	cleardevice();
	setcolor(63);
	for(i=0;i<p;i++)
	{
		line(e[i][0],ymax-e[i][1],e[i+1][0],ymax-e[i+1][1]);
	}
	getch();




}/*-main()-*/

/*---------------------------------------------------------------*/

clip_left(int a[10][10], int b[10][10])
{

	p=0;flag=0;m=0;
	for(i=0;i<n;i++)
	{

		dy=a[i+1][1]-a[i][1];
		dx=a[i+1][0]-a[i][0];


		if((dx!=0)&&(dy!=0))
		{
			m=(dy/dx);
		}

		if((a[i][0]<xwmin)&&(a[i+1][0]>=xwmin) ) 	flag=0;
		if((a[i][0]>=xwmin)&&(a[i+1][0]>=xwmin)) 	flag=1;
		if((a[i][0]>=xwmin)&&(a[i+1][0]<xwmin))  	flag=2;
		if((a[i][0]<xwmin)&&(a[i+1][0]<xwmin) )  	flag=3;


		switch(flag)
		{
			case 0 :
				x=xwmin;
				if(dy!=0)
				    y=(int)(a[i][1]+m*(x-a[i][0]));
				else
				    y=a[i][1];

				b[p][0]=x;
				b[p][1]=y;
				p++;

				b[p][0]=a[i+1][0];
				b[p][1]=a[i+1][1];
				p++;
				break;

			case 1 :
				b[p][0]=a[i+1][0];
				b[p][1]=a[i+1][1];
				p++;
				break;

			case 2 :
				x=xwmin;
				if(dy!=0)
				    y=(int)(a[i][1]+m*(x-a[i][0]));
				else
				    y=a[i][1];

				b[p][0]=x;
				b[p][1]=y;
				p++;
		}


	}/*-for()-*/

	b[p][0]=b[0][0];
	b[p][1]=b[0][1];

	cleardevice();
	setcolor(35);
	rectangle(xwmin,ymax-ywmin,xwmax,ymax-ywmax);
	setcolor(63);

	for(i=0;i<p;i++)
	{
		line(b[i][0],ymax-b[i][1],b[i+1][0],ymax-b[i+1][1]);
		getch();
	}
	getch();



}

/*--------------------------------------------------------*/


clip_right(int b[10][10],int c[10][10])
{

	n=p; p=0; m=0;

	for(i=0;i<n;i++)
	{
		dy=b[i+1][1]-b[i][1];
		dx=b[i+1][0]-b[i][0];

		if((dx!=0)&&(dy!=0))
		{
			m=(dy/dx);
		}

		if((b[i][0]>xwmax)&&(b[i+1][0]<=xwmax) )  flag=0;
		if((b[i][0]<=xwmax)&&(b[i+1][0]<=xwmax) ) flag=1;
		if((b[i][0]<=xwmax)&&(b[i+1][0]>xwmax) )  flag=2;
		if((b[i][0]>xwmax)&&(b[i+1][0]>xwmax) )   flag=3;


		switch(flag)
		{
			case 0 :
				x=xwmax;
				if(dy!=0)
				    y=(int)(b[i][1]+m*(x-b[i][0]));
				else
				    y=b[i][1];

				c[p][0]=x;
				c[p][1]=y;
				p++;
				c[p][0]=b[i+1][0];
				c[p][1]=b[i+1][1];
				p++;
				break;

			case 1 :
				c[p][0]=b[i+1][0];
				c[p][1]=b[i+1][1];
				p++;
				break;

			case 2 :
				x=xwmax;
				if(dy!=0)
				     y=(int)(b[i][1]+m*(x-b[i][0]));
				else
				     y=b[i][1];

				c[p][0]=x;
				c[p][1]=y;
				p++;
		}


	}/*-for()-*/

	c[p][0]=c[0][0];
	c[p][1]=c[0][1];

	cleardevice();
	setcolor(35);
	rectangle(xwmin,ymax-ywmin,xwmax,ymax-ywmax);
	setcolor(63);

	for(i=0;i<p;i++)
	{
		line(c[i][0],ymax-c[i][1],c[i+1][0],ymax-c[i+1][1]);
		getch();
	}
	getch();


}


/*--------------------------------------------------------*/

clip_bottom(int c[10][10],int d[10][10])
{

	n=p; p=0; m=0;

	for(i=0;i<n;i++)
	{
		dy=c[i+1][1]-c[i][1];
		dx=c[i+1][0]-c[i][0];

		if((dx!=0)&&(dy!=0))
		{
			m=(dy/dx);
		}


		if((c[i][1]<ywmin)&&(c[i+1][1]>=ywmin) )  flag=0;
		if((c[i][1]>=ywmin)&&(c[i+1][1]>=ywmin) ) flag=1;
		if((c[i][1]>=ywmin)&&(c[i+1][1]<ywmin) )  flag=2;
		if((c[i][1]<ywmin)&&(c[i+1][1]<ywmin) )   flag=3;


		switch(flag)
		{

		   case 0 :
				y=ywmin;
				if(dx!=0)
				     x=abs((int)(c[i][0]+(1/m)*(y-c[i][1])));
				else
				     x=c[i][0];

				d[p][0]=x;
				d[p][1]=y;
				p++;
				d[p][0]=c[i+1][0];
				d[p][1]=c[i+1][1];
				p++;
				break;

		   case 1 :
				d[p][0]=c[i+1][0];
				d[p][1]=c[i+1][1];
				p++;
				break;

		  case 2 :
				y=ywmin;
				if(dx!=0)
				     x=abs((int)(c[i][0]+(1/m)*(y-c[i][1])));
				else
				     x=c[i][0];

				d[p][0]=x;
				d[p][1]=y;
				p++;
		}



	}/*-for()-*/

	d[p][0]=d[0][0];
	d[p][1]=d[0][1];

	cleardevice();
	setcolor(35);
	rectangle(xwmin,ymax-ywmin,xwmax,ymax-ywmax);
	setcolor(63);

	for(i=0;i<p;i++)
	{
		line(d[i][0],ymax-d[i][1],d[i+1][0],ymax-d[i+1][1]);
		getch();
	}
	getch();


}

/*--------------------------------------------------------*/

clip_top(int d[10][10],int e[10][10])
{

	n=p;
	p=0;

	for(i=0;i<n;i++)
	{

		dy=d[i+1][1]-d[i][1];
		dx=d[i+1][0]-d[i][0];

		if((dx!=0)&&(dy!=0))
		{
			m=(dy/dx);
		}

		if((d[i][1]>ywmax)&&(d[i+1][1]<=ywmax) )  flag=0;
		if((d[i][1]<=ywmax)&&(d[i+1][1]<=ywmax) ) flag=1;
		if((d[i][1]<=ywmax)&&(d[i+1][1]>ywmax) )  flag=2;
		if((d[i][1]>ywmax)&&(d[i+1][1]>ywmax) )   flag=3;

		switch(flag)
		{
			case 0 :
				y=ywmax;
				if(dx!=0)
				     x=abs((int)(d[i][0]+(1/m)*(y-d[i][1])));
				else
				     x=d[i][0];

				e[p][0]=x;
				e[p][1]=y;
				p++;
				e[p][0]=d[i+1][0];
				e[p][1]=d[i+1][1];
				p++;
				break;

			case 1 :
				e[p][0]=d[i+1][0];
				e[p][1]=d[i+1][1];
				p++;
				break;

			case 2 :
				y=ywmax;
				if(dx!=0)
				     x=abs((int)(d[i][0]+(1/m)*(y-d[i][1])));
				else
				     x=d[i][0];

				e[p][0]=x;
				e[p][1]=y;
				p++;
		}

	}/*-for()-*/

	e[p][0]=e[0][0];
	e[p][1]=e[0][1];


	cleardevice();
	setcolor(35);
	rectangle(xwmin,ymax-ywmin,xwmax,ymax-ywmax);
	setcolor(63);

	for(i=0;i<p;i++)
	{
		line(e[i][0],ymax-e[i][1],e[i+1][0],ymax-e[i+1][1]);
		getch();
	}
	getch(); getch();
}



/*-****************************************************************-*/
