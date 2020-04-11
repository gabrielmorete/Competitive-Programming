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

int mx[4] = {-1, 0, 1, 0};  //U R D L
int my[4] = {0, 1, 0 , -1};

int t, r, c;
ll sum, ans;
ll m[112345];
int adj[112345][4]; // U R D L
bool out[112345];


int get_id(int x, int y){
	return x * c + y;
}


bool valid(int x, int y){
	if (x < 0 or y < 0)
		return 0;
	if (x >= r or y >= c)
		return 0;
	return 1;
}

bool elimin(int id){
	int s = 0, viz = 0;
	fr(i, 4)
		if (adj[id][i] != -1){
			viz++;
			s += m[adj[id][i]];
		}
	return m[id] * viz < s;
}

void del(int id){
	out[id] = 1;
	sum -= m[id];

	int u, d, l, ri;
	u = adj[id][0];
	ri = adj[id][1];
	d = adj[id][2];
	l = adj[id][3];
	
	if (u != -1)
		adj[u][2] = d;
	if (d != -1)
		adj[d][0] = u;
	if (ri != -1)
		adj[ri][3] = l;
	if (l != -1)
		adj[l][1] = ri;
}

queue<int> check, destroy;


void dfs(){
	ms(out, 0);
	int id;

	while (true){
		ans += sum; // Sobreviveu a rodada

		if (destroy.empty()) // Ninguem para eliminar
			return;

		while (!destroy.empty()){
			id = destroy.front();
			destroy.pop();

			if (out[id])
				continue;

			fr (k, 4)  // Checar os vizinhos
				if (adj[id][k] != -1)
					check.push(adj[id][k]);
				
			del(id);
		}

		while (!check.empty()){ 
			id = check.front();
			check.pop();

			if (out[id] or !elimin(id)) // Se já saiu ou não elimina
				continue;

			destroy.push(id); //deve ser destruido
		}	
	}
}

void solve(){
	ms(out, 0);
	while(!check.empty()) check.pop();
	while(!destroy.empty()) destroy.pop();
	sum = ans = 0;

	cin>>r>>c;
	

	fr(i,r){
		fr(j,c){
			cin>>m[get_id(i, j)];
			sum += m[get_id(i, j)];
		}
	}

	fr(i, r){
		fr(j, c){
			int id = get_id(i, j);
			fr(k, 4)
				if (valid(i + mx[k], j + my[k]))
					adj[id][k] = get_id(i + mx[k], j + my[k]);
				else
					adj[id][k] = -1;	
		}
	}

	fr(i, r){
		fr(j, c){
			if (elimin(get_id(i, j)))
				destroy.push(get_id(i, j));		
		}
	}
	
	dfs();

	cout<<ans<<endl;
}

int main(){
	fastio;
	cin>>t;
	frr(i, t){
		cout<<"Case #"<<i<<": ";
		solve();
	}
}