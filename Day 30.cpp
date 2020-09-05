// Largest Component Size by Common Factor

int ans;

class UF {
public:
    vector<int> parent;
    int numComponents;

    UF(int n) {
        parent.resize(n + 1, -1);
        numComponents = n;
    }

    int find(int x) {
        int root = x;
        while(parent[root] > 0) {
            root = parent[root];
        }

        // Path Compression
        while(parent[x] > 0) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;
    }

    void unionz(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);

        if(root1 == root2)
            return;

        if(parent[root1] < parent[root2]) {
            parent[root1] += parent[root2];
            ans = max(ans, -parent[root1]);
            parent[root2] = root1;
        } else {
            parent[root2] += parent[root1];
            ans = max(ans, -parent[root2]);
            parent[root1] = root2;
        }

        
        numComponents--;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        ans = 0;
        UF unionFind(100000);
        for(int x : A) {
            for(int i = 2; i * i <= x; i++) {
                if(x % i)
                    continue;
                unionFind.unionz(x, i);
                unionFind.unionz(x, x / i);
                // cout << i << " " << x << endl;
                // cout << unionFind.parent[i] << " " << unionFind.parent[x] << endl;
                // cout << x / i << " " << x << endl;
                // cout << unionFind.parent[i] << " " << unionFind.parent[x / i] << endl << endl;
            }
        }
        ans = 0;
        unordered_map<int, int> mp;
        for(int x : A) {
            
            ans = max(ans, ++mp[-unionFind.find(x)]);
        }
        return ans;
    }
};