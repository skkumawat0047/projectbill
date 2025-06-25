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
public:
    int id;
    string name, ID;
    float price;
    void avi_input();
    void avi_display();
    void viewProducts();
    void product_delet();
    // void product_update();
};
int P_id()
{
    string ID;
    int id;
    while (true)
    {
        int k = 0;
        cout << "Enter Product ID: ";
        cin >> ID;
        for (char c : ID)
        {
            if (!isdigit(c))
            {
                cout << "invalid, plz enter in digits!" << endl;
                k = 1;
                break;
            }
        }
        if (k != 1)
            break;
    }
    try
    {
        id = stoi(ID);
    }
    catch (const exception &e)
    {
        cout << " " << e.what() << '\n';
    }
    cin.ignore();
    return id;
}
int uniqueid()
{
    int id1 = P_id();
    Product p;
    bool exits = false;
    ifstream fin("product.txt", ios::in | ios::app);
    while (fin >> p.id >> p.name >> p.price)
    {
        if (p.id == id1)
        {
            exits = true;
            cout << "this id is allready exits, enter again please\n";
            break;
        }
    }
    fin.close();
    if (exits)
    {
        return uniqueid();
    }
    return id1;
}
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
void Product::avi_input()
{
    id = uniqueid();
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
    ofstream fout("product.txt", ios::app);
    fout << id << "    " << name << "    " << price << endl;
    fout.close();
    cout << "product added successfully! " << endl;
}
void Product::product_delet()
{
    Product p;
    int p_id = P_id();
    bool found = false;
    ifstream fin("product.txt", ios::in | ios::app);
    ofstream fout("temp.txt", ios::out | ios::app);
    while (fin >> p.id >> p.name >> p.price)
    {
        if (p.id == p_id)
        {
            found = true;
            continue;
        }
        fout << p.id << "    " << p.name << "    " << p.price << endl;
    }
    fin.close();
    fout.close();
    remove("product.txt");
    rename("temp.txt", "product.txt");
    if (found)
    {
        cout << "product deleted successfully!" << endl;
    }
    else
        cout << "product not found! " << endl;
}
void Product::viewProducts()
{
    ifstream fin("product.txt", ios::in | ios::app);
    if (!fin)
    {
        cout << " No products found." << endl;
        return;
    }

    Product p;
    cout << "ID" << setw(10) << "Name"
         << setw(10) << "Price\n";
    cout << "--------------------------------------------------\n";
    string s2;
    while (getline(fin, s2))
    {
        cout << s2 << endl;
    }

    fin.close();
    cout << "\n------------------------------------------------\n";
    cout << "\n";
}
class customer
{
    string name, number;

public:
    float total = 0;
    int c_id;
    float c_quantity;
    float discount = 0;
    void cust_input1();
    void cust_input2();
    float cust_input3();
    void cust_display();
};
int digit_mob(const string &number)
{
    for (char c : number)
    {
        if (!isdigit(c))
        return 11;
    }
    if(number.front()=='0'){
        return 11;
    }
    if (number.length() == 10)
        return 10;
    else
        return 11;
}
void customer ::cust_input1()
{
    customer c;
    name, number;
    while (true)
    {
        cout << "enter name: ";
        getline(cin, name);
        if ( namevalid(name))
            break;
        cout << "Invalid name, No digits/special characters allowed \n";
    }
    while (true)
    {
        cout << "enter (10 digits) mob_number: ";
        cin >> number;
        if (cin.fail() || (digit_mob(number)) == 11)
        {
            cout << "invelid input, plz enter in degits! " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            break;
    }
    ofstream fout("allcustomer.txt", ios::app);
    fout << "    name: " << name << "     Mob:" << number << "     ";
    fout.close();
}
float P_qunt()
{
    string Qunt;
    float quant;
    while (true)
    {
        int i = 0, j;
        j = 0;
        cout << "Enter Product quantity(in KG.): ";
        cin >> Qunt;
        for (char c : Qunt)
        {

            if (c == '.')
            {
                j = j + 1;
            }
            else if (!isdigit(c))
            {
                i = 1;
                break;
            }
        }
        if (j > 1 || i == 1 || Qunt.empty())
        {
            cout << "invlid input, plz enter again !\n";
            continue;
        }
        try
        {
            quant = stof(Qunt);
            if (quant <= 0)
            {
                cout << "quantity must be greater then 0! \n";
                continue;
            }
        }
        catch (const exception &e)
        {
            cout << "conversion error!" << e.what() << '\n';
            continue;
        }
        break;
    }
    cin.ignore(100, '\n');
    return quant;
}
void customer::cust_input2()
{
    Product p;
    char e;
    c_id = P_id();
    bool found = false;
    ifstream fin("product.txt", ios::in);
    ofstream cust("customer.txt", ios::out | ios::app);
    ofstream fout("allcustomer.txt", ios::out | ios::app);
    float total1;
    while (fin >> p.id >> p.name >> p.price)
    {
        if (p.id == c_id)
        {
            total1 = 0;
            found = true;
            c_quantity = P_qunt();
            cust << c_id << "    " << p.price << "    " << c_quantity << setprecision(3) << "    " << p.name << "    ";
            total1 = p.price * c_quantity;
            cust << total1 << endl;
            fout << "    P.id & qunt: " << c_id << "," << c_quantity;
            total = total + total1;
            break;
        }
    }
    fout.close();
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
        return;
    }
    else
    {
        cout << "invalid input!" << endl;
        cust_input2();
    }
}
float customer::cust_input3()
{
    char c;
    cout << "is discount available(y/n): ";
    cin >> c;
    if (c == 'y')
    {
        while (true)
        {
            cout << "Enter discount: ";
            cin >> discount;
            if (cin.fail() || discount < 0 || discount > 100)
            {
                cout << "invelid input, plz enter again! " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
                break;
        }
    }
    else if (c == 'n')
    {
        return 0;
    }
    else
    {
        cout << "invalid input\n ";
    }
    return discount;
}
void customer::cust_display()
{
    float a = discount;
    customer c;
    cout << "name: " << name << setw(20) << "mob_number: " << number << endl;
    cout << "\n--------------------***-------------------------\n";
    cout << "id" << "    price" << "   " << "qt.    " << "name     " << "   total\n";
    cout << "------------------------------------------------\n";
    ifstream cin("customer.txt", ios::out | ios::in | ios::app);
    string s1;
    while (getline(cin, s1))
    {
        cout << s1 << endl;
    }
    cout << "------------------------------------------------";
    cout << "\nyours total amount is: " << total << "\n";
    cout << "discount: " << a << "%\n";
    cout << "tax: 5% \n";
    cout << "tax amount is: " << (total * 5) / 100 << "\n";
    cout << "------------------------------------------------\n";
    cout << "your final amount is: " << total * ((105 - a) / 100) << "\n";
    cout << "*----------------------------------------------*\n";
    ofstream cust("customer.txt", ios::out | ios::trunc);
    cust.close();
    ofstream fout("allcustomer.txt", ios::out | ios::app);
    fout << "  dis: " << a << "%    tax: 5%" << "     total:" << total << endl;
    fout.close();
}
class Invoice
{
    int invoice_number;

public:
    void createInvoice();
    // void customerproducts();
    // void saveInvoice();
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
    ofstream fout("allcustomer.txt", ios::app);
    fout << "Bill.no: " << invoice_number;
    fout.close();
}

void Invoice::printInvoice()
{
    time_t now = time(0);
    char *td = ctime(&now);
    Invoice i;
    customer c;
    i.createInvoice();
    c.cust_input1();
    c.cust_input2();
    c.cust_input3();
    cout << "\n------------------   Welcome   -----------------\n";
    cout << "\n            ** Radhe-Radhe Grocery shop **          \n";
    cout << "\n/--------------------Invoice--------------------/" << endl;
    cout << "invoice number: " << i.invoice_number << "        T & D: " << td << endl;
    c.cust_display();
}
void productmenu()
{
    int choice;
    Product Product;
    do
    {
        cout << "1. for add product " << endl;
        cout << "2. for delet any product using Productid" << endl;
        cout << "3. for display products available on the store" << endl;
        cout << "4. exit back..." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Product.avi_input();
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
