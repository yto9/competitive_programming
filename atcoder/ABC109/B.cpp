#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<string> v;
    unordered_map<string,int> ump;
    REP(i, N) {
        string s; cin >> s;
        v.push_back(s);
        ump[s]++;
        if(ump[s] >= 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    char pre = v[0].back();
    for (int i = 1; i < N; i++) {
        if (pre != v[i].front()) {
            cout << "No" << endl;
            return 0;
        }
        pre = v[i].back();
    }
    cout << "Yes" << endl;
    return 0;
}
