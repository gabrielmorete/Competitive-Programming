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

	int g[2123456];
int main(){
	fastio;
	int n,m,cnt;
	int a, b;
	cin>>n>>m;

	vi v;

	cnt=0;

	while (n > 0 and m > 1){
		v.pb(1);
		v.pb(1);
		v.pb(0);
		n --;
		cnt++;
		m -=2;
	}

	if(m == 1){
		v.pb(1);
		m--;
	}


	if(m == 2){
		v.pb(1);
		v.pb(1);
		cnt++;
		m -= 2;
	}

	if(n > 0){
		v.insert(v.begin(),0);
		n--;
	}
	if(n > 0 and v.size() > 0 and v[v.size()-1] == 1){
		v.pb(0);
		n--;
	}

	if(n <= cnt and n > 0){
		int ct = 0;
		for(auto x:v){
			if(ct > 0 and g[ct-1] == 1 and x == 1 and n ){
				g[ct++] = 0;
				n--;
			}
			g[ct++] = x;
		}
		fr(i,ct)
			cout<<g[i];
		gnl;	
		return 0;
	}

	if(n <= cnt and n!=0){
		for(int i = 0; (i+1) < v.size();i++){
			cout<<v[i];
		
			if(v[i+1] == v[i] and n){
				cout<<0;
				n--;
			}
		}
		cout<<v[v.size()]<<endl;
		return 0;
	}


	if(n == 0 and m == 0){
		fr(i,v.size())
			cout<<v[i];
		gnl;
		return 0;
	}

	cout<<-1<<endl;
	
}