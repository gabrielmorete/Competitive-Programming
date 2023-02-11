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
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

int n, q, to[MAXN][33];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;
	frr(i, n)
		cin>>to[i][0];

	frr(j, 30)
		frr(i, n)
			to[i][j] = to[ to[i][j - 1] ][j - 1];

	while (q--){
		int v, k;
		cin>>v>>k;

		for (int i = 30; i >= 0; i--)
			if (k & (1<<i))
				v = to[v][i];

		cout<<v<<endl;	
	}			
}