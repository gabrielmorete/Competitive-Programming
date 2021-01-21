#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e6 + 10;


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	vector<int> cost = {0};
	for (int i = 1; i < MAXN; i++){
		cost.pb(cost.back() + i);
		if (cost.back() > MAXN)
			break;
	}

	int n, x;
	cin>>n;

	while (n--){
		cin>>x;
		int p = (int)(lower_bound(all(cost), x) - cost.begin());
		
		if (x == cost[p]){
			cout<<p<<endl;
			continue;
		}

		int dlt = cost[p] - x;

		if (dlt == 1){
			cout<<p + 1<<endl;
			continue;
		}

		cout<<p<<endl;
	}

}