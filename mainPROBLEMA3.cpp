int programmazionedinamica(const vector<int>& monete) {
    int M = monete.size();
    int totale = 0;

    for (int i = 0; i < M; i++) {
        totale += monete[i];
    }

    int N = totale / 2;
vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
        

            if (monete[i - 1] <= j) {
                dp[i][j] = std::max(dp[i - 1][j], monete[i - 1] + dp[i - 1][j - monete[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return totale - 2 * dp[M][N];
}


int main() {
    int N;
   cin >> N;

    while (N--) {
        int M;
       cin >> M;
       vector<int> monete(M);
        for (int i = 0; i < M; i++) {
          cin >> monete[i];
        }

        int differenza = programmazionedinamica(monete);
        cout<<endl;
        cout << differenza << std::endl;
    }

    return 0;
}

