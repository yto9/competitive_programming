#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

ll gcd(ll a,ll b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll K; cin >> K;
    ll res = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) {
            ll gcd_ij = gcd(i,j);
            for (int l = 1; l <= K; l++) {
                res += gcd(gcd_ij,l);
            }
        }
    }
    cout << res << endl;
    return 0;
}
