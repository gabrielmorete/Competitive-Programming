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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;

int n, b[MAXN];

void solve(){
	cin>>n;

	fr(i, n)
		scanf("%d", b + i);
		
	int minx, maxx, fr, dlt;

	minx = fr = dlt = 0;

	fr(i, n){
		fr += b[i] - 1;
		if (i > 0)
			fr -= b[i - 1];

		if (fr != 0)
			fr--;
		else{
			minx++;
			dlt++;
		}
	}

	if (b[n] < 2 * n )
		fr += 2 * n - b[n];

	dlt -= fr;

	minx += max(0, dlt);

	reverse(b, b + n);
	
	maxx = fr = dlt = 0;
	fr(i, n){
	
		if (i > 0)
			fr += b[i - 1] - b[i] - 1;
		else
			fr += 2 * n - b[i];


		if (fr != 0){
			fr--;
			maxx++;
		}
		else
			dlt++;
	}	


	if (b[n - 1] > 1)
		fr += b[n - 1] - 1;

	dlt -= fr;
	maxx -= max(0, dlt);

	printf("%d\n", max(0, maxx - minx + 1));
}

int32_t main(){
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
}