#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    vector<int> v;
    int N; cin >> N;
    vector<int> A;
    vector<int> B;
    int a = -1;
    int b = -1;
    int cnt = 0;
    REP(i,N) {
        int tmp; cin >> tmp;
        A.push_back(tmp);
        v.push_back(tmp);
    }
    REP(i,N) {
        int tmp; cin >> tmp;
        B.push_back(tmp);
    }
    sort(v.begin(),v.end());
    do {
        cnt++;
        REP(i, N) {
            if (v[i] != A[i]) break;
            if (i == N-1) a = cnt;
        }
        REP(i, N) {
            if (v[i] != B[i]) break;
            if (i == N-1) b = cnt;
        }

    } while (std::next_permutation(v.begin(), v.end()));
    cout << abs(a-b) << endl;
    return 0;
}
