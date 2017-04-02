#include <stdio.h>
#include <windows.h>
#include "colors.h"
#include "structures.h"
int segmentcolor(int tileid, int segment)
{
	int ColorAxis=12,ColorC=9,ColorR=6,ColorP=10,ColorS=11,ColorT=13,ColorX=2,ColorDefault=15,ColorWarning=12,ColorCommand=14;
	if(tileplaced[tileid].segments[segment]=='C')
	return ColorC;
	if(tileplaced[tileid].segments[segment]=='R')
	return ColorR;	
	if(tileplaced[tileid].segments[segment]=='P')
	return ColorP;
	if(tileplaced[tileid].segments[segment]=='S')
	return ColorS;
}

int segcolor(char seg[], int segment)
{
	int ColorAxis=12,ColorC=9,ColorR=6,ColorP=10,ColorS=11,ColorT=13,ColorX=2,ColorDefault=15,ColorWarning=12,ColorCommand=14;
	if(seg[segment]=='C')
	return ColorC;
	if(seg[segment]=='R')
	return ColorR;	
	if(seg[segment]=='P')
	return ColorP;
	if(seg[segment]=='S')
	return ColorS;
}
