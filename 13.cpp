//Toj 13 knapsack backpack
#include <bits/stdc++.h>
#define N 100001
using namespace std;

int weight[N];
int cost[N];
int dp[N];

int main(int argc, const char * argv[]) {
    int w, n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin >> w){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> weight[i] >> cost[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=weight[i]; j<=w; j++){
                dp[j]=max(dp[j],dp[j-weight[i]]+cost[i]);
            }
        }
        cout << dp[w] << endl;
    }
    return 0;
}
