#include <iostream>
#include <math.h>
#define ULL unsigned long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m;
    int record_started[200001];
    int tunnels[200001][3];
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        for(int i = 0; i < n + 1;i++) record_started[i] = 0;

        for(int i = 0; i < m; i++){
            cin >> tunnels[i][0] >> tunnels[i][1] >> tunnels[i][2];
        }
        long long maxVal = 0;
        for(int i = 0; i < m; i++){
            int l = tunnels[i][0], r = tunnels[i][1];
            if(record_started[l] == 0){
                record_started[l] = 1;
                long long nowShafts = r, nowVal = tunnels[i][2];
                for(int j = i + 1; j < m; j++){
                    
                    if(nowShafts == tunnels[j][0]){
                        nowShafts = tunnels[j][1];
                        nowVal += tunnels[j][2];
                    }else if(nowShafts == tunnels[j][1]){
                        nowShafts = tunnels[j][0];
                        nowVal += tunnels[j][2];
                    }
                    
                }
                if(nowVal > maxVal) maxVal = nowVal;
                //cout << nowVal << endl;
            }
            if(record_started[r] == 0){
                //cout << "r == " << r << endl;
                record_started[r] = 1;
                long long nowShafts = l, nowVal = tunnels[i][2];
                for(int j = i + 1; j < m; j++){
                    //cout << "nowShafts == " << nowShafts << endl;
                    if(nowShafts == tunnels[j][0]){
                        nowShafts = tunnels[j][1];
                        nowVal += tunnels[j][2];
                    }else if(nowShafts == tunnels[j][1]){
                        nowShafts = tunnels[j][0];
                        nowVal += tunnels[j][2];
                    }
                }
                if(nowVal > maxVal) maxVal = nowVal;
            }
        }
        cout << maxVal << endl;
    }
}