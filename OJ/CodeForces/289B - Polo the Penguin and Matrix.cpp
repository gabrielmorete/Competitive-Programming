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

int n, m, d;
vi v;

int abs(int a){
	if (a < 0)
		return -a;
	return a;
}

int test(int val){
	int ans = 0;

	for (auto x: v)
		ans += abs(val - x)/d;

	return ans;
}

int main(){
	fastio;
	
	cin>>n>>m>>d;

	
	int x;
	fr(i,n)
		fr(j,m){
			cin>>x;
			v.pb(x)	;
		}

	sort( all(v));

	fr(i, v.size())
		if (abs(v[i] - v[0]) % d != 0){
				cout<<-1<<endl;
				return 0;
			}

	int l, r, k1, k2, aux1,aux2;
	
	l = 0;
	r = v.size() - 1;

	while ((r - l) > 3) {
		k1 = l + (r - l)/3;
		k2 = r - (r - l)/3;

		aux1=test( v[k1]);
		aux2=test( v[k2]);

		if (aux1 > aux2)
			l=k1;
		else if (aux2 > aux1)
			r=k2;
		else{
			l=k1;
			r=k2;
		}
	}

//	cout<<l<<' '<<r<<endl;

	int best = INF;
	for(int i = l; i <= r; i++){
		best = min(best, test(v[i]));
	}

	cout<<best<<endl;


}