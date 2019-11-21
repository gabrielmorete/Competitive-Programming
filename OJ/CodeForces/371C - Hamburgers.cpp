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
ll ns, nb, nc, ps, pb, pc, r;
string t;
ll s, b, c;

bool test( ll val){
	ll ss, bb, cc, mn;
	ss = s*val;
	bb = b*val;
	cc = c*val;
	mn = r;
	if (ss != 0 and ss > ns)
		mn -= ps*(ss - ns);
	if (bb != 0 and bb > nb)
		mn -= pb*(bb - nb);
	if (cc != 0 and cc > nc)
		mn -= pc*(cc - nc);

	return mn >= 0;
}

int main(){
	fastio;
	cin>>t;
	cin>>nb>>ns>>nc;
	cin>>pb>>ps>>pc;
	cin>>r;

	for(auto x : t)
		if(x == 'B')
			b++;
		else if(x == 'C')
			c++;
		else
			s++;
	ll ini, fim, meio, bst;
	ini = 0;
	fim = (ll)(1e15);
	bst = 0;

	while (ini <= fim){
		meio = (ini + fim)/2;
		if (test(meio)){
			bst = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	cout<<bst<<endl;

}