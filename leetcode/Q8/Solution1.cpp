class Solution {
public:
    int myAtoi(string s) {
        if(s[0]==' ')return myAtoi(s.substr(1));
        int i=0;
        try
        {
            i=stoi(s);
        }catch(invalid_argument)
        {
            return 0;
        }
        catch(out_of_range)
        {    
            if(s[0]!='-')
            return -1*(1+pow(-2,31));
            else
                return pow(-2,31);
        }
       return i;
    }
};
