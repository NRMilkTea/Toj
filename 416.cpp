#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

vector<unsigned> dp={1,2,4,7};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    
    while(cin >> n){
        if(n+1 > dp.size()){
            int i = dp.size();
            dp.resize(n+1);
            for(; i <= n; ++i){
                dp[i] = ( dp[i-3] + dp[i-2] + dp[i-1]) % N;
            }
        }
        unsigned long long ans = dp[n];
        
        for(int i=0; i<n/2; ++i){
            ans = ( ans + (unsigned long long)dp[i] * dp[n-i-1] * 2) % N;
        }
        if(n&1) ans = ( ans + (unsigned long long)dp[n/2] * dp[n/2]) % N;
        cout << ans << endl;
    }
    
    return 0;
}
