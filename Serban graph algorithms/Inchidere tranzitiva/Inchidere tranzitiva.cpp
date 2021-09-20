int fromFileToTransitiveClosureMatrix(vector<vector<int>> &closure_matrix, ifstream &fin, int nodes){
    int predecessor, successor, edges = 0;

    while(fin >> predecessor >> successor){
        edges++;
        closure_matrix[predecessor][successor] = 1;
        //closure_matrix[successor][predecessor] = 1;
    }

    for(int k = 1; k <= nodes; k++){
        for(int i = 1; i <= nodes; i++){
            for(int  j = 1; j <= nodes; j++){
                closure_matrix[i][j] = closure_matrix[i][j] || (closure_matrix[i][k] && closure_matrix[k][j]);
            }
        }
    }

    return edges;
}

void printTransitiveClosureMatrix(vector<vector<int>> closure_matrix, int nodes){
    int i, j;
    for(i = 1; i <= nodes; i++){
        for(j = 1; j <= nodes; j++){
            cout << closure_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\TransitiveClosure\\in.txt");

    int nodes, edges;
    fin >> nodes;

    //from file to closure matrix
    vector<vector<int>> closure_matrix(nodes + 1, vector<int>(nodes + 1, 0));
    for(int i = 1; i <= nodes; i++){
        closure_matrix[i][i] = 1;
    }
    edges = fromFileToTransitiveClosureMatrix(closure_matrix, fin, nodes);
    printTransitiveClosureMatrix(closure_matrix, nodes);

    return 0;
}
