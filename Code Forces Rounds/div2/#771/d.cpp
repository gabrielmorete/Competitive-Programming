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

int n, m;
vector<array<int, 3>> ans;

int in[1010][1010], cor[1010][1010];
bool block[1010][1010];

void zero(int x, int y, int k){
	ans.pb({x, y, k});

	cor[x][y] = 0;
	cor[x + 1][y] = 0;
	cor[x][y + 1] = 0;
	cor[x + 1][y + 1] = 0;
}

int mx[4] = {0, 1, 0, 1};
int my[4] = {0, 0, 1, 1};

int test(int x, int y){
	if (x < 0 or x >= n)
		return -1;
	if (y < 0 or y >= m)
		return -1;

	set<int> q;
	fr(k, 4)
		if (cor[x + mx[k]][y + my[k]] != 0)
			q.insert(cor[x + mx[k]][y + my[k]]);

	if (q.size() != 1)
		return -1;			
	return *q.begin();
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, n)
		fr(j, m)
			cin>>cor[i][j];

	queue<pii> fila;

	fr(i, n - 1)
		fr(j, m - 1){
			int v = test(i, j);
			if (v != -1){
				zero(i, j, v);
				fila.push({i, j});
			}
		}

	while (!fila.empty()){
		int x, y;
		tie(x, y) = fila.front();
		fila.pop();

		for (int i = max(x - 1, 0); i < min(x + 2, n - 1); i++)
			for (int j = max(y - 1, 0); j < min(y + 2, m - 1); j++){
				int v = test(i, j);
				if (v != -1){
					zero(i, j, v);
					fila.push({i, j});
				}	
			}
	}	

	fr(i, n)
		fr(j, m)
			if (cor[i][j] != 0){
				cout<<"-1"<<endl;
				return 0;
			}

	reverse(all(ans));		

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x[0] + 1<<' '<<x[1] + 1<<' '<<x[2]<<endl;
}