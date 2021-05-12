#include<iostream>
#include <algorithm>
using namespace std;

long int count(long int arr[],long int len,long int x) {
    int c = 0;
    for(int i=0;i<len;++i) {
        if(arr[i]==x) {
            c++;
            if(c==2)
                break;
        }
    }
    return c;
}
long int find_max(long int arr[],long int len) {
    long int max = *max_element(arr , arr + len);
    long int n_max = count(arr,len,max);
    if(n_max == 1)
        return max;
    else {
        long int index1, index2;
        for(int i=0;i<len;++i) {
            if(arr[i]==max) {
                index1 = i;
                break;
            }
        }
        for(int i=0;i<len;++i) {
            if(arr[i]==max && i != index1) {
                index2= i;
                break;
            }
        }

        int t_len = index2-index1-1;
        if(t_len!=0) {
            index1++;
            long int temp[t_len];
            for(int i=0;i<t_len;++i) {
                temp[i] = arr[index1];
                index1++;
            }
            return *max_element(temp , temp + t_len);
        }
        else {
            arr[index1] = 0 ;
            arr[index2] = 0 ;
            for(int i=0;i<len;++i) {
                if(arr[i])
                    break;
                else if(i==len-1)
                    return 0;
            }
            return find_max(arr,len);
        }

    }
}

int main()
{
    long int len;
    cin>>len;
    long int arr1[len];
    for(int i=0;i<len;++i) {
        cin>>arr1[i];
    }
    long int arr2[len];
    for(int i=0;i<len;++i) {
        cin>>arr2[i];
    }
    long int ans1 = find_max(arr1,len);
    long int ans2 = find_max(arr2,len);
    cout << max(ans1,ans2);
    return 0;
}


