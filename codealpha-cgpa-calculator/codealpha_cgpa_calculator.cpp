#include <iostream>
using namespace std;

int main()
{
    int numCourses;

    // Take number of courses
    cout << "Enter number of courses: ";
    cin >> numCourses;

    float grade[numCourses];
    float credit[numCourses];

    float totalCredits = 0;
    float totalGradePoints = 0;

    // Input grade and credit hours for each course
    for (int i = 0; i < numCourses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade point: ";
        cin >> grade[i];

        cout << "Enter credit hours: ";
        cin >> credit[i];

        // Calculate total grade points
        totalGradePoints += grade[i] * credit[i];
        totalCredits += credit[i];
    }

    // Calculate GPA
    float gpa = totalGradePoints / totalCredits;

    // Display individual course details
    cout << "\n--- Course Details ---" << endl;
    for (int i = 0; i < numCourses; i++)
    {
        cout << "Course " << i + 1 
             << " | Grade: " << grade[i] 
             << " | Credit Hours: " << credit[i] << endl;
    }

    // Display GPA
    cout << "\nSemester GPA: " << gpa << endl;

    // CGPA calculation (taking previous data)
    float prevCGPA, prevCredits;

    cout << "\nEnter previous CGPA: ";
    cin >> prevCGPA;

    cout << "Enter total previous credit hours: ";
    cin >> prevCredits;

    float cgpa = ((prevCGPA * prevCredits) + totalGradePoints) 
                 / (prevCredits + totalCredits);

    // Display CGPA
    cout << "\nFinal CGPA: " << cgpa << endl;

    return 0;
}
