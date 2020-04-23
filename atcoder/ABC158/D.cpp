#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string S; cin >> S;
    int Q; cin >> Q;
    string S1 = "";
    string S2 = "";
    int numT1 = 0;
    REP(i, Q) {
        int t1; cin >> t1;
        if (t1 == 1) {
            numT1++;
            continue;
        }
        else {
            int f;
            char c;
            cin >> f >> c;
            if (numT1%2 == 0 && f == 1) S1.push_back(c);
            else if (numT1%2 == 0 && f == 2) S2.push_back(c);
            else if (numT1%2 == 1 && f == 1) S2.push_back(c);
            else if (numT1%2 == 1 && f == 2) S1.push_back(c);
         }
    }
    // cerr <<"S1:" << S1 << endl;
    // cerr <<"S2:" << S2 << endl;
    if (numT1%2) {
        reverse(S2.begin(), S2.end());
        reverse(S.begin(), S.end());
        cout << S2 << S << S1 << endl;
    }
    else {
        reverse(S1.begin(), S1.end());
        cout << S1 << S << S2 << endl;
    }
    return 0;
}
