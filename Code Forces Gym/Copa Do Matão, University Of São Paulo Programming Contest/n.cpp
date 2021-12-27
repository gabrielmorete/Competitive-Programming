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

int n, k, l, cap[110], pes[110], val[110], vol[110], gan[110];

int item[MAXN], elev[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k>>l;

	fr(i, n) // competidor
		cin>>cap[i]>>pes[i];

	fr(i, k) // item	
		cin>>vol[i]>>val[i];

	fr(j, MAXN) // maximo valor por capacidade
		item[j] = -1;	

	item[0] = 0;	
	fr(i, k)
		for (int j = 10010; j >= 0; j--)
			if (j - vol[i] >= 0 and item[j - vol[i]] >= 0)
				item[j] = max(item[j], item[j - vol[i]] + val[i]);

	frr(i, 10010)
		item[i] = max(item[i], item[i - 1]);		

	fr(i, n) // quanto cada ganha
		gan[i] = item[cap[i]];

	fr(j, MAXN) // valor maximo por peso no elev
		elev[j] = -1;

	elev[0] = 0;
	fr(i, n)
		for (int j = 10010; j >= 0; j--)
			if (j - pes[i] >= 0 and elev[j - pes[i]] >= 0)
				elev[j] = max(elev[j], elev[j - pes[i]] + gan[i]);

	int ans = elev[0];
	frr(i, l)
		ans = max(ans, elev[i]);

	cout<<ans<<endl;
}