#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;
vvi vec3;
vvi vec2;
vvi vec1;
vi parent1, parent2;
vi vis;
int sum;

  void find_path(vvi & vec, vi & parent, int i){
    for(int j = 0; j < vec[i].size(); ++j){
       if(parent[i] != parent[vec[i][j]]){
            sum++;
               if(parent[i] > parent[vec[i][j]])
                  parent[i] = parent[vec[i][j]];
                     else
                  parent[vec[i][j]] = parent[i];
                     find_path(vec, parent, vec[i][j]);
                                                          }
                                                              }
                                                                  }


  int main(){

     ios::sync_with_stdio(0);

        cin >> n >> m;
        vec1.resize(n);
        vec2.resize(n);
        vec3.resize(n);
        parent1.resize(n);
        vis.resize(n, 0);
        sum = 0;
           for(int i = 0; i < n; ++i) {
              parent1[i] = i;
                                             }
        int a, b, c;
           for(int i = 0; i < m; ++i) {
              cin >> a >> b >> c;
                  a--;
                  b--;
                   if(c == 3) {
                      vec3[a].push_back(b);
                      vec3[b].push_back(a);
                                                   }
                   else if(c == 2){
                      vec2[a].push_back(b);
                      vec2[b].push_back(a);
                                                         }
                   else if(c == 1){
                      vec1[a].push_back(b);
                      vec1[b].push_back(a);
                                                                 }
                                                                         }
          int ans  = 0;
             for(int i = 0; i < vec3.size(); ++i) {
                if(parent1[i] == i){
                    find_path(vec3, parent1, i);
                                                                                   }
                                                                                            }
                         ans += sum;
                         sum = 0;
                         parent2 = parent1;
             for(int i = 0; i < vec3.size(); ++i) {
                if(parent1[i] == i){
                    find_path(vec2, parent1, i);
                                                                                                     }
                                                                                                             }
                         ans += sum;
                         sum = 0;
             for(int i = 0; i < vec3.size(); ++i) {
                if(parent1[i] == i){
                    find_path(vec1, parent2, i);
                                                                                                                    }
                                                                                                                        }
                          ans += sum;
                             cout << m - ans << endl;

                                                                                                                              }
