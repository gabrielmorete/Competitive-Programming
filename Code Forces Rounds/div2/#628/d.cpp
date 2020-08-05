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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int32_t main(){
	fastio;
	ll u, v;
	cin>>u>>v;

	if (u > v){
		cout<<-1<<endl;
		return 0;
	}

	if (u == v and v == 0){
		cout<<0<<endl;
		return 0;
	}
	
	if (u == v){
		cout<<1<<endl;
		cout<<u<<endl;
		return 0;
	}

	ll dlt = v - u;

	if (dlt & 1ll){
		cout<<-1<<endl;
		return 0;
	}

	vector<ll> ans;

	if ((u | (dlt/2)) == (u + dlt/2)){
		ans.pb(u + dlt/2);
		ans.pb(dlt/2);
	}
	else{
		ans.pb(u);
		ans.pb(dlt/2);
		ans.pb(dlt/2);
	}

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}