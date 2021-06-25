
#include <cstdlib>
#include <memory.h>
#include <stdio.h>
#include "Statek.h"


typedef enum
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
}directions;

int move( int** pTab, int rows, int cols, int min_depth, int move, int x, int y, int* px, int* py, int** pRoot )
{
	*px = x;
	*py = y;
	switch( move )
	{
	case UP: ( *px )--; break;
	case RIGHT: ( *py )++; break;
	case DOWN: ( *px )++; break;
	case LEFT: ( *py )--; break;
	}
	if( ( *px<0 )||( *py<0 )||( *px>=rows )||( *py>=cols ) ) return 0;
	if( !( pTab[*px][*py]>min_depth ) ) return 0;
	if( pRoot[*px][*py] ) return 0;
	return 1;
}
int root( int** pTab, int rows, int cols, int min_depth, int x, int y, int** pRoot, int x_dest, int y_dest )
{
	static int move_count = 0;
	pRoot[x][y] = ++move_count;

	if( ( x==x_dest )&&( y==y_dest ) ) return 1;
	int xx = x, yy = y;
	for( int i = 0; i<4; i++ )
	{
		if( move( pTab, rows, cols, min_depth, i, x, y, &xx, &yy, pRoot ) )
		{
			if( root( pTab, rows, cols, min_depth, xx, yy, pRoot, x_dest, y_dest ) ) return 1;
		}
	}
	pRoot[xx][yy] = 0;
	move_count--;
	return 0;
}
void clearRoot( int** pRoot, int rows, int cols )
{
	memset( *pRoot, 0, rows*cols*sizeof( int ) );
}
int setTab( char* sFile, int** pTab, int rows, int cols )
{
	FILE* fin = fopen( sFile, "r" );
	if( !fin ) return 0;
	for( int i = 0; i<rows; i++, pTab++ )
	{
		int* pRow = *pTab;
		for( int j = 0; j<cols; j++, pRow++ )
		{
			fscanf( fin, "%d", pRow ); 
		}
	}
	return 1;
}