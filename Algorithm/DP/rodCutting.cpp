#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long val[n];
    for(int i=0;i<n;++i) {
        cin>>val[i];
    }
    long Max = INT8_MIN;
    long opt[n+1];
    opt[0]=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j) {
            Max  = max(val[j]+opt[i-j],Max);
        }
        opt[i+1]=Max;
    }
    cout<<opt[n]<<endl;
    return 0;

}

