#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string X; cin >> X;
    string ans = "YES";
    REP(i, X.size()){
        if (X[i] == 'c'){
            if (i == X.size()-1) {
                ans = "NO";
                break;
            }
            else {
                if (X[++i] != 'h') {
                    ans = "NO";
                    break;
                }
            }
        }
        else if (X[i] == 'o' || X[i] == 'k' || X[i] == 'u') continue;
        else {
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
