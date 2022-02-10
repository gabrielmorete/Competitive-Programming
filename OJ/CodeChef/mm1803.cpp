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

int n;
int mx[4] = {1, 0, 0, -1};
int my[4] = {0, -1, 1, 0};
string dir = "DLRU";

bool space, vis[11][11];
char mapa[11][11];

bool valid(int x, int y){
	if (x < 0 or x >= n)
		return false;
	if (y < 0 or y >= n)
		return false;
	return mapa[x][y] == '1';
}

string ans;

void backtrack(int px, int py){
	if (px == n - 1 and py == n - 1){
		if (space)
			cout<<" "<<ans;
		else
			cout<<ans;
		space = 1;
		return;
	}

	vis[px][py] = 1;

	fr(k, 4){
		int x = px + mx[k];
		int y = py + my[k];

		if (valid(x, y) and !vis[x][y]){
			ans.pb(dir[k]);

			backtrack(x, y);

			ans.pop_back();
		}
	}

	vis[px][py] = 0;
}


void solve(){
	cin>>n;
	
	fr(i, n)
		fr(j, n){
			string s;
			cin>>s;
			mapa[i][j] = s[0];
		}

	space = 0;		
	backtrack(0, 0);		

	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}