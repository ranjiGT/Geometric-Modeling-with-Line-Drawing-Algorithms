
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
main()
{

  int driver,mode;
  int x[20],y[20];
  int n;
  int i,k;
  int xwmin,ywmin,xwmax,ywmax;
  int dx,dy;
  float u1,u2;
  int p[5],q[5];
  float r[5];
  int wx[20],wy[20];
  int round(float a);
  printf("give the no of lines\n");
  scanf("%d",&n);
  cleardevice();
  for(i=0;i<2*n;i++)
     {
       printf("give the end-pt of line-no %d : ",i/2+1);

       scanf("%d %d",&x[i],&y[i]);
     }

  printf("give the window boundaries :\n");
  scanf("%d %d %d %d",&xwmin,&ywmin,&xwmax,&ywmax);

  for(i=0;i<2*n;i+=2)
    {
       u1=0;u2=1;
       dx=x[i+1]-x[i];dy=y[i+1]-y[i];

       p[1]=-dx;     q[1]=x[i]-xwmin;
       p[2]=dx;      q[2]=xwmax-x[i];
       p[3]=-dy;     q[3]=y[i]-ywmin;
       p[4]=dy;      q[4]=ywmax-y[i];

       for(k=1;k<=4;k++)
	   r[k]=(float)q[k]/p[k];

       for(k=1;k<=4;k++)
	{
	  if((p[k]==0)&&(q[k]<0))
		   {//discard the line
		   u1=1;u2=0; //make u1>u2 to execute the discard loop
		 }

	  else
	      if(p[k]<0)
		{                    //assign u1 the max of all r's
		 if(r[k]>u1) u1=r[k];//whose p[k]<0.

		}
	      else
	      if(p[k]>0)
		{	             //assign u2 the min of all r's
		 if(r[k]<u2) u2=r[k];//whose p[k]>0.
		}
	}
       if(u1>u2)
	    { //discard the line
	      wx[i]=0;wy[i]=0;
	      wx[i+1]=0;wy[i+1]=0;
	    }
       else
	   {
	     wx[i]=round(x[i]+u1*dx);
	     wy[i]=round(y[i]+u1*dy);
	     wx[i+1]=round(x[i]+u2*dx);
	     wy[i+1]=round(y[i]+u2*dy);
	   }
    }

  detectgraph(&driver,&mode);
  initgraph(&driver,&mode,"");

  outtextxy(250,460,"   BEFORE CLIPPING");
  rectangle(xwmin,479-ywmin,xwmax,479-ywmax);
  outtextxy(xwmin,479-(ywmax+8),"WINDOW");
  for(i=0;i<2*n;i+=2)
     line(x[i],479-y[i],x[i+1],479-y[i+1]);

  getch();
  cleardevice();

  outtextxy(250,460,"   AFTER CLIPPING");
  outtextxy(xwmin,479-(ywmax+8),"WINDOW");
  rectangle(xwmin,479-ywmin,xwmax,479-ywmax);
  for(i=0;i<2*n;i+=2)
     line(wx[i],479-wy[i],wx[i+1],479-wy[i+1]);

  getch();
  closegraph();
}
int round(float a)
{
  if((a-(int)a)>=0.5) return ceil(a);
  else return floor(a);
}


