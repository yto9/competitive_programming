#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int K; cin >> K;
    int even = K/2;
    int odd = K/2 + (K%2);
    cout << even * odd << endl;
    return 0;
}
