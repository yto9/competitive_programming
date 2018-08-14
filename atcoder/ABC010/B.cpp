#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int count = 0;
    vector<int> a;
    REP(i, n) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (auto x: a) {
        while(x % 3 == 2|| x % 2 == 0) {
            count++;
            x--;
        }
    }
    cout << count << endl;
    return 0;
}
