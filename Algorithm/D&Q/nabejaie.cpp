#include<iostream>

using namespace std;

long long int merge(long int arr[], long int l, long int m,long int h, long int len)
{
    long long int i = l , j = m+1 , arr_index = l , remain = 0 , count = 0, temp[len];
    for(int i=l;i<h+1;++i)
        temp[i] = arr[i];
    while((i<=m) && (j<=h)) {
        if(temp[i] <= temp[j]){
            arr[arr_index] = temp[i];
            i++;
            count += remain;
        }
        else {
            arr[arr_index] = temp[j];
            j++;
            remain++;
        }
        arr_index++;
    }

    while (j <= h) {
        arr[arr_index] = temp[j];
        j++;
        arr_index++;
    }
    while (i <= m) {
        arr[arr_index] = temp[i];
        i++;
        arr_index++;
        count+=remain;
    }
    return count;
}

long long int swap_counter(long int arr[], long int l, long int h,long int len)
{

    if (l >= h)
        return 0;
    long int m = l + (h - l) / 2;
    return swap_counter(arr, l, m, len) + swap_counter(arr, m + 1, h,len) + merge(arr, l, m, h,len);
}
int main()
{
    long int len;
    cin>>len;
    long int arr[len];
    for(int i=0;i<len;++i) {
        cin>>arr[i];
    }
    cout<<swap_counter(arr,0,len-1,len)<<endl;
    return 0;
}


