#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;using vvl = vector<vl>;using vs = vector<string>;
using ml = map<ll, ll>;using uml = unordered_map<ll, ll>;
using pl = pair<ll, ll>;using tl = tuple<ll, ll, ll>;
using vll = vector<pl>;using vlll = vector<tl>;
using pq = priority_queue <pl, vll, greater<pl>>; using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define rev(i, n) for (ll (i) = n-1; (i) >= 0; --(i) )
#define revv(i, n) for (ll (i) = n; (i) > 0; --(i) )
#define inc(v) rep(i, v.size()) cin>>v[i];
#define dec(v) rep(i, v.size()) cout<<v[i]<<" ";
#define inp(n) ll n; cin>>n;
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}

bool check(ll x, vl c, ll n, ll m) {
    int s=0,ns=0;
    for(int i=1;i<=n;++i) {
        s+=min(x,c[i]);
        if(c[i]<x) ns+=(x-c[i])/2;
    }
    if(ns+s>=m)    return true;
    else return false;
}
void calc()
{
    inp(n); inp(m); vl v(n, 0), mp(m+2, 0);
    rep(i, m)
    {
        inp(x); 
        mp[x]++; 
    }
    ll e=0, w=200000;
    while(abs(e-w)<=10)
    {
        ll mid=(e+w)/2;
        if(check(mid, mp, n, m)) w=mid+1;

        // ll ans=0, res=0;
        // repp(i, n) 
        // {
        //     ans+=min(mid,mp[i]);
        //     if(mp[i]<mid) res+=(mid-mp[i])/2;
        // }
        // if((res+ans)>=mid) w=mid+1;
        else e=mid-1;
    }
    for(ll j=e-5; j<=w+5; j++)
    {
        if(!check(j, mp, n, m)&&check(j+1, mp, n, m)) {
            cout << j+1;
            return;
        }
        // ll mid=j; bool f=false, f1=false;
        // ll ans=0, res=0;
        // repp(i, n) 
        // {
        //     ans+=min(mid,mp[i]);
        //     if(mp[i]<mid) res+=(mid-mp[i])/2;
        // }
        // if((res+ans)>=mid) f=true;
        // mid=j+1;
        // ans=0, res=0;
        // repp(i, n) 
        // {
        //     ans+=min(mid,mp[i]);
        //     if(mp[i]<mid) res+=(mid-mp[i])/2;
        // }
        // if((res+ans)>=mid) f1=true;
        // if(!f and f1)
        // {
        //     cout<<j+1;
        //     return;
        // }
    }
    return;
    // if(mp.size()==n)
    // {
    //     cout<<maxx;
    //     return;
    // }
    // pq p;
    // repp(i, n)
    // {
    //     if(mp.find(i)!=mp.end())
    //     {
    //         mp[i]--;
    //         res=max(1ll, res);
    //         p.push({1, i-1});
    //         // vis[i-1]++;
    //         v[i-1]=1;
    //     }
    //     else
    //     {
    //         res=2;
    //         p.push({2, i-1});
    //         v[i-1]=2;
    //         // vis[i-1]++;
    //         for(auto &x:mp)
    //         {
    //             if(x.S!=0) 
    //             {
    //                 x.S--;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // for(auto &x:mp)
    // {
    //     ll i=x.F-1;
    //     while(x.S--)
    //     {
    //         ll t=p.top().F, id=p.top().S;
    //         p.pop();
    //         if(id==i)
    //         {
    //             p.push({t+1, id});
    //             res=max(res, t+1);
    //         }
    //         else
    //         {
    //             if((v[id]+2) < (v[i]+1))
    //             {
    //                 v[id]+=2;
    //                 p.push({t+2, id});
    //                 res=max(res, t+2);
    //             }
    //             else
    //             {
    //                 v[i]+=1;
    //                 p.push({t+1, i});
    //                 res=max(res, t+1);
    //             }
    //         }
    //     }
    // }
    // cout<<res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
