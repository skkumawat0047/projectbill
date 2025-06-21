#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <ctime>
using namespace std;
class Product
{
    int id;
    string name;
    float price;

public:
    void avi_input();
    void avi_display();
    void viewProducts();
    void product_delet();
    int getid() { return id; }
    string getname() { return name; }
    float getprice() { return price; }
};

bool namevalid(const string &name)
{
    if (name.empty())
    {
        return false;
    }
    for (char c : name)
    {
        if (!isalpha(c) && !isspace(c))
        {
            return false;
        }
    }
    return true;
}
int P_id()
{
    int id;
    while (true)
    {
        cout << "Enter Product ID: ";
        cin >> id;
        if (cin.fail() || id <= 0)
        {
            cout << "invelid input, plz enter in degits! " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            break;
    }
    cin.ignore();
    return id;
}
void Product::avi_input()
{
    id = P_id();
    while (true)
    {
        cout << "enter name: ";
        getline(cin, name);
        if (namevalid(name))
            break;
        cout << "Invalid name. No digits/special characters allowed.\n";
    }

    while (true)
    {
        cout << "enter price: ";
        cin >> price;
        if (cin.fail() || price <= 0)
        {
            cout << "invelid input, plz enter in degits! " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            break;
    }
}
void Product::avi_display()
{
    cout << id << setw(10) << name << setw(10) << price << endl;
}
void Product::product_delet()
{
    Product p;
    int p_id=P_id();
    bool found = false;
    ifstream fin("product.bin", ios::binary);
    ofstream fout("temp.bin", ios::binary);
    while (fin.read((char *)&p, sizeof(p)))
    {
        if (p.getid() == p_id)
        {
            found = true;
            continue;
        }
        fout.write((char *)&p, sizeof(p));
    }
    fin.close();
    fout.close();
    remove("product.bin");
    rename("temp.bin", "product.bin");
    if (found)
    {
        cout << "product deleted successfully!" << endl;
    }
    else
        cout << "product not found! " << endl;
}

void Product::viewProducts()
{
    ifstream fin("product.bin", ios::binary);
    if (!fin)
    {
        cout << " No products found." << endl;
        return;
    }

    Product p;
    cout << setw(5) << "ID" << setw(10) << "Name"
         << setw(10) << "Price\n";
    cout << "--------------------------------------------------\n";
    while (fin.read((char *)&p, sizeof(p)))
        p.avi_display();
    fin.close();
}
void addproduct()
{
    Product p;
    ofstream fout("product.bin", ios::binary | ios::app);
    p.avi_input();
    fout.write((char *)&p, sizeof(p));
    fout.close();
    cout << "product added successfully! " << endl;
}
class customer
{
    string name;
    long long int mob_number;
public:
    float total=0;
    int c_id;
    int z=1;
    string productname;
    float productprice;
    float c_quantity;
    // int z;
    void cust_input1();
    void cust_input2();
    void cust_display();
    void printcustomer();
};
int digit_mob(long long int mob_number)
{
    int i = 0;
    while (mob_number > 0)
    {
        mob_number = mob_number / 10;
        i++;
    }
    if (i == 10)
        return 10;
    else
        return 11;
}
void customer ::cust_input1()
{
    name;
    mob_number;
    while (true)
    {
        cout << "enter name: ";
        getline(cin, name);
        if (namevalid(name))
            break;
        cout << "Invalid name. No digits/special characters allowed.\n";
    }
    while (true)
    {
        cout << "enter mob_number: ";
        cin >> mob_number;
        if (cin.fail() || mob_number <= 0 || (digit_mob(mob_number)) == 11)
        {
            cout << "invelid input, plz enter in degits! " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            break;
    }
}
float P_qunt()
{
    float quant;
    while (true)
    {
        cout << "Enter Product quantity: ";
        cin >> quant;
        if (cin.fail() || quant <= 0)
        {
            cout << "invelid input, plz enter in degits! " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            break;
    }
    cin.ignore();
    return quant;
}
void customer::cust_input2()
{
    Product p;
    char e;
    c_id=P_id();
    bool found = false;
    ifstream fin("product.bin", ios::binary | ios::in | ios::app);
    ofstream cust("customer.txt", ios::out | ios::app);
    float total1;
    while (fin.read((char *)&p, sizeof(p)))
    {
        if (p.getid() == c_id)
        {
            total1=0;
            found = true;
            c_quantity=P_qunt();
            z++;
            cust << c_id << "    " << p.getprice() << "    " << c_quantity << "    " << p.getname() <<"    ";
            total1 =  p.getprice() * c_quantity;
            cust<<total1<<endl;
        }
        // total = total + p.getprice() * c_quantity;
        break;
    }
    total =total+total1;
    cust.close();
    fin.close();
    if (!found)
    {
        cout << "product not found" << endl;
    }
    cout << "add more items(y/n): ";
    cin >> e;
    if (e == 'y')
    {
        cust_input2();
    }
    else if (e == 'n')
    {
        return ;
    }
    else
    {
        cout << "invalid input!" << endl;
        cust_input2();
    }
}
void customer::cust_display()
{
    // customer c;
    cout << "name: " << name << setw(20) << "mob_number: " << mob_number << endl;
    cout << "\n--------------------***-------------------------\n";
    cout << "id" << setw(10) << "price" << setw(5)<<"qt."<< "name" << "\n";
    cout << "------------------------------------------------\n";
    ifstream cin("customer.txt", ios::out | ios::in | ios::app);
    for (int i =1; i < z; i++)
    {
        string s1;
        getline(cin, s1);
        cout << s1 << endl;
    }
    cout<<"--------------------------------------------\n";
    cout << "\ntotal amount: " <<total << "\n";
    ofstream cust("customer.txt", ios::out | ios::trunc);
    cust.close();

}
// void all_customer()
// {
//     customer c;
//     ofstream fout("customer.bin", ios::binary | ios::app);
//     c.cust_input1();
//     fout.write((char *)&c, sizeof(c));
//     fout.close();
// }
class Invoice
{
    int invoice_number;
    // int discout;
public:
    void createInvoice();
    void customerproducts();
    void saveInvoice();
    void printInvoice();
};

void Invoice::createInvoice()
{
    customer c;
    while (true)
    {
        cout << "enter invoice_number: ";
        cin >> invoice_number;
        if (cin.fail() || invoice_number <= 0)
        {
            cout << "invelid input, plz enter in degits! " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            break;
    }
    cin.ignore();
}

void Invoice::printInvoice()
{
    Invoice i;
    customer c;
    i.createInvoice();
    c.cust_input1();
    c.cust_input2();
    cout << "\n/--------------------Invoice-------------------/" << endl;
    cout << "invoice number: " << i.invoice_number << endl;
    c.cust_display();
}
void productmenu()
{
    int choice;
    Product Product;
    do
    {
        cout << "1. for add product " << endl;
        // cout << "2. for update any product by productid." << endl;
        cout << "2. for delet any product using Productid" << endl;
        cout << "3. for display products available on the store" << endl;
        cout << "4. exit back..." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addproduct();
            break;
        case 2:
            Product.product_delet();
            break;
        case 3:
            Product.viewProducts();
            break;
        case 4:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "invalid input, please enter again!" << endl;
        }
    } while (choice != 4);
}
int main()
{
    int choice;
    do
    {
        cout << "enter a choice: " << endl;
        cout << "1. for product management." << endl;
        cout << "2. for printInvoice." << endl;
        cout << "3. for Exit. " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            productmenu();
            break;
        case 2:
            Invoice Invoice;
            Invoice.printInvoice();
        case 3:
            cout << "Exiting....." << endl;
            break;
        default:
            cout << "you entered a wrong choice! " << endl;
        }
    } while (choice != 3);
}
