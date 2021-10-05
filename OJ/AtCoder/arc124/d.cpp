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
const int MAXN = 2e5 + 10;

int n, m, a[MAXN], vis[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	frr(i, n + m)
		cin>>a[i];

	int fn = 0, fm = 0;	
	int ans = 0;
	frr(i, n + m)
		if (!vis[i]){
			int p = i, sz = 0;
			bool mn = 0, mm = 0;

			while (!vis[p]){
				vis[p] = 1;
				sz++;
				if (p <= n)
					mn = 1;
				else
					mm = 1;
				p = a[p];
			}

			if (sz == 1)
				continue;

			if (mn and !mm)
				fn++;
			if (mm and !mn)
				fm++;

			ans += sz;
			if (mn and mm)
				ans--;
			else
				ans++;
		}	

	ans -= 2 * min(fn, fm);

	cout<<ans<<endl;
}