//author :- Venk@t

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
int final_x[100],final_y[100];
int clip_rx[100],clip_lx[100];
int clip_ry[100],clip_ly[100];
int ref_x = 325,ref_y = 400;
char msg[100];
int block = 0;
char inchar = 0;
int scr;
int f_ref = 0;
int clip;
int clip_y;
int incr=0;
void ref_blk()
{
	int k;
	//	line(325,450,325,350);
	line(325+75,350,325,400);
	line(325+75,350,325,300);
	line(325-75,350,325,300);
	line(325-75,350,325,400);

	line(325-75,350,325-75,450);
	line(325,400,325,450);
	line(325+75,350,325+75,450);


    //	floodfill(350,350,WHITE);

}
void dis()
{
	int i;
      //	ref_blk();
	sprintf(msg,"Your score :- %d",scr);
	outtextxy(400,30,msg);
	for(i=0;i<block;i++)
	{

			line(final_x[i]+75-clip_rx[i],final_y[i]-50+clip_ry[i],final_x[i]+clip_lx[i],final_y[i]-clip_ly[i]);
			line(final_x[i]+75-clip_rx[i],final_y[i]-50+clip_ry[i],final_x[i]-clip_rx[i],final_y[i]-100+clip_ry[i]);
			line(final_x[i]-75+clip_lx[i],final_y[i]-50-clip_ly[i],final_x[i]-clip_rx[i],final_y[i]-100+clip_ry[i]);
			line(final_x[i]-75+clip_lx[i],final_y[i]-50-clip_ly[i],final_x[i]+clip_lx[i],final_y[i]-clip_ly[i]);

			line(final_x[i]-75+clip_lx[i],final_y[i]-50-clip_ly[i],final_x[i]-75+clip_lx[i],final_y[i]-50+20-clip_ly[i]);
			line(final_x[i]+clip_lx[i],final_y[i]-clip_ly[i],final_x[i]+clip_lx[i],final_y[i]+20-clip_ly[i]);
			line(final_x[i]+75-clip_rx[i],final_y[i]-50+clip_ry[i],final_x[i]+75-clip_rx[i],final_y[i]-50+20+clip_ry[i]);


			line(final_x[i]-75+clip_lx[i],final_y[i]-50+20-clip_ly[i],final_x[i]+clip_lx[i],final_y[i]+20-clip_ly[i]);
			line(final_x[i]+clip_lx[i],final_y[i]+20-clip_ly[i],final_x[i]+75-clip_rx[i],final_y[i]-50+20+clip_ry[i]);



	}
}

void boundary_fill(int x,int y,int boundary_color,int fill_color)
{
	int current;
	current=getpixel(x,y);
	if(current!=boundary_color && current!=fill_color)
	{
		putpixel(x,y,fill_color);
		delay(10);
		boundary_fill(x+1,y,boundary_color,fill_color);
		boundary_fill(x,y+1,boundary_color,fill_color);
		boundary_fill(x-1,y,boundary_color,fill_color);
		boundary_fill(x,y-1,boundary_color,fill_color);
	}
}



void blk()
{
	int i,a=0;
	int dclip;
	int dclip_y;
	clip = ref_x;
	clip_y = ref_y;
	cleardevice();
	if(f_ref==0)
	{
		ref_y = ref_y - 20;
		f_ref=1;
	}
	while(inchar != 27)
	{
		for(i=0;i<100;i++)
		{


			line(ref_x+75-i-clip_rx[block],ref_y-50+i+clip_ry[block],ref_x-i+clip_lx[block],ref_y+i-clip_ly[block]);
			line(ref_x+75-i-clip_rx[block],ref_y-50+i+clip_ry[block],ref_x-i-clip_rx[block],ref_y-100+i+clip_ry[block]);
			line(ref_x-75-i+clip_lx[block],ref_y-50+i-clip_ly[block],ref_x-i-clip_lx[block],ref_y-100+i-clip_ly[block]);
			line(ref_x-75-i+clip_lx[block],ref_y-50+i-clip_ly[block],ref_x-i+clip_rx[block],ref_y+i-clip_ry[block]);

			line(ref_x-75-i+clip_lx[block],ref_y-50+i-clip_ly[block],ref_x-75-i+clip_lx[block],ref_y-50+20+i-clip_ly[block]);
			line(ref_x-i+clip_lx[block],ref_y+i-clip_ly[block],ref_x-i+clip_lx[block],ref_y+20+i-clip_ly[block]);
			line(ref_x+75-i-clip_rx[block],ref_y-50+i+clip_ry[block],ref_x+75-i-clip_rx[block],ref_y-50+i+20+clip_ry[block]);


			line(ref_x-75-i+clip_lx[block],ref_y-50+20+i-clip_ly[block],ref_x-i+clip_lx[block],ref_y+20+i-clip_ly[block]);
			line(ref_x-i+clip_lx[block],ref_y+20+i-clip_ly[block],ref_x+75-i-clip_rx[block],ref_y-50+i+20+clip_ry[block]);


		      /*	else
			{
			line(final_x[block]+75-clip_rx[block]-i,final_y[block]-50+clip_ry[block]+i,final_x[block]+clip_lx[block]-i,final_y[block]-clip_ly[block]+i);
			line(final_x[block]+75-clip_rx[block]-i,final_y[block]-50+clip_ry[block]+i,final_x[block]-clip_rx[block]-i,final_y[block]-100+clip_ry[block]+i);
			line(final_x[block]-75+clip_lx[block]-i,final_y[block]-50-clip_ly[block]+i,final_x[block]-clip_rx[block]-i,final_y[block]-100+clip_ry[block]+i);
			line(final_x[block]-75+clip_lx[block]-i,final_y[block]-50-clip_ly[block]+i,final_x[block]+clip_lx[block]-i,final_y[block]-clip_ly[block]+i);

			line(final_x[block]-75+clip_lx[block]-i,final_y[block]-50-clip_ly[block]+i,final_x[block]-75+clip_lx[block]-i,final_y[block]-50+20-clip_ly[block]+i);
			line(final_x[block]+clip_lx[block]-i,final_y[block]-clip_ly[block]+i,final_x[block]+clip_lx[block]-i,final_y[block]+20-clip_ly[block]+i);
			line(final_x[block]+75-clip_rx[block]-i,final_y[block]-50+clip_ry[block]+i,final_x[block]+75-clip_rx[block]-i,final_y[block]-50+20+clip_ry[block]+i);


			line(final_x[block]-75+clip_lx[block]-i,final_y[block]-50+20-clip_ly[block]+i,final_x[block]+clip_lx[block]-i,final_y[block]+20-clip_ly[block]+i);
			line(final_x[block]+clip_lx[block]-i,final_y[block]+20-clip_ly[block]+i,final_x[block]+75-clip_rx[block]-i,final_y[block]-50+20+clip_ry[block]+i);
			}

		       */


		 //	floodfill(ref_x+25-i,ref_y-25-i,WHITE);

	 //		floodfill(ref_x+25-i,ref_y-50-i,WHITE);
			ref_blk();
			dis();
			delay(20);
			cleardevice();

			if(kbhit())
			{
				inchar = getch();
				if(inchar == 27)
					break;

				ref_x = ref_x - i;
				ref_y = ref_y + i;
				dclip = clip - ref_x;
				dclip_y = dclip;
				clip_lx[block] = dclip;
				clip_rx[block] = 0;
				clip_ly[block] = dclip_y;
				clip_ry[block] = 0;
				final_x[block] = ref_x;
				final_y[block] = ref_y;
				if(clip-ref_x > 50){
					inchar=27;
					break;   }
				block++;
				scr = block*10;
				ref_y = ref_y - 20;
				cleardevice();
				blk();
			}
		}
		for(i=100;i>-100;i--)
		{
			if(inchar == 27)
				break;

			line(ref_x+75-i,ref_y-50+i,ref_x-i,ref_y+i);
			line(ref_x+75-i,ref_y-50+i,ref_x-i,ref_y-100+i);
			line(ref_x-75-i,ref_y-50+i,ref_x-i,ref_y-100+i);
			line(ref_x-75-i,ref_y-50+i,ref_x-i,ref_y+i);

			line(ref_x-75-i,ref_y-50+i,ref_x-75-i,ref_y-50+20+i);
			line(ref_x-i,ref_y+i,ref_x-i,ref_y+20+i);
			line(ref_x+75-i,ref_y-50+i,ref_x+75-i,ref_y-50+i+20);


			line(ref_x-75-i,ref_y-50+20+i,ref_x-i,ref_y+20+i);
			line(ref_x-i,ref_y+20+i,ref_x+75-i,ref_y-50+i+20);

	   //		floodfill(ref_x+25-i,ref_y-25-i,WHITE);

			ref_blk();
			dis();
			delay(20);
			cleardevice();

			if(kbhit())
			{
				inchar = getch();
				if(inchar == 27)
					break;
				ref_x = ref_x - i;
				ref_y = ref_y + i;
				if(clip>ref_x)
				{
					dclip = clip - ref_x;
					clip_lx[block] = dclip;
					clip_rx[block] = 0;
					clip_ly[block] = dclip;
					clip_ry[block] = 0;
					if(clip-ref_x > 50){
					inchar=27;
					break;   }
				}
				else
				{
					dclip = ref_x - clip;
					clip_lx[block] = 0;
					clip_rx[block] = dclip;
					clip_ly[block] = 0;
					clip_ry[block] = dclip;
					if(ref_x-clip > 50){
					inchar=27;
					break;   }
				}
				final_x[block] = ref_x;
				final_y[block] = ref_y;
				block++;
				scr = block*10;
			      //	incr = incr + 10;
				ref_y = ref_y-20;
				cleardevice();
			   //	break;
				blk();
			}
		}
			for(i=-100;i<0;i++)
		{
			if(inchar == 27)
				break;


			line(ref_x+75-i,ref_y-50+i,ref_x-i,ref_y+i);
			line(ref_x+75-i,ref_y-50+i,ref_x-i,ref_y-100+i);
			line(ref_x-75-i,ref_y-50+i,ref_x-i,ref_y-100+i);
			line(ref_x-75-i,ref_y-50+i,ref_x-i,ref_y+i);

			line(ref_x-75-i,ref_y-50+i,ref_x-75-i,ref_y-50+20+i);
			line(ref_x-i,ref_y+i,ref_x-i,ref_y+20+i);
			line(ref_x+75-i,ref_y-50+i,ref_x+75-i,ref_y-50+i+20);

			line(ref_x-75-i,ref_y-50+20+i,ref_x-i,ref_y+20+i);
			line(ref_x-i,ref_y+20+i,ref_x+75-i,ref_y-50+i+20);

		      //	floodfill(350-i,350-i,WHITE);
	     //		floodfill(ref_x+25-i,ref_y-25-i,WHITE);
			ref_blk();
			dis();
			delay(20);
			cleardevice();

			if(kbhit())
			{
				inchar = getch();
				if(inchar == 27)
					break;

				ref_x = ref_x - i;
				ref_y = ref_y + i;
				dclip = ref_x - clip;
				clip_lx[block] = 0;
				clip_rx[block] = dclip;
				clip_ry[block] = dclip;
				clip_ly[block] = 0;
				final_x[block] = ref_x;
				final_y[block] = ref_y;
				if(ref_x-clip > 50){
					inchar=27;
					break;   }
				block++;
				scr = block*10;
			      //	incr = incr + 10;
				ref_y = ref_y-20;
				cleardevice();
			      //	break;
				blk();
			}
		}
	}


}
void main()
{
	int gd = DETECT,gm;
	FILE *fptr;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	ref_blk();
	blk();
	fptr = fopen("C:\\score.txt","w+");
	fprintf(fptr,"%d",scr);
	fclose(fptr);
	printf("Game Over");
	getch();
	closegraph();
}
