#include<bits/stdc++.h>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<int> mentions(numberOfUsers, 0);
    vector<int> timestamp(numberOfUsers, 0);

    for (const auto& event : events) {
        if (event[0] == "MESSAGE") {
            int timeStamp = stoi(event[1]);
            if (event[2] == "ALL") {
                for (int idx = 0; idx < numberOfUsers; idx++) {
                    mentions[idx]++;
                    timestamp[idx] = timeStamp;
                }
            } else if (event[2] == "HERE") {
                for (int idx = 0; idx < numberOfUsers; idx++) {
                    if (timestamp[idx] < timeStamp) {
                        mentions[idx]++;
                    }
                    timestamp[idx] = timeStamp;
                }
            } else {
                // Parsing mentions for specific users
                string s = event[2];
                stringstream ss(s);
                string token;
                while (getline(ss, token, ',')) {
                    if (token[0] == '@') {
                        int userID = stoi(token.substr(1)); // Extract user ID
                        if (userID >= 0 && userID < numberOfUsers) {
                            mentions[userID]++;
                            timestamp[userID] = timeStamp;
                        }
                    }
                }
            }
        } else if (event[0] == "OFFLINE") {
            int offlineTime = stoi(event[1]);
            string s = event[2];
            if (s[0] == '@') {
                int userID = stoi(s.substr(1)); // Extract user ID
                if (userID >= 0 && userID < numberOfUsers) {
                    timestamp[userID] = offlineTime + 60;
                }
            }
        }
    }

    return mentions;
}
int main(){
    int numberOfUsers;
    cin >> numberOfUsers;
    int n;
    cin >> n;
    vector<vector<string>> events(n,vector<string>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>events[i][j];
        }
    }
    vector<int> ans=countMentions(numberOfUsers,events);
    for(int i=0;i<numberOfUsers;i++){
        cout<<ans[i]<<" ";
    }
}