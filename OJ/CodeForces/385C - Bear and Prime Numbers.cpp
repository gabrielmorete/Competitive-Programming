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
const int sete = 10000000;

ll n, m, freq[11234567], ac[11234567];
bool vis[11234567]; 

void crivo(){
	for (ll i = 2; i < sete; i++){
		if (vis[i])
			continue;
		for (ll j = i; j <= sete; j += i){
			vis[j] = 1;
			ac[i] += freq[j];
		}
	}
}

int main(){
	scanf("%d", &n);

	int x;
	fr(i,n){
		scanf("%d", &x);
		freq[x]++;
	}

	crivo();

	frr(i,sete)
		ac[i] += ac[i - 1];

	scanf("%d", &m);

	int a, b;
	fr(i,m){
		scanf("%d %d", &a, &b);

		if(a > sete){
			printf("0\n");
			continue;
		}

		b = min(b, sete);
		printf("%I64d\n",ac[b] - ac[a - 1]);	
	}	

}