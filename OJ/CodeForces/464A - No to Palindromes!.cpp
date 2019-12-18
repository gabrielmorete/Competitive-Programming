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

int n, p;
bool valid(int v){
	if (v < 0 or v >= n)
		return false;
	return true;
}

int main(){
	fastio;
	cin>>n>>p;
	string s;

	cin>>s;
	for (int i = n - 1; i >= 0; i--){
		for (int j = s[i] + 1; j < p + 'a'; j++){
			if (valid(i - 2) and s[i - 2] == j)
				continue;
			if (valid(i - 1) and s[i - 1] == j)
				continue;

			s[i] = j;
			bool ok = 1;

			for (int k = i + 1; k < n; k++){
				int l;
				for (l = 'a'; l < p + 'a'; l++){
					if (valid(k - 2) and s[k - 2] == l)
						continue;
					if (valid(k - 1) and s[k - 1] == l)
						continue;
					break;
				}	
				if (l == p + 'a')
					ok = 0;
				s[k] = l;
			}

			if (ok){
				cout<<s<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
}