#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> v(N);
    REP(i, N){
        cin >> v[i];
    }
    auto it_max = *max_element(v.begin(),v.end());
    auto it_min = *min_element(v.begin(),v.end());
    cout << it_max - (it_min - 1) - N << endl;
    return 0;
}
