#include <iostream>
using namespace std;
int main()
{
    long int n,m;
    cin>>n>>m;
    long long a[n + 1][m + 1];
    a[0][0] = 0 ;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if(( i == 0 && j != 0) || ( i != 0 && j == 0))
                a[i][j] = 1;
            else
                a[i][j] = (a[i-1][j] + a[i][j-1]) % 1000000007;
        }
    }
    cout<< a[n][m] % 1000000007 <<endl;

    return 0;
}



