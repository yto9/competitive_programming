#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a;
    REP(i,n) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    bool up = true;
    REP(i,n) {
        if (a[i] % 2 == 0) cout << a[i] / 2 << endl;
        else {
            if (up && a[i] > 0) {
                cout << (a[i] / 2) + 1 << endl;
                up = false; 
            }
            else if (up && a[i] < 0) {
                cout << a[i]/ 2 << endl;
                up = false;
            }
            else if (!up && a[i] > 0) {
                cout << a[i]/2 << endl;
                up = true;
            }
            else {
                cout << a[i]/2 -1 << endl;
                up = true;
            }
        }
    }
    return 0;
}
