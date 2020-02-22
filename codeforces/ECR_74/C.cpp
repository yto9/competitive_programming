#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int q; cin >> q;
    REP(test, q) {
        int h, n; cin >> h >> n;
        vector<int> cliff;
        int res = 0;
        REP(i, n) {
            int tmp; cin >> tmp;
            cliff.push_back(tmp);
        }
        int i = 0;
        int current = cliff[0];
        while(i < n - 1) {
            if (current <= 2) break;
            if (cliff[i+1] != current - 1) {
                current = cliff[i+1] + 1;
            }
            else if (i < n - 2 && cliff[i+2] == current - 2) {
                current = cliff[i+2]; i+=2;
            }
            else if (i == n-1) {
                break;
            }
            else {
                res++;
                current -= 2;i++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
