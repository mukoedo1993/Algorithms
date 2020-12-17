//DFS:
//author: huahua
//https://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/
//modified by: mukoedo1993
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>>g;
        //g[A][B]=k -> A/B=k
        
        for(int i=0;i<equations.size();i++){
            const string&A=equations[i][0];
            const string&B=equations[i][1];
            const double k = values[i];
            g[A][B]=static_cast<double>(k);
            g[B][A]=static_cast<double>(1.0)/static_cast<double>(k);
        }
        
        vector<double>ans;
        for(const vector<string>&futari: queries){// futari:pair in Japanese
            const string& X=futari[0];
            const string& Y=futari[1];
            if(!g.count(X)||!g.count(Y)){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string>visited;
            ans.push_back(divide(X,Y,g,visited));
        }
        return ans;
    }

private:
    //get result of A/B:
    double divide(const string&A, const string&B,
                 unordered_map<string,unordered_map<string,double>>& g,
                 unordered_set<string>& visited){
        if(A==B)return 1.0;
        visited.insert(A);
        for(const pair<const string,double>&futari: g[A]){
            const string&C = futari.first;
            if(visited.count(C))continue;
            double d=divide(C,B,g,visited); //d=C/B
            // A/B=C/B*A/C
            if(d>0)return d*g[A][C];
        }
        return -1.0;
    }
};
