#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<double,double> pdd;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pdd> v_p;
    REP(i, N) {
        pdd tmp;
        cin >> tmp.first >> tmp.second;
        v_p.push_back(tmp);
    }
    double res = 0;
    ll cnt = 0;
    sort(v_p.begin(),v_p.end());
    do {
        REP(i, v_p.size()-1) {
            res += hypot(v_p[i+1].first - v_p[i].first, v_p[i+1].second - v_p[i].second);
        }
        cnt++;
    } while (next_permutation(v_p.begin(), v_p.end()));
    cerr << res << ":" << cnt << endl;
    cout << std::fixed << std::setprecision(10) << res/cnt << endl;
    return 0;
}
