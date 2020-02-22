#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> v;
    REP(i, N) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    for(auto x:v){
        if(x % 2 == 0) {
            if (x % 3 == 0 || x % 5 == 0) {
                continue;
            }
            else {
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}
