#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // 1 の場合は例外
}
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    if (n <= 2) {
        cout << "No" << endl;
        return 0;
    }
    int s = (n * (n + 1) )/ 2;
    if (is_prime(s)) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << 1 << " ";
    int idx;
    for (idx = 2; idx*idx <= s; idx++) {
        if (s % idx == 0) {
            cout << idx << endl;
            break;
        }
    }
    cout << n - 1 << " ";
    for (int i = 1; i <= n; i++) {
        if (i == idx) continue;
        if (i!= idx) cout << i;
        if (idx == n && i == n - 1) continue; 
        cout << " "; 
    }
    cout << endl;
    return 0;
}
