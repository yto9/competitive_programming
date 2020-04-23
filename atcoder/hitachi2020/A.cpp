#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string S; cin >> S;
    if ((int)S.size() % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    REP(i, (int)S.size()/2) {
        if (S[2*i] == 'h' && S[2*i + 1] == 'i') continue;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
