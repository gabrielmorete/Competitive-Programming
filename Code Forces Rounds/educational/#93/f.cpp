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
const int MAXN = 1e6 + 10;

int n, nxt[2][MAXN];
vi nxtp[2][MAXN];
string s;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>s;

	for (int i = n - 1; i >= 0; i--){ // proxima posição com esse caractere
		if (s[i] != '0') nxt[0][i] = 1 + nxt[0][i + 1];
		if (s[i] != '1') nxt[1][i] = 1 + nxt[1][i + 1];
	}

	for (int j = 0; j <= 1; j++){ // O(n)
		int l = 0;
		while (l < n){
			while (l < n and s[l] == '0' + j) 
				l++;
			if (l == n) 
				break;

			int r = l;
			while (r < n and s[r] != '0' + j)
				r++;
			r--;

			for (int sz = 1; sz <= r - l + 1; sz++)
				nxtp[j][sz].pb(l);

			l = r + 1;
		}
	}

	for (int j = 0; j <= 1; j++)
		for (int i = 1; i <= n; i++)
			reverse(all(nxtp[j][i]));


	for (int sz = 1; sz <= n; sz++){ //O(nlog(n)) -> serie harmonica
		int ans = 0;
		int l = 0;

		while (l < n){
			int pnxt = n + 1;

			for (int j = 0; j <= 1; j++){
				if (nxt[j][l] >= sz)
					pnxt = min(pnxt, l + sz);

				while (!nxtp[j][sz].empty() and nxtp[j][sz].back() < l) 
					nxtp[j][sz].pop_back();
				
				if (!nxtp[j][sz].empty())
					pnxt = min(pnxt, nxtp[j][sz].back() + sz);
			}

			if (pnxt < n + 1) 
				ans++;
			
			l = pnxt;		
		}

		cout<<ans<<' ';
	}
	gnl;
}