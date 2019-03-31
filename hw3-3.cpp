#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
int T,n,k;
stack<int> Stack;
vector<int> visited;
vector<vector<int> > adj;
void build_hei(int*SA, int*RA, int*S, int*Hei){
    int k=0;
    for(int i=0;i<n;i++){
        if(RA[i]!=0){
            while(S[i+k]==S[SA[RA[i]-1]+k])k++;
        }
        Hei[RA[i]]=k;
        k=max(0,k-1);
    }
}
void topologicalSort(int v,vector<int> &visited,stack<int> &Stack){ 
    visited[v]=1;//true
    if (adj[v].size()!=0){
		set<int> Set(adj[v].begin(),adj[v].end());
		set<int>::iterator i;
	    for (i=Set.begin();i!=Set.end();++i){ 
  	      int node=*i; 
  	      if (!visited[node]){
     	       topologicalSort(node,visited,Stack);
     	   }
    	}
	}
    Stack.push(v); 
} 
int main(){
	scanf("%d",&T);
	for (int t=0;t<T;t++){
		scanf("%d %d",&n,&k);
		int a[n],r[n],s[n],hei[n];
		adj.resize(k);
		visited.resize(k);
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);a[i]-=1;
		}
		for (int i=0;i<n;i++){
			scanf("%d",&r[i]);r[i]-=1;
			s[r[i]]=i;
		}
		build_hei(s,r,a,hei);
		for (int i=1;i<n;i++){
			int len_small=n-s[i-1];int len_big=n-s[i];
			if (hei[i]<min(len_small,len_big)){
				int small=a[s[i-1]+hei[i]];int big=a[s[i]+hei[i]];
				adj[small].push_back(big);
			}
		}
		for (int i=0;i<k;i++){visited[i]=0;}
	    for (int i=0;i<k;i++){ 
	    	if (visited[i]==0){
				topologicalSort(i,visited,Stack);
			}
		}  
	    while (!Stack.empty()){ 
	        printf("%d",Stack.top()+1); 
	        Stack.pop();
			if (!Stack.empty()){printf(" ");}
	    }
	    if (t!=T-1){printf("\n");adj.resize(0);}
	}
	return 0;
} 

