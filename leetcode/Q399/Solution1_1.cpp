//rewrite:
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>>g;
        for(int i=0;i<equations.size();i++){
            const vector<string> &futari= equations[i];
            const string &f=futari[0];
            const string &s=futari[1];
            const double k=values[i];
            g[f][f]=1.0;
            g[s][s]=1.0;
            g[f][s]=k;
            g[s][f]=1.0/k;
            
        }
        
        vector<double>ans;
        for(const vector<string>& futari:queries){
             const string&A=futari[0];
            const string&B=futari[1];
            if(!g.count(A)||!g.count(B))
            {  
                ans.push_back(-1.0);continue;
            } 
                unordered_set<string>visited;
                double d=solve(A,B,visited,g);
                ans.push_back(d);
        }
        return ans;
    }
    
    double solve(const string&A, const string&B,
                unordered_set<string>&visited,
                  unordered_map< string,unordered_map<string,double>>&g){
        if(A==B)return 1.0;
        visited.insert(A);
        for(const auto& it:(g.at(A))){
            
            const string &tmp=it.first;
            if(visited.count(tmp))continue;//otherwise, it might result in a endless loop...
            //hard to debug...
            double d=solve(tmp,B,visited,g);
            if(d>0)return d*g[A][tmp];
        }
        return -1.0;
    }
    
};
