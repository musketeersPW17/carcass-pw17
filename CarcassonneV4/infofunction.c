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

