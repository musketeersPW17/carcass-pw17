#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Tiles
{
	char segments[5];
	char special[10];			//to get rid of ( make just int special to hold both variables )
	int quantity;
	int id;
};
struct Tiles tile[20];

void tileinfoall( struct Tiles *tile ) 
{
   printf( "Tile Segments : %s		", tile->segments);
   printf( "Special : %s	", tile->special);
   printf( "Quantity : %d		", tile->quantity);
   printf( "ID : %d\n",tile->id); 
}
void tileinfoavilable( struct Tiles *tile ) 
{
	if(tile->quantity>0)
	{
   		printf( "Tile Segments : %s		", tile->segments);
		printf( "Special : %s		", tile->special);
		printf( "Quantity : %d		", tile->quantity);
		printf( "ID : %d\n",tile->id); 
	}
}

void yourtiles(int tot)		//tot- types of tiles
{
	int t=1;
	for(t;t<tot;t++)
	tileinfoavilable(&tile[t]);
}	
int quantitycheck(int typesoftiles)
{
	int number=0;
	int t;
	for(t=0;t<typesoftiles;t++)
	{
		number=number+tile[t].quantity;
	}
	return number;
}

void tileset(int a,int b,int set[a][b], int typesoftiles)
{
	int t,y,q=0,l=0,c=0,e=0,d,lx,ly;
//	int a=limit,b=limit;
/*	for(y=0;y<a;y++)
	{
		for(t=0;t<b;t++)
		{
			printf("set[%d][%d]%d\n",y,t,set[y][t]);	//	shows the array
		}
	}
*/	for(y=0;y<a;y++)
	{
		for(t=0;t<b;t++)
		{
			//printf("set[%d][%d]%d\n",t,y,set[t][y]);
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
//	printf("limit x %d, limit y %d\ninitial x %d, initial y %d\n",lx,ly,c,d);			//	TILE PLACEMENT INFO
//	printf("tile segments:  %s\n",tile[set[c][d]].segments);
//	printf("tile segments:  %c %c %c %c\n",tile[set[c][d]].segments[0],tile[set[c][d]].segments[1],tile[set[c][d]].segments[2],tile[set[c][d]].segments[3]);
//	printf("tile on map id:  %d\n",set[c][d]);
	
	printf("\n    ");
	for(t=c; t<lx-1; t++)
	{
		if(t<10)
		printf("   %d  ",t);
		if(t<100&&t>9)
		printf("  %d  ",t);
		if(t<1000&&t>99)
		printf("  %d ",t);
	}
	printf("\n");
	for(t=d; t<ly-1; t++)
	{
		printf("\n    ");
		for(y=c; y<lx-1; y++)
		printf("   %c  ",tile[set[y][t]].segments[0]);
		printf("\n");
		if(t<10)
		printf("%d   ",t);
		if(t<100&&t>9)
		printf("%d  ",t);
		if(t<1000&&t>99)
		printf("%d ",t);
		for(y=c; y<lx; y++)
		{
			printf(" %c ",tile[set[y][t]].segments[3]);
			if(strcmp(tile[set[y][t]].special, "Temple")==0)
			printf("%c %c",'T',tile[set[y][t]].segments[1]);
			else
			{
				if(strcmp(tile[set[y][t]].special, "Emblem")==0)
				printf("%c %c",'E',tile[set[y][t]].segments[1]);
				else
				printf("  %c",tile[set[y][t]].segments[1]);
			}
		}
		printf("\n    ");
		for(y=c; y<lx; y++)
		printf("   %c  ",tile[set[y][t]].segments[2]);
	}
}
int choicevalid(int chosen,int typesoftiles)
{
	int validity=0;
	while(validity==0)
	{
		if(chosen>typesoftiles||chosen<0)
		{
			printf("Wrong id, try again\n");
			scanf("%d", &chosen);
		}
		else
		{
			if(tile[chosen].quantity==0)
			{
				printf("Tile unavilable, choose other");
				scanf("%d", &chosen);
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
//	printf("set %d\n",set[coordx][coordy]);
	if(tile[set[coordx][coordy]].segments[3]==tile[set[coordx-1][coordy]].segments[1])
	valid++;
	if(set[coordx-1][coordy]==0)
	zero++;
//	printf("set-1 %d\n",set[coordx-1][coordy]);
	if(tile[set[coordx][coordy]].segments[1]==tile[set[coordx+1][coordy]].segments[3])
	valid++;
	if(set[coordx+1][coordy]==0)
	zero++;
//	printf("set+1 %d\n",set[coordx+1][coordy]);
	if(tile[set[coordx][coordy]].segments[2]==tile[set[coordx][coordy-1]].segments[0])
	valid++;
	if(set[coordx][coordy-1]==0)
	zero++;
//	printf("set-1 %d\n",set[coordx][coordy-1]);
	if(tile[set[coordx][coordy]].segments[0]==tile[set[coordx][coordy+1]].segments[2])
	valid++;
	if(set[coordx][coordy+1]==0)
	zero++;
//	printf("set+1 %d\n",set[coordx][coordy+1]);
	printf("valid %d zero %d\n",valid,zero);
	if(valid+zero==4&&valid>0)	//one for each near tile
	return 1;
}
				
		


int main()
{
	int limit;
	char sts[10];
	int typesoftiles=0;
	int i=1,added=0;
	int segcheck=0;
	int equal=0;
	FILE *read;
	char c[1000];
	read = fopen("test.txt","r");
	if (!read)
	return 1;
	while ( fscanf( read, "%s", c )!=EOF)
	{
		fscanf(read,"%[^\n]", c);		// reads text until newline 
		strcpy (sts, c);
		//printf("%d\n",quantitycheck(typesoftiles));
		if(quantitycheck(typesoftiles)==0)
		{
			typesoftiles++;
			tile[typesoftiles].segments[0]=sts[0];
			tile[typesoftiles].segments[1]=sts[1];
			tile[typesoftiles].segments[2]=sts[2];
			tile[typesoftiles].segments[3]=sts[3];
			if(sts[4]-'0'==1)
			strcpy (tile[typesoftiles].special,"Temple");
			if(sts[5]-'0'==1)
			strcpy (tile[typesoftiles].special,"Emblem");
			if(sts[4]-'0'==0&&sts[5]-'0'==0)
			strcpy (tile[typesoftiles].special,"Nothing");
			tile[typesoftiles].id=typesoftiles;
			tile[typesoftiles].quantity++;
		}
		else
		{
			for(i=1;i<=typesoftiles;i++)		//still need more work
			{
	//			printf("loop %d		",i);
				for(segcheck=0;segcheck<6;segcheck++)
				{
				//	printf("%c	%c\n",sts[segcheck],tile[i].segments[segcheck]);		//checking if the letters are the same
					if(segcheck>3)
					sts[segcheck]=sts[segcheck]-'0';
					if(segcheck<4)
					{
						if(sts[segcheck]==tile[i].segments[segcheck])
						{
							equal++;
						}
					}
					if(segcheck==4)
					{
						if(sts[segcheck]==1&&strcmp(tile[i].special, "Temple")==0)
						{
							equal++;
						}
						if(sts[segcheck]==0&&(strcmp(tile[i].special, "Nothing")==0||strcmp(tile[i].special, "Emblem")==0))
						{
							equal++;
						}
					}
					if(segcheck==5)
					{
						if(sts[segcheck]==1&&strcmp(tile[i].special, "Emblem")==0)
						{
							equal++;
						}
						if(sts[segcheck]==0&&(strcmp(tile[i].special, "Nothing")==0||strcmp(tile[i].special, "Temple")==0))
						{
							equal++;
						}
					}
					if(segcheck>3)
					sts[segcheck]=sts[segcheck]+'0';
				}
		//		printf("tile1 %s tile2 %s equal %d\n",sts,tile[i].segments,equal);
				if(equal==6)
				{
				tile[i].quantity++;
				added=1;
				}
				equal=0;
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
				if(sts[5]-'0'==1)
				strcpy (tile[typesoftiles].special,"Emblem");
				if(sts[4]-'0'==0&&sts[5]-'0'==0)
				strcpy (tile[typesoftiles].special,"Nothing");
				tile[typesoftiles].id=typesoftiles;
				tile[typesoftiles].quantity++;
			}
		}
		added=0;
		
	}
	fclose(read);			// end of input file reading	
	yourtiles(typesoftiles);
	printf("Number of tiles left %d\n",quantitycheck(typesoftiles));
	limit=2*(quantitycheck(typesoftiles)+2);
	int map[limit][limit],j;
	memset(map, 0, sizeof(map[0][0]) * limit * limit);
//	printf("number of tiles %d\n limit %d\n",numberoftiles,limit);
	int chosen,validity=0;
	printf("Choose id of the first tile\n");		//enter first tile
	scanf("%d", &chosen);
	while(validity==0)
	{
		if(chosen>typesoftiles-1||chosen<1)
		{
			printf("Wrong id, try again\n");
			scanf("%d", &chosen);
		}
		else
		validity=1;
	}
	int ITP=quantitycheck(typesoftiles)+1;	//initial tile placement
	map[ITP][ITP]=tile[chosen].id;
	tile[chosen].quantity--;
//	printf("map[%d][%d] %d\n",ITP,ITP,map[ITP][ITP]);		//chosen center tile info
	tileset(limit,limit,map,typesoftiles);
	int chosencoord1,chosencoord2;
	for(i=quantitycheck(typesoftiles);i>0;i--)
	{
		printf("\n\n");
		yourtiles(typesoftiles);
		printf("Number of tiles left %d\n",quantitycheck(typesoftiles));
		printf("\nChoose id of the next tile\n");		//enter first tile
		scanf("%d", &chosen);
		while(validity==0)
		{
			if(chosen>typesoftiles-1||chosen<1)
			{
				printf("Wrong id, try again\n");
				scanf("%d", &chosen);
			}
			else
			validity=1;
		}
		printf("Choose coordinates for the tile (x,y) \n");
		scanf("%d,%d", &chosencoord1,&chosencoord2);
		if(ifempty(limit,limit,chosencoord1,chosencoord2,map)!=1)
		{
			printf("There is already a tile at chosen coordinates, try again \n");
			printf("Choose coordinates for the tile (x,y) \n");
			scanf("%d,%d", &chosencoord1,&chosencoord2);
		}
		map[chosencoord1][chosencoord2]=tile[chosen].id;
		while(placementvalid(limit,limit,chosencoord1,chosencoord2,map)!=1)
		{
			printf("Invalid coordinates, try again \n");
			printf("Choose coordinates for the tile (x,y) \n");
			scanf("%d,%d", &chosencoord1,&chosencoord2);
			map[chosencoord1][chosencoord2]=tile[chosen].id;
		}
//		map[chosencoord1][chosencoord2]=tile[chosen].id;
		tile[chosen].quantity--;
		tileset(limit,limit,map,typesoftiles);
	}
}
