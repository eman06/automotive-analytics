#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
using namespace std;

class Car
{
    char name[100];
    char dateCrawled[20];
    char sellerType[10];
    char offerType[10];
    double price;
    char abTestingInfo[50];
    char vehicleType[20];
    int yearOfRegistration;
    char gearboxType[10];
    int powerOutputPS;
    char model[50];
    int kilometersDriven;
    int monthOfRegistration;
    char fuelType[20];
    char brand[20];
    char notRepairedDamage[10];
    char dateCreated[20];
    int numberOfPictures;
    int postalCode;
    char lastSeen[20];

public:
    Car()
    {
        name[0] = '\0';
        dateCrawled[0] = '\0';
        sellerType[0] = '\0';
        offerType[0] = '\0';
        price = 0.0;
        abTestingInfo[0] = '\0';
        vehicleType[0] = '\0';
        yearOfRegistration = 0;
        gearboxType[0] = '\0';
        powerOutputPS = 0;
        model[0] = '\0';
        kilometersDriven = 0;
        monthOfRegistration = 0;
        fuelType[0] = '\0';
        brand[0] = '\0';
        notRepairedDamage[0] = '\0';
        dateCreated[0] = '\0';
        numberOfPictures = 0;
        postalCode = 0;
        lastSeen[0] = '\0';
    }

    // Overloaded operators for addition and subtraction
    Car& operator+=(const Car& other)
    {
        price += other.price;
        powerOutputPS += other.powerOutputPS;
        kilometersDriven += other.kilometersDriven;
        numberOfPictures += other.numberOfPictures;
        postalCode += other.postalCode;
        return *this;
    }

    Car& operator-=(const Car& other)
    {
        price -= other.price;
        powerOutputPS -= other.powerOutputPS;
        kilometersDriven -= other.kilometersDriven;
        numberOfPictures -= other.numberOfPictures;
        postalCode -= other.postalCode;
        return *this;
    }

    bool operator==(const Car& other) const {
        return (strcmp(name, other.name) == 0) &&
            (strcmp(dateCrawled, other.dateCrawled) == 0) &&
            (strcmp(sellerType, other.sellerType) == 0) &&
            (strcmp(offerType, other.offerType) == 0) &&
            (price == other.price) &&
            (strcmp(abTestingInfo, other.abTestingInfo) == 0) &&
            (strcmp(vehicleType, other.vehicleType) == 0) &&
            (yearOfRegistration == other.yearOfRegistration) &&
            (strcmp(gearboxType, other.gearboxType) == 0) &&
            (powerOutputPS == other.powerOutputPS) &&
            (strcmp(model, other.model) == 0) &&
            (kilometersDriven == other.kilometersDriven) &&
            (monthOfRegistration == other.monthOfRegistration) &&
            (strcmp(fuelType, other.fuelType) == 0) &&
            (strcmp(brand, other.brand) == 0) &&
            (strcmp(notRepairedDamage, other.notRepairedDamage) == 0) &&
            (strcmp(dateCreated, other.dateCreated) == 0) &&
            (numberOfPictures == other.numberOfPictures) &&
            (postalCode == other.postalCode) &&
            (strcmp(lastSeen, other.lastSeen) == 0);
    }

    bool operator>(const Car& other) const {
        return price > other.price;
    }

    bool operator<(const Car& other) const {
        return price < other.price;
    }

    bool operator>=(const Car& other) const {
        return price >= other.price;
    }

    bool operator<=(const Car& other) const {
        return price <= other.price;
    }

    bool operator!=(const Car& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& output, const Car& car) {
        output << car.name << ", " << car.dateCrawled << ", " << car.sellerType << ", " << car.offerType << ", "
            << car.price << ", " << car.abTestingInfo << ", " << car.vehicleType << ", " << car.yearOfRegistration
            << ", " << car.gearboxType << ", " << car.powerOutputPS << ", " << car.model << ", "
            << car.kilometersDriven << ", " << car.monthOfRegistration << ", " << car.fuelType << ", "
            << car.brand << ", " << car.notRepairedDamage << ", " << car.dateCreated << ", " << car.numberOfPictures
            << ", " << car.postalCode << ", " << car.lastSeen;
        return output;
    }

    friend istream& operator>>(istream& input, Car& car) {
        string field;

        auto readField = [&](char* dest, size_t destSize) {
            getline(input, field, ',');
            if (field[0] == '"') {
                // Remove surrounding quotes
                field.erase(0, 1); // Remove opening quote
                field.erase(field.size() - 1, 1); // Remove closing quote
            }
            strncpy_s(dest, destSize, field.c_str(), destSize - 1);
            dest[destSize - 1] = '\0';
            };

        readField(car.dateCrawled, sizeof(car.dateCrawled));
        readField(car.name, sizeof(car.name));
        readField(car.sellerType, sizeof(car.sellerType));
        readField(car.offerType, sizeof(car.offerType));

        input >> car.price;
        input.ignore();
        readField(car.abTestingInfo, sizeof(car.abTestingInfo));
        readField(car.vehicleType, sizeof(car.vehicleType));

        input >> car.yearOfRegistration;
        input.ignore();
        readField(car.gearboxType, sizeof(car.gearboxType));
        input >> car.powerOutputPS;
        input.ignore();
        readField(car.model, sizeof(car.model));
        input >> car.kilometersDriven;
        input.ignore();
        input >> car.monthOfRegistration;
        input.ignore();
        readField(car.fuelType, sizeof(car.fuelType));
        readField(car.brand, sizeof(car.brand));
        readField(car.notRepairedDamage, sizeof(car.notRepairedDamage));
        readField(car.dateCreated, sizeof(car.dateCreated));

        input >> car.numberOfPictures;
        input.ignore(); // Ignore comma

        input >> car.postalCode;
        input.ignore(); // Ignore comma

        getline(input, field);
        strncpy_s(car.lastSeen, sizeof(car.lastSeen), field.c_str(), sizeof(car.lastSeen) - 1);
        car.lastSeen[sizeof(car.lastSeen) - 1] = '\0';

        return input;
    }

    Car operator+(const Car& other) const {
        Car result = *this;
        result.price += other.price;
        result.powerOutputPS += other.powerOutputPS;
        result.kilometersDriven += other.kilometersDriven;
        result.numberOfPictures += other.numberOfPictures;
        result.postalCode += other.postalCode;
        return result;
    }

    double operator-(const Car& other) const {
        return this->price - other.price;
    }
};

void pushBack(Car*& cars, int& size, int& capacity, const Car& car) {
    if (size >= capacity) {
        // Double the capacity
        capacity *= 2;
        Car* newCars = new Car[capacity];
        // Copy old cars to new array
        for (int i = 0; i < size; i++) {
            newCars[i] = cars[i];
        }
        delete[] cars;
        cars = newCars;
    }
    cars[size++] = car;
}

int main() {
    const int initialCapacity = 10;
    int size = 0;
    int capacity = initialCapacity;
    Car* cars = new Car[capacity];

    ifstream inputFile("C:\\Users\\USR\\Downloads\\OOP-Summer-2024-Assignment03\\OOP-Summer-2024-Assignment03\\autos.csv");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
        delete[] cars;
        return 1;
    }

    string line;
    getline(inputFile, line); // Skip header line
    while (getline(inputFile, line)) {
        stringstream lineStream(line);
        Car car;
        lineStream >> car; // Use the overloaded >> operator to read the car
        pushBack(cars, size, capacity, car);
    }

    inputFile.close();

    if (size > 1) {
        Car combinedCar = cars[0] + cars[1];
        cout << "Combined Car Details: " << combinedCar << endl;
        cout << "Price Difference: " << (cars[0] - cars[1]) << endl;
    }

    delete[] cars;

    return 0;
}
