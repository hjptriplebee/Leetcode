class node
{
public:
    int l, r, h;
};
class Solution {
public:
    node tree[20005 << 2];
    unordered_map<int, int> mp, mp2;
    void build(int l, int r,int now)
    {
        tree[now].l = l;
        tree[now].r = r;
        tree[now].h = 0;
        if(l == r) return ;
        int mid = (l + r) >> 1;
        build(l, mid, now << 1);
        build(mid + 1, r, now << 1 | 1);
    }
    void insert(int l, int r, int h, int now)
    {
        if(tree[now].h >= h) return ;
        if(tree[now].l == l && tree[now].r == r)
        {
            tree[now].h = h;
            //cout<<tree[now].l<<" "<<tree[now].r<<" "<<tree[now].h<<endl;
            return ;
        }
        if(tree[now].h > 0)
        {
            tree[now << 1].h = max(tree[now].h, tree[now << 1].h);
            tree[now << 1 | 1].h = max(tree[now].h, tree[now << 1 | 1].h);
            tree[now].h = 0;
        }
        int mid = (tree[now].l + tree[now].r) >> 1;
        if(r <= mid) insert(l, r, h, now << 1);
        else if(l > mid) insert(l, r, h, now << 1 | 1);
        else
        {
            insert(l, mid, h, now << 1);
            insert(mid + 1, r, h, now << 1 | 1);
        }
    }
    void query(vector<pair<int, int>> &res, int now)
    {
        if(tree[now].l == tree[now].r)
        {
            if(!res.empty() && tree[now].h == res[res.size() - 1].second) return ;
            pair<int, int> tmp = make_pair(mp2[tree[now].l], tree[now].h);
            //if()
            res.push_back(tmp);
            return ;
        }
        if(tree[now].h > 0)
        {
            tree[now << 1].h = max(tree[now].h, tree[now << 1].h);
            tree[now << 1 | 1].h = max(tree[now].h, tree[now << 1 | 1].h);
            tree[now].h = 0;
        }
        query(res, now << 1);
        query(res, now << 1 | 1);
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> index;
        vector<pair<int, int>> res;
        if(buildings.empty()) return res;
        for(int i = 0; i < buildings.size(); i++)
        for(int j = 0; j < 2; j++)
        if(!mp[buildings[i][j]])
        {
            mp[buildings[i][j]] = 1;
            index.push_back(buildings[i][j]);
        }
        sort(index.begin(), index.end());
        int n = index.size();
        for(int i = 0; i < n; i++) 
        {
            mp[index[i]] = i + 1;
            mp2[i + 1] = index[i];
        }
        build(1, n + 1, 1);//建树
        for(int i = 0; i < buildings.size(); i++) insert(mp[buildings[i][0]], mp[buildings[i][1]] - 1, buildings[i][2], 1);//插入房子
        query(res, 1);
        return res;
    }
};