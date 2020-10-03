#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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
const int MAXN = 1e5 + 10;

map<string, int> id;
map<int, int> trm;
int term[8], grp;

pii road[4];

int memo[1<<9][33];//steiner tree connecting mask with root v
int dist[33][33];

int gm(int msk){ // get mask of steiner terminals for a subset of roads
	int ans = 0;
	fr(i, 4)
		if (msk & (1<<i))
			ans |= (1 << (road[i].fst)) | (1 << (road[i].snd));
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, cnt = 0;
	string s, t;

	cin>>n>>m;
	while (n != 0){
		id.clear();
		trm.clear();
		memset(dist, INF, sizeof dist);
		memset(memo, INF, sizeof memo);

		cnt = 0;
		fr(i, n){
			cin>>s;
			id[s] = cnt++;
		}

		int x, aux;
		fr(i, m){
			cin>>s>>t>>x;
			aux = dist[id[s]][id[t]];
			dist[id[s]][id[t]] = min(x, aux);
			dist[id[t]][id[s]] = min(x, aux);
		}

		fr(v, n)
			dist[v][v] = 0;

		fr(k, n)
			fr(i, n)
				fr(j, n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
		int ntrm = 0; // number of different terminals
		fr(i, 4){
			cin>>s>>t;
			if (!trm.count(id[s])){
				term[ntrm] = id[s];
				trm[id[s]] = ntrm++;
			}
			if (!trm.count(id[t])){
				term[ntrm] = id[t];
				trm[id[t]] = ntrm++;
			}
			road[i] = {trm[id[s]], trm[id[t]]};
		}			

		for (int v = 0; v < n; v++)
			for (int i = 0; i < ntrm; i++)
				memo[1<<i][v] = dist[v][term[i]];

		for (int msk = 1; msk < 1 << ntrm; msk++) // steiner dp
			for (int v = 0; v < n; v++){
				for (int smsk = (msk - 1)&msk; smsk > 0; smsk = (smsk - 1) & msk)
					memo[msk][v] = min(memo[msk][v], memo[smsk][v] + memo[msk^smsk][v]);
				for (int u = 0; u < n; u++)
					memo[msk][u] = min(memo[msk][u], memo[msk][v] + dist[u][v]);	
			}	

		for (int msk = 1; msk < 1<<ntrm; msk++)
			memo[msk][0] = *min_element(memo[msk], memo[msk] + n);

		memo[0][0] = 0;
		int ans = INF;


		//  bruteforcing all possible solutions
		for (int m = 0; m < (1<<4); m++)
		for (int mm = 0; mm < (1<<4); mm++)
		for (int mmm = 0; mmm < (1<<4); mmm++)
		for (int mmmm = 0; mmmm < (1<<4); mmmm++)
			if (__builtin_popcount(m | mm | mmm | mmmm) == 4)
				if (!(m & mm) and !(m & mmm) and !(m & mmmm))
				if (!(mm & mmm) and !(mm & mmmm) and !(mmm & mmmm))
					ans = min(ans, memo[gm(m)][0] + memo[gm(mm)][0] 
						+ memo[gm(mmm)][0] + memo[gm(mmmm)][0]);

		cout<<ans<<endl;						

		cin>>n>>m;
	}
}