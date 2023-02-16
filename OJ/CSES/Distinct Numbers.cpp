#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;

	set<int> q;
	for (int i = 0; i < n; i++){
		int x;
		cin>>x;
		q.insert(x);
	}

	cout<<q.size()<<endl;
}