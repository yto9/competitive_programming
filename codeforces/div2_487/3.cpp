#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

vector<string> d1;
vector<string> d2;
int main(int argc, char const *argv[])
{
    int a,b,c,d; cin >> a >> b >> c >> d;
    char lg,ll,rg,rl;
    if (a >= b) {
        lg = 'A';
        ll = 'B';
    }
    else {
        lg = 'B';
        ll = 'A';
    }
    if (c >= d) {
        rg = 'C';
        rl = 'D';
    }
    else {
        rg = 'D';
        rl = 'C';
    }
    string l(50,lg);
    string r(50,rg);
    l[49] = ll;
    d1.push_back(l);
    r[0] = rl;
    d2.push_back(r);
    a--;b--;c--;d--;// use each 1 time
    l[49] = rg;
    r[0] = lg;
    REP(i, 25 - 1) {
        d1.push_back(l);
        d2.push_back(r);
    }
    // x = x - 1;
    REP(j, 5) {
        if (a * b == 0) break;
        for (int i = 2; i < 49; i += 2) {
            d1[j][i] = ll;
            a--;b--;
            if (a * b == 0) break;
        }
    }
    REP(j, 5) {
        if (c * d == 0) break;
        for (int i = 2; i < 49; i += 2) {
            d2[j][i] = rl;
            c--;d--;
            if (c * d == 0) break;
        }
    }

    REP(j, 5) {
        if (a * b == 0) break;
        for (int i = 2; i < 49; i += 2) {
            d1[j][i] = rg;
            a--;b--;
            if (a * b == 0) break;
        }
    }

    REP(j, 5) {
        if (c * d == 0) break;
        for (int i = 2; i < 49; i += 2) {
            d2[j][i] = lg;
            c--;d--;
            if (c * d == 0) break;
        }
    }

    cout << "50 50\n";
    REP(i, 25) {
        cout << d1[i] << "\n";
        cout << d2[i] << "\n";
    }
    return 0;
}
