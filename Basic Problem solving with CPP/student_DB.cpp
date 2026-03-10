#include<iostream>
using namespace std;

// Defining an ID card for a student using struct

struct Student{
    string name;
    int id;
    string department;
};

// Creating a Function to display the details
void display_student_info(Student S){
    cout << "Name: " << S.name << '\n';
    cout << "ID: " << S.id << '\n';
    cout << "Department: " << S.department << '\n';
}

// Time for main

int main(){
    // Taking index number as input
    int n;
    cout << "Total Students: ";
    cin >> n;

    Student s_total[n];

    // Creating a for loop to take input form the user
    for(int x = 0; x<n; x++){
        cout << "Student no. " << x+1 <<" Info" <<"\n";
        cout << "Name: ";
        cin >> s_total[x].name;
        cout << "ID: ";
        cin >> s_total[x].id;
        cout << "Department: ";
        cin >> s_total[x].department;
    }
cout << "\n\n";
    // to show the output
    cout << "Student Information: " << "\n";
    for (int x = 0; x<n; x++){
        display_student_info(s_total[x]);
        cout <<"\n";
    }
    return 0;
}

