#include <iostream>
using namespace std;

int main () {
    int n , sum = 0 , x , s = 0 ;
    cin >> n ;
    for(int i = 0 ; i <= n ; ++i ) {
        sum += i ;
    }
    for(int i = 0 ; i < n ; ++i ) {
        cin >> x ;
        s += x ;
    }
    cout << sum - s << endl ;
    return 0;
}