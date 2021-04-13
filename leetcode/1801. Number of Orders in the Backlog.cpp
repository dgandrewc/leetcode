class Solution {
public:
    struct cmp{
        bool operator()(vector<int> a, vector<int> b)
        {
            return a[0]<b[0];
        }
    };
    struct cmp2{
        bool operator()(vector<int> a, vector<int> b)
        {
            return a[0]>b[0];
        }
    };
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> buy;
        priority_queue<vector<int>, vector<vector<int>>, cmp2> sell;
        
        for(int i=0; i<orders.size(); i++)
        {
            if(orders[i][2]==0) // buy
            {
                while(!sell.empty() && orders[i][1]!=0 && sell.top()[0]<=orders[i][0])
                {
                    vector<int> sell_top=sell.top();
                    sell.pop();
                    if(sell_top[1]>orders[i][1])
                    {
                        sell_top[1]-=orders[i][1];
                        orders[i][1]=0;
                        sell.push(sell_top);
                    }
                    else
                    {
                        orders[i][1]-=sell_top[1];
                    }
                }
                
                if(orders[i][1]!=0)
                    buy.push({orders[i][0], orders[i][1], orders[i][2]});
            }
            else // sell
            {
                while(!buy.empty() && orders[i][1]!=0 && buy.top()[0]>=orders[i][0])
                {
                    vector<int> buy_top=buy.top();
                    buy.pop();
                    if(buy_top[1]>orders[i][1])
                    {
                        buy_top[1]-=orders[i][1];
                        orders[i][1]=0;
                        buy.push(buy_top);
                    }
                    else
                    {
                        orders[i][1]-=buy_top[1];
                    }
                }
                
                if(orders[i][1]!=0)
                    sell.push({orders[i][0], orders[i][1], orders[i][2]});
            }
        }
        
        int ans=0;
        
        while(!buy.empty())
        {
            ans+=buy.top()[1];
            ans%=1000000007;
            buy.pop();
        }
        while(!sell.empty())
        {
            ans+=sell.top()[1];
            ans%=1000000007;
            sell.pop();
        }
        
        return ans;
    }
};