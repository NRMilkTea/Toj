#include <bits/stdc++.h>
#define N 1000000
using namespace std;

vector<pair<long long, int>> stick;
int s[N];
bool visited[N];

bool cmp(pair<long long, int> firstElem, pair<long long, int> secondElem){
	return firstElem.first>secondElem.first; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	while(cin >> n){
		stick.clear();
		memset(visited,false,sizeof(visited));
		for(int i=0; i<n; i++) s[i]=i;
		long long h;
		for(int i=0; i<n; i++){
			cin >> h;
			stick.push_back(make_pair(h,i));
		}
		sort(stick.begin(),stick.end(),cmp);
		for(auto i:stick){
			int now=i.second;
			visited[now]=true;
			for(int j=now+1, num=0; j<n; j++, num++){
				if(visited[j]==true) break;
				s[j]=num;
			}
		}
		cout << s[0];
		for(int k=1; k<n; k++){
			cout << ' ' << s[k];
		}cout << endl;
	}
	
	
	return 0;
}

