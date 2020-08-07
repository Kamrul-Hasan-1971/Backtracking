#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  all(a)         a.begin(),a.end()

ll ara[20][20],vis[20][20],n;
int fx[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int fy[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
vector<pair<ll,ll> >ans;
bool fun(ll x,ll y,ll cnt)
{
    if(cnt==n*n)
    {
        for(ll i = 0 ; i < n*n ; i++)
            ara[ans[i].first][ans[i].second]=i;
        return  true;
    }
    for( ll i = 0 ; i < n ; i++)
    {
        ll p = x+fx[i];
        ll q = y+fy[i];
        if(p>=0 && p<n && q>=0 && q<n && vis[p][q]==0 )
        {
            vis[p][q]=1;
            ans.push_back({p,q});
            if(fun(p,q,cnt+1)) return true;
            ans.pop_back();
            vis[p][q]=0;
        }
    }
    return false;
}

int main()
{
    CIN;
    ans.push_back({0,0});
    cin >> n ;
    if(fun(0,0,1))
    {
        for(ll i = 0 ; i < n ; i++)
        {
            for(ll j = 0 ; j < n ; j++)
            {
                cout<<ara[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0 ;
}
