
#define DEPTH_MIN 10

int move( int** pTab, int rows, int cols, int min_depth, int move, int x, int y, int* px, int* py, int** pRoot );
int root( int** pTab, int rows, int cols, int min_depth, int x, int y, int** pRoot, int x_dest, int y_dest );
void clearRoot( int** pRoot, int rows, int cols );
int setTab( char* sFile, int** pTab, int rows, int cols );