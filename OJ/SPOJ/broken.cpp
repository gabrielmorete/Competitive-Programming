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

int m, n, freq[500];
string s;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (cin>>m and m > 0){
		getline(cin, s);
		getline(cin, s);

		n = s.size();

		int ans = 1;
		int q = -1;
		int p = 0;

		int df = 1;
		freq[s[0]] = 1;

		while (p < n){
			bool ok = 1;
			while (p + 1 < n and ok){
				if (freq[s[p + 1]] > 0){
					freq[s[p + 1]]++;
					p++;
				}
				else{
					if (df < m){
						freq[s[p + 1]]++;
						p++;
						df++;
					}
					else
						ok = 0;	
				}
			}

			ans = max(ans, p - q);

			if (p + 1 == n)
				break;

			while (df >= m){
				q++;
				freq[s[q]]--;
				if (freq[s[q]] == 0)
					df--;
			}
		}

		for (auto x : s)
			freq[x] = 0;

		cout<<ans<<endl;
	}

}