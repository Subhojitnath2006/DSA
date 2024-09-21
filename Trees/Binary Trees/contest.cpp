#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    int Spacecount = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i - 1] != ' ' && input[i] == ' ') {
            Spacecount++;
        }
    }

    int count = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i - 1] != ' ' && input[i] == ' ') {
            count++;
        }
        if (count == Spacecount - 2) {
            for (int index = i; input[index] != ' '; index++) {
                cout << input[index];
            }
            break;
        }
    }

    return 0;
}