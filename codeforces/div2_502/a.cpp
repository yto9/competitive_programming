#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    priority_queue<int> sum;
    int target = 0;
    REP(i, n){
        int a,b,c,d; cin >> a >> b >> c >> d;
        sum.push(a + b + c + d);
        if (i == 0) target = a + b + c + d;
    }
    REP(i,n) {
        int tmp = sum.top();sum.pop();
        if (tmp == target) {
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}
