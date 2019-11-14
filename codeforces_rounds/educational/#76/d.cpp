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
int n, m, a[212345], hero[212345];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);

		int mxm = 0;
		frr(i,n){
			scanf("%d", &a[i]);
			mxm = max(mxm, a[i]);
		}
		scanf("%d", &m);
		
		frr(i,n)
			hero[i] = 0;
		
		int x, y, mxh = 0;
		fr(i,m){
			scanf("%d %d", &x, &y);
			mxh = max(x, mxh);
			hero[y] = max(x, hero[y]);
		}
		
		if(mxm > mxh){
			printf("-1\n");
			continue;
		}

		x = 0;
		for(int i = n; i > 0; i--){
			x = max(x, hero[i]);
			hero[i] = x;
		}

		int ans = 0;
		int p = 1, mx;

		while (p <= n){
			mx = a[p];
			int i = p;
			while (i <= n and hero[i - p + 1] >= mx ) {
				mx = max(mx, a[i + 1]);
				i++;
			}
			ans++;
			p = i;
		}
		printf("%d\n", ans);

	}
}