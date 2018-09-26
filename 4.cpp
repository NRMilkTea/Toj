#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int t, n, l;
long long device[1000], outlet[1000], flipped[1000];

long long toNum(string s){
	long long num = 0;
	for(int i=0; i<l; i++){
		num = (num << 1) + s[i] - '0';
	}
	return num;
}

int toAction(long long flip){
	int action = 0;
	while(flip != 0){
		action = action + (flip & 1);
		flip >>= 1;
	}
	return action;
}

int match(){
	sort(device, device+n);
	sort(outlet, outlet+n);
	
	int minimumAction = 1e9;
	
	for(int i=0; i<n; i++){
		long long flip = device[0] ^ outlet[i];
		
		for(int j=0; j<n; j++){
			flipped[j] = device[j] ^ flip;
		}
		sort(flipped, flipped+n);
		bool Match = true;
		for(int j=0; j<n; j++){
			if(flipped[j] != outlet[j]){
				Match = false;
				break;
			}
		}
		if(Match){
			minimumAction = min(minimumAction, toAction(flip));
		}
	}
	if(minimumAction == 1e9) return -1;
	else return minimumAction;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	
	cin >> t;
	for(int Case = 1; Case <=t; Case++){
		//input
		cin >> n >> l;
		for(int i=0; i<n; i++){
			cin >> str;
			device[i] = toNum(str);
		}
		for(int i=0; i<n; i++){
			cin >> str;
			outlet[i] = toNum(str);
		}
		//end of input
		cout << "Case #" << Case << ": ";
		int ans = match();
		if(ans == -1) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;
	}
	
	return 0;
}

