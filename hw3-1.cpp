#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF LLONG_MAX
using namespace std;

struct Node{
	int v,w;
} node;
int n,m,a,b,c;
vector <vector <Node> > adj;
bool operator<(Node n1, Node n2) {return n1.w > n2.w;}
long long dijkstra(int s){ 
    long long dist[n];bool visit[n];
    for (int i=0;i<n;i++){
        dist[i]=INF;
        visit[i]=false;
    }
    dist[s]=0;
    priority_queue<Node> pq;
    pq.push((Node){s,dist[s]}); 
    for (int i=0;i<n;i++){
        int u=-1;
        while (!pq.empty() && visit[u=pq.top().v])
            pq.pop();
        if (u==-1) break;
        visit[u]=true;
        vector<Node>::iterator it;
        for (it=adj[u].begin();it!=adj[u].end();++it){
            if (!visit[it->v] && dist[u]!=INF){
            	long long dist_new=dist[u]+it->w;
            	if (dist[it->v]>dist_new){
            		dist[it->v]=dist_new;
             	   	pq.push((Node){it->v,dist[it->v]});
				}  
            }
        }
    }	
    long long ans=dist[0];
    for (int i=1;i<n;i++){
        if (dist[i]>ans){
        	ans=dist[i];
		}
	}
	if (ans==INF){ans=-1;}
	return ans;
}
int main(){	
	scanf("%d %d",&n,&m);
	adj.resize(n);
	for (int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		node.v=b-1;node.w=c;
		adj[a-1].push_back(node);
		node.v=a-1;
		adj[b-1].push_back(node);
	}
	vector<Node>::iterator it;
	printf("%lld",dijkstra(0));
	return 0;
}
