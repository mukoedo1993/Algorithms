class Solution {
public:
   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())return true;
        //in_degree
   
        int r=prerequisites.size();
        //initialize in_degree for each vertex:
        vector<int>in_degs(numCourses);
        vector<int> contrl=in_degs;//we will use this to determine whether our test succeed.
        for(int i=0;i<r;i++)
        for(int j=1;j<(prerequisites.at(i)).size();j++)
        {
            int hehe=(prerequisites.at(i)).at(j);
           
           in_degs.at(hehe)=in_degs.at(hehe)+1;
           
        }
      
        bool newzero=true;
        while(newzero){
             newzero=false;
            for(int i=0;i<r;i++)
            {
               
               if((prerequisites.at(i)).size()>1)
                {
                   
                    if(in_degs.at((prerequisites.at(i)).at(0))==0)
                    {   in_degs[prerequisites[i][1]]
                           =std::max(0,in_degs[prerequisites[i][1]]-1);
                           newzero=true;
                          //std::cout<<"hehe"<<r; 
                           for(int i1=0;i1<prerequisites[i].size()-1;i1++)
                           prerequisites[i][i1]=prerequisites[i][i1+1];
                           
                           if(prerequisites[i].size()==1) 
                           {
                                in_degs[prerequisites[i][0]]--;
                               (prerequisites[i]).clear();
                            }
                             if(prerequisites[i].size()>1) 
                            {
                                prerequisites[i].pop_back();  
                            }
                            
                    }
                   }
                }
            }
      //for(auto i:in_degs)std::cout<<i<<" ";
        if(contrl==in_degs)return true;
        return false;

    }
};
