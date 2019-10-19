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

int n, m;
int seg[1<<18];

int merge( int a, int b, bool op) {
	return op ? a | b : a ^ b;
}

void build() {
	bool op = 1;
	int cnt = n/2;
	for (int i = n - 1; i > 0; i--){
		if (i < cnt) {
			cnt = cnt/2;
			op = !op;
		}
		seg[i] = merge( seg[i<<1], seg[i<<1|1], op);
	}		
}

void modify( int p, int val) {
	bool op = 1;
	for (seg[p += n] = val; p > 1; p >>= 1){
		seg[p>>1] = merge( seg[p], seg[p^1], op);
		op = !op;
	}
}

int main(){
	fastio;
	cin>>n>>m;
	n = 1<<n;

	for (int i = 0; i < n; i++)
		cin>>seg[n + i];

	build();
	
	int p, b;
	for (int i = 0; i < m; i++) {
		cin>>p>>b;
		modify( p - 1, b);
		cout<<seg[1]<<endl;
	}
}