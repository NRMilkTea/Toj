#include <bits/stdc++.h>
#define N 10001
#define INF 100000001
using namespace std;

int height[N];
int nxt[N];
bool visit[N];
vector<int> edge[N];
int end_height;
int t, n, m, s, a, b, car, walk;

void Init(){
    for(int i=0; i<n; i++) edge[i].clear();
    for(int i=0; i<n; i++) nxt[i]=i;
    memset(height,0,n);
    end_height=INF;
}

int DFS(int s){
    int count=0;
    while(height[s]>end_height && nxt[s]!=s){
        s=nxt[s];
        count++;
    }
    if(height[s]==end_height) return count;
    return -1;
}
int BFS(int s){
    queue<pair<int,int>> q;
    memset(visit, false, n);
    q.push({s,0});
    visit[s]=true;
    while(!q.empty()){
        pair<int,int> v=q.front();q.pop();
    	if(height[v.first]==end_height){
  	    	return v.second*6;
		}
        for(auto i:edge[v.first]){
            if(!visit[i]){
                q.push({i,v.second+1});
                visit[i]=true;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    for(int k=1; k<=t; k++){
        //input
        cin >> n >> m >> s;
        Init();
        for(int i=0; i<n; i++){
            cin >> height[i];
            if(end_height>height[i]) end_height=height[i];
        }
        for(int i=0; i<m; i++){
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
            if(height[a]<height[b]) swap(a,b);
            if(height[b]<height[nxt[a]]) nxt[a]=b;
        }
        //operate
        car=DFS(s);
        walk=BFS(s);
        //output
        cout << "Case #" << k << ": ";
        if(walk==-1) cout << "Call 119!" << endl;
        else if(car==-1) cout << walk << endl;
        else cout << abs(walk-car) << endl;
    }
    
    return 0;
}
