#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    string S; cin >> S;
    string ans = "b";
    int res = 0;
    while(1){
        if (ans.size() >= N) {
            if (ans == S) {
                cout << res << endl;
                return 0;
            }
            else break;
        }
        ans = 'a' + ans + 'c';
        res++;
        if (ans.size() >= N) {
            if (ans == S) {
                cout << res << endl;
                return 0;
            }
            else break;
        }
        ans = 'c' + ans + 'a';
        res++;
        if (ans.size() >= N) {
            if (ans == S) {
                cout << res << endl;
                return 0;
            }
            else break;
        }
        ans = 'b' + ans + 'b';
        res++;
    }
    cout << -1 << endl;
    return 0;
}