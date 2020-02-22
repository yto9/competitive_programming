#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, A, B; cin >> N >> A >> B;
    ll res = -1;
    if ((B-A) % 2 == 0) res = (B-A)/2;
    else {
        res = min(B-1,N-A); // 早くついたほうがひたすら待っている場合
        res -= (abs(B-A) - 1)/2;
    }
    cout << res << endl;
    return 0;
}
