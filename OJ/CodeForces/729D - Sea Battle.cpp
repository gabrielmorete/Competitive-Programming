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

int main(){
	fastio;
	int n, a, b, k;
	string s;
	cin>>n>>a>>b>>k;
	cin>>s;

	vii seq;

	int at = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '1'){
			if (at != i)
				seq.pb({i - at, at});
			at = i + 1;
		}

	if (at != n)
		seq.pb({n - at, at});	

	int hits = 0;
	for (auto x : seq)
		hits += x.fst/b;

	vi ans;
	k = 0;
	while (hits >= a){
		while (seq[k].fst < b){
			k++; 
		}

		ans.pb(seq[k].snd + b);
		
		seq[k].snd += b;
		seq[k].fst -= b;
		hits--;
	}

	cout<<ans.size()<<endl;
	for (auto it : ans)
		cout<<it<<' ';
	gnl;
}