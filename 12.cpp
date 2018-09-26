#include <bits/stdc++.h>
#define N 3000 
using namespace std;

int n, m;
int button[N+1][N+1];
unsigned long long BIT[N+1][N+1];

void update(int x, int y, int val){
	for(int i=x; i<=n; i+=(i&-i)){
		for(int j=y; j<=m; j+=(j&-j)){
			BIT[i][j]+=val;
		}
	}
}

unsigned long long getsum(int x, int y){
	unsigned long long sum=0;
	for(int i=x; i>0; i-=(i&-i)){
		for(int j=y; j>0; j-=(j&-j)){
			sum+=BIT[i][j];
		}
	}
	return sum;
}

/*void show(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout << BIT[i][j] << ' ';
		}
		cout << endl;
	}
}*/

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//input
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> button[i][j];
			update(i,j,button[i][j]);
		}
	}
	//question
	int q, a, b, c, d;
	char op;
	cin >> q;
	while(q--){
		cin >> op;
		if(op=='Q'){
			cin >> a >> b >> c >> d;
			cout << (getsum(c, d)
					-getsum(c, b-1)
					-getsum(a-1, d)
					+getsum(a-1, b-1)) << endl;
			//sum(x1,y1,x2,y2)
		}
		if(op=='C'){
			cin >> a >> b >> c;
			update(a,b,c-button[a][b]);
			//update(x,y,val)
		}
		//if(op=='S') show();
	}
	
	
	return 0;
}

