#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a task
// create datatype for task with start and end time
// example: Task t = {1, 4}; // t.start = 1, t.end = 4
struct Task
{
	int start, end;
};

// Comparator function to sort tasks based on end time
bool compareTasks(const Task& a, const Task& b)
{
	return a.end < b.end;
}

// Function to find the maximum number of non-overlapping tasks
int maxNonOverlappingTasks(vector<Task>& tasks)
{
	// Sort tasks by their end time
	sort(tasks.begin(), tasks.end(), compareTasks);

	int count = 0;
	int lastEndTime = 0;

	// Select tasks that do not overlap
	for (auto task : tasks)
	{
		if (task.start >= lastEndTime)
		{
				
			count++;
			lastEndTime = task.end;
		}
	}

	return count;
}

//int main() {
//    int n;
//    cout << "Enter number of tasks: ";
//    cin >> n;
//
//    vector<Task> tasks(n);
//    cout << "Enter start and end times of tasks:\n";
//    for (int i = 0; i < n; i++) {
//        cin >> tasks[i].start >> tasks[i].end;
//    }
//
//    int maxTasks = maxNonOverlappingTasks(tasks);
//    cout << "Maximum number of non-overlapping tasks: " << maxTasks << endl;
//
//    return 0;
//}




#pragma region Another solution
				/*another solution using vector of pair instead of struct and print the tasks itseslfd*/



#include <iostream>  // Include input-output library
#include <vector>    // Include vector library for using dynamic arrays
#include <algorithm> // Include algorithm library for sorting

using namespace std;


// Comparator function to sort tasks based on end time
bool compareSecond(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;  // Sort in ascending order based on second element
}

// Function to select maximum number of activities that don't overlap
void CPU_Tasks(vector<pair<int, int>>& tasks) {
	// Sort activities based on their finishing time (smallest to largest)
	sort(tasks.begin(), tasks.end(), compareTasks);

	// First activity is always selected
	int lastEndTime = 0; // Index of the last selected activity
	cout << "task: (" << tasks[0].first << ", " << tasks[0].second << ") ";

	// Loop through the remaining activities
	for (int i = 1; i < tasks.size(); i++) {
		// If the current activity starts after or when the last selected one ends
		if (tasks[i].first >= tasks[lastEndTime].second) {
			// Select this activity
			cout << "(" << tasks[i].first << ", " << tasks[i].second << ") ";
			lastEndTime = i; // Update the last selected activity index
		}
	}
}

//int main() {
//    // List of activities with their start and finish times
//    vector<pair<int, int>> tasks = { {1, 3}, {2, 5}, {3, 9}, {6, 8}, {5, 7} };
//
//    // Call the function to select and print the maximum number of non-overlapping activities
//    CPU_Tasks(tasks);
//
//    return 0; // End the program
//}  
#pragma endregion
