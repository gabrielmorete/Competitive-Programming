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

const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e7 + 10;

const int INF = 5e8;

int f[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int e, es, ef;

	cin>>e>>es>>ef;

	f[0] = 0;
	for (int i = 1; i <= e; i++){
		f[i] = 1;
		
		if (i - es > 0)
			f[i] += f[i - es];

		if (i - ef > 0)
			f[i] += f[i - ef];
		
		if (f[i] >= INF)
			f[i] = INF;
	}

	double ans = min(((double) 200)/((double) f[e]), ((double) 225)/((double)f[e] + 1));

	cout<<setprecision(6)<<fixed;
	cout<<ans<<endl;

}