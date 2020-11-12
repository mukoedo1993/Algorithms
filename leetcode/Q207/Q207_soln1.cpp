class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())return true;
        //in_degree
   
      const  int r=prerequisites.size();
        //initialize in_degree for each vertex:
        vector<int>in_degs(numCourses);
        vector<int> contrl=in_degs;//we will use this to determine whether our test succeed.
        for(int i=0;i<r;i++)
        for(int j=1;j<(prerequisites[i]).size();j++)
        {
            int hehe=prerequisites[i][j];
           
           in_degs[hehe]=in_degs[hehe]+1;
           
        }
      
        bool newzero=true;
        while(newzero){
             newzero=false;
            for(int i=0;i<r;i++)
            {
               
               if((prerequisites.at(i)).size()>1)
                {
                   
                    if(in_degs[prerequisites[i][0]]==0)
                    {   in_degs[prerequisites[i][1]]
                           =in_degs[prerequisites[i][1]]-1;
                           newzero=true;
                          //std::cout<<"hehe"<<r; 
                         
                           for(int i1=0;i1<prerequisites[i].size()-1;i1++)
                           prerequisites[i][i1]=prerequisites[i][i1+1];
                           
                          
                             if(prerequisites[i].size()>0) 
                            {
                                if(prerequisites[i].size()==1)
                                  in_degs[prerequisites[i][0]]--;
                                prerequisites[i].pop_back();  
                            }
                            
                            
                    }
                   }
                }
            }
     // for(auto i:in_degs)std::cout<<i<<" ";
        if(contrl==in_degs)return true;
        return false;

    }
};

/*
Runtime: 32 ms, faster than 96.14% of C++ online submissions for Course Schedule.
Memory Usage: 12.3 MB, less than 5.03% of C++ online submissions for Course Schedule.
*/
