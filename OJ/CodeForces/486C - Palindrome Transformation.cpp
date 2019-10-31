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

int smal_d(int a, int b){
	a %= 26; 
	b %= 26;

	
	int ans, aux, cnt;

	if(a>b)
		swap(a,b);

	cnt = 0;
	for (aux = a; aux != b; aux++)
		cnt++;
	ans = cnt;

	cnt = 0;
	for (aux = b; aux != a; aux++, aux %= 26){
		cnt++;
	}
	ans = min(ans,cnt);	

	return ans;
}

int main(){
	fastio;
	int n, p, t;
	string s;

	cin>>n>>p;
	cin>>s;
	t = s.size();

	if (p > (t+1)/2){
		reverse( all(s));
		p = t - p + 1;
	}

	bool ok = 1;
	for (int i = 0; i < t; i++)
		if (s[i] != s[t - i - 1])
			ok = 0;
	if (ok) {
		cout<<0<<endl;
		return 0;
	}	

	int l, r;

	for (int i = 0; i < t; i++)
		if (s[i] != s[t - i - 1]){
			l = i;
			break;
		}
	
	for (int i = t/2 - 1; i >= 0; i--)
		if (s[i] != s[t - i - 1]){
			r = i; 
			break;
		}
	int ans = 0;

	for (int i = l; i <= r; i++){
		//cout<<s[i]<<' '<<s[t-i-1]<<' '<<smal_d(s[i],s[t-i-1])<<endl;
		ans +=smal_d(s[i],s[t-i-1]);
	}
	p--;
	ans += min( abs(l - p)  , abs(r-p));
	ans += abs(l-r);
	cout<<ans<<endl;		



}