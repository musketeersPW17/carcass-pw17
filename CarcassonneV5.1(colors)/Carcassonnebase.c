#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#include "heads/structures.h"
#include "heads/infofunction.h"
#include "heads/tileset.h"
#include "heads/validity.h"
#include "heads/colors.h"

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
	
int main()
{
	int ColorAxis=12,ColorC=9,ColorR=6,ColorP=10,ColorS=11,ColorT=13,ColorX=2,ColorDefault=15,ColorWarning=12,ColorCommand=14;
	ColorSet(ColorDefault);
	int limit;
	char sts[10];
	int typesoftiles=0;
	int alltiles=0;
	int i=1,ij=0,added=0;
	int segcheck=0;
	int equal=0;
	FILE *read;
	char c[1000];
	read = fopen("test.txt","r");
	if (!read)
	return 1;
	while ( fscanf( read, "%s", c )!=EOF)
	{
		fscanf(read,"%[^\n]", c);
		strcpy (sts, c);
		if(quantitycheck(typesoftiles)==0)
		{
			typesoftiles++;
			tile[typesoftiles].segments[0]=sts[0];
			tile[typesoftiles].segments[1]=sts[1];
			tile[typesoftiles].segments[2]=sts[2];
			tile[typesoftiles].segments[3]=sts[3];
			if(sts[4]-'0'==1)
			strcpy (tile[typesoftiles].special,"Temple");
			if(sts[4]-'0'==0)
			strcpy (tile[typesoftiles].special,"Nothing");
			if(ifcross(typesoftiles)==1)
			strcpy (tile[typesoftiles].special,"Crossroad");
			tile[typesoftiles].id=typesoftiles;
			tile[typesoftiles].quantity++;
			added=1;
			alltiles++;
		}
		else
		{
			
			for(i=1;i<=typesoftiles;i++)
			{
				for(ij=0;ij<4;ij++)
				{	
					for(segcheck=0;segcheck<4;segcheck++)
					{
						if(sts[(segcheck+ij)%4]==tile[i].segments[segcheck])
						{
							equal++;
						}
					}
					if(sts[4]-'0'==1&&strcmp(tile[i].special, "Temple")==0)
					equal++;
					if(sts[4]-'0'==0&&strcmp(tile[i].special, "Nothing")==0)
					equal++;
					if(segcross(sts)&&ifcross(i)==1)
					equal++;
				if(equal==5)
					{
					tile[i].quantity++;
					added=1;
					i=typesoftiles+1;
					alltiles++;
					}
					equal=0;
				}
			}
			if(added==0)
			{
				typesoftiles++;
				tile[typesoftiles].segments[0]=sts[0];
				tile[typesoftiles].segments[1]=sts[1];
				tile[typesoftiles].segments[2]=sts[2];
				tile[typesoftiles].segments[3]=sts[3];
				if(sts[4]-'0'==1)
				strcpy (tile[typesoftiles].special,"Temple");
				if(sts[4]-'0'==0)
				strcpy (tile[typesoftiles].special,"Nothing");
				if(segcross(sts)==1)
				strcpy (tile[typesoftiles].special,"Crossroad");
				tile[typesoftiles].id=typesoftiles;
				tile[typesoftiles].quantity++;
				alltiles++;
			}
			added=0;
		}
	}
	fclose(read);
	limit=2*(quantitycheck(typesoftiles)+2);
	int map[limit][limit],j,rot,clear=0,autotileset=0;
	char letter;
	memset(map, 0, sizeof(map[0][0]) * limit * limit);
	int chosen,validity=0;	
	int wish;
	yourtiles(typesoftiles);
	printf("Number of tiles left %d\n",quantitycheck(typesoftiles));
	ColorSet(ColorCommand);
	printf("Choose id of the first tile		(1-%d)\n",typesoftiles);
	scanf("%d", &chosen);
	ColorSet(ColorDefault);
	while(choicevalid(chosen,typesoftiles)==0)
	{
		ColorSet(ColorCommand);
		scanf(" %d", &chosen);
		ColorSet(ColorDefault);
	}
	rotationchoice(chosen);
	int ITP=quantitycheck(typesoftiles)+1, chosenid=1;
	strcpy(tileplaced[chosenid].segments,tile[chosen].segments);
	strcpy(tileplaced[chosenid].special,tile[chosen].special);
	map[ITP][ITP]=chosenid;
	tile[chosen].quantity--;
	tileset(limit,limit,map,typesoftiles);
	printf("\n\n");
	int chosencoord1,chosencoord2;
	printf("1. Tileset,\n2. Tile list,\n3. Place a tile,\n4. Clear console,\n");
	printf("5. Auto-clear,		(after placing a tile)	(%d)\n6. Auto-tileset,	(after placing a tile)	(%d)\n",clear,autotileset);
	ColorSet(ColorWarning);
	printf("Number of tiles left		%d\n",quantitycheck(typesoftiles));
	ColorSet(ColorDefault);
	while(quantitycheck(typesoftiles)!=0)
	{
		ColorSet(ColorCommand);
		printf("Choose a command\n");
		scanf("%d",&wish);
		ColorSet(ColorDefault);
		switch (wish)
		{
		case 1:
			tileset(limit,limit,map,typesoftiles);
			break;
		case 2:
			printf("\n");
			yourtiles(typesoftiles);
			break;
		case 4:
			system("cls");
			break;
		case 5:
			if(clear==0)
			clear=1;
			else
			clear=0;
			printf("auto-clear	%d\n",clear);
			break;
		case 6:
			if(autotileset==0)
			autotileset=1;
			else
			autotileset=0;
			printf("auto-tileset	%d\n",autotileset);
			break;
		case 3:
			ColorSet(ColorCommand);
			printf("Choose id of a tile\n");
			scanf("%d", &chosen);
			ColorSet(ColorDefault);
			while(choicevalid(chosen,typesoftiles)==0)
			{
				ColorSet(ColorCommand);
				scanf(" %d", &chosen);
				ColorSet(ColorDefault);
			}
			rotationchoice(chosen);
			ColorSet(ColorCommand);
			printf("Choose coordinates for the tile (x,y) \n");
			scanf("%d,%d", &chosencoord1,&chosencoord2);
			ColorSet(ColorDefault);
			int tileval=0;
			while(ifempty(limit,limit,chosencoord1,chosencoord2,map)!=1)
			{
				ColorSet(ColorWarning);
				printf("There is already a tile at chosen coordinates, try again \n");
				printf("Choose coordinates for the tile (x,y) \n");
				scanf("%d,%d", &chosencoord1,&chosencoord2);
				ColorSet(ColorDefault);
			}
			chosenid++;
			map[chosencoord1][chosencoord2]=chosenid;
			strcpy(tileplaced[chosenid].segments,tile[chosen].segments);
			strcpy(tileplaced[chosenid].special,tile[chosen].special);
			while(placementvalid(limit,limit,chosencoord1,chosencoord2,map)!=1)
			{
				map[chosencoord1][chosencoord2]=0;
				ColorSet(ColorWarning);
				printf("Invalid coordinates, try again \n");
				printf("Choose coordinates for the tile (x,y) \n");
				scanf("%d,%d", &chosencoord1,&chosencoord2);
				while(ifempty(limit,limit,chosencoord1,chosencoord2,map)!=1)
				{
					printf("There is already a tile at chosen coordinates, try again \n");
					printf("Choose coordinates for the tile (x,y) \n");
					scanf("%d,%d", &chosencoord1,&chosencoord2);
				}
				map[chosencoord1][chosencoord2]=chosenid;
				ColorSet(ColorDefault);
			}
			tile[chosen].quantity--;
			if(clear==1)
			{
				system("cls");
			}
			if(autotileset==1)
			{
				tileset(limit,limit,map,typesoftiles);
			}
			printf("1. Tileset,\n2. Tile list,\n3. Place a tile,\n4. Clear console,\n");
			printf("5. Auto-clear,		(after placing a tile)	(%d)\n6. Auto-tileset,	(after placing a tile)	(%d)\n",clear,autotileset);
			ColorSet(ColorWarning);
			printf("Number of tiles left		%d\n",quantitycheck(typesoftiles));
			ColorSet(ColorDefault);
			break;
		}
	}
}
