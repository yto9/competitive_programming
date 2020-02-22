#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int a,b,c; cin >> a >> b >> c;
    int r = a + b + c;
    if (r > 21) {
        cout << "bust" << endl;
    }
    else {
        cout << "win" << endl;
    }
    return 0;
}
