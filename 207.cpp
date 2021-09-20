class Solution {
private:
    typedef vector<vector<int>> Graph;
    
    Graph buildGraph(int numCourses, const vector<vector<int>>& prerequisites){
        Graph g(numCourses);
        
        for(vector<int> item: prerequisites){
            g[item[1]].push_back(item[0]);
        }
        
        return g;
    }
    
    vector<int> calculateInDegree(Graph &g){
        vector<int> res(g.size(), 0);
        
        for(vector<int> adj: g){
            for(int inVertex: adj){
                res[inVertex]++;
            }
            
        }
        
        return res;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g = buildGraph(numCourses, prerequisites);
        
        vector<int> degrees = calculateInDegree(g);
        
        for(int i = 0; i < numCourses; i++){
            int j = 0;
            for(j = 0; j < numCourses; j++){
               if(degrees[j] == 0){
                   break;
               }
            }
            
            if(j == numCourses){
                return false;
            }else{
                degrees[j]--;
                for(int num: g[j]){
                    degrees[num]--;
                }
            }
        }
        return true;
    }

};