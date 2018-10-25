#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v(n);
    unordered_map<int,int> ump;
    REP(i, n) {
        cin >> v[i];
        ump[v[i]]++;
    }
    int nice = 0;
    int n_nice = 0;
    vector<int> ev;
    vector<int> sv;
    for (auto x:ump) {
        if (x.second == 2) continue;
        if (x.second == 1) {
            nice++;
            sv.push_back(x.first);
        }
        else if (x.second >= 3) {
            n_nice++;
            ev.push_back(x.first);
        }
    }
    if (nice % 2 == 1 && n_nice == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int h_nice = nice/2;
    int hoge = nice%2;
    REP(i, n) {
        if (h_nice > 0) {
            bool f = false;
            for (auto s: sv) {
                if (v[i] == s) {
                    cout << "B";
                    h_nice--;
                    f = true;
                    break;
                }
            }
            if (f) continue;
        }
        if (hoge > 0) {
            bool f = false;
            for (auto e: ev) {
                if (v[i] == e) {
                    cout << "B";
                    hoge--;
                    f = true;
                    break;
                }
            }
            if (f) continue;
        }
        cout << "A";
    }
    cout << endl;
    return 0;
}
