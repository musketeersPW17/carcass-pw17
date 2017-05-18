#include <stdio.h>
#include "structures.h"
#include "colors.h"
int choicevalid(int chosen,int typesoftiles)
{
	int ColorAxis=12,ColorC=9,ColorR=6,ColorP=10,ColorS=11,ColorT=13,ColorX=2,ColorO=1,ColorDefault=15,ColorWarning=12,ColorCommand=14;
	int validity=0;
	while(validity==0)
	{
		if(chosen>typesoftiles||chosen<=0)
		{
			ColorSet(ColorWarning);
			printf("Wrong id, try again\n");
			ColorSet(ColorDefault);
			return 0;
		}
		else
		{
			if(tile[chosen].quantity==0)
			{
				ColorSet(ColorWarning);
				printf("Tile unavilable, choose other\n");
				ColorSet(ColorDefault);
				return 0;
			}
			else
			validity=1;		
		}
	}
	return 1;
}
int ifempty(int a, int b, int coordx,  int coordy, int set[a][b])
{
	if(set[coordx][coordy]!=0)
	return 0;
	return 1;
}
int placementvalid(int a, int b, int coordx,  int coordy, int set[a][b])
{
	int valid=0,zero=0;
	if(tileplaced[set[coordx][coordy]].segments[3]==tileplaced[set[coordx-1][coordy]].segments[1])
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[3]=='S'&&tileplaced[set[coordx-1][coordy]].segments[1]=='C')
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[3]=='C'&&tileplaced[set[coordx-1][coordy]].segments[1]=='S')
	valid++;
	if(set[coordx-1][coordy]==0)
	zero++;
	
	if(tileplaced[set[coordx][coordy]].segments[1]==tileplaced[set[coordx+1][coordy]].segments[3])
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[1]=='S'&&tileplaced[set[coordx+1][coordy]].segments[3]=='C')
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[1]=='C'&&tileplaced[set[coordx+1][coordy]].segments[3]=='S')
	valid++;
	if(set[coordx+1][coordy]==0)
	zero++;
	
	if(tileplaced[set[coordx][coordy]].segments[2]==tileplaced[set[coordx][coordy+1]].segments[0])
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[2]=='S'&&tileplaced[set[coordx][coordy+1]].segments[0]=='C')
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[2]=='C'&&tileplaced[set[coordx][coordy+1]].segments[0]=='S')
	valid++;
	if(set[coordx][coordy-1]==0)
	zero++;
	
	if(tileplaced[set[coordx][coordy]].segments[0]==tileplaced[set[coordx][coordy-1]].segments[2])
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[0]=='S'&&tileplaced[set[coordx][coordy-1]].segments[2]=='C')
	valid++;
	if(tileplaced[set[coordx][coordy]].segments[0]=='C'&&tileplaced[set[coordx][coordy-1]].segments[2]=='S')
	valid++;
	if(set[coordx][coordy+1]==0)
	zero++;
	
	if(valid+zero==4&&valid>0)
	return 1;
}
int rotationchoice(int ch)
{
	int ColorAxis=12,ColorC=9,ColorR=6,ColorP=10,ColorS=11,ColorT=13,ColorDefault=15,ColorWarning=12,ColorCommand=14;
	int punch=0, rota;
	char word;
	while(punch==0)
	{
		ColorSet(ColorCommand);
		printf("Choose number of rotations of the tile\n");
		scanf("%d", &rota);
		ColorSet(ColorDefault);
		rotationpre(rota,ch);
		ColorSet(ColorCommand);
		printf("Place the tile? (y/n)\n");
		scanf(" %c",&word);
		ColorSet(ColorDefault);				
		if(word==121)
		{
			rotation(rota,ch);
			punch=1;
		}
		if(word!=110&&word!=121)
		{
			punch=0;
			while(punch==0)
			{
				ColorSet(ColorWarning);
				printf("Wrong command, try again\n");
				scanf(" %c", &word);
				ColorSet(ColorDefault);
				if(word==121)
				{
					rotation(rota,ch);
					punch=1;
				}
			}
		}
	}
}
