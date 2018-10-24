#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    REP(i, n) {
        int l, r; cin >> l >> r;
        v1.push_back(make_pair(l,r));
        v2.push_back(make_pair(l,r));
    }

    auto itr_l = *max_element(v1.begin(), v1.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.first < rhs.first;
    });
    auto itr_r = *min_element(v1.begin(), v1.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.second < rhs.second;
    });
    int res = max(0, itr_r.second - itr_l.first);
    // possibly L will change
    sort(v1.begin(),v1.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs){
        if (lhs.first == rhs.first) return lhs.second > rhs.second;
        else return lhs.first < rhs.first;
    });
    itr_l = *max_element(v1.begin(), v1.end() - 1,[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.first < rhs.first;
    });
    itr_r = *min_element(v1.begin(), v1.end() - 1,[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.second < rhs.second;
    });
    res = max(res, itr_r.second - itr_l.first);
    // possibly R will change
    sort(v2.begin(),v2.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs){
        if (lhs.second == rhs.second) return lhs.first > rhs.first;
        else return lhs.second < rhs.second;
    });
    itr_l = *max_element(v2.begin() + 1, v2.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.first < rhs.first;
    });
    itr_r = *min_element(v2.begin() + 1, v2.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.second < rhs.second;
    });
    res = max(res, itr_r.second - itr_l.first);
    
    cout << res << endl;
    return 0;
}
