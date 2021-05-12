#include <iostream>
#include <string>
using namespace std;
long int dp[32];
long int c[32][32];
long int count(long int ind, long int n) {
    if(dp[ind] != -1)
        return dp[ind];
    dp[ind] = 0;
    for(int j= ind;j<n;++j) {
        if(j+1 == n)
            dp[ind] += c[ind][j];
        else
            dp[ind] += count(j+1,n) * c[ind][j]  % 1000000007;
    }
    return dp[ind];
}

int main()
{
    long int n;
    cin>>n;
    string str;
    cin>>str;
    long int len = str.length();
    cin.ignore();

    for(int i=0;i<len;++i) {
        for(int j=0;j<len;++j)
            c[i][j] = 0;
    }
    for(int k=0;k<n;++k) {
        string sub;
        long int cn;
        cin>>sub;
        cin.ignore();
        cin>>cn;
        long int pos = -1;
        for(int l=1;l<=len;++l) {
            while(str.find(sub,pos+l) != string::npos) {
                pos = str.find(sub,pos+l) ;
                long int length = sub.length();
                long int i = pos, j = pos + length - 1;
                c[i][j] = cn;
            }
        }
    }
//    for(int i=0;i<len;++i) {
//        for(int j=0;j<len;++j)
//            cout<<c[i][j]<<" ";
//        cout<<endl;
//    }
    for(int i = 0; i <= len; i++)
        dp[i] = -1;

    cout << count(0,len) % 1000000007<< endl;
    return 0;
}




