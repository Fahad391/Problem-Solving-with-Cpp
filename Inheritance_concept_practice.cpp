#include <iostream>
using namespace std;

class Vehicle{
    private:
        int speed;
        double fuel;
        double charge;
        string engine_type;
    public:
        void feature_1(int speed, double fuel, string engine_type){
            this->speed = speed;
            this->fuel = fuel;
            this->engine_type = engine_type;
            cout << endl;
        }

        void display_f1(){
            cout << "Features:" << endl;
            cout << "Speed: " << speed << " km/h" << endl;
            cout << "Fuel: " << fuel << " liters" << endl;
            cout << "Engine Type: " << engine_type << endl;
        }
        void feature_2(int speed, double charge, string engine_type){
            this->speed = speed;
            this->charge = charge;
            this->engine_type = engine_type;
        }
        void display_f2(){
            cout << "Features:" << endl;
            cout << "Speed: " << speed << " km/h" << endl;
            cout << "Charge: " << charge << " kWh" << endl;
            cout << "Engine Type: " << engine_type << endl;
            cout << endl;
        }
};

class Car : public Vehicle{
    public:
        void Brand(string brand, string model){
            cout << "Car Brand: " << brand << " Model: " << model << endl;
        }
};

int main(){
    Car c1, c2;
    c1.Brand("BYD", "SEALION 6");
    c1.feature_2(120, 80.5, "Electric");
    c1.display_f2();
    c2.Brand("Toyota", "Allion");
    c2.feature_1(150, 90.0, "Gasoline");
    c2.display_f1();

    return 0;
}
