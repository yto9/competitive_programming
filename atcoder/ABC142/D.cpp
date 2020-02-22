#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
// ll mod_pow(ll x, ll n, ll mod){//x^n % mod
//     if (n == 0)
//         return 1;
//     ll res = mod_pow(x * x % mod, n / 2, mod);
//     if (n & 1)
//         res = res * x % mod;
//     return res;
// }
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

bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll A, B; cin >> A >> B;
    ll gcd_ab = gcd(A,B);
    ll n = gcd_ab;
    ll res = 1;
    
    if(gcd_ab%2 == 0) res++;
    while(gcd_ab%2 == 0) gcd_ab/=2;
    n = gcd_ab;
    if (IsPrime(n)) {
        cout << res+1 << endl;
        return 0;
    }
    for (ll i = 3; i <= n; i=i+2) {
        if(gcd_ab%i==0) {
            res++;
            while(gcd_ab%i == 0) {
                gcd_ab /=i;
            }
            if(IsPrime(gcd_ab)) {
                res++;
                break;
            }
        }    
        if(gcd_ab == 1) break;
    }
    cout << res << endl;
    return 0;
}
