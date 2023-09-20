class Solution
{
        public:
        vector <int> rotate (int n, int d)
        {
            d%=16;
            int left1=n>>(16-d);
            int left2=n<<d;
            int ans1=(left1|left2)&((1<<16)-1);
            
            int right1=n<<(16-d);
            int right2=n>>d;
            int ans2=(right1|right2)&((1<<16)-1);
            
            return {ans1,ans2};
        }
};
