#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string A; cin >> A;
    char ans[10];
    if (A.size()>1) {
        int len = A.copy(ans,A.size()-1);
        ans[len] = '\0';
    }
    else if (A[0] != 'a') {
        ans[0] = A[0] - 1;
        ans[1] = '\0';
    }
    else {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
