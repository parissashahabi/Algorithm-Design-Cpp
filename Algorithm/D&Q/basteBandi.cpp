#include <iostream>
using namespace std;

bool is_fit(int arr[], int low, int high, int m, int k,int n) {
    int tempk = k , i = low;
    high = n-1;
    while((m >= 1) && (i <= high)) {
        label:
        k -= arr[i];
        if(k >= 0) {
            i++;
            if(i>high)
                break;
            goto label;
        }
        else {
            m--;
            k = tempk;
        }
    }
    if((m >= 0) && (i == high + 1))
        return true;
    else
        return false;
}
int find_j(int l, int r, int n, int m, int k, int arr[]) {

    if (r >= l) {
        int mid = l + (r - l) / 2;
        if(!is_fit(arr,mid,r,m,k,n))
            find_j(mid+1,r,n,m,k,arr);
        else {
            if(l==r)
                return n - mid;
            find_j(l,mid,n,m,k,arr);
        }
    }
}

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];

    cout<<find_j(0,n-1,n,m,k,arr)<<endl;
    return 0;
}
