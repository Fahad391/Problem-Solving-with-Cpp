#include <iostream>
using namespace std;

int main(){
    // An array of Scores
    int scores[5] = {85, 92, 78, 95, 88};

    // 0(1) Access to first index
    cout << "First Score: " << scores[0] << endl;

    // Linear Search - 0(n), checking each index
    int target = 95; // objective is to find the number 95
    // using a for loop
    for(int x = 0; x < 5; x++){
        if (scores[x] == target) // checks if the value is found in the Array
        {
            cout << "Found " << target << " at index: " << x << endl;
        }
    }

// Using Insertion in middle
// Gonna insert 99 at index 2, Shifting right
int n = 5; // our total indexes
// taking 2 varibales. One to insert value another for setting position
int insert_value = 99, insert_position = 2;

// creating a for loop to make it work
for(int x = n -1; x>= insert_position; x--){
    scores[x + 1] = scores[x]; // shit right
}
scores[insert_position] = insert_value; // to set the inserted value at targeted index

cout <<"\nAfter Insertion: ";
for (int x = 0; x<=n; x++){
    cout << scores[x] << " ";
}
cout << endl;

return 0;
}