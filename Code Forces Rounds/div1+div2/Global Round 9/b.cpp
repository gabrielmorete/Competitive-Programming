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
const int MAXN = 1e5 + 10;

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

int n, m, mapa[310][310];

bool valid(int x, int y){
	return (0 <= x and x < n) and (0 <= y and y < m);
}

void solve(){
	cin>>n>>m;

	fr(i, n)
		fr(j, m)
			cin>>mapa[i][j];

	bool ok = 1;		

	fr(i, n)
		fr(j, m){
			int a = 0;
			fr(k, 4)
				if (valid(i + mx[k], j + my[k]))
					a++;
			if (mapa[i][j] > a)
				ok = 0;
			mapa[i][j] = a;
		}

	if (!ok){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		fr(i, n){
			fr(j, m)
				cout<<mapa[i][j]<<' ';
			gnl;	
		}
	}			

}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}