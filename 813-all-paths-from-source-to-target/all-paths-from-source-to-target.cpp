class Solution {
public:
    
    void helper(int src,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& path,vector<bool>&vis ){
            if(src==graph.size()-1){
                ans.push_back(path);
                return;
            }

            vis[src]=true;

            for(int v: graph[src]){
                if(!vis[v]){
                    path.push_back(v);
                    helper(v,graph,ans,path,vis);
                    path.pop_back();
                }
            }
            vis[src]=false;

    }
   
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> vis(graph.size(),false);
        path.push_back(0);
        helper(0,graph,ans,path,vis);
        return ans;
    }
};