#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    vector<int> v;
    vector<double> v_ruiseki;
    REP(i, N) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        if (i==0) v_ruiseki.push_back((tmp+1)*tmp/2/(double)tmp);
        else v_ruiseki.push_back((tmp+1)*tmp/2/(double)tmp+v_ruiseki.back());
    }
    double max_sum_seq_K = 0.0;
    for(int i = K-1; i < N; i++) {
        if (i == K - 1) max_sum_seq_K = max(max_sum_seq_K, v_ruiseki[i]);
        else max_sum_seq_K = max(max_sum_seq_K, v_ruiseki[i] - v_ruiseki[i-K]);
    }
    cout << fixed << setprecision(7) << max_sum_seq_K << endl;
    return 0;
}
