#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string s; cin >> s;
    int res = 0;
    int l = (int)s.size();
    REP(i, l/2){
        if (s[i] != s[l-i-1]) res++;
    }
    cout << res << endl;
    return 0;
}
