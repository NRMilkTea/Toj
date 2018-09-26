#include <bits/stdc++.h>
using namespace std;

struct Edge{int s,e,w;} e[500000];
bool operator<(Edge e1, Edge e2) {return e1.w < e2.w;}
int p[1000];
void init(int V){for(int i=0; i<V; i++) p[i] = i;}
int  find(int x){return p[x]==x ? x : (p[x] = find(p[x]));}
void union_(int x, int y){p[find(x)] = find(y);}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	int V,E,W=0;
	cin >> V >> E;
	init(V);
	for(int i=0; i<E; i++){
		cout << i << endl;
		cin >> e[i].s >> e[i].e >> e[i].w;
	}
	sort(e,e+E);
	int i,j;
	for(i=0, j=0; i<V-1 and j<E; i++, j++){
		while( find(e[j].s) == find(e[j].e) ){j++;}
		union_(e[j].s, e[j].e);
		W += e[j].w;
	}
	if(i==V-1)cout << W << endl; 
	else cout << -1 << endl;
	
	return 0;
}

