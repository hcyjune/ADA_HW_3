#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector <int> v,v_new;
long long ans;
vector <long long> ans_prv;
int main(){
	scanf("%d",&n);
	v.resize(2*n);
	for (int i=0;i<n;i++){
		scanf("%d %d",&v[2*i],&v[2*i+1]);
	}
	ans=v[1]-v[0];ans*=ans;printf("%lld\n",ans);
	v_new.push_back(v[0]);v_new.push_back(v[1]);ans_prv.push_back(ans);
	vector<int>::iterator it;
	for (int i=1;i<n;i++){
		it=lower_bound(v_new.begin(),v_new.end(),v[2*i]);
		int id=it-v_new.begin();
		if (id<v_new.size()){
			v_new.erase(it,v_new.end());
			ans_prv.erase(ans_prv.begin()+id/2,ans_prv.end());
			if (id%2==0){v_new.push_back(v[2*i]);}
			ans=v[2*i+1]-v_new[v_new.size()-1];
		}
		else{		
			ans=v[2*i+1]-v[2*i];
			v_new.push_back(v[2*i]);
		}
		ans*=ans;if (ans_prv.size()!=0){ans+=ans_prv[ans_prv.size()-1];}printf("%lld",ans);
		ans_prv.push_back(ans);v_new.push_back(v[2*i+1]);if (i!=n-1){printf("\n");}
	}
	return 0;
}
