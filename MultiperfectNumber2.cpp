/*
 Multiperfect number in C++
 C++による倍積完全数の判定と個数を求めるプログラム
 (ii). 入力を2つの整数(N,Mとする)にし、N以上M以下の範囲で考える場合
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll POW(ll x,ll y){
    ll ret=1;
    for(ll i=1;i<=y;i++){
        ret*=x;
    }
    return ret;
}
vector<pair<ll,ll>> f(ll n){
    vector<pair<ll,ll>> v;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i!=0){
            continue;
        }else{
            ll cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            v.push_back(pair(i,cnt));
        }
    }
    if(n!=1){
        v.push_back(pair(n,1));
    }
    return v;
}
ll σ(ll n){
    if(n==1){
        return 1;
    }
    ll ans=1;
    vector<pair<ll,ll>> v=f(n);
    for(auto [i,j] : v){
        ll num=(POW(i,j+1)-1)/(i-1);
        ans*=num;
    }
    return ans;
}
int main(void){
    ll n,m,cnt=0;
    cin>>n>>m;
    for(ll i=n;i<=m;i++){
        ll num=σ(i);
        if(num%i==0){
            cnt++;
        }
    }
    printf("%lld以上%lld以下の整数には、倍積完全数が%lld個含まれています.\n",n,m,cnt);
    for(ll i=n;i<=m;i++){
        ll num=σ(i);
        if(num%i==0){
            printf("%lld: %lld倍完全数です.\n",i,num/i);
        }else{
            printf("%lld: 倍積完全数ではありません.\n",i);
        }
    }
    return 0; 
}