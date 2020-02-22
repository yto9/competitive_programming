#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    string s; cin >> s;
    if (N%2==1) {
        cout << "No" << endl;
        return 0;
    }
    else {
        REP(i, N/2) {
            if (s[i] != s[N/2 + i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    return 0;
}
