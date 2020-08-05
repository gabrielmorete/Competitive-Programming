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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

typedef tuple<int,int,int> tup;

int main(){
	fastio;
	int n;
	vector<tup> v;

	bool ok=0;
	int ini,fim;
	fim=0;ini=0;

	string s;

	cin>>n;
	getline(cin,s);
	getline(cin,s);

	fr(i,s.size()){

		if(s[i]=='G' && ok==0){
			ok=1;
			ini=i+1;

		}
		else if(s[i]=='S' && ok){
			fim=i+1;
			v.pb({ini,fim,fim-ini});
			fim=0;
			ini=0;
			ok=0;
		}

	}
	if(ini!=0){

		v.pb({ini,s.size(),s.size()-ini+1});
	}




	if(v.size()==0){
		cout<<0<<endl;
		return 0;
	}
	if(v.size()==1){
		cout<<get<2>(v[0])<<endl;
		return 0;
	}

	bool lol=0;
	if(v.size()>=2)
		lol=1;

	ok=0;
	if(v.size()>2)
		ok=1;
	

	int best=get<2>(v[0])+lol;

	for(int i=0;i<v.size()-1;i++){

		if((get<2>(v[i])+lol)>best){
			best=get<2>(v[i])+lol;
		}

		if(get<0>(v[i+1])-get<1>(v[i])==1){
			if((get<2>(v[i+1])+get<2>(v[i])+ok)>best)
				best=(get<2>(v[i+1])+get<2>(v[i])+ok);

		}
	}


	if((get<2>(v[v.size()-1])+lol)>best ){
		best=get<2>(v[v.size()-1])+lol;
	}

	cout<<best<<endl;
	
}