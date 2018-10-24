#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<pair<int, int>> vxl;
    vector<pair<int, int>> vxr;
    vector<pair<int, int>> vyb;
    vector<pair<int, int>> vyt;
    int v[140000][4];
    REP(i, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
        vxl.push_back(make_pair(i,v[i][0]));
        vxr.push_back(make_pair(i,v[i][2]));
        vyb.push_back(make_pair(i,v[i][1]));
        vyt.push_back(make_pair(i,v[i][3]));
    }
    vector<int> idx;
    sort(vxl.begin(),vxl.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.second > rhs.second;
    });
    idx.push_back(vxl[0].first);
    sort(vxr.begin(),vxr.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.second < rhs.second;
    });
    idx.push_back(vxr[0].first);
    sort(vyb.begin(),vyb.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.second > rhs.second;
    });
    idx.push_back(vyb[0].first);
    sort(vyt.begin(),vyt.end(),[](const pair<int,int>& lhs, const pair<int,int>& rhs) {
        return lhs.second < rhs.second;
    });
    idx.push_back(vyt[0].first);

    REP(i, 4) {
        int xl = (vxl[0].first == idx[i])? vxl[1].second :vxl[0].second;
        int xr = (vxr[0].first == idx[i])? vxr[1].second :vxr[0].second;
        int yb = (vyb[0].first == idx[i])? vyb[1].second: vyb[0].second;
        int yt = (vyt[0].first == idx[i])? vyt[1].second :vyt[0].second;
        if (xl <= xr && yb <= yt) {
            cout << xl << " " << yb << endl;
            return 0;
        }
    }
    cout << "fail" << endl;
    return 0;
}
