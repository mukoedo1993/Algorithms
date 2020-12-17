//https://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/
//Notice that the leetcode has updated the question. It replaced pair with vector.
// Author: Huahua
// Runtime: 3 ms
class Solution {
public:
  vector<double> calcEquation(const vector<vector<string>>& equations, vector<double>& values, const vector<vector<string>>& queries) {
  // parents["A"] = {"B", 2.0} -> A = 2.0 * B
  // parents["B"] = {"C", 3.0} -> B = 3.0 * C
  unordered_map<string, pair<string, double>> parents;
 
  for (int i = 0; i < equations.size(); ++i) {
    const string& A = equations[i][0];
    const string& B = equations[i][1];
    const double k = values[i];
    // Neighter is in the forrest
    if (!parents.count(A) && !parents.count(B)) {
      parents[A] = {B, k};
      parents[B] = {B, 1.0};
    } else if (!parents.count(A)) {
      parents[A] = {B, k};
    } else if (!parents.count(B)) {
      parents[B] = {A, 1.0 / k};
    } else {
      auto& rA = find(A, parents);
      auto& rB = find(B, parents);      
      parents[rA.first] = {rB.first, k / rA.second * rB.second};
    }    
  }
 
  vector<double> ans;
  for (const auto& pair : queries) {
    const string& X = pair[0];
    const string& Y = pair[1];
    if (!parents.count(X) || !parents.count(Y)) {
      ans.push_back(-1.0);
      continue;
    }
    auto& rX = find(X, parents); // {rX, X / rX}
    auto& rY = find(Y, parents); // {rY, Y / rY}
    if (rX.first != rY.first)
      ans.push_back(-1.0);
    else // X / Y = (X / rX / (Y / rY))
      ans.push_back(rX.second / rY.second);
  }
  return ans;
}
private:
  pair<string, double>& find(const string& C, unordered_map<string, pair<string, double>>& parents) {
    if (C != parents[C].first) {
      const auto& p = find(parents[C].first, parents);
      parents[C].first = p.first;
      parents[C].second *= p.second;
    }
    return parents[C];
  }
};
