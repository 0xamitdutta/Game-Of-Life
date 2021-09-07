/*
    Author : Amit Dutta
    Program : Conway's Game Of Life
    Description : This Program prints the Next Tick in the System given the Initial State of System
*/

#include <bits/stdc++.h>
using namespace std;

class GameOfLife {
    private:
        map<pair<int, int>, int> inputMap;
        map<pair<int, int>, int> resultantMap;

        pair<int, int> readPair(string coordinate);
        void checkDirections();
    
    public:
        GameOfLife();
        void getInputs();
        void printNextTick();
        void printMapContent(map<pair<int, int>, int> hash);
        map<pair<int, int>, int> getInputMap();
        map<pair<int, int>, int> getResultantMap();
};


GameOfLife::GameOfLife() {
    inputMap.clear();
    resultantMap.clear();
}


map<pair<int, int>, int> GameOfLife::getInputMap() {
    return inputMap;
}


map<pair<int, int>, int> GameOfLife::getResultantMap() {
    return resultantMap;
}


/*
    Function    : printMapContent()
    Parameter   : Map<pair<int, int>, int> which is map with key pair<int, int> and value as int
    Return      : Void
    Description : Prints either the InputMap which is the Initial State of Sytem or ResultantMap which is the Next Tick of the System
*/
void GameOfLife::printMapContent(map<pair<int, int>, int> hash) {
    for(auto pair : hash) {
        cout << pair.first.first << ", " << pair.first.second << " - " << pair.second << endl;
    }
}

/*
    Function    : readPair()
    Parameter   : String - A string of Input in the format x, y where x and y are co-ordinates
    Return      : A pair of integers x and y
    Description : It parses the String format in the format x, y using the comma delimeter and returns a pair x and y
*/
pair<int, int> GameOfLife::readPair(string coordinate) {
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


/*
    Function    : getInputs()
    Parameter   : None
    Return      : Void
    Description : It takes the Input in String format x, y. After taking the last Input, press Enter twice to exit from the loop
*/
void GameOfLife::getInputs() {
    string coordinate;
    while (getline(cin, coordinate)) {
        if (coordinate == "") {
            break;
        }
        auto pair = (readPair(coordinate));
        inputMap[pair] = 1;
    }
}


/*
    Function    : checkDirections()
    Parameter   : None
    Return      : Voide
    Description : Check all 8 Adjacent directions for a given cell, i.e, Horizontally, Vertically and Diagonally 
*/
void GameOfLife::checkDirections() {
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


/*
    Function    : printNextTick()
    Parameter   : None
    Return      : Void
    Description : Prints the next State of system following Conway's Game Of lIfe Rules as mentioned in the Github Repo
*/
void GameOfLife::printNextTick() {
    checkDirections();

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
    GameOfLife obj;
    obj.getInputs();
    obj.printNextTick();
    return 0;
}