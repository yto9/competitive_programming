#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MAX_N 500000
typedef long long ll;
const int B = 700; // バケットのサイズ
string S; //全体
vector<string> bucket_s; //バケット毎のstring
vector<map<string,int>> bucket; //バケット毎のmap

void query_1(int idx, char c) {// 0-indexようの引数
    S[idx] = c;
    char target = bucket_s[idx/B][idx-B*(idx/B)];
    bucket_s[idx/B][idx-B*(idx/B)] = c;
    if (bucket[idx/B][""+target] ==1) bucket[idx/B].erase(""+target);
    bucket[idx/B][""+c]++;
}

int query_2(int l, int r) { // 0-indexようの引数
    map<string, int> merged_mp;
    // 左端を含むbucket
    
    for (int i = l; i < min(r+1, B*(l/B + 1)); i++) {
        merged_mp["" + S[i]]++;
    }
    // cerr << "left: "<< merged_mp.size() << endl;
    // 端点を含まないbucket
    // for (int i = l/B + 1; i < r/B; i++) {
    //     // for(auto x: bucket[i]) {
    //     //     merged_mp[x.first]++;
    //     // }
    //     merged_mp.insert(bucket[i].begin(),bucket[i].end());
    // }
    // cerr << "left+center: "<< merged_mp.size() << endl;

    // 右端を含むbucket
    for (int i = max(l,r/B) ; i <= r; i++) {
        merged_mp["" + S[i]]++;
    }
    return merged_mp.size();
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    cin >> S;
    string tmp_s;
    REP(i, N) {
        tmp_s.push_back(S[i]);
        if (i%B == B-1) {
            bucket_s.push_back(tmp_s);
            tmp_s = "";
        }
    }
    if (tmp_s != "") bucket_s.push_back(tmp_s);
    REP(i, bucket_s.size()) {
        map<string,int> mp;
        for(auto x: bucket_s[i]) {
            mp["" + x]++;
        }
        bucket.push_back(mp);
    }
    int Q; cin >> Q;
    REP(i, Q) {
        int type; cin >> type;
        if (type == 1) {
            int idx;
            char c;
            cin >> idx >> c;
            query_1(idx-1, c);
        }
        else if (type == 2) {
            int l, r; cin >> l >> r;
            cout << query_2(l-1,r-1) << endl;
        }
    }
    return 0;
}
