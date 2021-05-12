#include <iostream>
using namespace std;
long int max(long int a,long int b){
    return a>b ? a : b;
}
long int min(long int a,long int b){
    return a>b ? b : a;
}
int main () {
    long int n,count;
    cin >> n ;
    long int aa[n];
    for(int i=0;i<n;++i) {
        cin>>aa[i];
        if(i==0)
            continue;
        aa[i] = aa[i] + aa[i-1];
    }

    cin >> count;
    for(int i=0;i<count;++i){
        long int a,b;
        cin>>a>>b;
        long int indexM = max(a,b);
        long int indexm = min(a,b);
        indexm = indexm -1;
        if(indexm<0)
            cout<<aa[indexM]<<endl;
        else
            cout<<aa[indexM] - aa[indexm] <<endl;
    }

    return 0;
}