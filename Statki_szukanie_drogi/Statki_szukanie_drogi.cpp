
#include <cstdlib>
#include <memory.h>
#include <stdio.h>
#include "Statek.h"

#define ROWS 10
#define COLS 10
#define MIN_DEPTH 10

int** CreateMatrix(int rows, int cols);
void DeleteMatrix(int*** pTab);

int main( int argc, char* argv[] )
{
	if( argc!=2 )
	{
		printf( "Usage: %s <input file>", argv[0] );
		return -1;
	}
	int** pDepthsTab = CreateMatrix( ROWS, COLS );
	int** pVisitedTab = CreateMatrix( ROWS, COLS );

	if( !pVisitedTab||!pDepthsTab )
	{
		printf( "Error: Creating matrix went wrong\n" );
		return -1;
	}

	if( !setTab( argv[1], pDepthsTab, ROWS, COLS ) )
	{
		printf( "Something went wrong with file.\n" );
		return -1;
	}
	
	if( root( pDepthsTab, ROWS, COLS, MIN_DEPTH, 0, 0, pVisitedTab, 9, 9 ) )
	{
		printf("Droga:\n");
		for( int i = 0; i<ROWS; i++ )
		{
			for( int j = 0; j<COLS; j++ )
			{
				int k = pVisitedTab[i][j];
				printf("%d",k);
				if( ( k>=0 )&&( k<10 ) ) printf("%c",' ');
				printf("%c",' ');
			}
			printf("%c",'\n');
		}
	}
	else printf("Nie ma mozliwej drogi");
	DeleteMatrix( &pDepthsTab );
	DeleteMatrix( &pVisitedTab );
	return 0;
}

int** CreateMatrix( int rows, int cols )
{
	int** pTab = (int**)malloc( rows*sizeof( int* ) );
	if( !pTab ) return NULL;
	int* pTemp = (int*)malloc( rows*cols*sizeof( int ) );
	if( !pTemp ) return NULL;
	memset( pTemp, 0, rows*cols*sizeof( int ) );
	int** v = pTab;
	for( int i = 0; i<rows; i++, pTemp += cols )
	{
		*v++ = pTemp;
	}
	return pTab;
}
void DeleteMatrix( int*** pTab )
{
	free( **pTab );
	free( *pTab );
	*pTab = NULL;
}

