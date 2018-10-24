#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int K = 30;
    int Xmax = 1000000000;
    int q = 2;
    printf("? %d\n", q); fflush(stdout);
    string xmod2; cin >> xmod2;
    printf("? %d\n", Xmax/2 -1); fflush(stdout);
    string halfxmodmax_1; cin >> halfxmodmax_1;
    K -= 2;
    int th_l = (xmod2 == halfxmodmax_1) ? 1:Xmax/2 -1; 
    int th_r = (xmod2 == halfxmodmax_1) ? Xmax/2-1: Xmax+1;
    int p;
    // string xmodth_l = (halfxmodmax_1 == "even")? "odd": "even";
    // string xmodth_r = (halfxmodmax_1 == "even")? halfxmodmax_1;// xmod2 == halfxmodmax_1 on this time
    bool right = (xmod2 == halfxmodmax_1) ? false: true;
    string pre = halfxmodmax_1;
    while(K > 0) {
        p = th_l+ (th_r-th_l)/2;
        p -= !(p%2); //query number should keep odd
        printf("? %d\n", p); fflush(stdout);
        string r; cin >> r;
        if (right && pre == r) {
            th_l = p;
        }
        else if (right && pre != r) {
            th_r = p;
        }
        else if ((!right) && pre == r) {
            
        }
        // if () { // |---->----| before finding lower bound odd
            // if (r != xmodth_r) {
                // xmodth_l = r;
                // th_l = p;
            // }
            // else {
                // th_r = p;
            // }
        // }
        // else { //
            // if (r == xmodth_l) {
                // th_l = p;
            // }
            // else {// r == xmodth_r
                // th_r = p;
            // }
        // }
        pre = r;
        K--;
    }
    cout << th_l << ":" << th_r << endl;

    return 0;
}
