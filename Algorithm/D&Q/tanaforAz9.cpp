#include <iostream>
#include <cmath>
using namespace std;

long power(long d) {
    if(d==1)
        return 9;
    if(d % 2 != 0)
        return (power(d/2) * power(d/2) * 9) % 1000000007;
    else
        return (power(d/2) * power(d/2)) % 1000000007;

}

int main() {
    long d;
    cin>>d;
    if(d==1)
        cout<<8<<endl;
    else
        cout<<(8*power(d-1)) % 1000000007<<endl;
    return 0;
}
