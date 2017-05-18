#include <stdio.h>
#include "structures.h"
int ifcross(int choice)
{
	int roads=0;
	if(tile[choice].segments[0]=='R')
	roads++;
	if(tile[choice].segments[1]=='R')
	roads++;
	if(tile[choice].segments[2]=='R')
	roads++;
	if(tile[choice].segments[3]=='R')
	roads++;
	if(roads>2)
	return 1;
	else
	return 0;
}
int segcross(char seg[])
{
	int roads=0;
	if(seg[0]=='R')
	roads++;
	if(seg[1]=='R')
	roads++;
	if(seg[2]=='R')
	roads++;
	if(seg[3]=='R')
	roads++;
	if(roads>2)
	return 1;
	else
	return 0;
}
int ifcity(int choice)
{
	int city=0;
	if(tile[choice].segments[0]=='S'||tile[choice].segments[0]=='C')
	city++;
	if(tile[choice].segments[1]=='S'||tile[choice].segments[1]=='C')
	city++;
	if(tile[choice].segments[2]=='S'||tile[choice].segments[2]=='C')
	city++;
	if(tile[choice].segments[3]=='S'||tile[choice].segments[3]=='C')
	city++;
	if(city==4)
	return 1;
	else
	return 0;
}
int segcity(char seg[])
{
	int city=0;
	if(seg[0]=='S'||seg[0]=='C')
	city++;
	if(seg[1]=='S'||seg[1]=='C')
	city++;
	if(seg[2]=='S'||seg[2]=='C')
	city++;
	if(seg[3]=='S'||seg[3]=='C')
	city++;
	if(city==4)
	return 1;
	else
	return 0;
}
