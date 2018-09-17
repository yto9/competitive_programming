#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    int visited[101] = {};
    int a, b; cin >> a >> b;
    visited[a]++; visited[b]++;
    int K; cin >> K;
    string ans = "YES";
    REP(i, K) {
        int tmp; cin >> tmp;
        if (visited[tmp] == 1) {
            ans = "NO";
            break;
        }
        visited[tmp]++;
    }
    cout << ans << endl;
    return 0;
}
