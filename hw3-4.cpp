#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
	int v1;int v2;int w;
} edge;
bool comp_w(Edge e1,Edge e2){return e1.w<e2.w;}
int N,n,a,t,V,E,ans,gcd;
vector<Edge> list;vector<int> p;
int find(int x) {
	if(x==p[x]){
		return x;}
	else{
		p[x]=find(p[x]);
		return p[x];}
}
int Kruskal(){
	int sum=0;p.resize(V);
    for (int i=0;i<V;i++){p[i]=i;}
    sort(list.begin(),list.end(),comp_w);
    int i,j;
    for (i=0,j=0;i<V-1&&j<E;++i){  
        while (find(list[j].v1)==find(list[j].v2)){j++;}
        p[find(list[j].v1)]=find(list[j].v2);
        //printf("(%d,%d)=%d\n",list[j].v1,list[j].v2,list[j].w);
        sum+=list[j].w;
        j++;
    }
    //if (i==V-1){printf("MST")};else{printf("MSF")};
    return sum;
}
int main(){
	scanf("%d",&N);n=N;
	for (int i=0;i<N;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a);
		}n-=1;
	}
	V=N+1;E=N*(N+1)/2;
	list.resize(E);n=N;int k=0;
	for (int i=0;i<N;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&t);
			edge.v1=i;edge.v2=j+(i+1);edge.w=t;
			list[k]=(edge);k++;
		}n-=1;
	}
	/*for (int i=0;i<E;i++){
		edge=list[i];
		printf("(%d,%d)=%d\n",edge.v1,edge.v2,edge.w);}*/
	ans=Kruskal();gcd=__gcd(N,ans);
	printf("%d %d",N/gcd,ans/gcd);
	return 0;
}
