#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Product{
	int id;
	public:
	void input();
//	bool namevalid();
};

bool namevalid(const string& name){
	if(name.empty()){
		return false;
	}
	for(char c: name){
		if(!isalpha(c) && !isspace(c)){
			return false;
		}
	}
	return true;
}
void Product::input() {
	int id;
	string name;
	float price;
	float quantity;
    cout << "Enter Product ID: ";
    cin >> id;
    if(cin.fail() || id<=0){
    	cout<<"invelid input, plz enter in degits! "<<endl;
    	cin.clear();
    	cin.ignore(10000,'\n');
    	input();
    	return ;
	}
	cout<<"your id is: "<<id<<endl;
	
	while(true){
		cout<<"enter name: ";
		getline(cin,name);
		if(namevalid(name)) break;
		    cout << "Invalid name. No digits/special characters allowed.\n";
	}
	
	while(true){
		cout<<"enter price: ";
		cin>>price;
		if(cin.fail() || price<=0){
    	cout<<"invelid input, plz enter in degits! "<<endl;
    	cin.clear();
    	cin.ignore(10000,'\n');
    	}
    	else break;
	}
	
	while (true) {
        cout << "Enter Quantity: ";
        cin >> quantity;
        if (cin.fail() || quantity <= 0) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid quantity. Try again.\n";
        } else break;
    }
}
int main(){
	Product p;
	p.input();
	return 0;
}