//***************************************************************************
//   THIS PROGRAM PERFORMS LINE CLIPPING USING COHEN-SUTHERLAND ALGORITHM.
//***************************************************************************

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

struct bits
  { unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
  } endpt[20];            //to store 4-bit region code for each end-pt

int xwmin,ywmin,xwmax,ywmax;//window boundary
float m[10];                //slope of the line
int x[20],y[20];            //end-pt of the line
int wx[20],wy[20];          //end-pt of the clipped line
void setregioncode(int i);  //func to set region code
void pt_of_interx(int i,float t);//func to find pt of intersection of the
				 //line with the window boundary.
void clipline(int i);       //func which actually performs clipping
int round(float a);         //func for rounding off

void main()
{
  int driver,mode;         //graphics system parameters
  int i,j,k;               //counters
  int n;                   //no of lines( max 10)
  clrscr();
  //to read no of lines
  printf("give the no of lines\n");
  scanf("%d",&n);

  //to read the end-pt of the lines
  j=1;
  for(i=0;i<2*n;i++)

   {
     printf("give the end-pt of the line no-%d ",j);

     scanf("%d %d",&x[i],&y[i]);
     if(i%2!=0)
		 j++;
   }

  for(k=0;k<n;k++)
    { if(x[2*k+1]!=x[2*k])
	 m[k]=(float)(y[2*k+1]-y[2*k])/(x[2*k+1]-x[2*k]);
    }

  //get window boundaries
  printf("give the window boundaries :\n");
  scanf("%d %d %d %d",&xwmin,&ywmin,&xwmax,&ywmax);

  //initialize the graphics system
  detectgraph(&driver,&mode);
  initgraph(&driver,&mode,"");

  rectangle(xwmin,479-ywmin,xwmax,479-ywmax);
  outtextxy(xwmin,479-(ywmax+8),"WINDOW");
  outtextxy(250,460,"BEFORE CLIPPING");

  //show the unclipped lines
  for(i=0;i<2*n;i+=2)
     line(x[i],479-y[i],x[i+1],479-y[i+1]);

  //wait and clear the screen
  getch();
  cleardevice();

  //set region codes for all end-pts
  for(i=0;i<2*n;i++)
      setregioncode(i);

  //for one line at a time
  for(i=0;i<2*n;i+=2)
  {
       if(((!endpt[i].bit1)&&(!endpt[i+1].bit1))&&
	  ((!endpt[i].bit2)&&(!endpt[i+1].bit2))&&
	  ((!endpt[i].bit3)&&(!endpt[i+1].bit3))&&
	  ((!endpt[i].bit4)&&(!endpt[i+1].bit4)))
	//if both points of the line are completely inside window
       {
	 wx[i]=x[i];wy[i]=y[i];
	 wx[i+1]=x[i+1];wy[i+1]=y[i+1];
       }
       else //now for a line completely outside
       if((endpt[i].bit1&&endpt[i+1].bit1)||
	  (endpt[i].bit2&&endpt[i+1].bit2)||
	  (endpt[i].bit3&&endpt[i+1].bit3)||
	  (endpt[i].bit4&&endpt[i+1].bit4))
	  {//discard the line
	    wx[i]=0;wy[i]=0;
	    wx[i+1]=0;wy[i+1]=0;
	  }
       else//now the line which is niether completely in nor completely out
	   clipline(i);

  }//end of outermost for loop

  rectangle(xwmin,479-ywmin,xwmax,479-ywmax);
  outtextxy(xwmin,479-(ywmax+8),"WINDOW");
  outtextxy(250,460,"AFTER CLIPPING");

  //show the clipped lines
  for(i=0;i<2*n;i+=2)
	line(wx[i],479-wy[i],wx[i+1],479-wy[i+1]);

  getch();
  closegraph();
} //end of main

void setregioncode(int i)
{
  if(x[i]<xwmin)
	endpt[i].bit1=1;
  else
	endpt[i].bit1=0;
  if(x[i]>xwmax)
	endpt[i].bit2=1;
  else
	endpt[i].bit2=0;
  if(y[i]<ywmin)
	endpt[i].bit3=1;
  else
	endpt[i].bit3=0;
  if(y[i]>ywmax)
	endpt[i].bit4=1;
  else
	endpt[i].bit4=0;
  return;
}

void pt_of_interx(int i,float t)
{
  int xx,yy;
   if(endpt[i].bit1)
     {
       xx=xwmin;
       yy=round(y[i]+t*(xwmin-x[i]));//if line is || to x axis slope,t=0
		   //and hence no special case is needed for such a line
     }
  else if(endpt[i].bit2)
	  {
	    xx=xwmax;
	    yy=round(y[i]+t*(xwmax-x[i]));//if line is || to x axis slope,t=0
		   //and hence no special case is needed for such a line
	  }
       else if(endpt[i].bit3)
	      {
		yy=ywmin;
		if(i%2==0) //if the pt is the first end-pt of the line
		  {//if the line is || to y axis
		   if((x[i+1]-x[i])==0)
			   xx=x[i];
		   else
			   xx=round(x[i]+(float)(ywmin-y[i])/t);
		  }
		else if(i%2!=0)//if the pt is the second end-pt of the line
		     {//if the line is || to y axis
		      if((x[i]-x[i-1])==0)
			   xx=x[i];
		      else
			   xx=round(x[i]+(float)(ywmin-y[i])/t);
		     }
	      }
	    else if(endpt[i].bit4)
		   {
		     yy=ywmax;
		     if(i%2==0) //if the pt is the first end-pt of the line
		       {//if the line is || to y axis
			if((x[i+1]-x[i])==0)
				xx=x[i];
			else
				xx=round(x[i]+(float)(ywmax-y[i])/t);
		       }
		     else if(i%2!=0)//if the pt is the second end-pt of the line
		       {//if the line is || to y axis
			if((x[i]-x[i-1])==0)
				xx=x[i];
			else
				xx=round(x[i]+(float)(ywmax-y[i])/t);
		       }
		   }
  x[i]=xx;
  y[i]=yy;
}

void clipline(int i)
{
     pt_of_interx(i,m[i/2]);
     setregioncode(i);
     if(endpt[i].bit1||endpt[i].bit2||endpt[i].bit3||endpt[i].bit4)
	clipline(i);
     else
      {
       wx[i]=x[i];wy[i]=y[i];
       if(i%2==0)
	    clipline(i+1);
      }
}

int round(float a)
{
 if((a-(int)a)>=0.5) return ceil(a);
 else return floor(a);
}



