#include <iostream>
#include<string>
using namespace std;

// A custom class for errors we expect
class FuelException{};

// A function to monitor the power grid
void monitor_Power_Grid(int status){
    if (status == 1){
        throw FuelException(); // we predicted this might happen
    }else if (status == 2){
        throw runtime_error("Power grid failure!"); // we didn't predict this might happen
    }else if (status == 3){
        throw "Voltage Spike"; // Unexpected 
    }
    // If status is 0, everything is fine
    cout << "Power grid is stable." << endl;
}

// time to write the main function
int main() {
    // Simulate the system 
    int system_Status = 1; // Change this value to test different scenarios (0, 1, 2, 3)

    // using exception handling to monitor the power grid
    try{
        // Run the system
        monitor_Power_Grid(system_Status); // System_status is the argument we send to the parameter of the fucntion
    }
    // using catch blocks to handle exceptions
    catch (const FuelException& e){// This is the specific error we know how to fix
        cout << "Switching to backup fuel source." << endl;
    }
    // Error we didn't predict but can handle
    catch (const runtime_error& e){
        cout << "Alert: " << e.what() << endl; // Output the error message
        cout << "Initiating emergency protocols." << endl;
    }
    // Handling all types of errors we didn't predict
    catch (...){
        cout << "An unexpected error occurred. Please investigate." << endl;
    }
    return 0;
}
