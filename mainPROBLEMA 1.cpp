PROBLEMA 1

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;

int maxSum(const std::vector<int>& vettore){
	int max=0;
	int sum = 0;

	for (int num : vettore) {
	     sum = std::max(num, sum + num);
	     max = std::max(max, sum);
	    }



	return max;
}

// Driver Code
int main()
{
	ifstream inputFile("\\Users\\espoc\\Documents\\file.txt");

    if (!inputFile.is_open()) {
          cout << "Impossibile aprire il file." << endl;
          return 1;
      }
    string line;
      while (getline(inputFile, line)) {
          if (line == "END") {
        	  cout<<"end"<<endl;
              break;
          }
          vector<int> test_case;
                size_t pos = 0;
          while ((pos = line.find(' ')) != string::npos) {


        	                  int num = stoi(line.substr(0, pos));
        	                  test_case.push_back(num);

                     line.erase(0, pos + 1);
                 }

        	         try {
        	             int num = stoi(line);
        	             test_case.push_back(num);
        	         } catch (const std::invalid_argument& e) {
        	             cout << "Invalid argument: " << e.what() << endl;

        	         }


                 int result = maxSum(test_case);
                 cout << result << endl;


      }

	return 0;
}
