//
// Created by 손민균 on 26. 10. 15.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    int n, r;
    cin >> n >> r;

    map<string, int> door_index_map;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        door_index_map[s] = i;
    }

    vector<int> workflow;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        workflow.push_back(door_index_map[s]);
    }

    map<string, int> grade_code_number_map;
    grade_code_number_map["Mugunghwa"] = 0;
    grade_code_number_map["ITX-Saemaeul"] = 0;
    grade_code_number_map["ITX-Cheongchun"] = 0;
    grade_code_number_map["S-Train"] = 2;
    grade_code_number_map["V-Train"] = 2;
    grade_code_number_map["Subway"] = 1;
    grade_code_number_map["Bus"] = 1;
    grade_code_number_map["Taxi"] = 1;
    grade_code_number_map["Airplane"] = 1;
    grade_code_number_map["KTX"] = 1;

    int k;
    cin >> k;

    vector<vector<pair<int, int> > > graph(n, vector<pair<int, int> >(n, make_pair(-1, -1)));

    for (int i = 0; i < k; i++) {
        string typeID, Si, Ei;
        int costi, costi2;
        cin >> typeID >> Si >> Ei >> costi;
        costi *= 2;
        costi2 = grade_code_number_map[typeID] == 2 ? costi / 2 : costi * grade_code_number_map[typeID];

        if (graph[door_index_map[Si]][door_index_map[Ei]].first == -1 || graph[door_index_map[Si]][door_index_map[Ei]].first > costi) graph[door_index_map[Si]][door_index_map[Ei]].first = costi;
        if (graph[door_index_map[Si]][door_index_map[Ei]].second == -1 || graph[door_index_map[Si]][door_index_map[Ei]].second > costi2) graph[door_index_map[Si]][door_index_map[Ei]].second = costi2;
        if (graph[door_index_map[Ei]][door_index_map[Si]].first == -1 || graph[door_index_map[Ei]][door_index_map[Si]].first > costi) graph[door_index_map[Ei]][door_index_map[Si]].first = costi;
        if (graph[door_index_map[Ei]][door_index_map[Si]].second == -1 || graph[door_index_map[Ei]][door_index_map[Si]].second > costi2)graph[door_index_map[Ei]][door_index_map[Si]].second = costi2;
    }

    for (int i = 0; i < n; i++) {
        graph[i][i].first = 0;
        graph[i][i].second = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                if (graph[j][i].first != -1 && graph[i][l].first != -1) {
                    if (graph[j][l].first == -1 || graph[j][l].first > graph[j][i].first + graph[i][l].first) {
                        graph[j][l].first = graph[j][i].first + graph[i][l].first;
                    }
                }
                if (graph[j][i].second != -1 && graph[i][l].second != -1) {
                    if (graph[j][l].second == -1 || graph[j][l].second > graph[j][i].second + graph[i][l].second) {
                        graph[j][l].second = graph[j][i].second + graph[i][l].second;
                    }
                }
            }
        }
    }

    pair<long long, long long> total_bil = make_pair(0, 0);
    for (int i = 1; i < m; i++) {
        total_bil.first += graph[workflow[i - 1]][workflow[i]].first;
        total_bil.second += graph[workflow[i - 1]][workflow[i]].second;
    }

    total_bil.second += r * 2;
    if (total_bil.second < total_bil.first) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}