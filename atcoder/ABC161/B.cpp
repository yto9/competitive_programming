#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int sum = 0;
    vector<int> A;
    REP(i, N) {
        int tmp; cin >> tmp;
        A.push_back(tmp);
        sum += tmp;
    }
    int cnt = 0;
    for (auto x: A){
        if (4*M*x >= sum) cnt++;
    }
    if (cnt >= M) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
