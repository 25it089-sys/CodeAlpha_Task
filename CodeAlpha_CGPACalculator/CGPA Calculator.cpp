#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    double grade, creditHours;
    double totalCredits = 0, totalGradePoints = 0;

    cout << fixed << setprecision(2);

    for (int i = 1; i <= numCourses; i++) {
        cout << "\nCourse " << i << ":\n";
        cout << "Enter grade (on 10-point scale): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> creditHours;

        totalCredits += creditHours;
        totalGradePoints += grade * creditHours;

        cout << "Course " << i << " → Grade: " << grade 
             << ", Credit Hours: " << creditHours << endl;
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\n==============================";
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nFinal CGPA: " << cgpa;
    cout << "\n==============================\n";

    return 0;
}