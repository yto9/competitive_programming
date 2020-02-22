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
        int n; cin >> n;
        if (n < 4) cout << 4 - n << endl;
        else if (n % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}
