#include "VendingMachine.h"
#include <iostream>
using namespace std;
VendingMachine::VendingMachine()
{
    setchoose(11);
    setmoney(11);
}
void VendingMachine:: menu(){
   cout<<"Welcome (: \nWhat do you want to buy today?"<<endl
        <<"\nDrinks"<<"                       "<<"candy"
        <<"\n______________________________________________\n"
        <<"\n1-pepsi          $7" <<"        "<<" 6-Gum           $5"
        <<"\n2-juice          $5" <<"        "<<" 7-lolly pop     $5"
        <<"\n3-7up            $7.5" <<"      "<<" 8-candy         $10.5"
        <<"\n4-Ice choclate   $20"<<"        "<<"9-donuts        $15"
        <<"\n5-Ice tea        $15"<<"        "<<"10-choclate     $20"
                             <<"\n0-Exit\n";
}
void VendingMachine:: setmoney(double money){
        this->money=money;
        }
void VendingMachine:: setchoose(int choose){
        this->choose=choose;
        }
double VendingMachine:: getmoney(){
            return money;
        }
int    VendingMachine:: getchoose(){
            return choose;
        }
void  VendingMachine::entermoney(){
        double t , t1 , f , p , h ;
        cout<<"Enter the money" << endl;
        cout << "Number of Twenties : ";
        cin>>t;
        cout << "Number of Tens : ";
        cin>>t1;
        cout << "Number of Fives : ";
        cin>>f;
        cout << "Number of Pounds : ";
        cin>>p;
        cout << "Number of half : ";
        cin>>h;
        cout << endl;
        setmoney(t*20 + t1*10 + f*5 + p + h*.5);
    }
bool VendingMachine::enterchoose(){
        cout<<"Enter your choose: ";
        cin>>choose;
        if(choose<0 || choose>10){
                cout<<"invalid " << endl;
                enterchoose();

        }
         else if(choose==0){
            bool half = false;
            if(int(money)== int(money-.5)) half = true;
            cout << "Pick your money >>> " << endl;
            if((int(money)/20)>0)cout << "Twenties : " << int(money)/20 << endl;
            money = int(money) % 20;
            if((int(money)/10)>0)cout << "Tens : " << int(money)/10 << endl;
            money = int(money) % 10;
            if((int(money)/5)>0)cout << "Fives : " << int(money)/5 << endl;
            money = int(money) % 5;
            if(money > 0)cout << "Pounds : " << money << endl;
            if(half) cout << "Half : 1" << endl << endl;
            return false;
        }
        else if(getmoney()<arr[choose-1]){
            cout<<"add money or choose another item or exist"<<endl;
            double t , t1 , f , p , h ;
            cout<<"Add money" << endl;
            cout << "Number of Twenties : ";
            cin>>t;
            cout << "Number of Tens : ";
            cin>>t1;
            cout << "Number of Fives : ";
            cin>>f;
            cout << "Number of Pounds : ";
            cin>>p;
            cout << "Number of half : ";
            cin>>h;
            cout << endl;
            money+=(t*20 + t1*10 + f*5 + p + h*.5);
            enterchoose();

        }
        else if(arr2[choose-1]==0){
            cout<<"this item is unavillable enter another choise or exist" << endl;
             enterchoose();
        }
        else{
            return true;
        }
     }
void VendingMachine::pickitem(){
            arr2[choose-1]-=1;
            money-=arr[choose-1];
            cout << endl <<"Pick your item >>>> " << endl;
            cout <<"your money now is: " << money << endl;
      }
VendingMachine::~VendingMachine()
{
    //dtor
}


