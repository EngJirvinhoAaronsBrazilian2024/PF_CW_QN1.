#include <iostream>
#include<string>
#include<map>

using namespace std;
map<string,pair<string, double>> accounts;

bool login(string &userId) {
string password;
cout<<"Please enter user ID:";
cin>> userId;
cout<<"Enter password:";
cin>> password;

if (accounts.find(userId)!=accounts.end() && accounts[userId].first == password){
    return true;
}
else{
    cout<<"***LOGIN FAILED!***"<<endl;
    return false;
 }
}

void createAccount(){
string userId,password;
cout<<"Create a new User ID:";
cin>>userId;
if (accounts.find(userId)!= accounts.end()){
    cout<<"User ID already exists.please choose another one."<<endl;
    return;
}
cout<<"Create a New password:";
cin>>password;
accounts[userId] = make_pair(password,0.0);
cout<<"\nThank you! Your account have been created."<< endl;
}

void withdrawMoney(string&userId){
    double amount;
cout<<"Enter amount to withdraw:$";
cin>>amount;

if(accounts[userId].second>=amount){
    accounts[userId].second -=amount;
    cout<<"Withdrawal successfully! New balance:$"<<accounts[userId].second<<endl;
}else
{
cout<<"Insufficient balance."<<endl;
 }
}

void depositeMoney(string&userId){
    double amount;
cout<<"Enter amount to deposit:$";
cin>> amount;

 accounts[userId].second +=amount;
 cout<<"\nDeposit successful! New balance:$"
<<accounts[userId].second<<endl;
}

void requestBalance(string&userId){
    cout<<"Your balance is:$"<<accounts[userId].second<<endl;
}

int main(){
    int choice;
    string userId;

    while (true){
        cout<<"Hi! Welcome to the ATM machine:\n";
        cout<<"\Please select an option from the menu below.\n";
        cout<<"1.Create a bank Account\n";
        cout<<"2.login\n";
        cout<<"3.Quit\n";
        cin>>choice;

        switch (choice){
        case 1:
            createAccount();
            break;
        case 2:
            if (login(userId)){
                while (true){
                    cout<<"Please select an option from the menu below:\n";
                    cout<<"\nAccess Granted!\n";
                    cout<<"1.Withdraw money\n";
                    cout<<"2.Deposit money\n";
                    cout<<"3.Request balance\n";
                    cout<<"4.Quit\n";
                    cin>>choice;

                    if (choice==4)break;

                    switch (choice){
                    case 1:
                        withdrawMoney(userId);
                        break;
                    case 2:
                        depositeMoney(userId);
                        break;
                    case 3:
                        requestBalance(userId);
                        break;
                    default:
                        cout<<"Invalid option. please try again."<<endl;
                    }
                }
            }
            break;
                    case 3:
                        cout<<"Thank you for using the ATM system.Have a nice day!"<<endl;
                        return 0;
                    default:
                        cout<<"Invalid option.please try again."<<endl;
        }
    }
}
