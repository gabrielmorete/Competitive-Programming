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
int n, a[1111][1111];
int sum;

int main(){
	scanf("%d", &n);
	fr(i,n)
		fr(j,n)
			scanf("%d",&a[i][j]);

	fr(i,n)
		sum += a[i][i];

	int q, typ, l;
	scanf("%d", &q);

	while(q--){
		scanf("%d", &typ);
		if(typ != 3)
			scanf("%d",&l);
		l--;
		if(typ == 1  or typ == 2){
			sum -= a[l][l];
			a[l][l] = 1 - a[l][l];
			sum += a[l][l];

		}
		else{
			printf("%d", sum % 2);	
		}
	}
	printf("\n");		
}