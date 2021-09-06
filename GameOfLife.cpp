#include <bits/stdc++.h>
using namespace std;

// Parse the Input from String and convert it to Pair of integers x, y
pair<int, int> readPair(string coordinate) {
    vector<int> coordinate_vector;
    string str;
    stringstream ss(coordinate);
    try {
        while (getline(ss, str, ',')) {
            try {
                coordinate_vector.push_back(stoi(str));
            }
            catch (...) {
                cout << "Please only use integers for the coordinates, i.e. 1, 2\n";
                exit(1);
            }
        }
        if (coordinate_vector.size() != 2) throw "Please separate input by commas\n";
    }
    catch (...) {
        cout << "Initial positions must be of form x, y where x and y are integers\n";
        exit(1);
    }

    return {coordinate_vector[0], coordinate_vector[1]};
}

// Get the desired inputs. Press Enter twice after entering the last coordinate to break the while loop
void getInputs(map<pair<int, int>, int>& inputMap) {
    string coordinate;
    while (getline(cin, coordinate)) {
        if (coordinate == "") {
            break;
        }
        auto pair = (readPair(coordinate));
        inputMap[pair] = 1;
    }
}

// Check all the 8 adjacent directions for a coordinate, i.e, horizontally, vertically and diagonally
void checkDirections(map<pair<int, int>, int>& inputMap, map<pair<int, int>, int>& resultantMap) {
    vector<int> xdir = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> ydir = {1, -1, 1, 0, -1, 1, 0, -1};

    for(auto pair : inputMap) {
        int x = pair.first.first;
        int y = pair.first.second;
        for(int i = 0; i < 8; i++) {
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            resultantMap[{nx, ny}]++;
        }
    }
    
}

// Print the next Tick from the initial set of Live cells
void printAnswer(map<pair<int, int>, int>& inputMap, map<pair<int, int>, int>& resultantMap) {
    vector<pair<int, int>> answer;
    for(auto pair : resultantMap) {
        if(pair.second == 3)
            answer.push_back({pair.first.first, pair.first.second});
        if(pair.second == 2 && inputMap.count(pair.first))
            answer.push_back({pair.first.first, pair.first.second});
    }

    cout << "The State of the System in the next Tick is" << endl;
    for(auto coordinate : answer) {
        cout << coordinate.first << ", " << coordinate.second << endl;
    }
}

int main(){
    map<pair<int, int>, int> inputMap, resultantMap;
    
    getInputs(inputMap);

    checkDirections(inputMap, resultantMap);

    printAnswer(inputMap, resultantMap);
    
    return 0;
}