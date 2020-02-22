#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> v;
    vector<int> vmi;
    REP(i, N) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        if (i == 0) {
            vmi.push_back(tmp);
        }
        else {
            vmi.push_back(min(tmp,vmi[i-1]));
        }
    }
    int res = 0;
    REP(i, N) {
        if (vmi[i] == v[i]) res++;
    }
    cout << res << endl;
    return 0;
}
