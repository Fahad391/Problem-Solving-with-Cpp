#include <iostream>
using namespace std;

//creating a structure to store student information
struct Student
{
    string name;
    int id;
    float marks[3]; // created an Array to store marks of 3 subjects
    float average; 
};

// Creating a function to calculate the average marks
void calculate_Avg(Student* S) // Using pointer to modify the original value
{
    float sum = 0; // By Default
    // creating a for loop to calculate the sum of marks
    for (int i = 0; i < 3; i++){
        sum += S->marks[i]; // Accessing the marks using pointer
    }
    // time to calculate the average
    S->average = sum / 3; // Stored directly in the original Structure
}

// Another function to find the top student
// Returns pointer to the top student
// pass by reference to avoid copying the entire array
Student* find_top_student(Student* students, int size){
    Student* topper = &students[0]; // Initialize topper to the first student
    // now a for loop to compare the average marks of each student
    for (int i = 1; i < size; i++){
        if (students[i].average > topper->average){ // the arrow operator is used to access the average of the current topper
            topper = &students[i]; // Update topper if current student has higher average
        }
        }
    return topper; // Return the pointer to the top student
    }

    // Function to find Student by ID and fix their mark
    // We use pointer to change the real data
    bool update_mark(Student* S, int size, int target_ID, int Course_Index, float new_mark){
         for (int i=0; i<size; i++){
            if(S[i].id == target_ID){
                S[i].marks[Course_Index] == new_mark; // fixes the mistake
                calculate_Avg(&S[i]); // Recalculate the average and trace back to the address
                return true;
            }
         }
         return false; // If Student not found
    }

  // Display the Result
  void display_Result_Sheet(Student* students, int size){
    cout << " " << endl;
    cout << "       SEMESTER RESULT SHEET    " << endl;
    cout << "\n " << endl;

    // a for loop to display the output
    for (int i = 0; i < size; i++){
        cout << "Student ID: " << students[i].id << '\n';
        cout << "Student Name: " << students[i].name << '\n';
        cout << "Marks: ";
        // a nested loop to show marks
        for (int j = 0; j <3; j++){
            cout << students[i].marks[j] << " ";
        }
        cout << '\n';
        cout << "Average: " << students[i].average << '\n';

        // Creating a Grade logic based on average marks
        if (students[i].average >= 90){
            cout << "Grade: A+" << '\n';
        }
        else if (students[i].average >= 80){
            cout << "Grade: A" << '\n';
        }
        else if (students[i].average >= 70){
            cout << "Grade: B+" << '\n';
        }
        else if (students[i].average >= 60){
            cout << "Grade: B" << '\n';
        }
        else if (students[i].average >= 50){
            cout << "Grade: C" << '\n';
        }
        else {
            cout << "Grade: F" << '\n';
        }
         cout << "\n\n ";
    }
  }

  // Main time

  int main(){
    Student students[10] ={
        { "Rafi", 101,  {88, 76, 92}, 0},
        { "Nadia", 102,  {95, 91, 89}, 0},
        { "Arif", 103,   {70, 68, 74}, 0},
        { "Tanha", 104,  {55, 60, 58}, 0},
        { "Sabbir", 105, {82, 79, 85}, 0},
        { "Mim", 106,    {90, 94, 88}, 0},
        { "Sadiq", 107,  {65, 72, 70}, 0},
        { "Fahim", 108,  {78, 80, 82}, 0},
        { "Rashid", 109,   {85, 87, 90}, 0},
        { "Shuvo", 110,  {60, 62, 58}, 0}

    };
    int size = sizeof(students)/ sizeof(students[0]); // Calculate the number of students
   // Calculate the average for each student
    for (int i = 0; i < size; i++){
        calculate_Avg(&students[i]); // passing ADDRESS — real modification
    }
    // Display the result sheet
    display_Result_Sheet(students, size);
    // Find the top student
    Student* topper = find_top_student(students, size); // Get the pointer to the top student
    cout << "Topper: " << topper->name << " with Average: " << topper->average << '\n';
    // Data entry mistake — fix Tanha's 2nd course mark
    cout<< "\n Fixing Data Entry Error for ID 104 (Tanha)..." << '\n';
    bool updated = update_mark(students, size, 104, 1, 65); // Update mark for Tanha's 2nd course   
    if (updated) {
        cout << "Mark updated successfully. New Average: " << students[3].average << '\n'; // Tanha is at index 3
    } else
    {
        cout << "ID not found." << '\n';
    }
    
    // Now display the result sheet again to see the changes
    display_Result_Sheet(students, size);

    // re-check the topper after the update
    topper = find_top_student(students, size); // Get the pointer to the top student again
    cout << "New Topper: " << topper->name << " with Average: " << topper->average << '\n'; 
    return 0;
  }