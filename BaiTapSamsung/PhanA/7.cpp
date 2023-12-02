#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 8;
const int COLS = 8;

bool isValid(int x, int y, vector<vector<int>>& image, vector<vector<bool>>& visited, int targetColor) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && !visited[x][y] && image[x][y] == targetColor;
}

void floodfillDFS(int x, int y, vector<vector<int>>& image, vector<vector<bool>>& visited, int targetColor, int newColor) {
    visited[x][y] = true;
    image[x][y] = newColor;

    static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, image, visited, targetColor)) {
            floodfillDFS(newX, newY, image, visited, targetColor, newColor);
        }
    }
}

void floodfill(int x, int y, vector<vector<int>>& image, int newColor) {
    if (image[x][y] == newColor) {
        return;
    }

    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    int targetColor = image[x][y];

    floodfillDFS(x, y, image, visited, targetColor, newColor);
}

void printImage(const vector<vector<int>>& image) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };
    cout << "Original Image:\n";
    printImage(image);
    floodfill(2, 2, image, 2);
    cout << "\nImage after Floodfill:\n";
    printImage(image);
    return 0;
}
