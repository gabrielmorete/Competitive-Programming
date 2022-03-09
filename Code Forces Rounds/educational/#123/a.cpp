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

int in[300];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--){
		string s;
		cin>>s;

		fr(i, 300)
			in[i] = 0;

		bool ok = 1;	

		fr(i, 6){
			if (s[i] < 'Z'){
				if (in[s[i] - 'A' + 'a'] == 0)
					ok = 0;
			}
			else
				in[s[i]] = 1;
		}	

		if (ok)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}