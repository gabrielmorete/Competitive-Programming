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
const int MAXN = 2e2 + 10;

int n, p, l[MAXN], r[MAXN], memo[MAXN][MAXN];
pii inter[MAXN][MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>p;

	vii id;

	fr(i, n){
		cin>>l[i]>>r[i];
		id.pb({r[i] - l[i], i});
	}

	sort(all(id));
	
	vi good;
	vii v;

	for (int i = 0; i < n; i++){
		bool ok = 0;
		int a = id[i].snd;
		for (int j = 0; j < i; j++){
			int b = id[j].snd;
			if (l[a] <= l[b] and r[b] <= r[a])
				ok = 1;					
		}
		if (ok)
			good.pb(r[a] - l[a]);
		else
			v.pb({l[a], r[a]});
	}	

	sort(all(v));

	int m = v.size();

	for (int i = 0; i < m; i++){
		inter[i][i] = v[i];
		for (int j = i + 1; j < m; j++)
			inter[i][j] = {v[j].fst, v[i].snd};		
	}

	memset(memo, -INF, sizeof memo);

	memo[0][0] = 0;

	for (int i = 1; i <= m; i++)
		for (int g = 1; g <= p; g++)
			for (int j = 1; j <= i; j++)
				if (inter[j - 1][i - 1].fst < inter[j - 1][i - 1].snd){ // intervalo valido
					memo[i][g] = max(memo[i][g], 
						memo[j - 1][g - 1] - inter[j - 1][i - 1].fst + inter[j - 1][i - 1].snd);
				}
   	sort(all(good));
   	reverse(all(good));

   	ll ans = 0, cur = 0, it = 0;
   	for (int g = p; g >= 0; g--){
   		if (g == 0 and m > 0)
   			break;
   		ans = max(ans, memo[m][g] + cur);
   		if (it < good.size())
   			cur += good[it++];
   		else
   			break;
   	}

   	cout<<ans<<endl;
}
