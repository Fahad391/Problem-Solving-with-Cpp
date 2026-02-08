#include <iostream>
#include <string>
using namespace std;

int main(){
    int num_of_students = 4; // number of students to be stored in 1D array

    string name_of_students[num_of_students] = {"Ali", "Maria", "Suleiman", "Zahra"};

    // creating a 2D array to store marks of each student in 3 subjects
    int marks_of_students[num_of_students][3] = {
        {96, 87, 75}, // stores marks of Ali 
        {80, 90, 98}, // stores marks of Maria
        {78, 85, 92}, // stores marks of Suleiman
        {92, 88, 95} // stores marks of Zahra
    };

// create a input system to search their name and get their marks
    string search_name;
    cout << "Search Student's Name: ";
    cin >> search_name;

    // create a boolean value found
    bool found = false; // false by default
    // creating a loop to search for the name in the array
    for (int i = 0; i < num_of_students; i++){
        if (name_of_students[i] == search_name){
            found = true ; // if name is found, set found to true
            cout << "Marks of " << search_name << ": ";
            // another loop to print the marks of the student found
            for (int q = 0; q < 3; q++){
                cout << marks_of_students[i][q] << " ";
            }
            cout << endl;
        }
    }
    if (!found){
        cout << "Student not found." << endl;
    }
}