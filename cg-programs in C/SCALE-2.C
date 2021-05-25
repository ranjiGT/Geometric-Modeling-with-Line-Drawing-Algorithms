/*-Scaling -*/
/******************************************************************/


#include <stdio.h>
#include <graphics.h>

main()
{

	int 	n,i,j,k,gd,gm,xo,yo;
	int 	x,y,xmax,ymax,X1,Y1,X2,Y2,temp;
	int  	a[20][2],b[20][2];
	float   sx,sy;


	clrscr();
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


	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");



	line(320,0,320,480);
	line(0,240,640,240);

	xo = 320; yo = 240;
	xmax = 640; ymax = 480;


	for(i=0;i<n;i++)  /*- draw poly -*/
	{
	     X1 = xo+a[i][0];
	     Y1 = ymax-(yo+a[i][1]);
	     X2 = xo+a[i+1][0];
	     Y2 = ymax-(yo+a[i+1][1]);

	     line( X1,Y1,X2,Y2 );
	}

	printf("\nEnter scaling parameters :\n ");
	printf("sx , sy = ");
	scanf("%f %f",&sx,&sy);

	for(i=0;i<n;i++)
	{
	     b[i][0] = (int) a[i][0] * sx;
	     b[i][1] = (int) a[i][1] * sy;
	}

	b[n][0] = b[0][0];
	b[n][1] = b[0][1];

	for(i=0;i<n;i++)  /*- draw poly -*/
	{
	     X1 = xo+b[i][0];
	     Y1 = ymax-(yo+b[i][1]);
	     X2 = xo+b[i+1][0];
	     Y2 = ymax-(yo+b[i+1][1]);

	     line( X1,Y1,X2,Y2 );
	}

	getch();

}/*-main()-*/

/**--------------------------------------------------------------**/