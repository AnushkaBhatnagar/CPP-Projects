#include <iostream>
using namespace std;

class CarService
{
    string make;
    string model;
    string carno;
    string status;
    public:
    void readData()
    {
        cout<<endl<<"Enter Make: ";
        getline(cin>>ws,make);
        cout<<"Enter Model: ";
        getline(cin>>ws,model);
        cout<<"Enter Car Number: ";
        getline(cin>>ws,carno);
        status="Waiting";
    }
    int search(CarService obj[], int n, string x)  //x is carno
    {    //returns index value of obj array where the particular car's details are stored
        for(int i=0;i<n;i++)
        {
            if(obj[i].carno==x)
            return i;
        }
        return 999;
    }
    void assignStatus()
    {
        cout<<"Enter the new status: ";
        cin>>status;
    }
    void displayStatus()
    {
        cout<<endl<<"Car Details are as follows:"<<endl;
        cout<<"Make: "<<make<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Number: "<<carno<<endl;
        cout<<"Status: "<<status<<endl;
    }
};
int main()
{
    int n, a, f;
    char c='y';
    string s;
    cout<<"Enter the number of cars: ";
    cin>>n;
    CarService obj[n];
    for(int i=0;i<n;i++)
    {
        obj[i].readData();
    }
    while(c=='y'||c=='Y')
    {
        cout<<endl<<"         ***MENU***"<<endl;
        cout<<"Enter 1 to change status"<<endl<<"Enter 2 to display status"<<endl;
        cin>>a;
        if(a==1)
        {
            cout<<"Enter the car number whose status is to be changed: ";
            getline(cin>>ws,s);
            f=obj[0].search(obj,n,s);
            if(f!=999)
            obj[f].assignStatus();
            else
            cout<<"Car number entered is not present in the database"<<endl;
        }
        else if(a==2)
        {
            cout<<"Enter the car number whose status is to be displayed: ";
            getline(cin>>ws,s);
            f=obj[0].search(obj,n,s);
            if(f!=999)
            obj[f].displayStatus();
            else
            cout<<"Car number entered is not present in the database"<<endl;
        }
        else
        cout<<"Invalid choice"<<endl;
        cout<<endl<<"Do you want to contine? Enter y/Y for yes: ";
        cin>>c;
    }
}
