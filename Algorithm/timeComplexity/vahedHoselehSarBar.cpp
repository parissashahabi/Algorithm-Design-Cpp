#include <iostream>
using namespace std;

int main () {
    int count , num , a = 0 , x , y ;
    cin >> count ;
    for(int i = 0 ; i < count ; ++i ) {
        cin >> num ;
        y = num % 10 ;
        while ( num > 0 ) {
            num /= 10 ;
            a++;
        }
        if ( a == 1 )
            x = 1 ;
        if( a == 2 )
            x = 3 ;
        if ( a == 3 )
            x = 6 ;
        if ( a == 4 )
            x = 10 ;


        cout << ((y - 1) * 10) + x << endl ;
        a = 0 ;
    }
    return 0;
}