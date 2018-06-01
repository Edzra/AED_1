#include<bits/stdc++.h>
#define MAX 1000002
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int pai[MAX],tam[MAX];

void init(int n){
    for (int i=0;i<=n;i++){
        pai[i]=i;
        tam[i]=1;
    }
}

int id(int x){
    if (pai[x]!=x) return pai[x]=id(pai[x]);
    return pai[x];
}

void join(int u, int v){
    u=id(u) , v=id(v);
    if (u==v) return;
    if (tam[u]<tam[v]) swap(u,v);
    pai[v]=u;
    tam[u]=tam[u]+tam[v];
}

int issame(int u, int v){
    return (id(u)==id(v));
}

int n,m,a,b,e,i,cont;

int main(){_
        while(cin>>n>>m){
                init(n);
                while(m--){
                    cin>>a>>b;
                    if(!issame(a,b)) join(a,b);

                }
                cin>>e;
                for(i=1; i<=n; i++){
                    if(issame(e,i)) cont++;
                }

                cout<<cont<<endl;
                cont=0;
        }

    return 0;
}
