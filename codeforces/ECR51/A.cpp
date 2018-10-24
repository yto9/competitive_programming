#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int T; cin >> T;
    REP(i, T) {
        string s; cin >> s;
        vector<int> v(3,0);// digit/up/low
        for (int i = 0; i < (int) s.size(); i++){
            if (isdigit(s[i])) v[0]++;
            else if (isupper(s[i])) v[1]++;
            else if (islower(s[i])) v[2]++;
        }
        if (v[1]*v[2]*v[3] == 0) {
            vector<int> v2(v.size());
            copy(v.begin(),v.end(),v2.begin());
            sort(v2.begin(),v2.end());
            if(v2[1] == 0){
                if (v[0] > 0) {
                    s[0] = 'A';
                    s[1] = 'a';
                }
                else if (v[1] > 0) {
                    s[0] = '0';
                    s[1] = 'a';
                }
                else if (v[2] > 0) {
                    s[0] = '0';
                    s[1] = 'A';
                }
            }
            else {
                for (int i = 0; i < (int) s.size(); i++){
                    if (isdigit(s[i])&&v[0]>1){
                        if (v[1] == 0) s[i] = 'A';
                        else if (v[2] == 0) s[i] = 'a';
                        break;
                    }
                    else if (isupper(s[i])&&v[1]>1){
                        if (v[0] == 0) s[i] = '0';
                        else if (v[2] == 0) s[i] = 'a';
                        break;
                    }
                    else if (islower(s[i])&&v[2]>1){
                        if (v[0] == 0) s[i] = '0';
                        else if (v[1] == 0) s[i] = 'A';
                        break;
                    };
                }
            }
        }  
        cout << s << endl;
    }
    return 0;
}
