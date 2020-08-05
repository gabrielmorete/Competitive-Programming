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

int main(){
	fastio;
	
	int k;
	string s;

	cin>>k;
	cin>>s;

	fr(i,s.size())
		s[i] -= '0';


	ll ans = 0;	
	if (k == 0){
		ll aux = 0;
		fr(i,s.size()){
			if (s[i] == 0)
				aux++;
			else{
				ans += ((1ll + aux)*aux)/2;
				aux = 0;
			}
		}
		
		ans += ((1ll + aux)*aux)/2;
		cout<<ans<<endl;
		
		return 0;	
	}	

	ll p1, p2, p3, p4;

	p1 = p2 = p3 = p4 = 0;
	ll aux = 0;

	int t = s.size();	

	
	while (p4 < t) {

		while (aux < k and p4 < t) {
			if (s[p4] == 1)
				aux++;
			if (aux == k)
				p3 = p4;
			else
				p4++;
		}

		if (p4 == t) break;

		while (p4 + 1 < t and s[p4 + 1] == 0)
			p4++;

		while (s[p2] == 0 and p2 < t)
			p2++;
		if (s[p1] == 1 and p1 < p2)
			p1++;
		ans += (p2 - p1 + 1)*(p4 - p3 + 1);

		p2++;
		p4++;
		p1 = p2;
		aux --;
		// dbg(p4);
		// dbg(p3);
		// dbg(p2);
		// dbg(p1);
	}

	cout<<ans<<endl;
}