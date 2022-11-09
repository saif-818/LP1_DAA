#include<bits/stdc++.h>
using namespace std;
#define N 4
#define INF INT_MAX
struct Node {
  vector < pair < int, int > > path;
  int matrix_reduced[N][N];
  int cost;
  int vertex;
  int level;
};
Node * newNode(int matrix_parent[N][N], vector < pair < int, int > >
  const & path, int level, int i, int j) {
  Node * node = new Node;
  node -> path = path;
  if (level != 0) {
    node -> path.push_back(make_pair(i, j));
  }
  memcpy(node -> matrix_reduced, matrix_parent, sizeof node -> matrix_reduced);
  for (int k = 0; level != 0 && k < N; k++) {
    node -> matrix_reduced[i][k] = INF;
    node -> matrix_reduced[k][j] = INF;
  }
  node -> matrix_reduced[j][0] = INF;
  node -> level = level;
  node -> vertex = j;
  return node;
}
void reduce_column(int matrix_reduced[N][N], int col[N]) {
  fill_n(col, N, INF);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (matrix_reduced[i][j] < col[j]) {
        col[j] = matrix_reduced[i][j];
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (matrix_reduced[i][j] != INF && col[j] != INF) {
        matrix_reduced[i][j] -= col[j];
      }
    }
  }
}

int compute_cost(int matrix_reduced[N][N]) {
  int cost = 0;
  int row[N];
  reduce_row(matrix_reduced, row);
  int col[N];
  reduce_column(matrix_reduced, col);
  for (int i = 0; i < N; i++) {
    cost += (row[i] != INT_MAX) ? row[i] : 0;
    cost += (col[i] != INT_MAX) ? col[i] : 0;
  }
  cout << "\nReduced Matrix :: \n\n";
  display_matrix(matrix_reduced);
  return cost;
}
void display_path(vector < pair < int, int > >
  const & list) {
  cout << "\n\nPath :: \n\n";
  for (int i = 0;
    (unsigned) i < list.size(); i++) {
    cout << list[i].first + 1 << " —> " << list[i].second + 1 << endl;
  }
}
