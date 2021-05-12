#include <bits/stdc++.h>
using namespace std;

inline int get(int x){
    cout << "? " << x << '\n';
    cout.flush();
    int a;
    cin >> a;
    return a;
}

inline void submit(int i){
    cout << "! " << i << '\n';
    cout.flush();
}

int main(){
    long long n, mid;
    cin >> n;
    long long l = 0, r = n -1;

    while(true) {
        mid = l + (r - l) / 2;
        if(mid-1 != -1 && mid+1 != n) {
            if(get(mid)>= max(get(mid-1), get(mid+1))) {
                submit(mid);
                break;
            } else if(get(mid) < get(mid-1)) {
                r = mid-1;
                continue;
            } else {
                l = mid+1;
                continue;
            }
        } else {
            submit(mid);
            break;
        }
    }
}