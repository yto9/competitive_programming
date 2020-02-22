#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string N; cin >> N;
    string P; // 1の位から
    bool carry = false;
    ll res = 0;
    for (auto itr = N.rbegin(); itr != N.rend(); itr++) {
        if (*itr + (carry == true) - '5' < 0) {
            P.push_back(*itr + (carry == true));
            res += *itr + (carry == true) - '0';//釣りは発生しない　支払い分
            carry = false;
        }
        else if (*itr + (carry == true) - '5' == 0)
        {
            if (itr != N.rend() && *(itr+1) - '5' >= 0) {
                P.push_back('0');
                res += (10 - (*itr + (carry == true) - '0')) % 10; //支払いは発生しない 釣り分
                carry = true;    
            }
            else {
                P.push_back(*itr + (carry == true));
                res += *itr + (carry == true) - '0';//釣りは発生しない　支払い分
               carry = false;
            }
        }
        else {
            P.push_back('0');
            res += (10 - (*itr + (carry == true) - '0')) % 10; //支払いは発生しない 釣り分
            carry = true;
        }
    }
    if (carry) {
        P.push_back('1');
        res += 1;
    }
    reverse(P.begin(), P.end());
    // ll shiharai = 0;
    // for (auto x: P) {
    //     shiharai += x - '0';
    // }
    cout << res << endl;
    return 0;
}
