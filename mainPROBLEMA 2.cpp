
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;



bool Safe(vector<vector<int>> board, int row, int col){
	int i,j;
	int N = board.size();
	for(int i = 0; i<col; i++){
		if(board[row][i]){
			return false;}
	}
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j]){
            return false;}}

    for (i = row, j = col; j >= 0 && i < N; i++, j--){
        if (board[i][j]){
             return false;}}



	return true;
}





vector<vector<int> > result;
bool backtracking( vector<vector<int>>& board, int col){

	int N = board.size();
	if(col == N){
		vector<int> v;

		for(int i  = 0; i <N; i++){

			for(int j =0; j<N; j++){

				if(board[i][j]== 1)
					v.push_back(j+1);
			}
		}
		result.push_back(v);

		return true;

	}


	for(int i =0; i<N;i++){

		if(Safe(board,i,col)){

			board[i][col]=1;

			backtracking(board, col+1);

			board[i][col]=0;
		}
	}

	return true;

}

vector<vector<int>> queen(int n){
	result.clear();


	vector<vector<int>> board(n, vector<int>(n,0));

	if(backtracking(board,0)== false){
		return {};
	}

		return result;
	}
int main(){

	ifstream inputFile("\\Users\\espoc\\Documents\\file2.txt");
	if (!inputFile.is_open()) {
	          cout << "Impossibile aprire il file." << endl;
	          return 1;
	      }



string line;

	      getline(inputFile, line);

          int num = stoi(line);


               for(int i =0; i<num;i++){
            	   string line;
            	   getline(inputFile, line);

            	          int num = stoi(line);


                vector<vector<int>> result = queen(num);
                 cout << result.size() << endl;


      }


}
