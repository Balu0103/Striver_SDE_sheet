#include<bits/stdc++.h>
class DisJointSet{
	vector<int> parent,size;
	public:
		DisJointSet(int n){
			parent.resize(n+1);
			size.resize(n+1,1);
			for(int i=0;i<=n;i++){
				parent[i]=i;
			}
		}
		int findUlParent(int u){
			if(u==parent[u]) return u;
			return parent[u]=findUlParent(parent[u]);
		}
		void unionBySize(int u, int v){
			int uPar_u=findUlParent(u);
			int uPar_v=findUlParent(v);
			if(size[uPar_u]>size[uPar_v]){
				size[uPar_u]+=size[uPar_v];
				parent[uPar_v]=uPar_u;
			}
			else{
				parent[uPar_u]=uPar_v;
				size[uPar_v]+=size[uPar_u];
			}
		}
};
int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<pair<int,pair<int,int>>> dis;
	for(auto it:edges){
		dis.push_back({it[2],{it[0],it[1]}});
	}
	int mst=0;
	DisJointSet ds(n);
	sort(dis.begin(),dis.end());
	for(auto it:dis){
		int wt=it.first;
		int node=it.second.first;
		int adjNode=it.second.second;
		if(ds.findUlParent(node)!=ds.findUlParent(adjNode)){
			mst+=wt;
			ds.unionBySize(node,adjNode);
		}
	}
	return mst;
}
