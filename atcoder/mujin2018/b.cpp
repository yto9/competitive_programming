#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{   
    int A; cin >> A;
    string S; cin >> S;
    bool flag = false;
    for (auto x : S){
        if (A == 0) {
            flag = true; break;
        }
        if (x == '+') A++;
        if (x == '-') A--;
    }
    if (A == 0) flag = true;
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
