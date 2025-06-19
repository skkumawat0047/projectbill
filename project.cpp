#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <ctime>
#include <vector>
using namespace std;
class Product
{
    public:
    int id;
    string name;
    float price;
    float quantity;
    void avi_input();
    void avi_display();
    void updateproduct();
    void product_delet();
    int getid() { return id; }
    float getprice() { return price;}
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
void Product::avi_input()
{
    // 	int id;
    // 	string name;
    // 	float price;
    // 	float quantity;
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
    // 	cout<<"your id is: "<<id<<endl;

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

    while (true)
    {
        cout << "Enter Quantity: ";
        cin >> quantity;
        if (cin.fail() || quantity <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid quantity. Try again.\n";
        }
        else
            break;
    }
}
void Product::avi_display()
{
    cout << setw(5) << id << setw(10) << name << setw(10) << price << setw(10) << quantity << endl;
}

void Product::updateproduct()
{
    Product p;
    int P_id;
    cout << "enter id to update product: " << endl;
    cin >> P_id;
    fstream file("product.bin", ios::binary | ios::in | ios::out);
    bool found = false;
    while (file.read((char *)&p, sizeof(p)))
    {
        if (p.getid() == P_id)
        {
            file.seekp(-sizeof(p), ios::cur);
            p.avi_input();
            file.write((char *)&p, sizeof(p));
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "product updated succesfuly" << endl;
    }
    else
    {
        cout << "id not found!" << endl;
    }
    file.close();
}

void Product::product_delet()
{
    Product p;
    int p_id;
    // int getid;
    bool found = false;
    cout << "enter product id: ";
    cin >> p_id;
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

void viewProducts()
{
    ifstream fin("product.bin", ios::binary);
    if (!fin)
    {
        cout << " No products found." << endl;
        return;
    }

    Product p;
    cout << setw(5) << "ID" << setw(10) << "Name"
         << setw(10) << "Price" << setw(10) << "Qty\n";
    cout << "--------------------------------------------------\n";
    while (fin.read((char *)&p, sizeof(p)))
        p.avi_display();
    fin.close();
}
// void addproduct()
// {
//     Product p;
//     ofstream fout("product.bin", ios::binary | ios::app);
//     p.avi_input();
//     fout.write((char *)&p, sizeof(p));
//     fout.close();
//     cout << "product added successfully! " << endl;
// }
class customer
{
    string name;
    long long int mob_number;
    public:
    int c_id;
    string productname;
    float productprice;
    float c_quantity;

    vector<int> items1={};
    vector<string> items2={};
    vector<float> items3={};
    vector<float> items4={};
    float total;
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
        cout << "enter mob_number ";
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
void customer::cust_input2(){
    Product p;
    char c;
    bool found= false;
    while(true){
    cout << "Enter Product ID: ";
    cin >>c_id;
    if(cin.fail() || c_id<=0){
    	cout<<"invelid input, plz enter in degits! "<<endl;
    	cin.clear();
    	cin.ignore(10000,'\n');}
    else break;
	}
	cin.ignore();
    ifstream fin("product.bin", ios::binary | ios::in);
    while(fin.read((char*)&p, sizeof(p))){
        if(p.getid()==c_id){
            found=true;
            cout<<"enter quantities:";
            cin>>c_quantity;
            break;
        }
        float a=p.price;
        float b= c_quantity;
        string c=p.name;
        items2.push_back(c);
        items3.push_back(b);
        items4.push_back(a);
        total= total+ a*b;
        break;
    }
    if(!found){
        cout<<"product not found"<<endl;
    }
    cout<<"add more items(y/n): ";
    cin>>c;
    if(c=='y'){
        cust_input2();
    }
    else return;
    
}

void customer::cust_display()
{

    cout << setw(10) << "name: " << name << setw(20) << "mob_number: " << mob_number << endl;
    for(size_t i; i<items1.size(); i++){
        cout<<items1[i]<<setw(10)<<items2[i]<<setw(10)<<items3[i]<<setw(10)<<items4[i]<<endl;
    }
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
        cout << "enter invoice_number";
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
}

void Invoice::printInvoice()
{
    customer c;
    Invoice i;
    c.cust_input1();
    c.cust_input2();
    i.createInvoice();
    cout << "/--------------------Invoice-------------------/" << endl;
    cout<<"invoice number: "<<i.invoice_number<<endl;
    c.cust_display();
    cout<<"total amount: "<<c.total;
}
void productmenu()
{
    int choice;
    Product Product;
    do
    {
        cout << "1. for add product " << endl;
        cout << "2. for update any product by productid." << endl;
        cout << "3. for delet any product using Productid" << endl;
        cout << "4. for display products available on the store" << endl;
        cout << "5. exit back..." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Product.avi_input();
            break;
        case 2:
            Product.updateproduct();
            break;
        case 3:
            Product.product_delet();
            break;
        case 4:
            Product.avi_display();
            break;
        case 5:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "invalid input, please enter again!" << endl;
        }
    } while (choice != 5);
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
