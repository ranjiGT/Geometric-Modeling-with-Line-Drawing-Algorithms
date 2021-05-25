#include<stdio.h>
#include<math.h>
#include<graphics.h>

void piechart( int xc, int yc, float r);
struct point
{
     float x,y;
} pts[2];

	int N, xc, yc;
	float r;
	float data[5];

main()
{
	int i;

	clrscr();

	printf("\n Enter no of points : ");
	scanf("%d", &N);

	printf("\n Enter data : ");
	for(i=0; i<N ; i++)
	 scanf("%f",&data[i]);

	 xc = 640/2;
	 yc = 480/2;
	 r = 200;
	 piechart(xc, yc, r);
	 getch();
}

void piechart( int xc, int yc, float r)
{

   int gd,gm,code=10;
   int i,x2,y2;
   float ls, theta, total;


   detectgraph(&gd, &gm);
   initgraph(&gd,&gm, " ");

   circle(xc, yc, r);

   total = 0; theta = 0;

   for(i=0; i<N; i++)
    total += data[i];

   pts[0].x = xc;
   pts[0].y = yc;


   for(i=0; i<N; i++)
   {
	theta += 2 * 3.14 * data[i] /total;

	pts[i].x = xc + r * cos(theta);
	pts[i].y = yc + r * sin(theta);

	x2 = pts[i].x;
	y2 = pts[i].y;

	setcolor(code++);
	line(xc, 480-yc, x2, 480-y2);

	getch();
   }

}
/*--------------------------------------------------------*/
