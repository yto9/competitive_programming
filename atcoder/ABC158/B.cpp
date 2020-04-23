#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, A, B; cin >> N >> A >> B;
    cout << N/(A+B) * A + min(A, N %(A+B)) << endl;
    return 0;
}
