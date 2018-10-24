#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n, k; cin >> n >> k;
    cout << k / n + (k%n!=0)<< endl;
    return 0;
}
