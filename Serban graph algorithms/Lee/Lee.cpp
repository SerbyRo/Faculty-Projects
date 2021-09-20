#include "lee.h"
#include <iostream>

void lee(vector<vector<int>> &maze, pair<int, int> start_point, pair<int, int> end_point, int rows, int columns){
    vector<int> row_direction = {-1, 0, 1, 0};
    vector<int> column_direction = {0, 1, 0, -1};

    queue<pair<int, int>> Queue;
    Queue.push(start_point);
    maze[start_point.first][start_point.second] = 1;
    int current_row, current_column, new_row, new_column;
    //lee
    while (!Queue.empty()){
        auto current_point = Queue.front();
        Queue.pop();
        current_row = current_point.first;
        current_column = current_point.second;
        for(int k = 0; k < 4; k++){
            new_row = current_row + row_direction[k];
            new_column = current_column + column_direction[k];
            if(new_row >= 0 && new_row < rows && new_column >= 0 && new_column < columns){
                if(maze[new_row][new_column] == 0){
                    maze[new_row][new_column] = maze[current_row][current_column] + 1;
                    Queue.push(make_pair(new_row, new_column));

                    if(new_row == end_point.first && new_column == end_point.second){
                        while (!Queue.empty()){
                            Queue.pop();
                        }
                        break;
                    }
                }
            }
        }
    }

    //path
    vector<vector<int>> path(rows, vector<int>(columns, 0));
    current_row = end_point.first;
    current_column = end_point.second;
    int current_val = maze[current_row][current_column];
    while (current_val != 1){
        path[current_row][current_column] = 1;
        for (int k = 0; k < 4; k++) {
            new_row = current_row + row_direction[k];
            new_column = current_column + column_direction[k];
            if(new_row >= 0 && new_row < rows && new_column >= 0 && new_column < columns) {
                if (maze[new_row][new_column] + 1 == maze[current_row][current_column]) {
                    current_row = new_row;
                    current_column = new_column;
                    current_val = maze[current_row][current_column];
                    break;
                }
            }
        }
    }
    path[current_row][current_column] = 1;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}


#include <iostream>
#include <fstream>
#include "readMaze.h"

void readMaze(vector<vector<int>> &maze, pair<int, int> &start_point, pair<int, int> &end_point, int &rows, int &columns, ifstream &fin){
    string line;
    int line_index = 0, column_index = 0;
    while (getline(fin, line)){
        int line_size = line.size();
        vector<int> line_vector(line_size);
        maze.push_back(line_vector);
        column_index = 1;
        for(auto element : line){
            if(element == 'S'){
                start_point = make_pair(line_index, column_index);
                maze[line_index][column_index] = 0;
            }
            else if(element == 'F'){
                end_point = make_pair(line_index, column_index);
                maze[line_index][column_index] = 0;
            }
            else if (element == '1'){
                maze[line_index][column_index] = -1;
            } else{
                maze[line_index][column_index] = 0;
            }
            column_index++;
        }
        line_index++;
    }
    rows = line_index;
    columns = column_index;
}

void printMaze(vector<vector<int>> maze){
    for(auto line : maze){
        for(auto element : line){
            cout << element << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


int main() {
    int rows, columns;
    pair<int, int> start_point, end_point;
    vector<vector<int>> maze;

    readMaze(maze, start_point, end_point, rows, columns, fin);
    //printMaze(maze);
    cout << start_point.first << " " << start_point.second << "\n";
    cout << end_point.first << " " << end_point.second << "\n";
    cout << rows << " " << columns << "\n\n";

    lee(maze, start_point, end_point, rows, columns);
    //printMaze(maze);

    return 0;
}

