#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<sstream>
using namespace std;
long long bankmoney=10000000;
long long pro=0;
int sec=0;
int mainn();
int main();
class login{
	private:
		string pass,pass2;
	public:
		login():pass("spartans"),pass2("root"){}
		void logcheck(string p,string u=""){
			if(p==pass && u==""){
				cout<<"WELCOME SPARTANS\n";
				cout<<"PLEASE WAIT.";
				for(int x=0;x<7;x++){
					cout<<".";
					Sleep(500);
				}
				sec=1;
				mainn();
			}else if(pass2==p && u=="admin"){
				cout<<"\nWELCOME SPARTANS\n";
				cout<<"PLEASE WAIT.";
				for(int x=0;x<7;x++){
					cout<<".";
					Sleep(500);
				}
				sec=2;
				mainn();
			}else{
				cout<<"WRONG PASSWORD...!\n";
				cout<<"Going to Login Menu.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(300);
				}
				main();
			}
		}
};
class account{
	protected:
		int acc_no,pin,status;
		string name,sname,type;
		long long phone,money;
	public:
		account():acc_no(0),pin(0),name(""),type(""),money(0),phone(0),status(0){}
		void acccrt(){
			acc_no=accnocheck();
			get_data();
			system("CLS");
			save_data();
			status=1;
			cout<<"ACCOUNT CREATED \n";
			cout<<"Your Account NO is "<<acc_no<<endl;
			cout<<"Enter any key...:=>";
			getch();
		}
		int accnocheck(){
			ifstream check;
			int ttemp=1000;
			string temp_check="";
			check.open("acc_no.txt",ios::in);
			while(!check.eof()){
				getline(check,temp_check);
				ttemp++;
			}
			check.close();
			return ttemp;
		}
		void save_data(){
			fstream sd;
			sd.open("account.txt",ios::app);
			sd<<"Account no \t:\t\t"<<acc_no<<endl;
			sd<<"Holder Name is \t:\t\t"<<name<<endl;
			sd<<"Secend Name is \t:\t\t"<<sname<<endl;
			sd<<"Money Availavle :\t\t"<<money<<endl;
			sd<<"Account Type\t:\t\t"<<type<<endl;
			sd<<"Phone no is\t:\t\t"<<phone<<endl;
			sd<<"***********************************************"<<endl;
			sd.close();
			if(type=="Current"){
				sd.open("Current_account.txt",ios::app);
			}else{
				sd.open("Saving_account.txt",ios::app);
			}
			sd<<"Account no \t:\t\t"<<acc_no<<endl;
				sd<<"Holder Name is \t:\t\t"<<name<<endl;
				sd<<"Secend Name is \t:\t\t"<<sname<<endl;
				sd<<"Money Availavle :\t\t"<<money<<endl;
				sd<<"Account Type\t:\t\t"<<type<<endl;
				sd<<"Phone no is\t:\t\t"<<phone<<endl;
				sd<<"***********************************************"<<endl;
				sd.close();
			sd.open("acc_no.txt",ios::app);
				sd<<acc_no<<endl;
			sd.close();
		}
		int find(){
			if(status==1){
				return acc_no;
			}
		}
		void deposit(){
				long long mon=0;
				cout<<"Enter Money :=> ";
				cin>>mon;
				money=money+mon;
				cout<<"Money Transfer Successfull\n";
				modi(acc_no,type,money);
				cout<<"Enter Any Key...:=> ";
				getch();
				system("CLS");
		}
		void show_data(){
			if(status==1){
				cout<<"#    "<<acc_no<<"\t\t"<<name<<"\t"<<type<<"\t\t"<<phone<<"\t\t"<<money<<endl;
			}else{
				cout<<"Account Closed\n";
			}
		}
		void show_data2(string a){
			if(type==a){
				if(status==1){
					cout<<"#    "<<acc_no<<"\t\t"<<name<<"\t"<<type<<"\t\t"<<phone<<"\t\t"<<money<<endl;
				}else{
					cout<<"ACCOUTN CLOSED\n";
				}
			}
		}
		void withdraw(int a){
			if(pin==a){
				long long withdraw=0;
				cout<<"Enter Money :=> ";
				cin>>withdraw;
				if(money>withdraw){
					money=money-withdraw;
					cout<<"CASH OUT SUCCESSFULL\n";
					cout<<"Remaining Blance = "<<money<<endl;
					modi(acc_no,type,money);
				}else{
					cout<<"Remaining Balance is less then you want\n";
				}
				cout<<"Enter any Key...:=> ";
				getch();
			}else{
				cout<<"Wrong Pin Code.";
				for(int x=0;x<5;x++){
					cout<<".";
					Sleep(500);
				}
			}
		}
		void modi(int account,string status,long long money=0){
			int a=0;
			stringstream sa,sm,sp;
			string temp_get[100],temp="Account no \t:\t\t",temp2,temp3,smoney,sphone;
			fstream accget,ac,accget2,ac2;
			sa<<account;
			sa>>temp2;
			sm<<money;
			sm>>smoney;
			accget.open("account.txt");
			temp3=temp+temp2;
				while(!accget.eof()){
					getline(accget,temp_get[a]);
					if(temp3==temp_get[a]){
						if(money==0){
							sp<<phone;
							sp>>sphone;
							a++;
							getline(accget,temp_get[a]);
							temp_get[a]="Holder Name is \t:\t\t"+name;
							a++;
							getline(accget,temp_get[a]);
							temp_get[a]="Second Name is \t:\t\t"+sname;
							a++;
							getline(accget,temp_get[a]);
							a++;
							getline(accget,temp_get[a]);
							a++;
							getline(accget,temp_get[a]);
							temp_get[a]="Phone no is\t:\t\t"+sphone;
						}else{
							a++;
							getline(accget,temp_get[a]);
							a++;
							getline(accget,temp_get[a]);
							a++;
							getline(accget,temp_get[a]);
							temp_get[a]="Money Availavle :\t\t"+smoney;
						}
					}
					a++;
				}
				accget.close();
				ac.open("account.txt",ios::out);
				for(int x=0;x<a;x++){
					ac<<temp_get[x]<<endl;
				}
				ac.close();
				a=0;
				///////////////////////////////////////
				if(status=="Current"){
						accget2.open("Current_account.txt");
					}else{
						accget2.open("Saving_account.txt");
					}
					temp3=temp+temp2;
					while(!accget2.eof()){
					getline(accget2,temp_get[a]);
					if(temp3==temp_get[a]){
						if(money>0){
							a++;
							getline(accget2,temp_get[a]);
							a++;
							getline(accget2,temp_get[a]);
							a++;
							getline(accget2,temp_get[a]);
							temp_get[a]="Money Availavle :\t\t"+smoney;
						}else{
							a++;
							getline(accget2,temp_get[a]);
							temp_get[a]="Holder Name is \t:\t\t"+name;
							a++;
							getline(accget2,temp_get[a]);
							temp_get[a]="Second Name is \t:\t\t"+sname;
							a++;
							getline(accget2,temp_get[a]);
							a++;
							getline(accget2,temp_get[a]);
							a++;
							getline(accget2,temp_get[a]);
							temp_get[a]="Phone no is\t:\t\t"+sphone;
						}
					}
					a++;
				}
				accget2.close();
				if(status=="Current"){
					ac2.open("Current_account.txt",ios::out);
				}else{
					ac2.open("Saving_account.txt",ios::out);
				}
				for(int x=0;x<a;x++){
					ac2<<temp_get[x]<<endl;
				}
				ac2.close();
		}
		void mod(int a){
			if(a==pin){
				cout<<"Enter New Name ";
				cin>>name;
				cout<<"Enter Secend Name ";
				cin>>sname;
				cout<<"Enter New Phone ";
				cin>>phone;
				cout<<"Enter New pin ";
				cin>>pin;
				cout<<"Please Wait.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
				cout<<"Record Updated\n";
				modi(acc_no,type);
				cout<<"Enter Any Button :=> ";
				getch();
			}else{
				cout<<"Wrong Pin Code\n";
				cout<<"Going to Main Menu.";
				for (int x=0;x<6;x++){
					cout<<".";
					Sleep(500);
				}
			}
		}
		void balance(int a){
			if(a==pin){
				cout<<"Your Available Balance is "<<money<<endl;
				cout<<"Enter Any Button :=> ";
				getch();
			}else{
				cout<<"Wrong Pin Code\nGoing to Main Menu.";
				for(int x=0;x<7;x++){
				cout<<".";
				Sleep(500);
			}
			}
		}
		string del(int a){
			if(a==pin){
				string temp;
				cout<<"Type yes for confrm \n";
				cin>>temp;
				if(temp=="Yes"||temp=="yes"){
					status=0;
					return temp;
				}else{
					status=1;
					return "No";
				}
			}else{
				cout<<"Wrong Pin Code...!\n";
				return "Wrong";
			}
		}
		void allbank(){
			ifstream accget;
			accget.open("account.txt");
			string temp_get;
				while(!accget.eof()){
					getline(accget,temp_get);
					cout<<temp_get<<endl;
				}
			accget.close();
		}
		int pinss(int tempacc){
			if(tempacc==acc_no){
				if(status==1){
					cout<<"=========================================================================================\n";
					cout<<"# Account No \t\t Name \t\t Phone \t\t Pin#\n";
					cout<<"=========================================================================================\n";
					cout<<"#    "<<acc_no<<"\t\t"<<name<<"\t\t"<<phone<<"\t\t"<<pin<<endl;
					return 1;
				}else{
					cout<<"=========================================================================================\n";
					cout<<"# Account No \t\t Name \t\t Phone \t\t Pin#\n";
					cout<<"=========================================================================================\n";
					cout<<"Account Closed    "<<endl;
					return 1;
				}
			}else{
				return 0;
			}
		}
		void pins(){
			if(status==1){
				cout<<"#    "<<acc_no<<"\t\t"<<name<<"\t\t"<<phone<<"\t\t"<<pin<<endl;
			}else{
				cout<<"#  Account Closed  "<<endl;
			}
		}
		account* operator +(account *op){
			account *temacc;
			temacc->money=money+op->money;
			return temacc;
		}
		void tst(){
			cout<<"Total customer money : "<<money<<endl;
			pro=bankmoney-money;
			if(pro>0){
				cout<<"Bank is on Profit\n";
			}else{
				cout<<"Bank is on Loss\n";
			}
		}
		virtual void get_data(){};
};
class saving:public account{
	public:
		void get_data(){
			cout<<"Enter Name :=> ";
			cin>>name;
			cout<<"Enter Second Name :=>";
			cin>>sname;
			cout<<"Enter Phone :=> ";
			cin>>phone;
			type="Saving";
			cout<<"Enter Pin :=> ";
			cin>>pin;
			money:
			cout<<"Enter Money Minimum 500 :=> ";
			cin>>money;
			if(money<500){
				cout<<"Please Add More Money minium 500 :=> ";
				cout<<"Going back.";Sleep(500);cout<<".";Sleep(500);cout<<".";
				goto money;
			}
			system("CLS");
			cout<<"PLEASE WAIT.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
		}
};
class current:public account{
	public:
		void get_data(){
			cout<<"Enter Name :=>";
			cin>>name;
			cout<<"Enter Second Name :=>";
			cin>>sname;
			cout<<"Enter Phone :=>";
			cin>>phone;
			cout<<"Enter Pin :=>";
			cin>>pin;
			type="Current";
			money:
			cout<<"Enter Money Minimum 1000 :=>";
			cin>>money;
			if(money<1000){
				cout<<"Please Add More Money minium 1000 :=>";
				cout<<"Going bsck.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
				goto money;
			}
			system("CLS");
			cout<<"PLEASE WAIT.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
		}
};
int main()
{
	system("CLS");
	login l1;
	string user="",pas="";
	cout<<"Enter username :=> ";
	cin>>user;
	if(user=="unknown"){
		cout<<"Enter password :=> ";
		cin>>pas;
		l1.logcheck(pas);
	}else if(user=="admin"){
		cout<<"Enter password :=> ";
		cin>>pas;
		l1.logcheck(pas,user);
	}else{
		cout<<"WRONG UNSERNAME\nGoing Login Page.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(300);
				}
		main();
	}
	return 0;
}
int mainn()
{
	system("color 70");
	account *ptr[10],*opr;
	string status="";
	int a=0,count=0,b=0,acc=0,get=0,pin=0,c=0;
	mainstart:
	system("CLS");
	cout<<"\t\t***************************************************************\n";
    cout<<"\t\t***************************************************************\n";
    cout<<"\t\t*****                    BANK SYSTEM                      *****\n";  
    cout<<"\t\t*****     REHAN MALIK    ABDULLAH TARIQ    HAMZA BUTT     *****\n";
    cout<<"\t\t***************************************************************\n";
    cout<<"\t\t***************************************************************\n\n";
	cout<<"\t\t[1] For New Account \n\t\t[2] For Deposit\n\t\t[3] for Withdraw \n\t\t[4] for Balance Enquiry\n";
	cout<<"\t\t[5] For Modification \n\t\t[6] for close account\n";
	if(sec==2){
		cout<<"\t\t[7] for show all account details\n\t\t[8] for Pins \n\t\t[9] for total ban amount and customers amount\n";
	}
	cout<<"\t\t[0] for Exit \n\t\t[11] for Log Out\n";
	cout<<"\n\n\t\t:=>";
	cin>>a;
	switch(a){
		case 1:
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                  NEW CUSTOMER MENU                  *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"\t\t[1] for Saving Account \n\t\t[2] for Current Account \n\n\t\t:=>";
			cin>>b;
			switch(b){
				case 1:
					system("CLS");
					cout<<"\t\t***************************************************************\n";
					cout<<"\t\t*****                    SAVING ACCOUNT                   *****\n";
					cout<<"\t\t***************************************************************\n\n\n";
					ptr[count]=new saving;
					ptr[count]->acccrt();
					count++;
					goto mainstart;
					break;
				case 2:
					system("CLS");
					cout<<"\t\t***************************************************************\n";
					cout<<"\t\t*****                   CURRENT ACCOUNT                   *****\n";
					cout<<"\t\t***************************************************************\n\n\n";
					ptr[count]=new current;
					ptr[count]->acccrt();
					count++;
					goto mainstart;
					break;
				default:
					cout<<"\t\tWrong Input \n\t\tGoing To Main Menu.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
					goto mainstart;
			}
		case 2:
			system("CLS");
			b=0;
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                     DEPOSET MENU                    *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"Enter Account Number :=>";
			cin>>acc;
			for(int x=0;x<count;x++){
				get=ptr[x]->find();
				if(get==acc){
					ptr[x]->deposit();
					b=1;
					cout<<"Please Wait.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
					break;
				}
			}
			if(b==0){
				cout<<"Wrong Account Number...!\n";
				cout<<"Going to Main Menu.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
			}
			goto mainstart;
		case 3:
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                    WITHDRAW MENU                    *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"Enter Account Number :=> ";
			cin>>acc;
			b=0;
			for(int x=0;x<count;x++){
				get=ptr[x]->find();
				if(get==acc){
					cout<<"Enter Pin :=>";
					cin>>pin;
					ptr[x]->withdraw(pin);
					b=1;
					break;
				}
			}
			if(b==0){
				cout<<"Wrong Account Number...!\n";
				cout<<"Going to Main Menu.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
			}
			goto mainstart;
		case 4:
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                   Balance Inquiry                   *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"Enter Account Number :=>";
			cin>>acc;
			b=0;
			for(int x=0;x<count;x++){
				get=ptr[x]->find();
				if(get==acc){
					cout<<"Enter Pin :=>";
					cin>>pin;
					ptr[x]->balance(pin);
					b=1;
					break;
				}
			}
			if(b==0){
				cout<<"Wrong Account Number...!\n";
				cout<<"Going to Main Menu.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
			}
			goto mainstart;
		case 5:
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                  Modification MENU                  *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"Enter Account Number :=>";
			cin>>acc;
			b=0;
			for(int x=0;x<count;x++){
				get=ptr[x]->find();
				if(get==acc){
					cout<<"Enter Pin :=>";
					cin>>pin;
					ptr[x]->mod(pin);
					b=1;
					break;
				}
			}
			if(b==0){
				cout<<"Wrong Account Number...!\n";
				cout<<"Going to Main Menu.";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<".\n";
			}
			goto mainstart;
		case 6:
			status="";
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                 ACCOUNT CLOSING MENU                *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"Enter Account Number :=> ";
			cin>>acc;
			b=0;
			for(int x=0;x<count;x++){
				get=ptr[x]->find();
				if(get==acc){
					cout<<"Enter Pin :=> ";
					cin>>pin;
					status=ptr[x]->del(pin);
					get=x;
					b=1;
					break;
				}
			}
			if(status=="yes"||status=="Yes" && b==1){
				cout<<"Account Closed.\n";
				cout<<"Going to Main Menu.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(500);
				}
			}else if(b==1 && status=="No"){
				cout<<"You cancled the closed request\nGoting to Main Menu.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(500);
				}
			}
			else if(status==""){
				cout<<"Wrong Account Number\nGoing to Main menu.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(500);
				}
				goto mainstart;
			}else{
				cout<<"Going to Main Menu";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(500);
				}
			}
			goto mainstart;
		case 7:
		if(sec==2){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                     Record MENU                     *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			b=0;
			cout<<"\t\t[1] for All Account\n\t\t[2] for all Current Accounts \n\t\t[3] for all saving Accounts\n\t\t[4] for all bank Accounts\n\n\n\t\t:=>";
			cin>>b;
			switch(b){
				case 1:
					system("CLS");
					cout<<"\t\t***************************************************************\n";
					cout<<"\t\t*****                     ALL Records                     *****\n";
					cout<<"\t\t***************************************************************\n\n\n";
					cout<<"=========================================================================================\n";
					cout<<"# Account No \t\t Name \t\t Type \t\t Phone \t\t Money #\n";
					cout<<"=========================================================================================\n";
					for(int x=0;x<count;x++){
						ptr[x]->show_data();
					}
					break;
				case 2:
					system("CLS");
					cout<<"\t\t***************************************************************\n";
					cout<<"\t\t*****                Current Account Records              *****\n";
					cout<<"\t\t***************************************************************\n\n\n";
					status="Current";
					cout<<"=========================================================================================\n";
					cout<<"# Account No \t\t Name \t\t Type \t\t Phone \t\t Money #\n";
					cout<<"=========================================================================================\n";
					for(int x=0;x<count;x++){
						ptr[x]->show_data2(status);
					}
					break;
				case 3:
					system("CLS");
					cout<<"\t\t***************************************************************\n";
					cout<<"\t\t*****                Saving Account Records               *****\n";
					cout<<"\t\t***************************************************************\n\n\n";
					status="Saving";
					cout<<"=========================================================================================\n";
					cout<<"# Account No \t\t Name \t\t Type \t\t Phone \t\t Money #\n";
					cout<<"=========================================================================================\n";
					for(int x=0;x<count;x++){
						ptr[x]->show_data2(status);
					}
					break;
				case 4:
					system("CLS");
					cout<<"\t\t***************************************************************\n";
					cout<<"\t\t*****                  ALL BANK ACCOUNTS                  *****\n";
					cout<<"\t\t***************************************************************\n\n\n";
					cout<<"All Bank Accounts\n";
					ptr[count]->allbank();
					break;
				default:
					cout<<"Wrong Input\n";
			}
			cout<<"Enter Any Key...:=>";
			getch();
			goto mainstart;
		}else{
			cout<<"Access Denied\nGoing to Main Menu.";
			for(int x=0;x<7;x++){
				cout<<".";
				Sleep(500);
			}
		}
		goto mainstart;
		case 8:
		if(sec==2){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                      PIN MENU                       *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"\t\tEnter All Pin\n";
			cout<<"\t\tEnter 1 for a spacfic account\n\t\tEnter 2 for all accounts\n\n\t\t:=>";
			cin>>b;
			if(b==1){
				cout<<"Enter Account Number :=> ";
				cin>>acc;
				for(int x=0;x<count;x++){
					c=ptr[x]->pinss(acc);
				}
				if(c==1){
					cout<<"Enter An button :=>";
					getch();
				}else{
					cout<<"Wrong Account Number \n";
					cout<<"Going to Main Menu.";
					for(int x=0;x<6;x++){
						cout<<".";
						Sleep(500);
					}
				}
			}else if(b==2){
				cout<<"=========================================================================================\n";
				cout<<"# Account No \t\t Name \t\t Phone \t\t Pin#\n";
				cout<<"=========================================================================================\n";
				for(int x=0;x<count;x++){
					ptr[x]->pins();
				}
				cout<<"Enter Any Key...:=> ";
				getch();
			}else{
				cout<<"Wrong Input\n";
				cout<<"Going to Main Menu.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(500);
				}
			}
			goto mainstart;
		}else{
			cout<<"Access Denied\nGoing to Main Menu";
			for(int x=0;x<7;x++){
				cout<<".";
				Sleep(500);
			}
		}
		goto mainstart;
		case 9:
		if(sec==2){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                   BANK CASH MENU                    *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			opr= new account;
			for(int x=0;x<count;x++){
				opr=opr->operator +(ptr[x]);
			}
				cout<<"TOTAL BANK MONEY : "<<bankmoney<<endl;
				opr->tst();
				cout<<"Enter Any Key...:=> ";
				getch();
				goto mainstart;
			}else{
				cout<<"Access Denied\nGoing to Main Menu.";
				for(int x=0;x<7;x++){
					cout<<".";
					Sleep(500);
				}
			}
			goto mainstart;
		case 0:
			cout<<"LogOut.";
			for(int x=0;x<7;x++){
				cout<<".";
				Sleep(500);
			}
			system("CLS");
			cout<<"\t\t**************************[EXIT]*****************************\n";
			cout<<"\t\t*******************   [SPARTAN'S GROUP]    ******************\n";
			cout<<"\t\t*** REHAN MALIK(066), ABDULLAH TARIQ(088),HAMZA BUTT(060) ***\n";
			cout<<"\t\t*************************************************************\n";
			cout<<"\t\t*************************************************************\n\n\n";
			break;
		case 11:
			sec=0;
			system("CLS");
			cout<<"\t\t************************[LOG OUT]****************************\n";
			cout<<"\t\t*******************   [SPARTAN'S GROUP]    ******************\n";
			cout<<"\t\t*** REHAN MALIK(066), ABDULLAH TARIQ(088),HAMZA BUTT(060) ***\n";
			cout<<"\t\t*************************************************************\n";
			cout<<"\t\t*************************************************************\n\n\n";
			cout<<"PLEASE WAIT.";
			for(int x=0;x<7;x++){
				cout<<".";
				Sleep(500);
			}
			system("color 07");
			main();
			break;
		default:
			cout<<"Wrong Input \nGoing To Main Menu.";
			for(int x=0;x<7;x++){
				cout<<".";
				Sleep(500);
			}
			goto mainstart;
	}
	return 0;
}
