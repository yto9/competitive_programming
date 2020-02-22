#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
const int MAX = 1000000;
bool IsPrime[MAX];
vector<int> Era(int n = MAX) {
    vector<int> res;
    IsPrime[0] = false; IsPrime[1] = false; 
    for (int i = 2; i < n; ++i) IsPrime[i] = true;
    for (int i = 2; i < n; ++i) {
        if (IsPrime[i]) {
            res.push_back(i);
            for (int j = i*2; j < n; j += i) IsPrime[j] = false;
        }
    }
    return res;
}
typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    Era();
    int X; cin >> X;
    while(IsPrime[X]!=true) {
        X++;
    }
    cout << X << endl;
    return 0;
}
