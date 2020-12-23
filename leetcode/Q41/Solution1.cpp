class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())return 1;
         const int size=nums.size();
      //To eradicate invalid values
        for(int i=0;i<size;i++){
           
            if(nums[i]<=0||nums[i]>size)nums[i]=size+1;
           
        }
        
        
        for(int i=0;i<size;i++){
           const int index=abs(nums[i]);
            if(index>size)//So we skip these invalid values
                continue;
                nums[index-1]= abs(nums[index-1])*(-1);//if we have dealt with the value before, 
                //the value we are dealing with now will remain a negative value.
        }
        
      
       for(int i=0;i<size;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
     
      
       return size+1;
    }

    
};
