#include <iostream>
using namespace std;
int main(){

    int number;
    cin >> number;
    for(int i = 1 ; i <= number ; ++i ) {
        cout << i ;
        if( i == number ) {
            cout << endl ;
            break;
        }
        cout << " " ;
    }
    return 0;
}