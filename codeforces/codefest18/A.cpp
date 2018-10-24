#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int res = 0;
    int count = 0;
    for (int i = 1; res < n ; i*=2) {
        res += i;
        count++;
    }
    cout << count << endl;
    return 0;
}
