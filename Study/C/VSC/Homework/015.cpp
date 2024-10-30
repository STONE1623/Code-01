#include <iostream>

using namespace std;

void print ( int w )

{ for( int i = 1 ; i <= w ; i ++)

{ for ( int j = 1 ; j <= i ; j ++)

cout << i << " " ;

cout << endl ;

}

}

int main ()

{ print( 5 ) ; }