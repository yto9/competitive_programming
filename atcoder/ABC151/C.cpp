#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int, string> p_is;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, M; cin >> N >> M;
    int v[100000];
    REP(i, M) {
        v[i] = 0;
    }
    ll ac = 0;
    ll wa = 0;
    REP(i, M) {
        int tmp;
        string st;
        cin >> tmp >> st;
        if (v[tmp] >= 0) {
            if (st == "WA") v[tmp]++;
            if (st == "AC") {
                wa += v[tmp];
                if (v[tmp] >= 0) ac++;
                v[tmp] = -1;
            }
        }
    }
    cout << ac << " " << wa << endl;
    return 0;
}
