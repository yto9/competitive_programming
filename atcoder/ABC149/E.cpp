#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, M; cin >> N >> M;
    vector<ll> A;
    REP(i,N){
        ll tmp; cin >> tmp;
        A.push_back(tmp);
    }
    sort(A.begin(),A.end(),greater<ll>());
    vector<ll> rui;
    rui.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        rui.push_back(rui[i-1]+A[i]);
    }

    return 0;
}
