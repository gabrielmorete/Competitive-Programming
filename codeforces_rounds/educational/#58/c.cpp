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

int sz[112345],id[112345];
typedef tuple<int,int,int> tup;

void init(int n){
	frr(i,n){
		id[i]=i;
		sz[i]=1;
	}
}

int find(int a){
	if(id[a]==a) return a;
	return id[a]=find(id[a]);
}

void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(sz[a]<sz[b])
		swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}



void solve(){
	int n,l,r;
	set<tup> q;

	cin>>n;
	init(n);

	frr(i,n){
		cin>>l>>r;

		auto re=q.lower_bound({l,l,0}); 
		auto rd=q.lower_bound({0,l,0});
		auto ld=q.lower_bound({r,0,0});
		auto le=q.lower_bound({l,0,0});
		if(!q.empty()){
			auto it=q.end;
			it--;
		}

		// if(l==r && r==4){
		// 	cout<<get<0>(*re)<<' '<<get<1>(*re);
		// 	gnl;
		// }

		if(re==q.end() && get<1>(it)<l){
			q.insert({l,r,i});
			continue;
		}

		if(re!=q.end() and r < get<0>(*re)){
			q.insert({l,r,i});
			continue;
		}
		if(re!=q.end()){
			int left=min(l,get<0>(*re));
			int rigt=min(r,get<1>(*re));
			merge(i,get<2>(*re));
			q.erase(re);
			q.insert({left,rigt,find(i)});
		}

		if(rd!=q.end() && rd!=re && get<0>(*rd)<r){
			int left=min(l,get<0>(*rd));
			int rigt=min(r,get<1>(*rd));
			merge(i,get<2>(*rd));
			q.erase(rd);
			q.insert({left,rigt,find(i)});
		}
	}
	map<int,int> m;
	bool ok=0,ok2=0;
	frr(i,n){
		int rp=find(i);
		if(m[rp]==0){
			if(ok==0){
				m[rp]=1;
				ok=1;
			}
			else{
				ok2=1;
				m[rp]=2;
			}
		}
}

if(ok==0 or ok2==0){
	cout<<-1<<endl;
	return;
}

frr(i,n){
	int rp=find(i);
	cout<<m[rp]<<' ';
}
gnl;


}


int main(){
	fastio;
	int T;
	cin>>T;
	while(T--) solve();
}