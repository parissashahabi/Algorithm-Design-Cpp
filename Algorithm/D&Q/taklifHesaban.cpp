#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double find_x(double a,double low,double high) {
    double mid = low + (high-low) / 2;
    int c = cos(mid)*1000;
    int m = a*mid*1000;
    if(c==m)
        return mid;
    if(a*mid < cos(mid))
        return find_x(a,mid,high);
    else
        return find_x(a,low,mid);

}

int main () {
    double a;
    cin>>a;
    printf("%.3lf",find_x(a,-1/a,1/a));
    cout<<endl;
    return 0;
}

