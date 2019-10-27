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
	int n, m, k;
	cin>>n>>m>>k;

	if (k < n){
		frr( i, k - 1){
			cout<<m<<' ';
			frr(j,m)
				cout<<i<<' '<<j<<' ';
			gnl;	
		}
		cout<<(n - k + 1)*m<<' ';
		for (int i = k; i <= n; i++){
			frr(j,m)
			cout<<i<<' '<<j<<' ';
			if (i == n)
				break;
			i++;
			fr(j,m)
			cout<<i<<' '<<m-j<<' ';

		}
		gnl;
	}
	else if (k == n){
		frr(i,n){
			cout<<m<<' ';
			frr(j,m)
				cout<<i<<' '<<j<<' ';
			gnl;	
		}
	}
	else{
		bool ok;
		vii v;
		ok = 1;
		frr(i,n){
			frr(j,m)
				ok ? v.pb({i,j}) : v.pb({i, m - j + 1});
			ok = !ok;	
		}

		fr(i,v.size()){
			if (k > 1){
				cout<<2<<' '<<v[i].fst<<' '<<v[i].snd<<' '<<v[i + 1].fst<<' '<<v[i + 1].snd<<endl;
				i++;
				k--;
			}
			else{
				cout<<v.size()-i;
				for (int j = i; j < v.size(); j++)
					cout<<' '<<v[j].fst<<' '<<v[j].snd;
				gnl;
				return 0;	
			}
		}
			

	}
}