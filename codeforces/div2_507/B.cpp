#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n,k; cin >> n >> k;
    int num = (n - 1) / (2*k + 1) + 1;
    cout << num << endl;
    int rest = (2*k + 1) * num - n; // 0<= rest <= 2k
    int first = min((2*k + 1) - rest, k + 1);
    REP(i, num) {
        if (i != num -1 ) cout << first + i * (2*k + 1) << " ";
        else cout << first + i * (2*k + 1) << endl;
    } 
    return 0;
}
