#include <iostream>
#include <math.h>
#define ULL unsigned long long
using namespace std;

#define MAX_N 1000005
bool notprime[MAX_N] = {};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    notprime[0] = 1;
    notprime[1] = 1;
    for (int i=2;i<MAX_N;i++){
        if (notprime[i] == 1)
            continue;
        notprime[i] = 0;
        for (int j=i+i;j<MAX_N;j+=i){
            notprime[j] = 1;
        }
    }
    // for (int i=1;i<100;i++){
    //     if (!notprime[i]){
    //         cout << i << "\n";
    //     }
    // }
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        cout << "NY"[(b==a+2) & !notprime[a] & !notprime[b]] << "\n";
    }
    return 0;
}