/*-- point plotting  --*/
/******************************************************/

	#include<stdio.h>
	#include<graphics.h>

	void main()
	{
		int x,y  ;
		int gd, gm ;

		detectgraph(&gd,&gm);
		initgraph(&gd,&gm," ");

		printf("\n\t Enter the cordinates  of  point : \n\n ");
		scanf("%d %d",&x,&y);

		putpixel (x, y, WHITE );

		getch();
	}

/*******************************************************/