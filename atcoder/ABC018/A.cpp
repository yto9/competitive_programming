#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    vector<int> v(3);
    REP(i, 3) {
        cin >> v[i];
    }
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        if (itr == max_element(v.begin(), v.end())) cout << 1 << endl;
        else if (itr == min_element(v.begin(),v.end())) cout << 3 << endl;
        else cout << 2 << endl;
    }
    return 0;
}
