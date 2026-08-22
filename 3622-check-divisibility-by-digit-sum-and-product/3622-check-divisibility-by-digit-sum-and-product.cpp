class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int sum=0;
        int mul=1;
        for(int i=0;i<=s.size()-1;i++){
            
            int digits=s[i]-'0';
            sum+=digits;
            mul*=digits;
        }
            if(n%(sum+mul)==0){
                return true;
            }
            

        return false;
        
    }
};