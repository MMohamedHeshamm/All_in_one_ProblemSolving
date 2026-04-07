#include <iostream>
#include <vector>
#include "1. Graph traversal_Sheet.cpp"
#include "2. DFS_Sheet.cpp"
#include "3. Dikjistra_Sheet.cpp"
#include "4. Complete Search_Sheet.cpp"
#include "5. Binary search_Sheet.cpp"
#include "6. Merge Sort_Sheet.cpp"
#include "7. Dynamic Programming_Sheet.cpp"
#include "8. GreedyAlgorithm_Sheet.cpp"
#include "9. Learning outcome 3_Sheet.cpp"
#include "10. Learning Outcome 4_Sheet.cpp"
#include "11. Learning Outcome 5_Sheet.cpp"
#include "BFS.cpp"
#include "DFS.cpp"
#include "Adjacency List.cpp"
#include "Factorial (Memoization).cpp"
#include "RabinKarp.cpp"
using namespace std;


int main() {
   

	string text = "abcde";
	    string pattern = "abc";
	
	    if (rabinKarpSearch(text, pattern)) {
	        cout << "Pattern found in text!" << endl;
	    }
	    else {
	        cout << "Pattern NOT found in text!" << endl;
	    }
}
