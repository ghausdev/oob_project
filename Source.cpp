
#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include "Header.h"
#include<fstream>
#include<time.h>
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>

using namespace std;



int main() {
	system("COLOR f0");

	
	Admin * a = new Admin(22, "Ghaus", "Malik", "1234123412343", "ghaus123", "Ghaus123.com");
	

 
		
   NAFS ad;
   ad.set_ADM(a,1);

	

	char co;

	


	bool exit = 1;
	int ch;
	cout << "\t\t\t\t##################################################" << endl;
	cout << "\t\t\t\t#                    Airline                     #" << endl;
	cout << "\t\t\t\t#                MANAGEMENT SYSTEM               #" << endl;
	cout << "\t\t\t\t##################################################" << endl;
	cout << endl << endl;
	bool exitProgram = false;// Flag to exit the program
	while (!exitProgram)
	{
		cout << R"(
                       1. Admin Panel
                       2. Passenger Panel
                       3. Schedule
                       4. Exit
                   )" << endl;


		try {
			cin >> co;
			if (!cin)
				throw 1;
		}
		catch (int x) {
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		system("cls");
		switch (co)
		{
		case '1':
		{
			bool managerMenu = true; 
			while (managerMenu)
			{
				cout << endl << endl;
				cout << "\n1: Create Account ";
				cout << "\n2: Login ";
				cout << "\n3: Back to Main Menu\n";
				cout << endl;

				try {
					cin >> ch;
					if (!cin)
						throw 1;
				}
				catch (int x) {
					cout << "Invalid Input" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}

				switch (ch)
				{
				case 1:
					system("cls");
					ad.add_admin();
					
					system("cls");
					break;
				case 2:

					system("cls");
					ad.login_admin();
					
					system("cls");
					break;
				case 3:
					
					system("cls");
					managerMenu = false;
					break;


				default:
					cout << "Invalid Choice" << endl;
					break;
				}
			}
			break;
		}
		case '2':
		{
			bool salesMenu = true; 
			while (salesMenu)
			{
				cout << endl << endl;
				cout << "\n1: Create Account";
				cout << "\n2: Login";
				cout << "\n3: Back to Main Menu\n";

				try {
					cin >> ch;
					if (!cin)
						throw 1;
				}
				catch (int x) {
					cout << "Invalid Input" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}
				switch (ch)
				{
				case 1:
					system("cls");
					ad.add_passenger();
					
				
					system("cls");
					break;
				case 2:
					
					system("cls");
					ad.login_passenger();
					
					
					system("cls");
					break;
				case 3:
					
					system("cls");
					salesMenu = false;
					break;
				default:
					cout << "Invalid Choice" << endl;
					break;
				}
			}
			break;
		}
		case '3':
			ad.schedule();
			cout<<"\n\t\t\t\tPress Enter to go back to Main Menu............................."<<endl;
			Sleep(1000);
			
		  _getch();
			system("cls");
			break;
		case '4':
			cout << "Thank you, GoodBye" << endl;
			exitProgram = true;
			Sleep(1000);
			system("cls");
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
	}


    return 0;
}

