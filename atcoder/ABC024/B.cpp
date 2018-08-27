#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N;
    int T;
    cin >> N >> T;
    int sum = 0;
    int pre;
    REP(i, N) {
        int tmp; cin >> tmp;
        if (i > 0) sum += min(T, tmp - pre);
        pre = tmp;
    }
    sum += T;
    cout << sum << endl;
    return 0;
}
