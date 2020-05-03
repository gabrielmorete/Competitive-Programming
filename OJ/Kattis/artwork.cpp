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
int n, m, q;
int id[1123456], sz[1123456];
int grid[1123][1123];

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

vector< pair<pii, pii> > chg;

bool valid(int x, int y){
	if (x < 0 or y < 0)
		return false;
	if (x >= n or y >= m)
		return false;
	return grid[x][y] <= 0;
}

int crd(int x, int y){
	return x * m + y;
}

int find(int a){
	return a == id[a]? a : id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) 
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
}

int main(){
	fastio;
	cin>>n>>m>>q;

	fr(i, n * m){
		id[i] = i;
		sz[i] = 1;
	}
	
	int a, b, c, d, x, y; 

	fr(l, q){
		cin>>a>>b>>c>>d;
		a--;b--;c--;d--;
		chg.pb({{a, b}, {c, d}});
		x = max(a, c); y = max(b, d);
		a = min(a, c); c = x;
		b = min(b, d); d = y;

		for (int i = a; i <= c; i++)
			for (int j = b; j <= d; j++)
				grid[i][j]++;
	}

	fr(i, n){
		fr (j, m){
			if (grid[i][j])
				continue;

			fr(k, 4)
				if (valid(i + mx[k], j + my[k]) and find(crd(i, j)) != find(crd(i + mx[k], j + my[k])))
					merge(crd(i, j), crd(i + mx[k], j + my[k]));
			}
	}

	int tot = 0;
	fr(i, n){
		fr(j, m)
			if(grid[i][j] == 0 and find(crd(i, j)) == crd(i, j))
				tot++;		
	}

	vi ans;
	ans.pb(tot);

	reverse(all(chg));

	fr(l, q){

		a = chg[l].fst.fst; b = chg[l].fst.snd;
		c = chg[l].snd.fst; d = chg[l].snd.snd;
		x = max(a, c); y = max(b, d);
		a = min(a, c); c = x;
		b = min(b, d); d = y;


		for (int i = a; i <= c; i++){
			for (int j = b; j <= d; j++){
				grid[i][j]--;

				if (grid[i][j] == 0){
					int cnt = 0;
					fr(k, 4)
						if (valid(i + mx[k], j + my[k]) and find(crd(i, j)) != find(crd(i + mx[k], j + my[k]))){
							cnt++;
							merge(crd(i, j), crd(i + mx[k], j + my[k]));
						}

					if (cnt == 0)
						tot++;
					else if (cnt > 1)
						tot -= (cnt - 1);		
				}
			}
		}
			
		ans.pb(tot);
	}
	ans.pop_back();
	reverse(all(ans));
	for (int s : ans)
		cout<<s<<endl;

}