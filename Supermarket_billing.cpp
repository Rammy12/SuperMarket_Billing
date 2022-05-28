#include<iostream>
#include<fstream>
using namespace std;
class shopping 
{
	int pcode;
	float price;
	float dis;
	string pname;
public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();

};
//menu function
void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t\t _______________________________________\n";
	cout<<"\t\t\t\t|                                       |\n";
	cout<<"\t\t\t\t|        Supermarket Main Menu          |\n";
	cout<<"\t\t\t\t|                                       |\n";
	cout<<"\t\t\t\t|_______________________________________|\n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t\t|   1.)Administrator    |\n";
	cout<<"\t\t\t\t\t|                       |\n";
	cout<<"\t\t\t\t\t|   2.)Buyer            |\n";
	cout<<"\t\t\t\t\t|                       |\n";
	cout<<"\t\t\t\t\t|   3.)Exit             |\n";
	cout<<"\t\t\t\t\t|                       |\n";
	cout<<"\t\t\t\t\t     Please Select!      \n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			cout<<"\t\t\t Plese login   \n";
		    cout<<"\t\t\t Enter Email   \n";
		    cin>>email;
		    cout<<"\t\t\t    Password   \n";
		    cin>>password;
		    if(email=="ramesh@email.com" && password=="Ramesh@123")
		    {
			    administrator();
		    }
		    else
		   {
			    cout<<"Invalid Username/Password";
		   }
		   break;
		}
		case 2:
		{
			buyer();
		}
		case 3:
		{
			exit(0);
		}
		default:
		{
			cout<<"Please Select given options";
		}


	}
	goto m;
}
//administrator function
void shopping:: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|_______1.) Add the Product____|";
	cout<<"\n\t\t\t|                              |";
	cout<<"\n\t\t\t|_______2.) Modify the Product_|";
	cout<<"\n\t\t\t|                              |";
	cout<<"\n\t\t\t|_______3.) Delete the Product_|";
	cout<<"\n\t\t\t|                              |";
	cout<<"\n\t\t\t|_______4.) Back to main manu__|";
	cout<<"\n\t\t\t|                              |";

	cout<<"\n\n\t Please Enter the choice\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			add();
			break;
		}
		case 2:
		{
			edit();
			break;
		}
		case 3:
		{
			rem();
			break;
		}
		case 4:
		{
			menu();
			break;
		}
		default:
		{
			cout<<"Invalid choice";
		}
	}
	goto m;
}
//buyer function
void shopping:: buyer()
{ 
	m:
	int choice;
	cout<<"\t\t\t Buyer \n";
	cout<<"\t\t\t____________________ \n";
	cout<<"                           \n";
	cout<<"\t\t\t| 1.) Buy Product   |\n";
	cout<<"                           \n";
	cout<<"\t\t\t| 2.) Go Back       |\n";
	cout<<"                           \n";
	cout<<"\t\t\t Enter Your choice : \n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			receipt();
			break;
		}
		case 2:
		{
			menu();
			break;
		}
		default:
		{
			cout<<"Invalid choice";
		}
	}
	goto m;
}
//add function
void shopping:: add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;

	cout<<"\n\n\t\t\t Add new product ";
	cout<<"\n\n\t Product code of the product \n";
	cin>>pcode;
	cout<<"\n\n\t Name of the product \n";
	cin>>pname;
	cout<<"\n\n\t price of the product \n";
	cin>>price;
	cout<<"\n\n\t Discount of the product \n";
	cin>>dis;

	data.open("database.txt",ios::in);
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();

	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
	if(token==1)
	{
		goto m;
	}
	else
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
   }
	cout<<"record insrted";
}
//edit function
void shopping:: edit()
{
	fstream data;
	fstream data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t product Code";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n file doesn't exist ";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t product new code";
				cin>>c;
				cout<<"\n\t\t name of the product";
				cin>>n;
				cout<<"\n\t\t price";
				cin>>p;
				cout<<"\n\t\t Discount";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t Record edited";
				token++;

			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found Sorry!";
		}
	}

	
}
void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t product code";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesn't exist";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");

		if(token==0)
		{
			cout<<"\n\n\t Record not found";
		}
	}

}
void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n______________________________________________________________________\n";
	cout<<"Product Code \t Product Name \t Price \t Discount";
	cout<<"\n\n______________________________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}
void shopping:: receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;

	cout<<"\n\n\t\t\t           RECEIPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	else
	{
		data.close();
		list();
		cout<<"\n ______________________________________________________________________\n";
		cout<<"\n|                                                                     |\n";
		cout<<"\n|                       Plese Place The Order                         |\n";
		cout<<"\n|                                                                     |\n";
		cout<<"\n|_____________________________________________________________________|\n";
		do
		{
			m:
			cout<<"\n\n Enter product code \n";
			cin>>arrc[c];
			cout<<"\n\n Enter product Quantity \n";
			cin>>arrq[c];
			for(int i=0; i<c; i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n dublicate product code plese try again";
					goto m;
				}
			}
			c++;
			cout<<"\n\n do you want to buy another product? if yes than plese press y else no\n";
			cin>>choice;
		}
		while(choice=='y');
		cout<<"\n\n\t\t_____________________RECEIPT____________________";
		cout<<"\n Product No\tProduct name\tProduct Quantity\tPrice\t Amount \tAmount With Discount\n";
		for(int i=0; i<c; i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;

				}
				data>>pcode>>pname>>price>>dis;
			}

		}
		data.close();

	}
	cout<<"\n\n_____________________________________________";
	cout<<"\n Total Amount :"<<total<<"\n";

}

int main()
{
	shopping s;
	s.menu();
	return 0;
} 