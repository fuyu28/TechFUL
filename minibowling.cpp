/* CやC++などシェルに実行結果コード返却を明示する言語を利用する場合 基本的に0を返却してください。 */
#include <bits/stdc++.h>
using namespace std;

int spare(vector<vector<int>> scores, int i);
int strike(vector<vector<int>> scores, int i);

int spare(vector<vector<int>> scores, int i) {
    int spare_score = 10;
    ++i;
    if (scores.at(i).at(0) == 10) {
        spare_score += strike(scores, i);
    }
    if (scores.at(i).at(0) + scores.at(i).at(1) == 10) {
        spare_score += spare(scores, i);
    }
    spare_score += scores.at(i).at(0);
    return spare_score;
}

int strike(vector<vector<int>> scores, int i) {
    ++i;
    int strike_score = 10;
    if (scores.at(i).at(0) == 10) {
        strike_score += strike(scores, i);
    }
    if (scores.at(i).at(0) + scores.at(i).at(1) == 10) {
        strike_score += spare(scores, i);
    }
    strike_score += (scores.at(i).at(0) + scores.at(i).at(1));
    return strike_score;
}

int main()
{
    int N;
    cin >> N;
    int score = 0;
    vector<vector<int>> scores(N,vector<int>(2));
    for (int i = 0; i < N; ++i) {
        cin >> scores.at(i).at(0) >> scores.at(i).at(1);
    }

    for (int i = 0; i < N; ++i) {
        if (scores.at(i).at(0) == 10) {
            score += strike(scores, i);
            continue;
        }
        if (scores.at(i).at(0) + scores.at(i).at(1) == 10) {
            score += spare(scores, i);
            continue;
        }
        score += (scores.at(i).at(0) + scores.at(i).at(1));
    }

    cout << score << endl;
    return 0;
}