#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n; cin >> n;
    priority_queue<ll> a;
    priority_queue<ll> b;
    REP(i, n) {
        ll tmp; cin >> tmp;
        a.push(tmp);
    }
    REP(i, n) {
        ll tmp; cin >> tmp;
        b.push(tmp);
    }
    ll ta, tb;
    if(!a.empty()) ta = a.top();
    else ta = 0;
    if(!b.empty()) tb = b.top();
    else tb = 0;
    ll res = 0;
    while (ta + tb != 0){
        //turn A
        if (ta > tb) {
            res += ta;
            a.pop();
            if(!a.empty()) ta = a.top();
            else ta = 0;
        }
        else {
            b.pop();
            if(!b.empty()) tb = b.top();
            else tb = 0;
        }
        if (ta + tb == 0) break;
        //turn B
        if (tb > ta) {
            res -= tb;
            b.pop();
            if(!b.empty()) tb = b.top();
            else tb = 0;
        }
        else {
            a.pop();
            if(!a.empty()) ta = a.top();
            else ta = 0;
        }
    }
    cout << res << endl;
    return 0;
}
