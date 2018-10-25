#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N,M,A,B; cin >> N >> M >> A >> B;
    set<int> s_a;
    REP(i, M) {
        int l,r; cin >> l >> r;
        for(int x = l; x <= r; x++) {
            s_a.insert(x);
        }
    }
    int num_A = (int)s_a.size();
    cout << A * num_A + B *(N - num_A) << endl;
    return 0;
}
