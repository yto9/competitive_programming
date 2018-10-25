#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N, M; cin >> N >> M;
    vector<string> table;
    REP(i, N) {
        string s; cin >> s;
        table.push_back(s);
    }
    REP(i, N) {
        int cnt = 0;
        int jj;
        REP(j, M){
            if (table[i][j] != 'B') continue;
            else {
                if (cnt == 0) {
                    jj = j;
                }
                cnt++;
            }
        }
        if (cnt > 0) {
            cout << i + 1 + cnt/2 << " " << jj + 1 + cnt/2 << endl;
            return 0;
        }
    }
    return 0;
}
