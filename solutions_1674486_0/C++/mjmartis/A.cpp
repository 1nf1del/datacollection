#include <iostream>
#include <vector>
#include <queue>
#define for0(i, N) for(int i = 0; i < (N); i++)
using namespace std;

int main(int argc, char *argv[]) {
        int T;
        cin >> T;
        
        for0(t, T) {
            int N;
            cin >> N;
            
            vector<vector<bool> > g(N, vector<bool>(N, false));
            
            for0(i, N) {
                int M;
                cin >> M;
                
                for0(j, M) {
                    int C;
                    cin >> C;
                    //cout << C-1 << endl;
                    g[C-1][i] = true;
                }
            }
            
            bool bad = false;
            
            for0(i, N) {
                queue<int> q;
                q.push(i);
                vector<bool> vis(N, false);
                
                while(q.empty() == false) {
                    int n = q.front();
                    q.pop();

                    if(vis[n]) {
                        bad = true;
                        break;
                    }
                    
                    vis[n] = true;
                    
                    for0(j, N) {
                        if(j == i) continue;
                        if(g[n][j]) q.push(j);
                    }
                }
                
                if(bad) break;
            }
            
            cout << "Case #" << (t+1) <<": " << ((bad) ? "Yes" : "No") << endl;
        }
    }
                        
                    
        
        
        
        
        
        
        
    
