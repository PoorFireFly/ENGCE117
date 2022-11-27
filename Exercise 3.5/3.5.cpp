#include <stdio.h>

int main() {
	int a[10] ;
	int count[10] ;
	int b ,j ,i ;
	printf( "store in array : " ) ;
	scanf( "%d", &a[0] ) ;
	//Input
	for( i = 1 ; i <= a[0] ; i++ ) {
		printf( "Element[%d]: ", i ) ;
		scanf( "%d" , &b ) ;
		a[i] = b ;
	}//end for
		//Process
		for( i = 1 ; i <= a[0] ; i++ ) {
			if( a[i] < 10 ) {
				count[i] = 1 ;
				for( j = i+1 ; j<= a[0] ; j++ ) {
					if( a[i] < 10 ) {
						if( a[i] == a[j] ) {
							count[i] += 1 ;
							a[j] = 10 ;
						}//end if
					}//end if
				}//end for
			}//end if
		}//end for
	//Output	
	printf( "------------\n" ) ;
	for( i = 1 ; i <= a[0] ; i++ ) {
		if( a[i] < 10 ){
			printf( "%d --> %d\n", a[i], count[i] ) ;
		}
	}
	return 0 ;
}
