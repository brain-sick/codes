#include<bits/stdc++.h>
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define pb           push_back
#define ff           first
#define ss           second
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define Pi           2*acos(0.0)
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
using namespace std;
const int mod = 1e9+7;
ll expo(ll a,ll b,ll m = mod){
	a%=mod;
	ll res = 1;
	while(b){
		if(b&1)
			res = (res*a)%m;
		a = (a*a)%m;
		b>>=1;
	}
	return res;
}
ll gcd(ll a,ll b){
	while(b>0){
		ll r = a%b;
		a = b; b = r;
	}
	return a;
}
void printTime(clock_t start,clock_t end){
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
}
const int nax = 100005;
vector<int> adj[nax] , nadj[nax];
stack<int> st;
vector<bool> vis1(nax,0) , vis2(nax,0);
void dfs1(int u){
    vis1[u] = 1;
    for(auto v:adj[u]){
        if(vis1[v]) continue;
        dfs1(v);
    }
    st.push(u);
}
vector<int> who(nax,-1);
vector<ll> cnt(nax,0);
void dfs2(int u,int rep){
    vis2[u] = 1;
    who[u] = rep;
    for(auto v:nadj[u]){
        if(vis2[v]) continue;
        dfs2(v,rep);
    }
}

int main()
{
	 
    boost
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
    clock_t start, end; 
    start = clock();
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> c(nax);
        rep(i,1,n+1) cin>>c[i];
        int m;
        cin>>m;
        rep(i,0,m){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
        }
        for(int i=1;i<=n;i++){
            if(!vis1[i])
                dfs1(i);
        }
        for(int u=1;u<=n;u++){
            for(int v:adj[u]){
                nadj[v].pb(u);
            }
        }
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(!vis2[u])
                dfs2(u,u);
        }
        vector<int> cost=c;
        
        for(int i=1;i<=n;i++){
            cost[who[i]] = min(cost[who[i]],cost[i]);
        }
        
        for(int i=1;i<=n;i++){
            if(c[i]==cost[who[i]])
            cnt[who[i]]++;    
        }
        
        
        /*vector<int> in(nax,0);
        for(int u=1;u<=n;u++){
            for(auto v:adj[u]){
                if(who[u]==u && who[v]==v){
                    in[who[v]]++;
                    
                }
            }
        }*/
        ll ans = 0;
        ll ways = 1;
        for(int i=1;i<=n;i++){
            if(who[i]==i){
                ans+=cost[i];
                ways = (ways * cnt[i]%mod)%mod;
                
            }
        }
        cout<<ans<<"\n"<<ways<<"\n";
    }
    end = clock();
    //printTime(start,end);
    return 0;
}
