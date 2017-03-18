#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Tiles
{
	char segments[4];
	int temple;
	int emblem;
	int quantity;
	int id;
};
struct Tiles tile[20];

void tileinfo( struct Tiles *tile ) 
{
   printf( "Tile Segments : %s		", tile->segments);
   printf( "Emblem : %d		", tile->emblem);
   printf( "Temple : %d		", tile->temple);
   printf( "Quantity : %d		", tile->quantity);
   printf( "ID : %d\n",tile->id);
   
   
}
void yourtiles(int tot)		//tot- types of tiles
{
	int t=1;
	for(t;t<tot;t++)
	tileinfo(&tile[t]);
}
	


int main()
{

	char sts[10];
	int typesoftiles=1;
	int i=1,added=2;
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
		if(added==0)					//checking if tile occured before
		{
			for(i=1;i<typesoftiles;i++)
			{
				if (added==0)
				{
					for(segcheck=0;segcheck<6;segcheck++)
					{
					//	printf("%c	%c\n",sts[segcheck],tile[i].segments[segcheck]);		//checking if the letters are the same
						if(segcheck>3)
						sts[segcheck]=sts[segcheck]-'0';
						if(sts[segcheck]==tile[i].segments[segcheck])
						{
							equal++;
						}
						if(segcheck>3)
						sts[segcheck]=sts[segcheck]+'0';
					}
					if(equal==6)
					{
						tile[i].quantity++;
						added=1;
					}
					else
					{
						added=2;
					}
					equal=0;
				}
			}
		}
		if(added==2)
		{
		//	printf("%s \n",sts);		//adding new type of tile
			tile[typesoftiles].segments[0]=sts[0];
			tile[typesoftiles].segments[1]=sts[1];
			tile[typesoftiles].segments[2]=sts[2];
			tile[typesoftiles].segments[3]=sts[3];
			tile[typesoftiles].emblem=sts[5]-'0';
			tile[typesoftiles].temple=sts[4]-'0';
			tile[typesoftiles].id=typesoftiles;
			tile[typesoftiles].quantity++;
			typesoftiles++;
		}
		added=0;
	}	
	fclose(read);			// end of input file reading
	
	yourtiles(typesoftiles);
	
	
}
