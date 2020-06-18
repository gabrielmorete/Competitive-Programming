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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;

int n, freq[40];

int32_t main(){
	fastio;
	cin>>n;

	int a, cnt;
	fr(i, n){
		cin>>a;
		cnt = 0;
		while (a > 0){
		//	dbg(a);
			freq[cnt] += a % 2;
			a /= 2;
			cnt++;
		}
	}

	ll ans = 0, aux;

	fr(i, n){
		aux = 0;
		fr(j, 23)
			if (freq[j]){
				aux += 1ll<<j;
				freq[j]--;
			}
		ans += aux * aux;	
	}

	cout<<ans<<endl;
	
}