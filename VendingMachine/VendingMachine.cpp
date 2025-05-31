#include <iostream>  
#include <vector>     //for dynamic array (vector) used for listing the products info
#include <map>      // Used for tracking of how many times a particular product is sold
#include <set>     // Used for restocking or making restocking easy
#include <string>     // for string data type
#include <iomanip>      // for stream manipulators (e.g., setw, setprecision)
#include <limits> 

// C++ compiler did not comile € symbol, that is why $ sign is used instead
using namespace std;
// Using of namespace for organizing the code to prevent compiling errors or mixing function names etc, works more like a folder
namespace VendingSystem {
    class VendingComponent {
        protected:
        string name;

        public:
        // Default constructor
        VendingComponent() = default;
        VendingComponent(const string& n) : name(n) {} // Parameterized Constructor
        virtual ~VendingComponent() = default; // Virtual destructor
        virtual void displayInfo() const = 0; // pure virtual function to make the base class abstract

        // Encapsulation for name (Getter & Setter)
        string getName() const { return name; }
        void setName(const string& n) { name = n; }
        

    };

    // Derived Class 'Product'
    class Product : public VendingComponent {
        
        protected:
        double price = 0.0;
        int stock = 0;

        public:
        Product() = default; // Default constructor
        Product(const string& n, double p, int s) : VendingComponent(n), price(p), stock(s) {}

        virtual ~Product() = default;

        void displayInfo() const override {
            cout << "Product: " << name << ", Price: $" << price << fixed << setprecision(2) << "Stock: " << stock << endl;
        }
        // Encapsulation for Price and Stock ...
        double getPrice() const { return price;}
        double getStock() const { return stock;}
        void setPrice(double p) { price = p;}
        void setStock(int s) { stock = s; }

        Product operator +(const Product& other) const { // Operloading two product parts
            return Product (name + "_" + other.name, (price + other.price) / 2, stock + other.stock);
        }
        friend ostream& operator<<(ostream& os, const Product& p) { // Overloading part
            os << p.name << " ($" << fixed << setprecision(2) << p.price
               << ", " << p.stock << " in stock)";
            return os;
        }
    };

    // The class Snack inherits from Product
    class Snack : public Product {
        
        private: 
        string flavor;

        public: // Constructor 
        Snack(const string&n, double p , int s, const string& f) : Product(n, p, s), flavor(f) {}

        void displayInfo() const override {     // Overriding display method
            cout << "Snack: " << name << " (" << flavor << "), Price: $" << fixed
                 << setprecision(2) << price << ", Stock: " << stock << endl; 
        }
    
        string getFlavor() const { return flavor; }        
        void setFlavor(const string& f) { flavor = f; }       
     };

    class Beverage : public Product {
        
        private: 
        string type;

        public:
        // Constructor
        Beverage(const string& n, double p, int s, const string& t) : Product(n, p, s), type(t) {}
        void displayInfo() const override {
            cout << "Beverage: " << name << " (" << type << "), Price: $" << fixed << setprecision(2) << price << ", Stock: " << stock << endl;
        }
        string getType() const { return type;}
        void setType(const string& t) {type = t;}

     };

     // Helper Class 'VendingMachine'
     class VendingMachine {
        private:
        vector<Product*> inventory; // Using vector for listing the produncts and pointer to Product objects
        map<string, int> sales;      // Map is used to track sales count
        set<string> outOfStock;         // Set is used to track out-of-stock products
        double balance;         
        double totalEarnings;

        public:
        VendingMachine () { // Constructor

            // Listing all the Products information by the help of vector and pointers
            inventory.push_back( new Beverage ("Coke", 2.99, 15, "Soda"));
            inventory.push_back( new Beverage ("Red Bull", 3.55, 20, "Energy Drink"));
            inventory.push_back( new Beverage ("Apple Juice", 1.20, 10, "Juice"));
            inventory.push_back( new Beverage ("Water", 1.85, 15, "Still"));
            inventory.push_back( new Beverage ("Lemonade", 2.99, 12, "Soda"));
            inventory.push_back( new Beverage ("Iced Tea", 2.55, 7, "Tea"));
            inventory.push_back( new Beverage ("Monster", 2.80, 10, "Energy Drink"));

            inventory.push_back( new Snack ("Potato Chips", 2.50, 10, "Sour Cream"));
            inventory.push_back( new Snack ("Chocolate Bar", 2.20, 15, "Milk Chocolate"));
            inventory.push_back( new Snack ("Popcorn", 2.00, 7, "Butter Flavor"));
            inventory.push_back(new Snack ("Protein Bar", 3.00, 15, "Strawberry"));
            inventory.push_back( new Snack ("Nuts", 1.80, 12, "Mixed"));
            inventory.push_back( new Snack ("Cookies", 2.80, 12, "Chocolate"));
            inventory.push_back( new Snack ("Crackers", 2.30, 12, "Plain"));

        }
        ~VendingMachine() { // Destroying the Vending Machine
            for (Product*p : inventory) {
                delete p;
            }
        }

        void displayInventory() { // The function to show and display the inventory list
            int category;
        
            while(true) {
                cout << "\n *** Product Inventory *** \n";
                cout <<"0. Back to Main Menu \n\n";
                cout <<"Select Category: \n";
                cout <<"1. Beverage \n 2. Snacks \n\n Enter Choice: ";
                cin >> category;
                if (category == 0) break;
                // Use of switch for choosing between beverage and snack option
                switch (category) {
                    case 1: { // The Beverage Menu list, by the help of (setw = wet width) the menu looks more organized or like a table
                        // The left is used for the text aligning as left.
                        cout << "\n*** Beverages ***\n";
                        cout << left << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Type" << setw(15) << "Price ($)" << setw(10) << "Stock" << endl;
                        cout << string(70, '-') << endl;

                        vector<size_t> beverageIndices;
                        size_t index = 0;
                        for (size_t i = 0; i < inventory.size(); i++) {
                            Beverage* beverage = dynamic_cast<Beverage*>(inventory[i]);
                            if (beverage) {
                                ++index;
                                beverageIndices.push_back(i);  // the defaultfloat part is used to prevent decimal points in stock values
                                cout << setw(5) << index << setw(20) << beverage->getName() << setw(15) << beverage->getType()
                                     << setw(15) << fixed << setprecision(2) << beverage->getPrice() << defaultfloat
                                     << setw(10) << beverage->getStock() << endl;
                            }
                        }
                        if (index == 0) {
                            cout << "No beverages available.\n";
                            break;
                        }
                        int selection;
                        cout << "\nSelect a Beverage (1-" << index << ", 0 to go back): ";
                        while (!(cin >> selection)) {
                            cout << "Invalid input! Please enter a number: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (selection == 0) break;
                        if (selection < 1 || selection > static_cast<int>(index)) {
                            cout << "Invalid selection!\n";
                            break;
                        }
                        Beverage* beverage = dynamic_cast<Beverage*>(inventory[beverageIndices[selection - 1]]);
                        if (beverage) {
                            cout << "Selected: " << *beverage << endl;
                            processPurchase(beverage);
                        }
                        break;
                    }
                    case 2: { // The Snack part is done the same as Beverage part. 
                        cout << "\n*** Snacks ***\n";
                        cout << left << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Flavor" << setw(15) << "Price ($)" << setw(10) << "Stock" << endl;
                        cout << string(70, '-') << endl;

                        vector<size_t> snackIndices;
                        size_t index = 0;
                        for (size_t i = 0; i < inventory.size(); i++) {
                            Snack* snack = dynamic_cast<Snack*>(inventory[i]);
                            if (snack) {
                                ++index;
                                snackIndices.push_back(i);
                                cout << setw(5) << index << setw(20) << snack->getName() << setw(15) << snack->getFlavor()
                                     << setw(15) << fixed << setprecision(2) << snack->getPrice() << defaultfloat
                                     << setw(10) << snack->getStock() << endl;
                            }
                        }
                        if (index == 0) {
                            cout << "No snacks available.\n";
                            break;
                        } // THe following part is added to do a product selection inside the Beverage or Snack catetory
                        int selection;
                        cout << "\nSelect a Snack (1-" << index << ", 0 to go back): ";
                        while (!(cin >> selection)) {
                            cout << "Invalid input! Please enter a number: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (selection == 0) break;
                        if (selection < 1 || selection > static_cast<int>(index)) {
                            cout << "Invalid selection!\n";
                            break;
                        }
                        Snack* snack = dynamic_cast<Snack*>(inventory[snackIndices[selection - 1]]);
                        if (snack) {
                            cout << "Selected: " << *snack << endl;
                            processPurchase(snack);
                        }
                        break;
                    }
                    default:
                        cout << "Invalid category!\n";
                }
            }
        }

            // This part is also added inside the categories, to make it easy for the buyer to insert money after selection and purchase
            void insertMoney(double amount) {                       
                if (amount > 0) {
                    balance += amount;
                    cout << "Inserted: $" << fixed << setprecision(2) << amount
                    << ". Current balance: $" << balance << endl;
                } else {
                    cout << "Invalid amount!\n";
                }
             }



             // The Purchasing part
             void purchase(const string& productName) {
            for (Product* p : inventory) {
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
                        cout << "Purchased: " << *p << endl;
                        cout << "Remaining balance: $" << fixed << setprecision(2) << balance << endl;
                    } else {
                        cout << "Insufficient balance! Need $" << fixed << setprecision(2) << (p->getPrice() - balance) << " more.\n";
                    }
                    return;
                }
            }
            cout << "Product not found!\n";
        }

        void processPurchase(Product* product) {
            if (product->getStock() == 0) {
                outOfStock.insert(product->getName());
                cout << product->getName() << " is out of stock!\n";
                return;
            }
            cout << "Price: $" << fixed << setprecision(2) << product->getPrice() << ". Current balance: $" << balance << endl;
            while (balance < product->getPrice()) {
                double amount;
                cout << "Insert $" << fixed << setprecision(2) << (product->getPrice() - balance) << " or more (0 to cancel): ";
                while (!(cin >> amount)) {
                    cout << "Invalid input! Please enter a number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (amount == 0) {
                    cout << "Purchase cancelled.\n";
                    return;
                }
                insertMoney(amount);
            }
            purchase(product->getName());
        }

        void returnChange() {
            if (balance > 0) {
                cout << "Returning Change: $" << fixed << setprecision(2) << balance << endl;
                balance = 0;
            }
        }

        void restock(const string& productName, int quantity) {
            for (Product* p : inventory) {
                if (p->getName() == productName) {
                    p->setStock(p->getStock() + quantity);
                    outOfStock.erase(productName);
                    cout << productName << " restocked with " << quantity << " units\n";
                    return;
                }
            }
            cout << "Product not found!\n";
        }

        void displayEarnings() const {
            cout << "Total Earnings: $" << fixed << setprecision(2) << totalEarnings << endl;
            cout << "Sales by product:\n";
            for (const auto& sale : sales) {
                cout << sale.first << ": " << sale.second << " units\n";
            }
        }
    };
} // namespace VendingSystem ends here


// Main function Starts here
int main() {
    using namespace VendingSystem;

    // Create an instance of VendingMachine
    VendingMachine vm;   
    int choice;
    string productName;
    int quantity;
    // Infinite loop
    while (true) {                                          
        cout << "\n ----- Vending Machine Menu -----\n";
        cout << "1. View Products and Purchase...\n2. Return the Change\n3. Admin: Restock\n4. Admin: View Earnings\n5. Exit\n";
        cout << "Enter choice: ";

        // Input validation for menu choice
        while(!(cin >> choice)) {
            cout <<"Invalid input! Please Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Using switch case to toggle between the Vending machine menu list
        switch (choice) {
            case 1:
                vm.displayInventory();   
                break;
            case 2:
                vm.returnChange();                     
                break;
            case 3: 
            cout << "Enter product name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, productName);
                cout << "Enter quantity: ";
                while (!(cin >> quantity)) {
                    cout << "Invalid input! Please enter a number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                vm.restock(productName, quantity);                   
                break;
                
            case 4:
                vm.displayEarnings();                          
                break;
            case 5: 
                cout << "Thank you for using the vending machine!\n";
                return 0;                                   
            default:
                cout << "Invalid choice!\n";      
        }
    }
}

 
