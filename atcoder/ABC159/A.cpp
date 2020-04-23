#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    cout << (N+M)*(N+M-1)/2 - N * M << endl;
    return 0;
}
