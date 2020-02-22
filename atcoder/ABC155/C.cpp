#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    map<string, int> mp;
    REP(i, N) {
        string tmp; cin >> tmp;
        mp[tmp]++;
    }

    int ma_value = 0;
    for(auto x: mp) {
        ma_value = max(x.second, ma_value);
    }
    for (auto x: mp) {
        if (x.second == ma_value) {
            cout << x.first << endl;
        }
    }
    
    return 0;
}
