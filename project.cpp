#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class customer{
	string name;
	long long int mob_number;
	public:
		void cust_input();
		void cust_display();
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
int digit_mob(long long int mob_number){
    int i=0;
    while(mob_number>0){
        mob_number=mob_number/10;
        i++;
    }
    if(i==10) 
        return 10;
    else 
       return 11;
       
}
void customer :: cust_input() {
    while(true){
		cout<<"enter name: ";
		getline(cin,name);
		if(namevalid(name)) break;
		    cout << "Invalid name. No digits/special characters allowed.\n";
	}
	while(true){
		cout<<"enter mob_number ";
		cin>>mob_number;
		if(cin.fail() || mob_number<=0 || (digit_mob(mob_number))==11) {
    	cout<<"invelid input, plz enter in degits! "<<endl;
    	cin.clear();
    	cin.ignore(10000,'\n');
    	}
    	else break;
	}
    cout<<mob_number<<endl;
}
void customer::cust_display(){
    cout<<"/------------customer-detials--------------/"<<endl;
    cout<<setw(10)<<"name"<<setw(20)<<"mob_number"<<endl;
    cout<<setw(10)<<name<<setw(20)<<mob_number<<endl;
}
int main()
{
	customer c;
	c.cust_input();
	c.cust_display();
	return 0;
}