#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int X,Y; cin >> X >> Y;
    int res = 0;
    if (X==1&&Y==1) res += 400000;
    if (X==1) res += 300000;
    if (X==2) res += 200000;
    if (X==3) res += 100000;
    if (Y==1) res += 300000;
    if (Y==2) res += 200000;
    if (Y==3) res += 100000;
    cout << res << endl;
    return 0;
}
