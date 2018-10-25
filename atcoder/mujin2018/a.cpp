#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    bool mujin = false;
    if (S.size() >= 5) {
        if (S[0] == 'M') {
            if (S[1] == 'U') {
                if (S[2] == 'J') {
                    if (S[3] == 'I') {
                        if (S[4] == 'N') mujin = true;
                    }
                }
            }
        }
    }
    if(mujin) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
