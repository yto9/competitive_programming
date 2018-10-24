#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, X; cin >> N >> X;
    vector<int> vl;
    vector<int> vu;
    REP(i, N) {
        int tmp; cin >> tmp;
        if (tmp>X) vu.push_back(tmp);
        else vl.push_back(tmp);
    }
    sort(vu.begin(), vu.end());
    sort(vl.begin(), vl.end(), greater<int>());
    
    int ml = (vl.size() == 0)? 0 : X - vl[0];
    int mu = (vu.size() == 0)? 0 : vu[0] - X;
    for (int i = 1; i < vl.size(); i++) {
        ml = gcd(ml, vl[i - 1] - vl[i]);
    }
    for (int i = 1; i < vu.size(); i++) {
        mu = gcd(mu, vu[i] - vu[i - 1]);
    }
    if (ml * mu != 0) {
        cout << gcd(ml, mu) << endl;
    } 
    else {
        cout << max(ml, mu) << endl;
    }
    return 0;
}
