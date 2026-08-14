class DSU{
public:
    vector<int> parent,rank,size;
    
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

        for(int i = 0 ; i<=n ; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node] == node) return node;

        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
         
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string,int> mailNode; // MAPS MAIL TO NODE 

        for(int i = 0 ; i<n ; i++){
            for(int j = 1 ; j<accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mailNode.find(mail) == mailNode.end()){
                    mailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i,mailNode[mail]);
                }
            }
        }

        vector<vector<string>> merged(n);
        for(auto it : mailNode){
            string mail = it.first;
            int node = ds.findUpar(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0 ; i<n ; i++){
            if(merged[i].size() == 0) continue;
            sort(merged[i].begin() , merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merged[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};