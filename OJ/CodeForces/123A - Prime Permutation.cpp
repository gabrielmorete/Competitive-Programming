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


string s;
int freq[330];

bool check[1010];
void crivo(){
	for (int i = 2; i <= 1000; i++)
		if (!check[i]){
			for (int j = 2 * i; j <= 1000; j += i)
				check[j] = 1;
	}
}

int main(){
	fastio;

	crivo();

	cin>>s;
	
	int mx = 0;
	char c;
	for (auto x : s){
		freq[x]++;
		if (freq[x] > mx){
			mx = freq[x];
			c = x;
		}
	}

	string ans(s.size(), 0);

	int tot = 0;

	for (int i = 2; i <= s.size(); i++){
		if (check[i] or (!check[i] and i <= s.size()/2))
			tot++;
	}

	if (tot > mx){
		cout<<"NO"<<endl;
		return 0;
	}

	frr(i, s.size()){
		if (i == 1 or (!check[i] and i > s.size()/2))
			continue;
		ans[i - 1] = c;
		freq[c]--;
	}

	fr(i, s.size())
		if (ans[i] == 0)
			frr(j, 330)
				if (freq[j]){
					ans[i] = j;
					freq[j]--;
					break;
				}
	cout<<"YES"<<endl;
	cout<<ans<<endl;			


}