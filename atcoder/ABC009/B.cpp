#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    set<int> st;
    REP(i, N) {
        int tmp; cin >> tmp;
        st.insert(tmp);
    }
    auto itr = st.end();
    itr--;itr--;
    cout << *itr << endl;
    return 0;
}
