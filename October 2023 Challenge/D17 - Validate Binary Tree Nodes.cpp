class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftchild, vector<int>& rightchild) {
        vector<int> indegree(n, 0); 

        for(int i=0;i<n;++i)
        {
            if(leftchild[i]!=-1) indegree[leftchild[i]]++;
            if(rightchild[i]!=-1) indegree[rightchild[i]]++;
        }
        int root = -1;
        for(int i=0;i<n;++i)
        {
            if(indegree[i]==0)
            {
                if(root==-1) root=i;
                else return false;
            }
        }

        if(root==-1) return false;
        vector<bool> visited(n, false);
        queue<int> queue;
        queue.push(root); 
        while(!queue.empty())
        {
            int node = queue.front();
            queue.pop();
            if(visited[node]) return false;
            visited[node] = true;
            if(leftchild[node]!=-1) queue.push(leftchild[node]);
            if(rightchild[node]!=-1) queue.push(rightchild[node]);
        }
        return accumulate(visited.begin(), visited.end(), 0)==n;
    }
};
