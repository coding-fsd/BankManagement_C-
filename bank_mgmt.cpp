#include<iostream>
#include<fstream>
using namespace std;

class Bank 
{
	public: 
    	string name,acctype;
    	int deposit,withdraw,balance,accno=0,lines=1;
    	void deposit1();
    	void withdraw1(); 
    	void display();
    	void create ()
    	{
    		accno++;
		cout<<"\nEnter Name: ";
		cin>>name;
		cout<<"Enter Account Type(Savings/Current): ";
		cin>>acctype;
		cout<<"Enter Balance: ";
		cin>>balance;
		ofstream file("database.txt",ios::app);
		file <<accno<<"\t\t"<<name<<"\t"<<acctype<<"\t\t"<<balance<<"\n";
		lines=lines+1;
		file.close();
		cout<<"\nAccount Created Successfully with Account Number being: "<<accno<<endl;
    	}
};

void Bank :: deposit1()
{
	string str;
	int num,line_no,flag=0;
	num=accno;
	cout<<"\nEnter Amount that is to be deposited: ";
	cin>>deposit;
	str=num;
	try
	{
		if(deposit<=0)
		{
			throw deposit;
		}
		else
		{
			fstream file("database.txt",ios::in|ios::binary|ios::out);
			balance=balance+deposit;
			for(int i=1;getline(file,str) && i<lines;i++)
			{
				if(i==num)
				{
					flag=1;
					break;
				}
					
			}
			if(flag==1)
			{
				cout<<"\nAmount Successfully deposited";
				cout<<"\nUpdated Balance is: "<<balance<<endl;
				file <<accno<<"\t\t"<<name<<"\t"<<acctype<<"\t\t"<<balance<<"\n";
			}
			else
			{
				cout<<"Account Not Found";
			}
			file.close();
		}
	}
	catch(int x)
	{
		cout<<"\nAmount cannot be less than or equal to 0";
		deposit1();
	}
}

void Bank :: withdraw1()
{
	string str;
	int num,line_no,flag=0;
	num=accno;
	cout<<"\nEnter Amount that is to be withdrawn: ";
	cin>>withdraw;
	str=num;
	try
	{
		if(withdraw<=0||withdraw>balance)
		{
			throw withdraw;
		}
		else
		{
			fstream file("database.txt",ios::in|ios::binary|ios::out);
			balance=balance-withdraw;
			for(int i=1;getline(file,str) && i<lines;i++)
			{
				if(i==num)
				{
					flag=1;
					break;
				}
					
			}
			if(flag==1)
			{
				cout<<"\nAmount Successfully withdrawn";
				cout<<"\nUpdated Balance is: "<<balance<<endl;
				file <<accno<<"\t\t"<<name<<"\t"<<acctype<<"\t\t"<<balance<<"\n";
			}
			else
			{
				cout<<"Account Not Found";
			}
			file.close();
		}
	}
	catch(int x)
	{
		cout<<"\nAmount cannot be less than or equal to 0/Amount cannot be greater than the balance available";
		withdraw1();
	}
}

void Bank :: display ()
{
	Bank b1;
	ifstream file("database.txt",ios::in|ios::binary);
	string line;
    	if (file.is_open())
    	{
		while (getline (file,line))
		{
			cout << line << '\n';
		}
		file.close();
    	}
}

int main()
{
	Bank b;
	ofstream file("database.txt");
	file <<"Account Number\tName\tAccount Type\tBalance\n";
	file.close();
	int ch,ch1;
	cout<<"\n-----------Welcome to IDFC Bank----------------"<<endl;
	b.create();
	do
	{	
		cout<<"\n1)Deposit 2)Withdraw 3)Display 4)Logout: ";
        	cin>>ch;
        	switch (ch)
        	{

           		case 1: b.deposit1();
                        	 break;
                        	 
            		case 2: b.withdraw1();
                        	break;
                        	
            		case 3: b.display();
                        	 break;
                        	 
            		case 4: cout<<"Thank you!\n";
            			break;
            		
            		default: cout<<"Invalid Choice";
            			 break;
            		
        	}  
        }while(ch!=4);
        return 0;
}
