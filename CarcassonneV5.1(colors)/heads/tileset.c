#include <stdio.h>
#include <windows.h>
#include "colors.h"
#include "structures.h"
void tileset(int a,int b,int set[a][b], int typesoftiles)
{
	int ColorAxis=12,ColorC=9,ColorR=6,ColorP=10,ColorS=11,ColorT=13,ColorX=2,ColorDefault=15,ColorWarning=12,ColorCommand=14;
	int t,y,q=0,l=0,c=0,e=0,d,lx,ly;
	for(y=0;y<a;y++)
	{
		for(t=0;t<b;t++)
		{
			if(set[t][y]==0)
			{
				q++;
			}
			else
			{
				t=b;
				l++;
				if(l==1)
				{
					d=e;
					e=b+1;
				}
			}
			if(q==b)
			{
				if(l<1)
				e++;
				else
				e--;
			}
		}
		q=0;
	}
	ly=e;
	e=0;
	l=0;
	printf("\n");
	for(y=0;y<b;y++)
	{
		for(t=0;t<a;t++)
		{
			if(set[y][t]==0)
			{
				q++;
			}
			else
			{
				t=a;
				l++;
				if(l==1)
				{
					c=e;
					e=a+1;
				}
			}
			if(q==(a-1))
			{
				if(l<1)
				e++;
				else
				e--;
			}
		}
		q=0;
	}
	lx=e;
	printf("\n    ");
	ColorSet(ColorAxis);
	for(t=c; t<lx-1; t++)
	{
		if(t<10)
		printf("   %d  ",t);
		if(t<100&&t>9)
		printf("  %d  ",t);
		if(t<1000&&t>99)
		printf("  %d ",t);
	}
	ColorSet(ColorDefault);
	printf("\n");
	for(t=d; t<ly-1; t++)
	{
		printf("\n    ");
		for(y=c; y<lx-1; y++)
		{
			ColorSet(segmentcolor(set[y][t],0));
			printf("   %c  ",tileplaced[set[y][t]].segments[0]);
			ColorSet(ColorDefault);
		}
		printf("\n");
		ColorSet(ColorAxis);
		if(t<10)
		printf("%d   ",t);
		if(t<100&&t>9)
		printf("%d  ",t);
		if(t<1000&&t>99)
		printf("%d ",t);
		ColorSet(ColorDefault);
		for(y=c; y<lx; y++)
		{
			ColorSet(segmentcolor(set[y][t],3));
			printf(" %c ",tileplaced[set[y][t]].segments[3]);
			ColorSet(ColorDefault);
			if(strcmp(tileplaced[set[y][t]].special, "Temple")==0)
			{
				ColorSet(ColorT);
				printf("%c",'T');
				ColorSet(ColorDefault);
				ColorSet(segmentcolor(set[y][t],1));
				printf(" %c",tileplaced[set[y][t]].segments[1]);
				ColorSet(ColorDefault);
			}
			else if(strcmp(tileplaced[set[y][t]].special, "Crossroad")==0)
			{
				ColorSet(ColorX);
				printf("%c",'X');
				ColorSet(ColorDefault);
				ColorSet(segmentcolor(set[y][t],1));
				printf(" %c",tileplaced[set[y][t]].segments[1]);
				ColorSet(ColorDefault);
			}
			else
			{
				ColorSet(segmentcolor(set[y][t],1));
				printf("  %c",tileplaced[set[y][t]].segments[1]);
				ColorSet(ColorDefault);
			}
		}
		printf("\n    ");
		for(y=c; y<lx; y++)
		{
		ColorSet(segmentcolor(set[y][t],2));
		printf("   %c  ",tileplaced[set[y][t]].segments[2]);
		ColorSet(ColorDefault);
		}
	}
	printf("\n");
}
