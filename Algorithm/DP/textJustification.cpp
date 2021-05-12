#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

vector <string> words;
vector <long int> parent_pointers(100000);
const int maxn = 10000;
long int W, words_len[maxn], dp[maxn], ind =0;

long int argmin(int i,int j, long int ans, long int cdpPlusBadness)
{
    if(cdpPlusBadness < ans)
    {
        parent_pointers[i] = j;
        return cdpPlusBadness ;
    }
    return ans ;
}
long int badness(int i, int j) {
    long int sum = 0;
    for(int k=i;k<j;++k)
        sum += words_len[k];
    sum += j - i - 1;
    return (long int)pow(W - sum, 3);
}
void splitWords(string str)
{
    istringstream ss(str);
    string word;
    while (ss >> word)
    {
        words.push_back(word);
        words_len[ind] = word.length();
        ind++;
    }
}
long int cdp(long int i){
    if(dp[i] != -1)
        return dp[i];
    if(i == ind)
        return dp[i] = 0;
    long int sum_w = 0, ans = INT32_MAX;
    for(int j = i; j < ind; j++){
        sum_w += words_len[j];
        if(sum_w <= W){
            sum_w++;
            ans = argmin(i,j+1, ans, cdp(j + 1) + badness(i, j+1));
        }
        else
            break;
    }
    return dp[i] = ans;
}

int main(){
    cin >> W;
    cin.ignore();
    string line;
//    while (true)
//    {
//        getline(cin, line);
//        if (line.empty())
//            break;
//        splitWords(line);
//    }
    while(cin >> line) {
        splitWords(line);
    }
    for(int i = 0; i <= ind; i++)
        dp[i] = -1;
    cout << cdp(0) << endl;
    int it = 0, j =0;
    while(it < words.size() )
    {
        it = parent_pointers[j];
        for(int i = j; i <= it+1 ; i++)
        {
            if(i + 1 == it) {
                cout<<words[i];
                break;
            }
            cout << words[i] << " " ;
        }
        cout << endl ;
        j = it ;
//        cout<<it<<" "<<endl;
    }
}