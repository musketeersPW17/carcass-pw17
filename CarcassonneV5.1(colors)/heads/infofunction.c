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
	for(t=0;t<typesoftiles;t++)
	{
		number=number+tile[t].quantity;
	}
	return number;
}
