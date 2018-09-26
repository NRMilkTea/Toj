#include <bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main(){ //io;
	string name;
	cin >> name;
	name[0] = toupper(name[0]);
	cout << " Nice to see you, " << name << "!" << endl;
	return 0;
}

