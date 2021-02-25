#include <iostream>
#include <algorithm>
using namespace std;
int f[200000];
struct node{
    int a,b,c;
};
int find(int x)
{
    if (x==f[x]) return f[x];
    else return f[x]=find(f[x]);//
}
bool cmp(node a,node b){
    return a.c<b.c;
}
int main() {
    node M[100000000];
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <=n ; ++i) {
        f[i]=i;
    }
    for (int i = 1; i <=m ; ++i) {
        cin>>M[i].a>>M[i].b>>M[i].c;
    }
    sort(M+1,M+m+1,cmp);
    for (int i = 1; i <=m; ++i) {
       int fx=find(M[i].a),fy=find(M[i].b);
        if (fx!=fy){f[fx]=fy,n--;}//合并树
        if (n==1){cout<<M[i].c;
            return 0;}
        }
    cout<<-1;
    return 0;
}
