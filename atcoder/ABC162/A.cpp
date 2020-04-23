#include <iostream>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string N; cin >> N;
    bool flag = false;
    for (auto x: N){
        if (x == '7') flag = true;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
