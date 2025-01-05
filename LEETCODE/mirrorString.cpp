#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

int mirrorScore(const string& s) {
    // Create a map for mirror characters
    unordered_map<char, char> mirror = {
        {'a', 'z'}, {'b', 'y'}, {'c', 'x'}, {'d', 'w'}, {'e', 'v'},
        {'f', 'u'}, {'g', 't'}, {'h', 's'}, {'i', 'r'}, {'j', 'q'},
        {'k', 'p'}, {'l', 'o'}, {'m', 'n'}, {'n', 'm'}, {'o', 'l'},
        {'p', 'k'}, {'q', 'j'}, {'r', 'i'}, {'s', 'h'}, {'t', 'g'},
        {'u', 'f'}, {'v', 'e'}, {'w', 'd'}, {'x', 'c'}, {'y', 'b'},
        {'z', 'a'}
    };

    stack<int> indices; // Stack to hold unmarked indices
    int totalScore = 0;

    for (int i = 0; i < s.length(); ++i) {
        char currentChar = s[i];
        char mirrorChar = mirror[currentChar];

        // Check for the closest unmarked index j
        while (!indices.empty()) {
            int j = indices.top();
            if (s[j] == mirrorChar) {
                // Found a matching mirror index
                totalScore += (i - j);
                indices.pop(); // Mark index j as used
                break; // Move to the next i
            }
            indices.pop(); // Remove non-matching index
        }

        // Push the current index onto the stack as unmarked
        indices.push(i);
    }

    return totalScore;
}

int main() {
    string s;
    cin >> s;
    int result = mirrorScore(s);
    cout << result << endl;
    return 0;
}
