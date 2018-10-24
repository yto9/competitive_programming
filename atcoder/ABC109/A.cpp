#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int a,b; cin >> a >> b;
    if (a*b % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
