#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    int grade;
    int deleteGrade;

    // Step 1: Create file and write five grades
    ofstream file("grades.txt");

    cout << "Enter 5 grades:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> grade;
        file << grade << endl;
    }

    file.close();

    // Step 2: Read and print grades
    ifstream in("grades.txt");

    cout << "\nGrades before deletion:" << endl;

    while (in >> grade)
    {
        cout << grade << endl;
    }

    in.close();

    // Step 3: Enter grade to delete
    cout << "\nEnter grade to delete: ";
    cin >> deleteGrade;

    ifstream oldFile("grades.txt");
    ofstream tempFile("temp.txt");

    bool found = false;

    while (oldFile >> grade)
    {
        if (grade == deleteGrade && !found)
        {
            found = true;
            continue;
        }

        tempFile << grade << endl;
    }

    oldFile.close();
    tempFile.close();

    // Step 4: Replace original file
    if (found)
    {
        if (remove("grades.txt") == 0)
        {
            if (rename("temp.txt", "grades.txt") == 0)
            {
                cout << "\nGrade deleted successfully!" << endl;
            }
            else
            {
                cout << "\nError replacing file!" << endl;
            }
        }
        else
        {
            cout << "\nError deleting original file!" << endl;
        }
    }
    else
    {
        remove("temp.txt");
        cout << "\nGrade not found!" << endl;
    }

    // Print grades after deletion
    ifstream result("grades.txt");

    if (result)
    {
        cout << "\nGrades after deletion:" << endl;

        while (result >> grade)
        {
            cout << grade << endl;
        }

        result.close();
    }

    return 0;
}
