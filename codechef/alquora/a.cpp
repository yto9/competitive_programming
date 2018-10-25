// #include <bits/stdc++.h>
#include <iostream>

using namespace std; 
typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int test = 0; test < T; test++) {
        int N; cin >> N;
        string S; cin >> S;
        int num_of_vowel = 0;
        int v[5] = {0};
        for (int i = 0; i<N;i++) {
            if (S[i] == 'A'){ v[0] = 1;}
            if (S[i] == 'I'){ v[1] = 1;}
            if (S[i] == 'U'){ v[2] = 1;}
            if (S[i] == 'E'){ v[3] = 1;}
            if (S[i] == 'O'){ v[4] = 1;}
        }
        for (int j=0; j< 5;j++) {
            num_of_vowel += v[j];
        }
        if (num_of_vowel >= 2) cout << "Yes\n";
        else cout << "No\n";
    }
    cout.flush();
    return 0;
}
