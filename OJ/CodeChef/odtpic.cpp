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
const ll mod=1ll << 32;
const int LMAXN = 25;

int n, m, q;
bitset<4123> a[112345], b[112345];


int main(){
	fastio;
	cin>>n>>m>>q;

	int x;
	frr(i, n){
		cin>>x;
		a[i][x] = true;
		a[i] ^= a[i - 1];
	}

	frr(i, m){
		cin>>x;
		b[i][x] = true;
		b[i] ^= b[i - 1];
	}

	int l, r, ll, rr;
	bitset<4123> aux, aux2;

	while (q--){
		aux.reset();
		aux2.reset();
		cin>>l>>r>>ll>>rr;
		aux = a[l - 1] ^ a[r];
		aux2 = b[ll - 1] ^ b[rr];
		aux ^= aux2;
		cout<<aux.count()<<endl;
	}
}
