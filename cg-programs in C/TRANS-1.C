/*- Translation -*/
/******************************************************************/


#include <stdio.h>
#include <graphics.h>

main()
{

	int 	n,i,j,k,gd,gm,tx,ty;
	int 	xmax,ymax;
	int  	a[20][2],b[20][2];


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

	xmax = 640; ymax = 480;

	drawpoly(n+1,a);

	printf("\nEnter translation distance :\n ");
	printf("tx , ty = ");
	scanf("%d %d",&tx,&ty);

	for(i=0;i<n;i++)
	{
	  b[i][0] = a[i][0] + tx;
	  b[i][1] = a[i][1] + ty;
	}

	b[n][0] = b[0][0];
	b[n][1] = b[0][1];

	drawpoly(n+1,b);


	getch();

}/*-main()-*/

/**--------------------------------------------------------------**/