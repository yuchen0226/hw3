#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> grades;

    cout << "Enter the grades (enter -1 to end input):\n";

    int grade;
    while (true) {
        cin >> grade;
        if (grade == -1)
            break;
        grades.push_back(grade);
    }

    if (grades.empty()) {
        cout << "No grades entered. Exiting...\n";
        return 0;
    }

    // Find the maximum grade
    int maxGrade = *max_element(grades.begin(), grades.end());

    // Initialize histogram with zeros
    vector<int> histogram(maxGrade + 1, 0);

    // Count occurrences of each grade
    for (int grade : grades) {
        histogram[grade]++;
    }

    // Output histogram
    cout << "\nGrade Histogram:\n";
    for (int i = 0; i <= maxGrade; ++i) {
        cout << i << ": ";
        for (int j = 0; j < histogram[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
