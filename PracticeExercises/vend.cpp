#include <iostream>  
#include <vector>     //for dynamic array (vector) container
#include <map>      // for key-value pair (map) container
#include <set>     // for unique element (set) container
#include <string>     // for string data type
#include <iomanip>      // for stream manipulators (e.g., setw, setprecision)
#include <limits>    // for numeric_limits to handle input buffers

using namespace std;   
// Using namespace to organize vending machine-related code
namespace VendingSystem {   

// Abstract base class representing a generic vending component
class VendingComponent {
protected:
    string name = ""; 

public:
// Default constructor
    VendingComponent() = default;                  
    VendingComponent(const string& n) : name(n) {} // Parameterized constructor 
    virtual ~VendingComponent() = default;    // Virtual destructor
    virtual void display() const = 0;              // Pure virtual function to make the base class abstract
// Encapsulation (Getter & Setter)
    string getName() const { return name; }        
    void setName(const string& n) { name = n; }    
};

// Derived class inheriting from VendingComponent
class Product : public VendingComponent {
protected:
    double price = 0.0; 
    int stock = 0;      

public:
    Product() = default;    // Default constructor
    Product(const string& n, double p = 0.0, int s = 0)     // Parameterized constructor with default values
        : VendingComponent(n), price(p), stock(s) {}
    virtual ~Product() = default;                           // Virtual destructor

    void display() const override {                         // Override display method
        cout << "Product: " << name << ", Price: €" << fixed << setprecision(2)
             << price << ", Stock: " << stock << endl;      // Display product details with 2 decimal places
    }

    double getPrice() const { return price; }               // Getter for price
    int getStock() const { return stock; }                  // Getter for stock
    void setPrice(double p) { price = p; }                  // Setter for price
    void setStock(int s) { stock = s; }                     // Setter for stock

    Product operator+(const Product& other) const {          // Operator overloading for adding two products
        return Product(name + "_" + other.name, (price + other.price) / 2, stock + other.stock);
    }

    friend ostream& operator<<(ostream& os, const Product& p) { // Friend function to overload << operator
        os << p.name << " ($" << fixed << setprecision(2) << p.price
           << ", " << p.stock << " in stock)";
        return os;
    }
};

// Subclass of Product representing a snack
class Snack : public Product {
private:
    string flavor;  // Private member for snack flavor

public:
    Snack(const string& n = "", double p = 0.0, int s = 0, const string& f = "")
        : Product(n, p, s), flavor(f) {}   // Constructor with default values

    void display() const override {     // Overriding display method
        cout << "Snack: " << name << " (" << flavor << "), Price: €" << fixed
             << setprecision(2) << price << ", Stock: " << stock << endl; // Display with Euro symbol
    }

    string getFlavor() const { return flavor; }        // Getter for flavor
    void setFlavor(const string& f) { flavor = f; }       // Setter for flavor
};

// Subclass of Product representing a beverage
class Beverage : public Product {
private:
    string type;    // Private member for beverage type (e.g., Soda, Juice)

public:
    Beverage(const string& n = "", double p = 0.0, int s = 0, const string& t = "")
        : Product(n, p, s), type(t) {}          // Constructor with default values

    void display() const override {            // Override display method
        cout << "Beverage: " << name << " (" << type << "), Price: €" << fixed
             << setprecision(2) << price << ", Stock: " << stock << endl; // Display with Euro symbol
    }

    string getType() const { return type; }                 // Getter for type
    void setType(const string& t) { type = t; }             // Setter for type
};

// Main class to manage the vending machine
class VendingMachine {
private:
    vector<Product*> inventory;     // Vector to store pointers to Product objects
    map<string, int> sales;         // Map to track sales count by product name
    set<string> outOfStock;         // Set to track out-of-stock products
    double balance = 0.0;           // Current balance of inserted money
    double totalEarnings = 0.0;     // Total earnings from sales

public:
    VendingMachine() {  // Constructor
        inventory.push_back(new Beverage("Cola", 1.99, 10, "Soda"));
        inventory.push_back(new Beverage("Water", 0.99, 15, "Still"));
        inventory.push_back(new Beverage("Orange Juice", 2.50, 15, "Juice"));
        inventory.push_back(new Beverage("Apple Juice", 2.30, 15, "Juice"));
        inventory.push_back(new Beverage("Lemonade", 1.80, 12, "Soda"));
        inventory.push_back(new Beverage("Energy Drink", 3.00, 5, "Energy"));
        inventory.push_back(new Beverage("Iced Tea", 2.20, 7, "Tea"));

        inventory.push_back(new Snack("Chips", 2.00, 10, "Cheese"));
        inventory.push_back(new Snack("Protein Bar", 1.80, 8, "Vanile"));
        inventory.push_back(new Snack("Cookies", 2.50, 6, "Chocolate"));
        inventory.push_back(new Snack("Popcorn", 1.90, 9, "Butter"));
        inventory.push_back(new Snack("Chocolate Bar", 1.50, 7, "Chocolate"));
        inventory.push_back(new Snack("Nuts", 2.80, 5, "Mixed"));
        inventory.push_back(new Snack("Crackers", 1.60, 11, "Plain"));
    }

    ~VendingMachine() {                                     // Destructor
        for (auto p : inventory) {
            delete p;                                       // Delete dynamically allocated objects
        }
    }

    void displayInventory() {                               // Method to display inventory
        int category;
        while (true) {
            cout << "\n *** Product Inventory ***\n";
            cout << "0. Back to Main Menu\n\n";
            cout << "Select Category:\n";
            cout << "1. Beverages\n2. Snacks\nEnter choice: ";
            cin >> category;
            if (category == 0) break;

            switch (category) {
                case 1: {
                    cout << "\n *** Beverages ***\n";
                    cout << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Type"
                         << setw(15) << "Price (€)" << setw(10) << "Stock" << endl;
                    cout << string(80, '-') << endl;
                    size_t index = 0;
                    for (size_t i = 0; i < inventory.size(); i++) {
                        Beverage* bev = dynamic_cast<Beverage*>(inventory[i]);
                        if (bev) {
                            ++index;
                            cout << setw(5) << index << setw(20) << bev->getName()
                                 << setw(15) << bev->getType()
                                 << setw(15) << fixed << setprecision(2) << bev->getPrice()
                                 << setw(10) << bev->getStock() << endl;
                        }
                    }
                    int selection;
                    cout << "\nSelect a beverage (1-" << index << ", 0 to go back): ";
                    cin >> selection;
                    if (selection > 0 && selection <= static_cast<int>(index)) {
                        Beverage* bev = dynamic_cast<Beverage*>(inventory[selection - 1]);
                        if (bev) {
                            cout << "Selected: " << *bev << endl;
                        }
                    }
                    break;
                }
                case 2: {
                    cout << "\n--- Snacks ---\n";
                    cout << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Flavor"
                         << setw(15) << "Price (€)" << setw(10) << "Stock" << endl;
                    cout << string(80, '-') << endl;
                    size_t index = 0;
                    for (size_t i = 0; i < inventory.size(); ++i) {
                        Snack* snack = dynamic_cast<Snack*>(inventory[i]);
                        if (snack) {
                            ++index;
                            cout << setw(5) << index << setw(20) << snack->getName()
                                 << setw(15) << snack->getFlavor()
                                 << setw(15) << fixed << setprecision(2) << snack->getPrice()
                                 << setw(10) << snack->getStock() << endl;
                        }
                    }
                    int selection;
                    cout << "\nSelect a snack (1-" << index << ", 0 to go back): ";
                    cin >> selection;
                    if (selection > 0 && selection <= static_cast<int>(index)) {
                        Snack* snack = dynamic_cast<Snack*>(inventory[selection - 1]);
                        if (snack) {
                            cout << "Selected: " << *snack << endl;
                        }
                    }
                    break;
                }
                default:
                    cout << "Invalid category!\n";
            }
        }
    }
    // Method to insert money into the machine
    void insertMoney(double amount) {                       
        if (amount > 0) {
            balance += amount;
            cout << "Inserted: €" << fixed << setprecision(2) << amount
                 << ". Current balance: €" << balance << endl;
        } else {
            cout << "Invalid amount!\n";
        }
    }
    // Method to purchase a product
    void purchase(const string& productName) {              
        for (auto p : inventory) {
            if (p->getName() == productName) {
                if (p->getStock() == 0) {
                    outOfStock.insert(productName);
                    cout << productName << " is out of stock!\n";
                    return;
                }
                if (balance >= p->getPrice()) {
                    balance -= p->getPrice();
                    p->setStock(p->getStock() - 1);
                    sales[productName]++;
                    totalEarnings += p->getPrice();
                    cout << "Purchased " << *p << endl;
                    cout << "Remaining balance: $" << fixed << setprecision(2) << balance << endl;
                } else {
                    cout << "Insufficient balance! Need $"
                         << fixed << setprecision(2) << p->getPrice() << endl;
                }
                return;
            }
        }
        cout << "Product not found!\n";
    }
    // Returning money
    void returnChange() {                                   
        if (balance > 0) {
            cout << "Returning change: €" << fixed << setprecision(2) << balance << endl;
            balance = 0;
        }
    }
    // Restockinng a product
    void restock(const string& productName, int quantity) { 
        for (auto p : inventory) {
            if (p->getName() == productName) {
                p->setStock(p->getStock() + quantity);
                outOfStock.erase(productName);
                cout << productName << " restocked with " << quantity << " units\n";
                return;
            }
        }
        cout << "Product not found!\n";
    }
    // Display total Earnings of the machine
    void displayEarnings() const {                          
        cout << "Total Earnings: $" << fixed << setprecision(2) << totalEarnings << endl;
        cout << "Sales by product:\n";
        for (const auto& sale : sales) {
            cout << sale.first << ": " << sale.second << " units\n";
        }
    }
};

} // namespace VendingSystem ends here

// The main function starts here
int main() {                                                
    using namespace VendingSystem;

    VendingMachine vm;   // Create an instance of VendingMachine
    int choice;
    string productName;
    double amount;
    // Infinite loop
    while (true) {                                          
        cout << "\n ----- Vending Machine Menu -----\n";
        cout << "1. View Products\n2. Insert Money\n3. Purchase Item\n"
             << "4. Return Change\n5. Admin: Restock\n6. Admin: View Earnings\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                vm.displayInventory();   // Display available products
                break;
            case 2:
                cout << "Enter amount to insert: €";
                cin >> amount;
                vm.insertMoney(amount);                     // Insert money into the machine
                break;
            case 3:
                cout << "Enter product name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, productName);
                vm.purchase(productName);                   // Purchase a product
                break;
            case 4:
                vm.returnChange();                          // Return change to the user
                break;
            case 5: {
                cout << "Enter product name to restock: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, productName);
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;
                vm.restock(productName, quantity);          // Restock a product
                break;
            }
            case 6:
                vm.displayEarnings();                       // Display earnings
                break;
            case 7:
                cout << "Thank you for using the vending machine!\n";
                return 0;                                   // Exit the program
            default:
                cout << "Invalid choice!\n";                 // Handle invalid input
        }
    }
}