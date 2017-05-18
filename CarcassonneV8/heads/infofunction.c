#include "structures.h"
#include <stdio.h>
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
void yourtiles(int tot)
{
	int t=1;
	for(t;t<=tot;t++)
	tileinfoavilable(&tile[t]);
}
int quantitycheck(int typesoftiles)
{
	int number=0;
	int t;
	for(t=1;t<=typesoftiles;t++)
	{
		number=number+tile[t].quantity;
	}
	return number;
}
void menu(int clear, int autotileset, int autotilelist)
{
	printf("1. Tileset,\n2. Tile list,\n3. Place a tile,\n4. Clear console,\n");
	printf("5. Auto-clear,		(%d)\n6. Auto-tileset,	(%d)\n7. Auto-tilelist,	(%d)\n",clear,autotileset,autotilelist);
}
