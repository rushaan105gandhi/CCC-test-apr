#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY related as parameter.
 */
void dfs(vector<vector<int>> &v, int node, vector<int> &visited)
{
    visited[node] = 1;
    for (int nbr = 0; nbr < v.size(); ++nbr)
    {
        if (!visited[nbr] && v[node][nbr])
            dfs(v, nbr, visited);
    }
}
int countGroups(vector<string> related) {
    int ans = 0;
    int n = related.size();
    vector<vector<int>> graph(n,vector<int>(n,0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            
            if (related[i][j] == '1')   
            {
                graph[i][j]=1;
            }
        }
}
    vector<int> visit(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (!visit[i])
            dfs(graph, i, visit), ans++;
    }
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string related_count_temp;
    getline(cin, related_count_temp);

    int related_count = stoi(ltrim(rtrim(related_count_temp)));

    vector<string> related(related_count);

    for (int i = 0; i < related_count; i++) {
        string related_item;
        getline(cin, related_item);

        related[i] = related_item;
    }

    int result = countGroups(related);

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
