#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
struct data_t {
    int x;
    int y;
    int z;
    int idx;
    // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
    bool operator<( const data_t& right ) const {
        return (x == right.x) ? ((y == right.y) ? z < right.z : y < right.y): x < right.x;
    }
};
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<data_t> v;
    REP(i, n) {
        data_t d; cin >> d.x >> d.y >> d.z;
        d.idx = i + 1;
        v.push_back(d);
    }
    sort(v.begin(),v.end());
    int j = n/2 + 1;
    for (int i = n/2;i>0;i--) {
        cout << v[i-1].idx << " " << v[j-1].idx << endl;
        j++;
    }
    return 0;
}
