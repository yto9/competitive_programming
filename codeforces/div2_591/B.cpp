#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int q; cin >> q;
    REP(i, q){
        string s,t;
        cin >> s;
        cin >> t;
        map<char,int> mp_alpha;
        for(auto x:s) {
            mp_alpha[x]++;
        }
        bool possible = false;
        for(auto x:t) {
            if(mp_alpha[x] > 0){
                possible = true;
                break;
            }
        }
        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
