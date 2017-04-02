#include <stdio.h>
#include <windows.h>
#include "colors.h"
#include "structures.h"
void rotationpre(int rotations, int tileid)
{
	int ColorAxis=12,ColorC=9,ColorR=6,ColorP=10,ColorS=11,ColorT=13,ColorX=2,ColorDefault=15,ColorWarning=12,ColorCommand=14;
	char c[10];
	rotations=rotations % 4;
	c[(0+rotations) % 4]=tile[tileid].segments[0];
	c[(1+rotations) % 4]=tile[tileid].segments[1];
	c[(2+rotations) % 4]=tile[tileid].segments[2];
	c[(3+rotations) % 4]=tile[tileid].segments[3];
	ColorSet(segcolor(c,0));
	printf("\n   %c",c[0]);
	ColorSet(ColorDefault);
	ColorSet(segcolor(c,3));
	printf("\n %c ",c[3]);
	ColorSet(ColorDefault);
	if(strcmp(tile[tileid].special, "Temple")==0)
	{
		ColorSet(ColorT);
		printf("%c",'T');
		ColorSet(ColorDefault);
		ColorSet(segcolor(c,1));
		printf(" %c",c[1]);
		ColorSet(ColorDefault);
	}
	else if(strcmp(tile[tileid].special, "Crossroad")==0)
	{
		ColorSet(ColorX);
		printf("%c",'X');
		ColorSet(ColorDefault);
		ColorSet(segcolor(c,1));
		printf(" %c",c[1]);
		ColorSet(ColorDefault);
	}
	else
	{
		ColorSet(segcolor(c,1));
		printf("  %c",c[1]);
		ColorSet(ColorDefault);
	}
	ColorSet(segcolor(c,2));
	printf("\n   %c\n\n",c[2]);
	ColorSet(ColorDefault);
}

void rotation(int rotations, int tileid)
{
	int t,o;
	char v1,v2;
	for(t=0;t<rotations;t++)
	{
		v1=tile[tileid].segments[1];
		tile[tileid].segments[1]=tile[tileid].segments[0];
		v2=tile[tileid].segments[2];
		tile[tileid].segments[2]=v1;
		v1=tile[tileid].segments[3];
		tile[tileid].segments[3]=v2;
		tile[tileid].segments[0]=v1;
	}
}
