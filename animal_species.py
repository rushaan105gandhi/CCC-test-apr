#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'minimumGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY predators as parameter.
 */

int minimumGroups(vector<int> predators) {
    int n = predators.size();

    // Initialize the graph and in-degree array
    vector<vector<int>> graph(n);
    vector<int> indegree(n);
    for (int i = 0; i < n; i++) {
        if (predators[i] != -1) {
            graph[predators[i]].push_back(i);
            indegree[i]++;
        }
    }

    // Perform topological sort
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int groups = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        groups++;
    }

    return groups;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string predators_count_temp;
    getline(cin, predators_count_temp);

    int predators_count = stoi(ltrim(rtrim(predators_count_temp)));

    vector<int> predators(predators_count);

    for (int i = 0; i < predators_count; i++) {
        string predators_item_temp;
        getline(cin, predators_item_temp);

        int predators_item = stoi(ltrim(rtrim(predators_item_temp)));

        predators[i] = predators_item;
    }

    int result = minimumGroups(predators);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
