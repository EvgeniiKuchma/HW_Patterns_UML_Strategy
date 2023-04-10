#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Product {
public:
    Product(string name, int quantity, double price) : name_(name), quantity_(quantity), price_(price) {}
    string getName() const { return name_; }
    int getQuantity() const { return quantity_; }
    double getPrice() const { return price_; }
private:
    string name_;
    int quantity_;
    double price_;
};

class Truck {
public:
    virtual vector<Product> unload() = 0;
};

class RefrigeratedTruck : public Truck {
public:
    vector<Product> unload() override {
        // ��� ��� ��������� ������� �� ������������ ���������
        vector<Product> products;
        return products;
    }
};

class OpenTruck : public Truck {
public:
    vector<Product> unload() override {
        // ��� ��� ��������� ������� �� ��������� ���������
        vector<Product> products;
        return products;
    }
};

class Warehouse {
public:
    Warehouse(string type) : type_(type) {}
    void accept(unique_ptr<Truck> truck) {
        vector<Product> products = truck->unload();
        // ��� ��� ��������� ������� � ���������� �� �� �����
    }
    string getType() const { return type_; }
private:
    string type_;
};

int main() {

    unique_ptr<RefrigeratedTruck> refrigeratedTruck = make_unique<RefrigeratedTruck>();
    unique_ptr<OpenTruck> openTruck = make_unique<OpenTruck>();
    Warehouse warehouse("cold"); // ��� ������

    if (warehouse.getType() == "cold") {
        // �������� ��������� ��� ��������� ����� �� �������� ������
        // � ����������� �� ���� ���������
        if (dynamic_cast<RefrigeratedTruck*>(refrigeratedTruck.get()) != nullptr) {
            // ��� ��� ��������� ����� �� �������� ������ �� ������������ ���������     
        }
        else if (dynamic_cast<OpenTruck*>(openTruck.get()) != nullptr) {
            // ��� ��� ��������� ����� �� �������� ������ �� ��������� ���������
        }
        else if (warehouse.getType() == "normal") {
            // �������� ��������� ��� ��������� ����� �� ������� ������
            // � ����������� �� ���� ���������
            if (dynamic_cast<RefrigeratedTruck*>(refrigeratedTruck.get()) != nullptr) {
                // ��� ��� ��������� ����� �� ������� ������ �� ������������ ���������          
            }
            else if (dynamic_cast<OpenTruck*>(openTruck.get()) != nullptr) {
                // ��� ��� ��������� ����� �� ������� ������ �� ��������� ���������            
            }
        }

    }
    return 0;
}