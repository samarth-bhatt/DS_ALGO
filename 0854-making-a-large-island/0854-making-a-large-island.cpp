class DSU{
    public:
    vector<int>size;
    vector<int>parent;
    DSU(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUpar(parent[node]); // path compression
    }
    void unionBySize(int u, int v){
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);
        if(upar_u == upar_v) return; // already there's an edge
        if(size[upar_u] < size[upar_v]){
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        } else{
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(); // rows
        int m = grid[0].size(); // cols

        int size = n*m + 1;

        DSU ds(size);

        // Step1 - Connecting already connected ones as a single component
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 0) continue;
                int delRow[4] = {-1, 0, +1, 0};
                int delCol[4] = {0, +1, 0, -1};
                for(int i=0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                        int nodeNo = row*m + col;
                        int adjNodeNo = nrow*m + ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Step2 - Try making the cells with value to 1 and see how much max increase in the size of connected components could be obtained, by connecting
        int maxSize = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 1) continue;
                int delRow[4] = {-1, 0, +1, 0};
                int delCol[4] = {0, +1, 0, -1};
                unordered_set<int>uniqueComponents; // to avoid inserting same components many times, which could've resulted in extra counting, hence we insert only Upar of adjacents
                for(int i=0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                        int adjNode = nrow*m + ncol;
                        uniqueComponents.insert(ds.findUpar(adjNode));
                    }
                }
                int currSize = 0;
                for(auto &comp: uniqueComponents) currSize += ds.size[comp];
                maxSize = max(maxSize, currSize + 1); // +1 to include node being changes from 0 to 1
            }
        }
        
        // Step3: There can be a scenario, When all connected components are distinct, so changing 0 to 1 in previous step and count maxSize would not work,
        // So, individually calculating the size of distinct components and taking max out of those distinct component sizes and global_max size which we calculate in step2 by try making 0 to 1 to increase component size

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                int node = row*m + col;
                maxSize = max(maxSize, ds.size[ds.findUpar(node)]);
            }
        }
        return maxSize;
    }
};