#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

namespace VendingSystem {

// ABSTRACT BASE CLASS
class VendingComponent {
public:
    virtual void display() const = 0; // pure virtual function
    virtual ~VendingComponent() {}    // virtual destructor
};

// PRODUCT CLASS
class Product : public VendingComponent {
protected:
    string name;
    double price;
    int stock;

public:
    // Constructors
    Product() : name(""), price(0.0), stock(0) {}
    Product(string n, double p, int s) : name(n), price(p), stock(s) {}

    // Destructor
    virtual ~Product() {}

    // Getters and Setters
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void setStock(int s) { stock = s; }
    void reduceStock() { if (stock > 0) stock--; }

    // Overridden display
    virtual void display() const override {
        cout << name << " - $" << price << " (Stock: " << stock << ")\n";
    }

    // Operator Overloading
    friend ostream& operator<<(ostream& os, const Product& p) {
        os << p.name << " - $" << p.price << " (Stock: " << p.stock << ")";
        return os;
    }

    Product operator+(const Product& other) {
        return Product(name + "+" + other.name,
                       (price + other.price) / 2,
                       stock + other.stock);
    }
};

// BEVERAGE SUBCLASS
class Beverage : public Product {
    string flavor;

public:
    Beverage() : Product(), flavor("") {}
    Beverage(string n, double p, int s, string f) : Product(n, p, s), flavor(f) {}

    void display() const override {
        cout << name << " (" << flavor << ") - $" << price << " (Stock: " << stock << ")\n";
    }
};

// VENDING MACHINE MANAGER
class VendingMachine {
private:
    vector<Product*> inventory;
    double balance;
    double earnings;
    map<string, int> sales;
    set<string> outOfStock;

public:
    VendingMachine() : balance(0.0), earnings(0.0) {}
    ~VendingMachine() {
        for (auto p : inventory) delete p;
    }

    void addProduct(Product* p) {
        inventory.push_back(p);
    }

    void displayInventory() {
        cout << "\nAvailable Products:\n";
        for (auto p : inventory) {
            p->display();
        }
    }

    void insertMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Inserted: $" << amount << ". Current balance: $" << balance << endl;
        } else {
            cout << "Invalid amount." << endl;
        }
    }

    void purchase(string productName) {
        for (auto p : inventory) {
            if (p->getName() == productName) {
                if (p->getStock() == 0) {
                    cout << "Sorry, " << productName << " is out of stock.\n";
                    outOfStock.insert(productName);
                    return;
                }
                if (balance >= p->getPrice()) {
                    balance -= p->getPrice();
                    p->reduceStock();
                    earnings += p->getPrice();
                    sales[productName]++;
                    cout << "Purchased " << productName << ". Remaining balance: $" << balance << "\n";
                    return;
                } else {
                    cout << "Not enough balance.\n";
                    return;
                }
            }
        }
        cout << "Product not found.\n";
    }

    void returnChange() {
        cout << "Returning change: $" << balance << "\n";
        balance = 0.0;
    }

    void restock(string name, int amount) {
        for (auto p : inventory) {
            if (p->getName() == name) {
                p->setStock(p->getStock() + amount);
                outOfStock.erase(name);
                cout << name << " restocked.\n";
                return;
            }
        }
        cout << "Product not found.\n";
    }

    void displayEarnings() const {
        cout << "Total earnings: $" << earnings << "\n";
        cout << "Sales by product:\n";
        for (const auto& pair : sales) {
            cout << pair.first << ": " << pair.second << " sold\n";
        }
    }
};

} // namespace VendingSystem

using namespace VendingSystem;

int main() {
    VendingMachine vm;
    vm.addProduct(new Beverage("Coke", 1.5, 10, "Cola"));
    vm.addProduct(new Beverage("Pepsi", 1.4, 8, "Cola"));
    vm.addProduct(new Product("Chips", 2.0, 5));

    vm.displayInventory();
    vm.insertMoney(5.0);
    vm.purchase("Coke");
    vm.returnChange();

    vm.restock("Coke", 5);
    vm.displayEarnings();

    return 0;
}
