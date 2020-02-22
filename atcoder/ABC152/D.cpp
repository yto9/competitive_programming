#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll res = 0;
    map<string,ll> mp;
    for (int i = 1; i <= N; i++) {
        string fala = "";
        string lafa = ""; 
        string s = to_string(i);
        char fa = s.front();
        char la = s.back();
        fala += fa;
        fala += la;
        lafa += la;
        lafa += fa;
        res += mp[lafa]*2;
        mp[fala]++;
        if (fa == la) res++;
    }
    cout << res << endl;
    return 0;
}
