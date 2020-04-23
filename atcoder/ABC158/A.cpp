#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string S; cin >> S;
    if (S[0]== S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
