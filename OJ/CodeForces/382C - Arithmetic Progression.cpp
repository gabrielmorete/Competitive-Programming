#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

map<int, int> del;

int main(){
	fastio;
	int n, x;
	vi v;

	cin>>n;
	fr(i,n) {
		cin>>x;
		v.pb(x);
	}
	sort(all(v));

	if (n == 1) {
		cout<<-1<<endl;
		return 0;
	}

	if (n == 2) {
		int delta = v[1] - v[0];

		if (delta == 0){
			cout<<1<<endl;
			cout<<v[0]<<endl;
			return 0;
		}

		if (delta % 2 == 0) {
			cout<<3<<endl;
			cout<<v[0] - delta<<' '<<v[0] + delta/2<<' '<<v[1] + delta<<endl;
			return 0;
		}
		cout<<2<<endl;
		cout<<v[0] - delta<<' '<<v[1] + delta<<endl;
		return 0;
	}

	int erro = 0;
	int delta = v[1] - v[0];

	fr(i, n - 1)
		del[v[i + 1] - v[i]]++;

	if (del.size() <= 1)
		erro = 0;
	if (del.size() > 2)
		erro = 2;
	if (del.size() == 2){			
		int a, b, da, db;
		a = -1;
		for(auto x : del) {
			if (a == -1){
				a = x.snd;
				da = x.fst;
			}
			else {
				b = x.snd;
				db = x.fst;
			}
		}

		if (min(a,b) > 1){
			cout<<0<<endl;
			return 0;
		}
		else{
			if(a < b)
				swap(da,db);
			delta = da;
			erro = 1;
		}

	}	

	if (erro > 1) {
		cout<<0<<endl;
		return 0;
	}

	if (erro == 0){
		
		if (delta == 0){
			cout<<1<<endl;
			cout<<v[0]<<endl;
			return 0;
		}

		cout<<2<<endl;
		cout<<v[0] - delta<<' '<<v[n-  1] + delta<<endl;
		return 0;
	}

	
	fr(i, n - 1)
		if(v[i + 1] - v[i] != delta) {
			if (v[i] + 2*delta == v[i+ 1]){
				cout<<1<<endl;
				cout<<v[i] + delta<<endl;
			}
			else {
				cout<<0<<endl;
			}
			return 0;
		}
			



}