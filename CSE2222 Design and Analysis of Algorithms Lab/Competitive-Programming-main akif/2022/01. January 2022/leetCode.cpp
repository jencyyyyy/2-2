class Solution 
{
    public:
        vector<long long> sortedSquares(vector<int>& nums) 
        {

            int N = nums.size();

            int i;

            vector<int>neg;

            int xx = 1;
            for(i = xx; i<=N; i++){
                if(nums[i]>=0)  
                    break;
                int p = nums[i];
                neg.push_back(p*p);
            }

            xx = i;

            vector<long long> sq;
            int j = neg.size()-1;

            while(xx<=N){

                if(j>=0)
                {
                    if(neg[j]<=(nums[xx]*nums[xx]))
                    {
                        sq.push_back(neg[j]);
                        j--;
                    }

                    else 
                    {
                        sq.push_back(nums[xx]*nums[xx]);
                        xx++;
                    }
                }

                else
                {
                    sq.push_back(nums[xx]*nums[xx]);
                    xx++;
                }
            }

            return sq;
        }
};

int main(){
    Solution *s = new Solution();
    s->sor
}