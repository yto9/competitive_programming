#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int a,b; cin >> a >> b;
    int ma = max(a,b);
    int mi = min(a,b);
    REP(i, ma) {
        cout << mi;
    }
    cout << endl;
    return 0;
}
