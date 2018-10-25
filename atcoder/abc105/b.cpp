#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    string ans = "No\n";
    for(int i = 0; i <= N / 7; i++) {
        int sum7 = 7*i;
        if((N - sum7)%4 == 0) {
            ans = "Yes\n";
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
