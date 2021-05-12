#include <iostream>
#include <algorithm>
using namespace std;
int max_substring(int arr[], int len) {
    int maxSum = 0 ;
    for(int i=0;i<len;++i) {
        if(arr[i]>0)
            maxSum += arr[i];
    }
    if(maxSum)
        return maxSum;
    else
        return *max_element(arr , arr + len);
}
int findCSS(int l, int r, int ss[],int len) {
    int c = (l+r)/2;
    int suml = 0;
    int sumr = 0;
    int leftmax = INT8_MIN, rightmax = INT8_MIN;
    for(int i=r;i>=0;--i) {
        suml += ss[i];
        if(suml>leftmax)
            leftmax = suml;
    }
    for(int i=r+1;i<len;++i) {
        sumr += ss[i];
        if(sumr>rightmax)
            rightmax = sumr;
    }
    return leftmax+rightmax;
}
int max_subarray(int arr[], int len) {
    if(len==1)
        return arr[0];
    else{
        int lenLeft = len/2, lenRight = len - lenLeft;
        int left[lenLeft] , right[lenRight] ;
        for(int i=0;i<lenLeft;++i)
            left[i] = arr[i];

        for(int i=0;i<lenRight;++i)
            right[i] = arr[i+lenLeft];
        int ss[3];
        ss[0] = max_subarray(left , lenLeft);
        ss[1] = max_subarray(right , lenRight);
        ss[2] = findCSS(0,lenLeft, arr,len);

        return *max_element(ss , ss + 3);

    }
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {
        int len;
        cin>>len;
        int arr[len];
        for(int j=0;j<len;++j)
            cin>>arr[j];

        cout<<max_subarray(arr, len)<<" "<<max_substring(arr,len)<<endl;
    }
    return 0;
}


