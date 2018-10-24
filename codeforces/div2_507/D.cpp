#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n;
    int k;
    cin >> n >> k;
    ll l = 1;
    ll r = n;
    cout << l << " " << r << endl;
    cout.flush(); 
    while(1){
        string s;
        cin >> s;
        if (s == "Yes") {
            r = (l + r)/2;
            cout << l << " " << r << endl;
            cout.flush();
        }
        else if(s == "No") {
            r = l + 2 *(r - l);
            l = (l + r) / 2;
        }
    }
    return 0;
}
