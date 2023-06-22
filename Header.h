#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
using namespace std;
 
bool VerifyFinancialDetail(string card_holder_name, string card_number, string expiry_date, string cvv)
{
    if (card_holder_name.length() < 3)
    {
        cout << "Invalid card holder name" << endl;
        return false;
    }
    if (card_number.length() != 16)
    {
        cout << "Invalid card number" << endl;
        return false;
    }
    if (expiry_date.length() != 5)
    {
        cout << "Invalid expiry date" << endl;
        return false;
    }
    if (cvv.length() != 3)
    {
        cout << "Invalid CVV" << endl;
        return false;
    }
    return true;
}

class account
{
public:
    string First;
    string Second;
    string usernames;
    string password;
    int age;
    string cnic;
    string card_number, card_holder_name, expiry_date, cvv;
    bool dependant;
    double prize;
   
    

public:

   string get_card_number() { return card_number; }
   string get_card_holder_name() { return card_holder_name; }
   string get_expiry_date() { return expiry_date; }
   string get_cvv() { return cvv; }
    account()
    {
		First = "";
        Second = "";
		usernames = "";
		password = "";
		age = 0;
		cnic = "";
	}

    account& operator=(const account& other)
    {
       
			this->First = other.First;
            this->Second = other.Second;
			this->usernames = other.usernames;
			this->password = other.password;
			this->age = other.age;
			this->cnic = other.cnic;
		
		return *this;
	}


    string getpassword()
    {
        string pass = "";  // store the password string
        char ch;  // store the user's input character

        cout << "Enter your password: ";

        // loop until user presses the Enter key
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b') {  // handle backspace key
                if (!pass.empty()) {
                    pass.pop_back();  // remove the last character from password string
                    _putch('\b');  // move the cursor back one position
                    _putch(' ');  // overwrite the character with a blank space
                    _putch('\b');  // move the cursor back one position again
                }
            }
            else {
                pass += ch;  // add the input character to password string
                _putch('*');  // print an asterisk on the console
            }
        }
        return pass;
    }

    virtual void print()
    {

    }

    void acc(string First, string Second ,string usernames, string password, int age, string cnic)
    {
        this->First = First;
        this->Second = Second;
		this->usernames = usernames;
		this->password = password;
		this->age = age;
		this->cnic = cnic;
	}
    

    //getters
    string get_first() { return First; }
    string get_second() { return Second; }
    string get_usernames() { return usernames; }
    string get_password() { return password; }
    int get_age() { return age; }
    string get_cnic() { return cnic; }
    //setters
    void set_first(string First) { this->First = First; }
    void set_second(string Second) { this->Second = Second; }
    void set_usernames(string usernames) { this->usernames = usernames; }
    void set_password(string password) { this->password = password; }
    void set_age(int age) { this->age = age; }
    void set_cnic(string cnic) { this->cnic = cnic; }

    void register_user(string first, string second, string cnic, string usernames , bool b)
    {

        this->First = first;
        this->Second = second;
        this->cnic = cnic;
        this->usernames = usernames;
        cout << "Enter your age: ";
        cin >> age;
        Password();
        cout << "Account Create Successfully";
        if (b)
        {
            cout << endl;  addfin();
            
        }
        
    }
    // verify age
    void verify_age()
    {
     
        if (!dependant)
        {
            while (age <= 17)
            {
				cout << "You have entered an invalid age" << endl;
				cout << "Enter your age: ";
				cin >> age;
			}
		}
        else
        {
            while (age >= 18)
            {
				cout << "You have entered an invalid age" << endl;
				cout << "Enter your age: ";
				cin >> age;
			}
		}

       



    }
    // functin for password
    void Password()
    {
        string verify;
        cout << "\nEnter password: \n";
        password = getpassword();
       


       

        while (!verify_password(password))
        {
            cout << "\nRe-Enter password: \n";
            password = getpassword();
        }

        try {
            if (password.length() < 8)
				throw "Password must be at least 8 characters long";
            // Check if password contains at least one special character
            bool has_special = false;
            for (char c : password) {
                if (!isalnum(c)) {

                    has_special = true;
                    break;
                }
            }
            if (!has_special) {
                throw  "Password must contain at least one special character.";  
            }

            bool has_upper = false;
            for (char c : password) {
                if (isupper(c)) {
                    has_upper = true;
                    break;
                }
            }
            if (!has_upper) {
                throw "Password must contain at least one uppercase letter.";
               
            }

            bool has_lower = false;
            for (char c : password) {
                if (islower(c)) {
                    has_lower = true;
                    break;
                }
            }
            if (!has_lower) {
                throw "Password must contain at least one lowercase letter." ;
                
            }

            bool has_digit = false;
            for (char c : password) {
                if (isdigit(c)) {

                    has_digit = true;
                    break;
                }
            }

            if (!has_digit) {
                throw "Password must contain at least one numeric digit.";
                
            }

        }
        catch (const char* msg) {
			cout << msg << endl;
			cout << "ReEnter password: ";
			cin >> password;
		}

        
        cout << "\nRe-enter password to verify ";
         verify= getpassword();
        while (password != verify)
        {
            cout << "Passwords do not match. Please try again." << endl;
            cin >> verify;
        }
        cout << "\nPassword verified." << endl;
    }


    bool verify_password(string pass)
    {
        // Check if password is 8 characters long
        if (pass.length() < 8) {
            cout << " Password Must has atleast 8 char. "<< endl;
            return false;
        }

        // Check if password contains at least one special character
        bool has_special = false;
        for (char c : pass) {
            if (!isalnum(c)) {

                has_special = true;
                break;
            }
        }
        if (!has_special) {
            cout << "Password must contain at least one special character." << endl;
            return false;
        }

        // Check if password contains at least one uppercase letter
        bool has_upper = false;
        for (char c : pass) {
            if (isupper(c)) {
                has_upper = true;
                break;
            }
        }
        if (!has_upper) {
            cout << "Password must contain at least one uppercase letter." << endl;
            return false;
        }

        // Check if password contains at least one lowercase letter
        bool has_lower = false;
        for (char c : pass) {
            if (islower(c)) {
                has_lower = true;
                break;
            }
        }
        if (!has_lower) {
            cout << "Password must contain at least one lowercase letter." << endl;
            return false;
        }

        // Check if password contains at least one numeric digit
        bool has_digit = false;
        for (char c : pass) {
            if (isdigit(c)) {

                has_digit = true;
                break;
            }
        }

        if (!has_digit) {
            cout << "Password must contain at least one numeric digit." << endl;
            return false;
        }

        return true;
    }

  



  


    void addfin()
    {

        int choice;


        cout << "Choose your payment method:" << std::endl;
        cout << "1. Visa" << std::endl;
        cout << "2. Mastercard" << std::endl;
        cout << "3. American Express" << std::endl;
        cout << "4. Paypal" << std::endl;
        cout << "Enter your choice (1-4): ";
        try {
            cin >> choice;
            if (!cin)
                throw 1;
        }
        catch (int x) {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }

        switch (choice) {
        case 1:
            cout << "You have chosen Visa" << endl;
            break;
        case 2:
            cout << "You have chosen Mastercard" << endl;
            break;
        case 3:
            cout << "You have chosen American Express" << endl;
            break;
        case 4:
            cout << "You have chosen Paypal" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;

        }

        cout << "Enter card holder name: ";
        cin.ignore();
        getline(std::cin, card_holder_name);
        cout << "Enter card number: ";
        cin >> card_number;
        cout << "Enter expiry date (MM/YY): ";
        cin >> expiry_date;
        cout << "Enter CVV: ";
        cin >> cvv;
        cout<< "Eenter Available Balance: ";
        cin >> prize;
        


        while (!VerifyFinancialDetail(card_holder_name, card_number, expiry_date, cvv))
        {
            cout << "Enter card holder name: ";
            cin.ignore();
            getline(std::cin, card_holder_name);
            cout << "Enter card number: ";
            cin >> card_number;
            cout << "Enter expiry date (MM/YY): ";
            cin >> expiry_date;
            cout << "Enter CVV: ";
            cin >> cvv;

        }

        cout << "Payment Method Added";

    }

};


class Admin : public account

{
public:
    Admin()
    {
		First = " ";
		Second = " ";
		cnic = " ";
		usernames = " ";
		password = " ";
	}
    // copy constructor
    Admin(const Admin& obj)
    {
		this->age = obj.age;
        this->First = obj.First;
        this->Second = obj.Second;
        this->cnic = obj.cnic;
        this->usernames = obj.usernames;
        this->password = obj.password;

    }
    // parameterized constructor
    Admin(int age, string first, string second, string cnic, string usernames, string password)
    {
        this->age = age;
		this->First = first;
		this->Second = second;
		this->cnic = cnic;
		this->usernames = usernames;
		this->password = password;
	}

    // function for edit te information
    void edit_information()
    {
        cout << "Choose What you want to edit: " << endl;
        cout << "1. First Name" << endl;
        cout << "2. Second Name" << endl;
        cout << "3. CNIC" << endl;
        cout << "4. Username" << endl;
        cout << "5. Age" << endl;
        cout << "6. Password" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;

        try {
            cin >> choice;
            if (!cin)
				throw 1;
        }
        catch (int x) {
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			return;
		}
        
        switch (choice)
        {
        case 1:
            cout << "Enter First Name: ";
            cin.ignore();
            getline(std::cin, First);
            break;
        case 2:
            cout << "Enter Second Name: ";
            cin.ignore();
            getline(std::cin, Second);
            break;
        case 3:
            cout << "Enter CNIC: ";
            cin.ignore();
            getline(std::cin, cnic);
            break;
        case 4:
            cout << "Enter Username: ";
            cin.ignore();
            getline(std::cin, usernames);
            break;
        case 5:
            cout << "Enter Age: ";
            cin >> age;


            break;
        case 6:
            cout << "Enter Password: ";
            cin.ignore();
            getline(std::cin, password);
            break;
 
        case 7:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    // functon for print the information
    void print()
    {
        // Print the user's personal information using a clean and simple format
        cout << "Personal Information" << endl;
        cout << "----------------------" << endl;
        cout << "First Name: " << First << endl;
        cout << "Last Name: " << Second << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Username: " << usernames << endl;
        cout << "Age: " << age << endl;
    }

   

};
class Passenger : public account
{ 
private:
    string Destination;
    string Departure;
    string date;
    string visa;
    string Passport;
    int ID;
   
    string dependant_name;
    string dependant_cnic;
    string dependant_relation;
    double ticket_prize;

public:


  
        Passenger()
        {
            Destination = " ";
			Departure = " ";
			date = " ";
            dependant = false;
        }


        Passenger(int age,string first, string second, string cnic, string usernames, string password, string card_holder_name, string card_number, string expiry_date, string cvv, double prize, string Destination="0", string Departure="0", string date = "0", string visa = "0", string Passport = "0") 
        {   
            this->age = age;
            this->First = first;
            this->Second = second;
            this->cnic = cnic;
            this->usernames = usernames;
            this->password = password;
            this->card_holder_name = card_holder_name;
            this->card_number = card_number;
            this->expiry_date = expiry_date;
            this->cvv = cvv;
            this->Destination = Destination;
            this->Departure = Departure;
            this->date = date;
            this->visa = visa;
            this->Passport = Passport;
            this->prize = prize;
            dependant = false;

		
        }

       
     // copy constructor
        Passenger(const Passenger& obj)
        {
			this->age = obj.age;
			this->First = obj.First;
			this->Second = obj.Second;
			this->cnic = obj.cnic;
			this->usernames = obj.usernames;
			this->password = obj.password;
			this->card_holder_name = obj.card_holder_name;
			this->card_number = obj.card_number;
			this->expiry_date = obj.expiry_date;
			this->cvv = obj.cvv;
			this->Destination = obj.Destination;
			this->Departure = obj.Departure;
			this->date = obj.date;
			this->visa = obj.visa;
			this->Passport = obj.Passport;
			this->prize = obj.prize;
			dependant = false;
		}
			
    
        void set_id(int id)
        {
			this->ID = id;
		}
        string getPassport() {
            return Passport;
        }
        string getVisa() {
			return visa;
		}
        void setPassport(string Passport) {
			this->Passport = Passport;
		}
        void setVisa(string visa) {
            this->visa = visa;
        }
        double getprize() {
			return prize;
		}
        void setprize(double prize) {
            this->prize = prize;
        }

        void setID(int ID) {
			this->ID = ID;
		}
        int getID() {
            return ID;
        }
        bool get_dependant() {
			return dependant;
		}
        void set_dependant(bool dependant) {
			this->dependant = dependant;
		}
        void set_dependant_name(string dependant_name) {
            this->dependant_name = dependant_name;
        }
        void set_dependant_cnic(string dependant_cnic) {
			this->dependant_cnic = dependant_cnic;
		}
        void set_dependant_relation(string dependant_relation) {
            this->dependant_relation = dependant_relation;
            }

        string get_dependant_name() {
            return dependant_name;

        }
        string get_dependant_cnic() {
			return dependant_cnic;
		}
        string get_dependant_relation() {
			return dependant_relation;
		}
        void set_ticket_prize(double ticket_prize) {
            this->ticket_prize = ticket_prize;
        }
        double get_ticket_prize() {
			return ticket_prize;
		}

        int get_id() {
			return ID;
		}
        
           
        void print() {
            cout << "+-------------------------------------------+\n";
            cout << "|             Passenger Information          |\n";
            cout << "+-------------------------------------------+\n";
            cout << "| First Name:      " << setw(24) << left << First << "|\n";
            cout << "| Last Name:       " << setw(24) << left << Second << "|\n";
            cout << "| CNIC:            " << setw(24) << left << cnic << "|\n";
            cout << "| Username:        " << setw(24) << left << usernames << "|\n";
            cout << "| Age:             " << setw(24) << left << age << "|\n";
            cout << "| Password:        " << left;
            for (int i = 0; i < password.length(); i++) {
                cout << "*";
            }
            cout << "|\n";

            if (dependant) {
                cout << "+-------------------------------------------+\n";
                cout << "|          Dependant Information            |\n";
                cout << "+-------------------------------------------+\n";
                cout << "| Name:            " << setw(24) << left << dependant_name << "|\n";
                cout << "| CNIC:            " << setw(24) << left << dependant_cnic << "|\n";
                cout << "| Relation:        " << setw(24) << left << dependant_relation << "|\n";
            }

            cout << "+-------------------------------------------+\n";
            cout << "|          Payment Information              |\n";
            cout << "+-------------------------------------------+\n";
            cout << "| Card Holder Name:" << setw(24) << left << card_holder_name << "|\n";
            cout << "| Card Number:     "  << left;
            for (int i = 0; i < card_number.length(); i++) {
                if (i % 4 == 0 && i != 0) {
                    cout << " ";
                }
                if (i < 4 || i >= card_number.length() - 4) {
                    cout << card_number[i];
                }
                else {
                    cout << "*";
                }
            }
            cout << "|\n";
            cout << "+-------------------------------------------+\n";
        }


        void edit_information()
        { 
            cout<<"Choose What you want to edit: "<<endl;
            cout<<"1. First Name"<<endl;
            cout<<"2. Second Name"<<endl;
            cout<<"3. CNIC"<<endl;
            cout<<"4. Username"<<endl;
            cout<<"5. Age"<<endl;
            cout<<"6. Password"<<endl;
            cout<<"7. Payment Details"<<endl;
            cout<<"8. Exit"<<endl;
            cout<<"Enter your choice: ";
            int choice;
            
            try {
                cin >> choice;
                if (!cin)
                    throw 1;
            }
            catch (int x) {
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                return;
            }

            switch (choice)
            {
                case 1:
				cout<<"Enter First Name: ";
				cin.ignore();
				getline(std::cin, First);
				break;
                case 2:
                    cout<<"Enter Second Name: ";
                    cin.ignore();
                    getline(std::cin, Second);
                    break;
                    case 3:
                        cout<<"Enter CNIC: ";
                        cin.ignore();
                        getline(std::cin, cnic);
                        break;
                        case 4:
							cout<<"Enter Username: ";
							cin.ignore();
							getline(std::cin, usernames);
							break;
							case 5:
								cout<<"Enter Age: ";
                                cin >> age;
                                
								
								break;
								case 6:
									cout<<"Enter Password: ";
									cin.ignore();
									getline(std::cin, password);
									break;
									case 7:
										cout<<"Enter Card Holder Name: ";
										cin.ignore();
										getline(std::cin, card_holder_name);
										cout<<"Enter Card Number: ";
										cin.ignore();
										getline(std::cin, card_number);
										cout<<"Enter Expiry Date: ";
										cin.ignore();
										getline(std::cin, expiry_date);
										cout<<"Enter CVV: ";
										cin.ignore();
										getline(std::cin, cvv);
										break;
                                        case 8:
                                            break;
											default:
												cout<<"Invalid Choice"<<endl;
												break;
            }
        }

        // make << operator overloading just for prize
        friend ostream& operator<<(ostream& out,Passenger& P)
        {
			
            if (P.ID == -1)
            {
                cout <<"Refund has been added to your Account";
                P.prize+=P.ticket_prize*0.75;
            }
            cout << endl;
            out<<"\nTotal Amount: "<<P.prize<<endl;
			return out;
		}


 

};



class Flight
{
    string Destination;
    string Departure;
    string start_Time;
    string end_Time;
    string Flight_number;
    int total_hours;
    bool local;
    bool isbusiness;
    int seats[6][10];
    int row, col;
    bool isblocked;
    bool isdirect;
    string D1;
    string visited;

public:
    Flight()
    {
		Destination = " ";
		Departure = " ";
		start_Time = " ";
		end_Time = " ";
		Flight_number = " ";

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                seats[i][j] = 0;
            }
        }


       
        for (int i = 0; i < 10; i++)
        {
			seats[0][i] = 9;
		}
	}
    Flight(string d, string de, string s, string e, string f, bool l , bool isdir , string d1, string visited)
    {
		Destination = d;
		Departure = de;
		start_Time = s;
		end_Time = e;
		Flight_number = f;
        local = l;
        isdirect = isdir;
        D1 = d1;
        this->visited = visited;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                seats[i][j] = 0;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            seats[0][i] = 9;
        }

        isblocked = false;

       
        int start = stoi(start_Time);
        int end = stoi(end_Time);
        total_hours = end - start;

	}

    // copy constructor
    Flight(const Flight& f)
    {
        Destination = f.Destination;
        Departure = f.Departure;
            
        start_Time = f.start_Time;
        end_Time = f.end_Time;
        Flight_number = f.Flight_number;
        local = f.local;
        isdirect = f.isdirect;
        D1 = f.D1;
        visited = f.visited;
        total_hours = f.total_hours;
        isblocked = f.isblocked;
        isbusiness = f.isbusiness;
        row = f.row;
        col = f.col;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
				seats[i][j] = f.seats[i][j];
			}
		}

    }
    void set_Destination(string d)
    {
		Destination = d;
	}
    void set_Departure(string de)
    {
		Departure = de;
	}
    void set_start_Time(string s)
    {
		start_Time = s;
	}
    void set_end_Time(string e)
    {
		end_Time = e;
	}
    void set_Flight_number(string f)
    {
		Flight_number = f;
	}
    string get_Destination()
    {
		return Destination;
	}
    string get_Departure()
    {
		return Departure;
	}
    string get_start_Time()
    {
		return start_Time;
	}
    string get_end_Time()
    {
		return end_Time;
	}
    string get_Flight_number()
    {
		return Flight_number;
	}
    bool get_local()
    {
		return local;
	}
    void set_local(bool l)
    {
        local = l;
    }
    bool get_isbusiness()
    {
		return isbusiness;
	}
    void set_isbusiness(bool b)
    {
		isbusiness = b;
	}
    int get_total_hours()
    {
        return total_hours;
    }

    int get_row()
    {
        return row;
    }
   
    int get_col()
    {
		return col;
	}
    void set_row(int r)
    {
        row = r;
    }
    void set_col(int c)
    {
		col = c;
	}
    bool get_isblocked()
    {
        return isblocked;

    }
    void set_isblocked(bool b)
    {
		isblocked = b;
	}
    bool get_isdirect()
    {
		return isdirect;
	}
    void set_isdirect(bool b)
    {
        isdirect = b;
    }
    string get_D1()
    {
		return D1;
	}
    void set_D1(string d)
    {
        D1 = d;
    }
   
    void set_total_hours(int t)
    {
		total_hours = t;
	}
    
    
    void restrict()
   
    {    
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j += 2)
            {
				seats[i][j] = 2;
			}
		}


    }
 
    void book()
    {   
        bool booked=0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << seats[i][j] << " ";
            } cout << endl;
        }
        cout << endl;

        cout << "First 10 Rows for Business Class" << endl;
        do {
cout << "Enter row number: ";
			cin >> row;
			cout << "Enter column number: ";
			cin >> col;
			if (seats[row][col] == 0)
			{
				seats[row][col] = 1;
				cout << "Seat booked successfully" << endl;
				booked = 0;
			}
			else if (seats[row][col] == 1)
			{
				cout << "Seat is already booked" << endl;
				booked = 1;
			}

            else if (seats[row][col] == 2)
            {
				cout << "You cannot Book it be because of Covid 19 Policies" << endl;
				booked = 1;
			}
		} while (booked == 1);
      

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << seats[i][j] << " ";
            } cout << endl;
        }

        // check if user have selected in first 10 rows then isbusinuss=1 otherwise 0
        if (row < 1)
        {
            cout << "You have selected Business Class";
			isbusiness = 1;
		}
        else
        {   cout << "You have selected Economy Class";
			isbusiness = 0;
		}

        cout << endl;

        // calculate total hours
		int start = stoi(start_Time);
		int end = stoi(end_Time);
		total_hours = end - start;
		cout << "Total hours: " << total_hours << endl;


    



   }

    void cancel(int r, int c)
    {
		seats[r][c] = 0;
	}
  
    void print()
    {
        cout << setw(12) << left << Flight_number << setw(16) << left << Destination << setw(16) << left << Departure << setw(12) << left << start_Time << setw(12) << left << end_Time << setw(12) << left << total_hours << setw(8) << left << (isdirect ? "Dir" : "Non");
        if (isdirect == 0)
        {
            cout << setw(16) << left << D1;
        }

        else
        {
			cout << setw(16) << left << " ";
		}

        cout<<setw(8) << left << visited;
        cout << endl;
    }

};

// class airport
class Airport
{
public:
    string name;
    Flight* flights;
    int numFlights;

    
    Airport(const Airport& a)
    {
		name = a.name;
		numFlights = a.numFlights;
		flights = new Flight[numFlights];
        for (int i = 0; i < numFlights; i++)
        {
			flights[i] = a.flights[i];
		}
	}
    Airport(string name)
    {
        this->name = name;
        numFlights = 0;
    }
    Airport(string name, Flight* flights, int numFlights)
    {
		this->name = name;
		this->flights = flights;
		this->numFlights = numFlights;
	}
    void addFlight(Flight * flight)
    {
        if (numFlights < 15)
        {   

            Flight * temp = new Flight[numFlights + 1];
            for (int i = 0; i < numFlights; i++)
            {
				temp[i] = flights[i];
			}

            delete[] flights;
            flights = temp;
            flights[numFlights] = *flight;
          
            numFlights++;
           
		}
        else
        {
            cout << "Airport is full" << endl;
        }
         
           
    }

    void restrict_seats()
    {   
        short_details();
        string f;
        cout << "Enter Flight Number: ";
        cin >> f;
        for (int i = 0; i < numFlights; i++)
        {
            if (f == flights[i].get_Flight_number())
            {
				flights[i].restrict();
				cout << "Seats Restricted" << endl;
                return;
			}
		}

       
    }
    void removeFlight()

    {   
        short_details();
        string f;
        cout << "Enter Flight Number: ";
        cin >> f;
        for (int i = 0; i < numFlights; i++)
        {
            if (f == flights[i].get_Flight_number())
            {
                for (int j = i; j < numFlights - 1; j++)
                {
					flights[j] = flights[j + 1];
				}
				numFlights--;
				break;
			}
		}

        cout << "Flight Removed";
	}

    void add_new_flight()
    {

        string  de, s, e, f;
        bool isdirect;
        string D1;
        string visit;
		bool l;
		cout << "Enter Destination: ";
		cin >> de;
        cout << "1: Direct \n0:Indirect: ";
        cin >> isdirect;
        if (isdirect == 0)
        {
			cout << "Enter  Stay Country: ";
			cin >> D1;
		}

		cout << "Enter Start Time: ";
		cin >> s;
		cout << "Enter End Time: ";
		cin >> e;
        cout << "1: Least Visited \n2: Most Visited \n";
        cin >> visit;
        if (visit == "1")
        {
            visit="Least Visited";
        }
        
        else if (visit == "2")
        {
			
            visit = "Most Visited";
		}
       
        do {
            cout << "Enter Flight Number: ";
            cin >> f;

        } while (check_flight(f) == true);
		
		cout << "1: for Local Flight \n0: for International Flight: ";
		cin >> l;
        Flight* flight = new Flight(de, name, s, e, f, l, isdirect, D1, visit);
		addFlight(flight);
        cout << "\nFlight Successfully Added\n";
    }

    bool check_flight(string f)
    {
        for (int i = 0; i < numFlights; i++)
        {
            if (f == flights[i].get_Flight_number())
            {
                cout << "Flight Number already exist";
				return true;
			}
		}
		return false;
	}




    void short_details()
    {
        for (int i = 0; i < numFlights; i++)
        {
			cout << i + 1 << ": "; 
            cout<<"Flight Number: "<<flights[i].get_Flight_number();
            cout << " Destination: " << flights[i].get_Destination();
            if (flights[i].get_local())
            {
                cout << "\tType: Local" ;

           }
            else
            {
				cout << "\t Type: International" ;
			}
            if (flights[i].get_isblocked())
            {
				cout << "\tStatus: Blocked" << endl;

             }
            else
            {
                cout << "\tStatus: Unblocked" << endl;
            }

            cout << endl;
		}
    }

    void change_schedule()
    {
        short_details();
        string f, s, e;
        cout << "Enter Flight Number to change schedule: ";
        cin >> f;
        cout << "0: For international flight" << endl;
        cout << "1: For local flight" << endl;
        int l;
        cin >> l;
        string d;
        cout << "Enter New destination: ";
        cin >> d;
        cout << "Enter Start Time: ";
        cin >> s;
        cout << "Enter End Time: ";
        cin >> e;
       
        int h = stoi(e.substr(0, 2)) - stoi(s.substr(0, 2));
        for (int i = 0; i < numFlights; i++)
        {
            if (f == flights[i].get_Flight_number())
            {
				flights[i].set_Destination(d);
				flights[i].set_start_Time(s);
				flights[i].set_end_Time(e);
				flights[i].set_local(l);
                flights[i].set_total_hours(h);
				cout << "Schedule is changed";
                return;
			}
		}


        cout << "Airline of that Flight No. is not here";
        

    }

    void block_flight()
    {
        short_details();
        string f;
		cout << "Enter Flight Number to block: ";
		cin >> f;
        for (int i = 0; i < numFlights; i++)
        {
            if (f == flights[i].get_Flight_number())
            {
				
                flights[i].set_isblocked(true);
				cout << "Flight is blocked";
			}
		}
    }

    void resume_flight()
    {
        short_details();
        		string f;
                cout << "Enter Flight Number to resume: ";
                cin >> f;
                for (int i = 0; i < numFlights; i++)
                {
                    if (f == flights[i].get_Flight_number())
                    {
						flights[i].set_isblocked(false);
						cout << "Flight is resumed";
					}
				}
    }

    Flight* getFlight(int i)
    {
		return &flights[i];
	}



    void printAirportDetails(bool local)
    {
        cout << "-----------------------------------------------" << endl;
        cout << setw(6) << setfill(' ') << left << "| No." << "| Flight No. " << "|   Destination     " << "|     Departure    " << "| Start Time" << "| End Time" << "| Total Hours" << "| Type" << "| Connecting Airport |" << endl;
        cout << "-----------------------------------------------" << endl;

        int count = 1;
        for (int i = 0; i < numFlights; i++)
        {
            if (local == flights[i].get_local() && !flights[i].get_isblocked())
            {    
                cout << count<<"\t"; flights[i].print();
                count++;
            }
        }
        if (count == 1) {
            cout << "No flights available." << endl;
        }
        cout << "-----------------------------------------------" << endl;
    }
};

// make clas for booking or ticket handling
class Booking
{
	int Seat_Row;
    int Seat_Column;
	bool isBusiness;
	int totalHours;
    string Destination;
    string Departure;
	int price;
    string Name;
    string CNIC;
    string start_Time;
    string end_Time;
    string Flight_number;
    bool local;
    static int total;
    string Date;
    static int ID;
    int uniqueID;
    Flight * flight;
    Passenger * passenger;

public:
    Booking()
    {
		Seat_Row = 0;
		Seat_Column = 0;
		isBusiness = 0;
		totalHours = 0;
		Destination = "";
		Departure = "";
		price = 0;
		Name = "";
		CNIC = "";
		start_Time = "";
		end_Time = "";
		Flight_number = "";
		local = 0;
        total = 0;
        Date = "0";
        

	}
    Booking(int r, int c, bool b, int t, string d, string de, int p, string n, string cnic, string s, string e, string f, bool l)
    {
		Seat_Row = r;
		Seat_Column = c;
		isBusiness = b;
		totalHours = t;
		Destination = d;
		Departure = de;
		price = p;
		Name = n;
		CNIC = cnic;
		start_Time = s;
		end_Time = e;
		Flight_number = f;
		local = l;
        total=0;
	}

    
    Booking(const Booking& b)
    {
        Seat_Row = b.Seat_Row;
        Seat_Column = b.Seat_Column;

        isBusiness = b.isBusiness;
        totalHours = b.totalHours;
        Destination = b.Destination;
        Departure = b.Departure;
        price = b.price;
        Name = b.Name;
        CNIC = b.CNIC;
        start_Time = b.start_Time;
        end_Time = b.end_Time;
        Flight_number = b.Flight_number;
        local = b.local;
        total = b.total;
        Date = b.Date;
        uniqueID = b.uniqueID;
        flight = b.flight;
        passenger = b.passenger;

    }
    void set_Seat_Row(int r)
    {
		Seat_Row = r;
	}
    void set_Seat_Column(int c)
    {
		Seat_Column = c;
	}
    void set_isBusiness(bool b)
    {
		isBusiness = b;
	}
    void set_totalHours(int t)
    {
		totalHours = t;
	}
    void set_Destination(string d)
    {
		Destination = d;
	}
    void set_Departure(string de)
    {
		Departure = de;
	}
    void set_price(int p)
    {
		price = p;
	}
    void set_Name(string n)
    {
		Name = n;
	}
    void set_CNIC(string cnic)
    {
		CNIC = cnic;
	}
    void set_start_Time(string s)
    {
		start_Time = s;
	}
    void set_end_Time(string e)
    {
		end_Time = e;
	}
    void set_Flight_number(string f)
    {
		Flight_number = f;
	}
    void set_local(bool l)
    {
		local = l;
	}
    int get_Seat_Row()
    {
		return Seat_Row;
	}
    int get_Seat_Column()
    {
		return Seat_Column;
	}
    bool get_isBusiness()
    {
		return isBusiness;
	}
    int get_totalHours()
    {
		return totalHours;
	}
    string get_Destination()
    {
		return Destination;
	}
    string get_Departure()
    {
		return Departure;
	}
    int get_price()
    {
		return price;
	}
    string get_Name()
    {
		return Name;
	}
    string get_CNIC()
    {
		return CNIC;
	}
    string get_start_Time()
    {
		return start_Time;
	}
    string get_end_Time()
    {
		return end_Time;
	}
    string get_Flight_number()
    {
		return Flight_number;
	}
    bool get_local()
    {
		return local;
	}
    int get_ID()
    {
        return uniqueID;
 }
    void set_ID(int id)
    {
		uniqueID = id;
	}

    void add_booking(string name, string cnic, string flight_number, string departure, string destination, string start_time, string end_time, int total_hours, int seat_row, int seat_column, int price, bool is_business, bool local)
    {
        Name = name;
        CNIC = cnic;
        Flight_number = flight_number;
        Departure = departure;
        Destination = destination;
        start_Time = start_time;
        end_Time = end_time;
        totalHours = total_hours;
        Seat_Row = seat_row;
        Seat_Column = seat_column;
        this->price = price;
        isBusiness = is_business;
        this->local = local;
            

    }
        
    void add_Booking(Passenger * P, Flight *F, string d)
    {  
        flight = F;
        passenger = P;
        Name = P->get_first() + " " + P->get_second();
		CNIC = P->get_cnic();
		Flight_number = F->get_Flight_number();
		Departure = F->get_Departure();
		Destination = F->get_Destination();
		start_Time = F->get_start_Time();
		end_Time = F->get_end_Time();
		totalHours = F->get_total_hours();
		Seat_Row = F->get_row();
		Seat_Column = F->get_col();
		price = P->get_ticket_prize();
		isBusiness = F->get_isbusiness();
		local = F->get_local();
        Date = d;
        uniqueID=ID;
        
        P->setID(ID);

        
       
        ID++;
    }
        
    void cancel_Booking(Passenger * P)
    {   
        
        
        cout<<"You would only get 75% refund of your ticket price"<<endl;
        cout<<"Do you want to continue? (Y/N)"<<endl;
        char ch;
        cin>>ch;
        if (ch == 'Y' || ch == 'y')
        {
			cout<<"Your ticket has been cancelled"<<endl;
			cout<<"You will get "<<price*0.75<<" Rs. back"<<endl;
            flight->cancel(Seat_Row, Seat_Column);
            passenger->setID(-1);
            passenger->setprize(0);
            
		}
        else
        {
			cout<<"Your ticket has not been cancelled"<<endl;
		}
        
		

    }

    void direct_cancel(Passenger * P)
    {
        
            flight->cancel(Seat_Row, Seat_Column);
            passenger->setID(-1);
            passenger->setprize(0);
        
      
    }

    void print()
    {
        // Setting up formatting options
        cout << setfill('*') << setw(80) << "" << endl;
        cout << setfill(' ') << left << setw(25) << "* Name:" << setw(30) << Name << "*" << endl;
        cout << left << setw(25) << "* CNIC:" << setw(30) << CNIC << "*" << endl;
        cout << left << setw(25) << "* Flight Number:" << setw(30) << Flight_number << "*" << endl;
        cout << left << setw(25) << "* Departure:" << setw(30) << Departure << "*" << endl;
        cout << left << setw(25) << "* Destination:" << setw(30) << Destination << "*" << endl;
        cout << left << setw(25) << "* Start Time:" << setw(30) << start_Time << "*" << endl;
        cout << left << setw(25) << "* End Time:" << setw(30) << end_Time << "*" << endl;
        cout << left << setw(25) << "* Total Hours:" << setw(30) << totalHours << "*" << endl;
        cout << left << setw(25) << "* Seat Row:" << setw(30) << Seat_Row << "*" << endl;
        cout << left << setw(25) << "* Seat Column:" << setw(30) << Seat_Column << "*" << endl;
        cout << left << setw(25) << "* Price:" << setw(30) << price << "*" << endl;
        cout << left << setw(25) << "* Is Business:" << setw(30) << isBusiness << "*" << endl;
        cout << left << setw(25) << "* Is Local:" << setw(30) << local << "*" << endl;
        cout << left << setw(25) << "* Date:" << setw(30) << Date << "*" << endl;
        cout << setfill('*') << setw(80) << "" << endl;
    }

};
class NAFS
{
    Airport * airport[10];
    int total_airports;
    Booking* Book;
    static int total_bookings;
    Passenger * Pass;
    static int total_passengers;
    Admin * Ad;
    static int total_admins;
public:
    // copy and parameterized constructor
    

    NAFS(int total_airports, int total_bookings, int total_passengers, int total_admins)
    {
		this->total_airports = total_airports;
		this->total_bookings = total_bookings;
		this->total_passengers = total_passengers;
		this->total_admins = total_admins;
		Book = new Booking[total_bookings];
		Pass = new Passenger[total_passengers];
		Ad = new Admin[total_admins];
	}
    NAFS(NAFS& obj)
    {
        total_airports = obj.total_airports;
        total_bookings = obj.total_bookings;
        total_passengers = obj.total_passengers;
        total_admins = obj.total_admins;
        Book = new Booking[ total_bookings];
        Pass = new Passenger[total_passengers];
        Ad = new Admin[total_admins];
        for (int i = 0; i < total_bookings; i++)
        {
			Book[i] = obj.Book[i];
		}
        for (int i = 0; i < total_passengers; i++)
        {
            Pass[i] = obj.Pass[i];
        }
        for (int i = 0; i < total_admins; i++)
        {
			Ad[i] = obj.Ad[i];
		}

    }

    int get_total_bookings()
    {
		return total_bookings;
	}
    int get_total_passengers()
    {
        return total_passengers;
    }
 

    ~NAFS()
    {   

        

        save_bookings();
       // save_passengers();
        save_passengers();
     
    }


    // make a function that saves all bookings data in a file
    void save_bookings()
    {
		ofstream fout;
		fout.open("Bookings.txt");
		fout << total_bookings << endl;
        for (int i = 0; i < total_bookings; i++)
        {
			fout << Book[i].get_Name() << endl;
			fout << Book[i].get_CNIC() << endl;
			fout << Book[i].get_Flight_number() << endl;
			fout << Book[i].get_Departure() << endl;
			fout << Book[i].get_Destination() << endl;
			fout << Book[i].get_start_Time() << endl;
			fout << Book[i].get_end_Time() << endl;
			fout << Book[i].get_price() << endl;
			fout << Book[i].get_local() << endl;
            fout << Book[i].get_ID() << endl;

		}
		fout.close();
	}

    // make a function that loads all bookings data from a file
    void load_bookings()
    {
        ifstream fin;
        fin.open("Bookings.txt");
        fin >> total_bookings;
        Book = new Booking[total_bookings];
        for (int i = 0; i < total_bookings; i++)
        {
			string name, cnic, flight_number, departure, destination, start_time, end_time;
			double price;
			bool local;
            int id;
			fin >> name;
			fin >> cnic;
			fin >> flight_number;
			fin >> departure;
			fin >> destination;
			fin >> start_time;
			fin >> end_time;
			fin >> price;
			fin >> local;
            fin >> id;

			Book[i].set_Name(name);
			Book[i].set_CNIC(cnic);
			Book[i].set_Flight_number(flight_number);
			Book[i].set_Departure(departure);
			Book[i].set_Destination(destination);
			Book[i].set_start_Time(start_time);
			Book[i].set_end_Time(end_time);
			Book[i].set_price(price);
			Book[i].set_local(local);
            Book[i].set_ID(id);
            
		}
    }

    void save_passengers()
    {
        ofstream fout;
        

        fout.open("Passengers.txt");
        fout << total_passengers << endl;
        for (int i = 0; i < total_passengers; i++)
        {
            fout << Pass[i].get_first()<< endl;
            fout << Pass[i].get_second() << endl;
			fout << Pass[i].cnic << endl;
			fout << Pass[i].age << endl;
            fout << Pass[i].usernames << endl;
            fout << Pass[i].password << endl;
			fout << Pass[i].getprize() << endl;
            fout << Pass[i].card_holder_name << endl;
            fout << Pass[i].card_number << endl;
            fout << Pass[i].getID() << endl;
            
           
              
            
		}
        fout.close();

    }


    void load_passengers()
    {
		ifstream fin;
		fin.open("Passengers.txt");
		fin >> total_passengers;
        Pass = new Passenger[total_passengers];
        for (int i = 0; i < total_passengers; i++)
        {
            int age;
			string first, second, cnic, username, password;
			double prize;
            int id;

			fin >> first;
			fin >> second;
			fin >> cnic;
			fin >> age;
			fin >> username;
			fin >> password;
			fin >> prize;
            fin >> id;
			Pass[i].set_first(first);
			Pass[i].set_second(second);
			Pass[i].set_cnic(cnic);
			Pass[i].set_age(age);
			Pass[i].set_usernames(username);
			Pass[i].set_password(password);
			Pass[i].setprize(prize);
            fin >> Pass[i].card_holder_name;
			fin >> Pass[i].card_number;
            Pass[i].setID(id);

		}
		fin.close();
	}
    NAFS()
    {   
   

        Ad = NULL;
        Pass = NULL;
        load_passengers();
        load_bookings();
        
        total_airports = 0;
        airport[0] = new Airport("Islamabad North");
        airport[1] = new Airport("Islamabad South");
        airport[2] = new Airport("Lahore North");
        airport[3] = new Airport("Lahore South");
        airport[4] = new Airport("Quetta North");
        airport[5] = new Airport("Quetta South");
        airport[6] = new Airport("Peshawar North");
        airport[7] = new Airport("Peshawar South");
        airport[8] = new Airport("Karachi North");
        airport[9] = new Airport("Karachi South");

    
        airport[0]->addFlight(new Flight("Lahore North", "Islamabad North", "6:00", "8:00", "PK-001",1, 1," ", "Most Visited"));
        airport[0]->addFlight(new Flight("Quetta North", "Islamabad North", "8:00", "10:00", "PK-002",1, 1," ", "Most Visited"));
        airport[0]->addFlight(new Flight("Peshawar North", "Islamabad North", "10:00", "12:00", "PK-003",1, 1," ", "Least Visited"));
        airport[0]->addFlight(new Flight("Karachi North", "Islamabad North", "12:00", "14:00", "PK-004",1, 1," ", "Least Visited"));
        airport[0]->addFlight(new Flight("Lahore South", "Islamabad North", "14:00", "16:00", "PK-005",1, 1," ", "Most Visited"));
        airport[0]->addFlight(new Flight("Quetta South", "Islamabad North", "16:00", "18:00", "PK-006",1, 1,"", "Most Visited"));
        airport[0]->addFlight(new Flight("Peshawar South", "Islamabad North", "18:00", "20:00", "PK-007",1, 1,"", "Least Visited"));
        airport[0]->addFlight(new Flight("Karachi South", "Islamabad North", "20:00", "22:00", "PK-008",1, 1,"", "Least Visited"));
        airport[0]->addFlight(new Flight("Lahore North", "Islamabad North", "6:00", "8:00", "PK-009",1, 1,"", "Most Visited"));
        airport[0]->addFlight(new Flight("Quetta North", "Islamabad North", "8:00", "10:00", "PK-010",1, 1,"", "Most Visited"));




        airport[0]->addFlight(new Flight("Munich", "Islamabad North", "6:00", "11:00", "PK-011",0,0,"Dubai","Most Visited"));
        airport[0]->addFlight(new Flight("London", "Islamabad North", "8:00", "14:00", "PK-012",0,0,"Dubai","Most Visited"));
        airport[0]->addFlight(new Flight("New York", "Islamabad North", "10:00", "18:00", "PK-013",0,0,"Dubai","Most Visited"));
        airport[0]->addFlight(new Flight("Paris", "Islamabad North", "12:00", "17:00", "PK-014",0,0,"Dubai","Most Visited"));
        airport[0]->addFlight(new Flight("Dubai", "Islamabad North", "14:00", "15:00", "PK-015",0,1,"", "Least Visited"));


        airport[1]->addFlight(new Flight("Lahore North", "Islamabad South", "6:00", "8:00", "PK-211",1,1,"", "Most Visited"));
        airport[1]->addFlight(new Flight("Quetta North", "Islamabad South", "8:00", "10:00", "PK-212",1,1,"", "Most Visited"));
        airport[1]->addFlight(new Flight("Peshawar North", "Islamabad South", "10:00", "12:00", "PK-213",1,1,"", "Least Visited"));
        airport[1]->addFlight(new Flight("Karachi North", "Islamabad South", "12:00", "14:00", "PK-214",1,1,"", "Least Visited"));
        airport[1]->addFlight(new Flight("Lahore South", "Islamabad South", "14:00", "16:00", "PK-215",1,1,"", "Most Visited"));
        airport[1]->addFlight(new Flight("Quetta South", "Islamabad South", "16:00", "18:00", "PK-216",1,1,"", "Most Visited"));
        airport[1]->addFlight(new Flight("Peshawar South", "Islamabad South", "18:00", "20:00", "PK-217",1,1,"", "Least Visited"));
        airport[1]->addFlight(new Flight("Karachi South", "Islamabad South", "20:00", "22:00", "PK-218",1,1,"", "Least Visited"));
        airport[1]->addFlight(new Flight("Lahore North", "Islamabad South", "6:00", "8:00", "PK-219",1,1,"", "Most Visited"));
        airport[1]->addFlight(new Flight("Quetta North", "Islamabad South", "8:00", "10:00", "PK-220",1,1,"", "Most Visited"));


        airport[1]->addFlight(new Flight("Munich", "Islamabad South", "6:00", "11:00", "PK-221",0,0,"Dubai","Most Visited"));
        airport[1]->addFlight(new Flight("London", "Islamabad South", "8:00", "14:00", "PK-222",0,0,"Dubai","Most Visited"));
        airport[1]->addFlight(new Flight("New York", "Islamabad South", "10:00", "18:00", "PK-223",0,0,"Dubai","Most Visited"));
        airport[1]->addFlight(new Flight("Paris", "Islamabad South", "12:00", "17:00", "PK-224",0,0,"Dubai","Most Visited"));
        airport[1]->addFlight(new Flight("Dubai", "Islamabad South", "14:00", "15:00", "PK-225",0,1,"", "Least Visited"));


        airport[2]->addFlight(new Flight("Islamabad North", "Lahore North", "6:00", "8:00", "PK-101",1,1,"", "Least Visited"));
        airport[2]->addFlight(new Flight("Quetta North", "Lahore North", "8:00", "10:00", "PK-102",1,1,"", "Least Visited"));
        airport[2]->addFlight(new Flight("Peshawar North", "Lahore North", "10:00", "12:00", "PK-103",1,1,"", "Most Visited"));
        airport[2]->addFlight(new Flight("Karachi North", "Lahore North", "12:00", "14:00", "PK-104",1,0,"Islamabad","Most Visited"));
        airport[2]->addFlight(new Flight("Islamabad South", "Lahore North", "14:00", "16:00", "PK-105",1,1,"", "Least Visited"));
        airport[2]->addFlight(new Flight("Quetta South", "Lahore North", "16:00", "18:00", "PK-106",1,1,"", "Least Visited"));
        airport[2]->addFlight(new Flight("Peshawar South", "Lahore North", "18:00", "20:00", "PK-107",1,1,"", "Most Visited"));
        airport[2]->addFlight(new Flight("Karachi North", "Lahore North", "20:00", "22:00", "PK-108",1,0,"Islamabad","Least Visited"));



        airport[2]->addFlight(new Flight("Munich", "Lahore North", "6:00", "11:00", "PK-109",0,0,"Dubai","Most Visited"));
        airport[2]->addFlight(new Flight("London", "Lahore North", "8:00", "14:00", "PK-110",0,0,"Dubai","Most Visited"));
        airport[2]->addFlight(new Flight("New York", "Lahore North", "10:00", "18:00", "PK-111",0,0,"Dubai","Most Visited"));
        airport[2]->addFlight(new Flight("Paris", "Lahore North", "12:00", "17:00", "PK-112",0,0,"Dubai","Most Visited"));
        airport[2]->addFlight(new Flight("Dubai", "Lahore North", "14:00", "15:00", "PK-113",0,1,"", "Least Visited"));



        airport[3]->addFlight(new Flight("Islamabad North", "Lahore South", "6:00", "8:00", "PK-301",1,1,"", "Least Visited"));
        airport[3]->addFlight(new Flight("Quetta North", "Lahore South", "8:00", "10:00", "PK-302",1,1,"", "Least Visited"));
        airport[3]->addFlight(new Flight("Peshawar North", "Lahore South", "10:00", "12:00", "PK-303",1,1,"", "Most Visited"));
        airport[3]->addFlight(new Flight("Karachi North", "Lahore South", "12:00", "14:00", "PK-304",1,0,"Islamabad","Most Visited"));
        airport[3]->addFlight(new Flight("Islamabad South", "Lahore South", "14:00", "16:00", "PK-305",1,1,"", "Least Visited"));
        airport[3]->addFlight(new Flight("Quetta South", "Lahore South", "16:00", "18:00", "PK-306",1,1,"", "Least Visited"));
        airport[3]->addFlight(new Flight("Peshawar South", "Lahore South", "18:00", "20:00", "PK-307",1,1,"", "Most Visited"));
        airport[3]->addFlight(new Flight("Karachi North", "Lahore South", "20:00", "22:00", "PK-308",1,0,"Islamabad","Least Visited"));


        
        airport[3]->addFlight(new Flight("Munich", "Lahore South", "6:00", "11:00", "PK-309",0,0,"Dubai","Most Visited"));
        airport[3]->addFlight(new Flight("London", "Lahore South", "8:00", "14:00", "PK-310",0,0,"Dubai","Most Visited"));
        airport[3]->addFlight(new Flight("New York", "Lahore South", "10:00", "18:00", "PK-311",0,0,"Dubai","Most Visited"));
        airport[3]->addFlight(new Flight("Paris", "Lahore South", "12:00", "17:00", "PK-312",0,0,"Dubai","Most Visited"));
        airport[3]->addFlight(new Flight("Dubai", "Lahore South", "14:00", "15:00", "PK-313",0,1,"", "Least Visited"));

 
        airport[4]->addFlight(new Flight("Islamabad North", "Karachi North", "6:00", "8:00", "PK-401",1,1,"", "Least Visited"));
        airport[4]->addFlight(new Flight("Quetta North", "Karachi North", "8:00", "10:00", "PK-402",1,1,"", "Least Visited"));
        airport[4]->addFlight(new Flight("Peshawar North", "Karachi North", "10:00", "12:00", "PK-403",1,1,"", "Most Visited"));
        airport[4]->addFlight(new Flight("Lahore North", "Karachi North", "12:00", "14:00", "PK-404",1,0,"Islamabad","Most Visited"));
        airport[4]->addFlight(new Flight("Islamabad South", "Karachi North", "14:00", "16:00", "PK-405",1,1,"", "Least Visited"));
        airport[4]->addFlight(new Flight("Quetta South", "Karachi North", "16:00", "18:00", "PK-406",1,1,"", "Least Visited"));
        airport[4]->addFlight(new Flight("Peshawar South", "Karachi North", "18:00", "20:00", "PK-407",1,1,"", "Most Visited"));
        airport[4]->addFlight(new Flight("Lahore North", "Karachi North", "20:00", "22:00", "PK-408",1,0,"Islamabad","Least Visited"));


   
        airport[4]->addFlight(new Flight("Munich", "Karachi North", "6:00", "11:00", "PK-409",0,0,"Dubai","Most Visited"));
        airport[4]->addFlight(new Flight("London", "Karachi North", "8:00", "14:00", "PK-410",0,0,"Dubai","Most Visited"));
        airport[4]->addFlight(new Flight("New York", "Karachi North", "10:00", "18:00", "PK-411",0,0,"Dubai","Most Visited"));
        airport[4]->addFlight(new Flight("Paris", "Karachi North", "12:00", "17:00", "PK-412",0,0,"Dubai","Most Visited"));
        airport[4]->addFlight(new Flight("Dubai", "Karachi North", "14:00", "15:00", "PK-413",0,1,"", "Least Visited"));


        airport[5]->addFlight(new Flight("Islamabad North", "Karachi South", "6:00", "8:00", "PK-501",1,1,"","Least Visited"));
        airport[5]->addFlight(new Flight("Quetta North", "Karachi South", "8:00", "10:00", "PK-502",1,1,"","Least Visited"));
        airport[5]->addFlight(new Flight("Peshawar North", "Karachi South", "10:00", "12:00", "PK-503",1,1,"","Most Visited"));
        airport[5]->addFlight(new Flight("Lahore North", "Karachi South", "12:00", "14:00", "PK-504",1,0,"Islamabad","Most Visited"));
        airport[5]->addFlight(new Flight("Islamabad South", "Karachi South", "14:00", "16:00", "PK-505",1,1,"","Least Visited"));
        airport[5]->addFlight(new Flight("Quetta South", "Karachi South", "16:00", "18:00", "PK-506",1,1,"","Least Visited"));
        airport[5]->addFlight(new Flight("Peshawar South", "Karachi South", "18:00", "20:00", "PK-507",1,1,"","Most Visited"));
        airport[5]->addFlight(new Flight("Lahore North", "Karachi South", "20:00", "22:00", "PK-508",1,0,"Islamabad","Least Visited"));


        




        
        airport[5]->addFlight(new Flight("Munich", "Karachi South", "6:00", "11:00", "PK-509",0,0,"Dubai","Most Visited"));
        airport[5]->addFlight(new Flight("London", "Karachi South", "8:00", "14:00", "PK-510",0,0,"Dubai","Most Visited"));
        airport[5]->addFlight(new Flight("New York", "Karachi South", "10:00", "18:00", "PK-511",0,0,"Dubai","Most Visited"));
        airport[5]->addFlight(new Flight("Paris", "Karachi South", "12:00", "17:00", "PK-512",0,0,"Dubai","Most Visited"));
        airport[5]->addFlight(new Flight("Dubai", "Karachi South", "14:00", "15:00", "PK-513",0,1,"","Least Visited"));

       
        airport[6]->addFlight(new Flight("Islamabad North", "Peshawar North", "6:00", "8:00", "PK-601",1,1,"","Most Visited"));
        airport[6]->addFlight(new Flight("Quetta North", "Peshawar North", "8:00", "10:00", "PK-602",1,1,"","Least Visited"));
        airport[6]->addFlight(new Flight("Karachi North", "Peshawar North", "10:00", "12:00", "PK-603",1,1,"","Most Visited"));
        airport[6]->addFlight(new Flight("Lahore North", "Peshawar North", "12:00", "14:00", "PK-604",1,0,"Islamabad","Least Visited"));
        airport[6]->addFlight(new Flight("Islamabad South", "Peshawar North", "14:00", "16:00", "PK-605",1,1,"","Most Visited"));
        airport[6]->addFlight(new Flight("Quetta South", "Peshawar North", "16:00", "18:00", "PK-606",1,1,"","Least Visited"));
        airport[6]->addFlight(new Flight("Karachi South", "Peshawar North", "18:00", "20:00", "PK-607",1,1,"","Most Visited"));
        airport[6]->addFlight(new Flight("Lahore North", "Peshawar North", "20:00", "22:00", "PK-608",1,0,"Islamabad","Least Visited"));



      
        airport[6]->addFlight(new Flight("Munich", "Peshawar North", "6:00", "11:00", "PK-609",0,0,"Dubai","Most Visited"));
        airport[6]->addFlight(new Flight("London", "Peshawar North", "8:00", "14:00", "PK-610",0,0,"Dubai","Most Visited"));
        airport[6]->addFlight(new Flight("New York", "Peshawar North", "10:00", "18:00", "PK-611",0,0,"Dubai","Most Visited"));
        airport[6]->addFlight(new Flight("Paris", "Peshawar North", "12:00", "17:00", "PK-612",0,0,"Dubai","Most Visited"));
        airport[6]->addFlight(new Flight("Dubai", "Peshawar North", "14:00", "15:00", "PK-613",0,1,"","Least Visited"));

        airport[7]->addFlight(new Flight("Islamabad North", "Peshawar South", "6:00", "8:00", "PK-701",1,1,"","Least Visited"));
        airport[7]->addFlight(new Flight("Quetta North", "Peshawar South", "8:00", "10:00", "PK-702",1,1,"","Least Visited"));
        airport[7]->addFlight(new Flight("Karachi North", "Peshawar South", "10:00", "12:00", "PK-703",1,1,"","Most Visited"));
        airport[7]->addFlight(new Flight("Lahore North", "Peshawar South", "12:00", "14:00", "PK-704",1,0,"Islamabad","Least Visited"));
        airport[7]->addFlight(new Flight("Islamabad South", "Peshawar South", "14:00", "16:00", "PK-705",1,1,"","Least Visited"));
        airport[7]->addFlight(new Flight("Quetta South", "Peshawar South", "16:00", "18:00", "PK-706",1,1,"","Least Visited"));
        airport[7]->addFlight(new Flight("Karachi South", "Peshawar South", "18:00", "20:00", "PK-707",1,1,"","Most Visited"));
        airport[7]->addFlight(new Flight("Lahore North", "Peshawar South", "20:00", "22:00", "PK-708",1,0,"Islamabad","Least Visited"));



        
        airport[7]->addFlight(new Flight("Munich", "Peshawar South", "6:00", "11:00", "PK-709",0,0,"Dubai","Most Visited"));
        airport[7]->addFlight(new Flight("London", "Peshawar South", "8:00", "14:00", "PK-710",0,0,"Dubai","Most Visited"));
        airport[7]->addFlight(new Flight("New York", "Peshawar South", "10:00", "18:00", "PK-711",0,0,"Dubai","Most Visited"));
        airport[7]->addFlight(new Flight("Paris", "Peshawar South", "12:00", "17:00", "PK-712",0,0,"Dubai","Most Visited"));
        airport[7]->addFlight(new Flight("Dubai", "Peshawar South", "14:00", "15:00", "PK-713",0,1,"","Least Visited"));


        airport[8]->addFlight(new Flight("Islamabad North", "Quetta North", "6:00", "8:00", "PK-801",1,1,"","Least Visited"));
        airport[8]->addFlight(new Flight("Peshawar North", "Quetta North", "8:00", "10:00", "PK-802",1,1,"","Least Visited"));
        airport[8]->addFlight(new Flight("Karachi North", "Quetta North", "10:00", "12:00", "PK-803",1,1,"","Most Visited"));
        airport[8]->addFlight(new Flight("Lahore North", "Quetta North", "12:00", "14:00", "PK-804",1,0,"Islamabad","Least Visited"));
        airport[8]->addFlight(new Flight("Islamabad South", "Quetta North", "14:00", "16:00", "PK-805",1,1,"","Least Visited"));
        airport[8]->addFlight(new Flight("Peshawar South", "Quetta North", "16:00", "18:00", "PK-806",1,1,"","Least Visited"));
        airport[8]->addFlight(new Flight("Karachi South", "Quetta North", "18:00", "20:00", "PK-807",1,1,"","Most Visited"));
        airport[8]->addFlight(new Flight("Lahore North", "Quetta North", "20:00", "22:00", "PK-808",1,0,"Islamabad","Least Visited"));


        
        
        airport[8]->addFlight(new Flight("Munich", "Quetta North", "6:00", "11:00", "PK-809",0,0,"Dubai","Most Visited"));
        airport[8]->addFlight(new Flight("London", "Quetta North", "8:00", "14:00", "PK-810",0,0,"Dubai","Most Visited"));
        airport[8]->addFlight(new Flight("New York", "Quetta North", "10:00", "18:00", "PK-811",0,0,"Dubai","Most Visited"));
        airport[8]->addFlight(new Flight("Paris", "Quetta North", "12:00", "17:00", "PK-812",0,0,"Dubai","Most Visited"));
        airport[8]->addFlight(new Flight("Dubai", "Quetta North", "14:00", "15:00", "PK-813",0,1,"","Least Visited"));

        airport[9]->addFlight(new Flight("Islamabad North", "Quetta South", "6:00", "8:00", "PK-901",1,1,"","Most Visited"));
        airport[9]->addFlight(new Flight("Peshawar North", "Quetta South", "8:00", "10:00", "PK-902",1,1,"","Least Visited"));
        airport[9]->addFlight(new Flight("Karachi North", "Quetta South", "10:00", "12:00", "PK-903",1,1,"","Most Visited"));
        airport[9]->addFlight(new Flight("Lahore North", "Quetta South", "12:00", "14:00", "PK-904",1,0,"Islamabad","Least Visited"));
        airport[9]->addFlight(new Flight("Islamabad South", "Quetta South", "14:00", "16:00", "PK-905",1,1,"","Most Visited"));
        airport[9]->addFlight(new Flight("Peshawar South", "Quetta South", "16:00", "18:00", "PK-906",1,1,"","Least Visited"));
        airport[9]->addFlight(new Flight("Karachi South", "Quetta South", "18:00", "20:00", "PK-907",1,1,"","Most Visited"));
        airport[9]->addFlight(new Flight("Lahore North", "Quetta South", "20:00", "22:00", "PK-908",1,0,"Islamabad","Least Visited"));

        
        
   

        airport[9]->addFlight(new Flight("Munich", "Quetta South", "6:00", "11:00", "PK-909",0,0,"Dubai","Most Visited"));
        airport[9]->addFlight(new Flight("London", "Quetta South", "8:00", "14:00", "PK-910",0,0,"Dubai","Most Visited"));
        airport[9]->addFlight(new Flight("New York", "Quetta South", "10:00", "18:00", "PK-911",0,0,"Dubai","Most Visited"));
        airport[9]->addFlight(new Flight("Paris", "Quetta South", "12:00", "17:00", "PK-912",0,0,"Dubai","Most Visited"));
        airport[9]->addFlight(new Flight("Dubai", "Quetta South", "14:00", "15:00", "PK-913",0,1,"","Least Visited"));

       

    }
   



  
 
    NAFS(Admin* a, Passenger* p)
    {
        Ad = a;
        Pass = p;
    }

    void set_PASS(Passenger* p , int total)
    {
		Pass = p;
        total_passengers = total;
	}
    void set_ADM(Admin* a, int total)
    {
        Ad = a;
		total_admins = total;
    }
	

    void add_admin()
    {
        

        Admin * temp;
        temp = new Admin[total_admins + 1];

        
        int i = 0;

        for (; i < total_admins; i++)
        {
            
            temp[i] = Ad[i];
            
        }

       
        
        Ad = temp;
 
        string first, second, cnic, username;
        cout << "Enter your First Name: ";
        cin >> first;
        cout << "Enter your Second Name: ";
        cin >> second;
        cout << "Enter your CNIC: ";
        cin >> cnic;
        cnic = check_cnic(cnic, total_admins, Ad);
        cout << "Enter your username: ";
        cin >> username;
        username = check_username(username, total_admins, Ad);
        Ad[i].register_user(first, second, cnic, username, 0);
        total_admins++;
    }


    void add_passenger(Passenger * P = NULL)
    {
       
        Passenger* temp = new Passenger[total_passengers + 1];
        
        for (int i = 0; i < total_passengers; i++)
        {
            temp[i] = Pass[i]; 
        }
       
        
        Pass = temp;
        string first, second, cnic, username;
        cout << "Enter your First Name: ";
        cin >> first;
        cout << "Enter your Second Name: ";
        cin >> second;
        cout << "Enter your CNIC: ";
        cin >> cnic;
        cnic = check_cnic(cnic, total_passengers, Pass);
        cout << "Enter your username: ";
        cin >> username;
        username = check_username(username, total_passengers, Pass);
        if (P != NULL)
        {
           
            Pass[total_passengers].set_dependant(1);
            Pass[total_passengers].set_dependant_name(P->get_first() + " " + P->get_second());
            Pass[total_passengers].set_dependant_cnic(P->get_cnic());
            cout << "Whats Your Relation: ";
            string relation;
            cin >> relation;
            Pass[total_passengers].set_dependant_relation(relation);
            
			
		}
        Pass[total_passengers].register_user(first, second, cnic, username, 1);
        total_passengers++;
       
    }
    void add_booking(Passenger* P, Flight *F, string date)
    {
        Booking * temp = new Booking[total_bookings + 1];
        for (int i = 0; i < total_bookings; i++)
        {
			temp[i] = Book[i];

		}
        delete[] Book;
        Book = temp;  

        Book[total_bookings].add_Booking(P, F, date);
        total_bookings++;

   }

    string check_cnic(string cnic, int total, account* user)
    {
        bool valid = true;
        while (cnic.length() != 13)
        {
            cout << "CNIC must be of 13 Digits" << endl;
            cout << "Enter your CNIC: ";
            cin >> cnic;
        }
        while (valid)
        {
            for (int i = 0; i < total; i++)
            {
                if (user[i].get_cnic() == cnic)
                {
                    cout << "CNIC already Exists" << endl;
                    valid = false;
                    break;
                }

            }

            if (valid) break; else {
                cout << "Enter your CNIC: \n";
                cin >> cnic;
            }

        }


        return cnic;

    }


    string check_username(string username, int total, account* user)
    {
        bool valid = true;
        while (valid)
        {
            for (int i = 0; i < total; i++)
            {
                if (user[i].get_usernames() == username)
                {
                    cout << "Username already Exists" << endl;
                    valid = false;
                    break;
                }

            }

            if (valid) break; else {
                cout << "Enter your username: \n";
                cin >> username;
            }

        }  return username;
    }

    void print_admins()
    {
        for (int i = 0; i < total_admins; i++)
        {
            Ad[i].print();
        }
    }
    void print_passengers()
    {
        for (int i = 0; i < total_passengers; i++)
        {
            Pass[i].print();
        }
    }


    

    void login_admin()
    {
        string username, password;
		cout << "Enter your username: ";
		cin >> username;
        password = get_password();
        for (int i = 0; i < total_admins; i++)
        {
            if (Ad[i].get_usernames() == username && Ad[i].get_password() == password)
            {
				cout << "\nLogin Successful\n" << endl;
                system("cls");
                login_as_admin(&Ad[i]);
                return;
				
			}
           
		}
        cout << "Invalid Username or Password\n";
		Sleep(1000);
    }

    void login_passenger()
    {
		string username, password;
        cout << "Enter your username: ";
        cin >> username;
        password = get_password();
        for (int i = 0; i < total_passengers; i++)
        {
            if (Pass[i].get_usernames() == username && Pass[i].get_password() == password)
            {
                cout << "Login Successful" << endl;
                system("cls");
                login_as_passenger(&Pass[i]);
                return;

            }

            
        }  cout<<" Invalid Username or Password\n";
        Sleep(1000);

       
    }

    void schedule()
    {   string date;
       
        cout << "Enter the Date (DD/MM/YY)\n";
        cin >> date;
        cout << "\n\n";
        cout << "--------------------------------------------------\n";
        cout << "|          WELCOME TO OUR AIRPORT SYSTEM          |\n";
        cout << "--------------------------------------------------\n";
        cout << "|        Please Select Your Departure Airport     |\n";
        cout << "--------------------------------------------------\n";
        cout << "|  1. Islamabad North Airport                     |\n";
        cout << "|  2. Islamabad South Airport                     |\n";
        cout << "|  3. Lahore North Airport                        |\n";
        cout << "|  4. Lahore South Airport                        |\n";
        cout << "|  5. Karachi North Airport                       |\n";
        cout << "|  6. Karachi South Airport                       |\n";
        cout << "|  7. Peshawar North Airport                      |\n";
        cout << "|  8. Peshawar South Airport                      |\n";
        cout << "|  9. Quetta North Airport                        |\n";
        cout << "|  10. Quetta South Airport                       |\n";
        cout << "--------------------------------------------------\n";

        int choice;
        try {
            cin >> choice;
            if (!cin)
                throw 1;
        }
        catch (int x) {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
        int airport_name;
        switch (choice)
        {
        case 1:
            airport_name = 0;
            break;
        case 2:
            airport_name = 1;
            break;
        case 3:
            airport_name = 2;
            break;
        case 4:
            airport_name = 3;
            break;
        case 5:
            airport_name = 4;
            break;
        case 6:
            airport_name = 5;
            break;
        case 7:
            airport_name = 6;
            break;
        case 8:
            airport_name = 7;
            break;
        case 9:
            airport_name = 8;
            break;
        case 10:
            airport_name = 9;
            break;
        default:
            cout << "Invalid Choice";
            break;
        }

        cout << endl;

        
        cout << "1. International Flight\n";
        cout << "2. Domestic Flight\n";
        
        cin >> choice;
        switch (choice)
        {
        case 1:
            international_flight_details(airport[airport_name]);
            
            break;
        case 2:
            local_flight_details(airport[airport_name]);
			break;
        default :
            cout<<"Invalid Choice";
            break;




        }

    }

   
    void style()
    {
        cout << endl << endl << endl << endl;
        cout << "\n\t\t\t\tPress Enter to go back to Main Menu............................." << endl;
        Sleep(1000);

        _getch();
    }

    void local_flight_details(Airport* a)
    {

        a->printAirportDetails(1);


    }

    void international_flight_details(Airport* a)
    {
       
        a->printAirportDetails(0);
       
    }

    void login_as_passenger(Passenger * p)
    {
        int ch;
        
            bool passengerMenu = true;
            while (passengerMenu)
            {
                cout << endl << endl;
                cout << "\n1: Account Details";
                cout << "\n2: Edit Account Details";
                cout << "\n3: Make a Booking";
                cout << "\n4: ReSchedule a Booking";
                cout << "\n5: Cancel a Booking";
                cout << "\n6: View Tickets";
                cout << "\n7: Register for Dependants";
                cout << "\n8: See Payments";
                cout << "\n9: Log out\n";
               
                
                try {
					cin >> ch;
					if (!cin)
						throw 1;
				}
                catch (int x) {
					cout << "Invalid Input" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					return;
				}
                switch (ch)
                {
                case 1:
                    system("cls");
                    p->print();
                    break;
                case 2:
                    system("cls");
					p->edit_information();
                    system("cls");
					break;
                case 3:
                    system("cls");
					booking(p);
                    style();
                    system("cls");
					break;
                case 4:
                    system("cls");
                    cout << "\nHere You Can Reschedule Your Booking\n";
                        direct_cancel(p);
                        booking(p);


                        system("cls");
                    break;
                case 5:
                    system("cls");
                    cancel_booking(p);
                    style();
                    system("cls");
					break;
                case 6:
                    system("cls");
					view_ticket(p);
                    break;
				case 7:
                    system("cls");
                    add_passenger(p);

                    style();
                    system("cls");
                    
					break;
                    case 8:
					system("cls");
                   
                    // call stream << operator
                    cout << *p;

                    
                    break;
					
                case 9:
					passengerMenu = false;
					break;
                    default:
					cout << "\nInvalid Choice\n";
					break;






                }

            }
    }

    void login_as_admin(Admin* a)
    {
		int ch;
		bool adminMenu = true;
        while (adminMenu)
        {
			
			cout << "\n1: Account Details";
			cout << "\n2: Edit Account Details";
			cout << "\n3: Add Flight";
            cout << "\n4: Block Flight";
            cout << "\n5: Resume Flight";
            cout << "\n6: Change the Schedule of Flight";
            cout << "\n7: Remove a Flight";
            cout << "\n8: All Available Flights at Particular Airport";
            cout << "\n9: Restrict Passengers in a Flight";
            cout << "\n10: Print All Registered Passengers";
            cout << "\n11: Log out\n";
            cin >> ch;
            
            try {

              
                if (!(cin))
					throw 1;
            }

            catch (int x) {
				cout << "Invalid Input" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				return;
			}
            switch (ch)
            {
			case 1:
                system("cls");
				a->print();
				break;
			case 2:
                system("cls");
                a->edit_information();
                style();
                system("cls");
                break;
            case 3:
                system("cls");
                add_flight();
                style();
                system("cls");
				break;
            case 4:
                system("cls");
				block_flight();
                style();
                system("cls");
				break;
            case 5:
                system("cls");
                resume_flight();
                style();
                system("cls");
                break;
            case 6:
                system("cls");
				schdule_flight();
                style();
                system("cls");
				break;
            case 7:
                remove_flight();
                style();
                system("cls");
                break;
            case 8:
                system("cls");
                print_flight();
				break;
            case 9:
                system("cls");
                restrict_it(); 
                style();
                system("cls");
                break;
            case 10:
                system("cls");
				print_passenger();
				break;
            case 11:
                system("cls");
                adminMenu = false;
                break;
            default:
                cout << "\nInvalid Choice\n";
				break;


            }
        }
    }

    void print_passenger()
    {
        cout << "\nTotal Passenger" << total_passengers << endl;

        for (int i = 0; i < total_passengers; i++)
        {
			Pass[i].print();
		}
	}
    void print_flight()
    {   int count = get_airport();
    cout << "\nINTERNATIONAL AIRLINES\n";

        airport[count]->printAirportDetails(0);
        cout << "\nLOCAL AIRLINES\n";
        airport[count]->printAirportDetails(1);
    }
    void remove_flight()
    {
        airport[get_airport()]->removeFlight();
    }
    void block_flight()
    {
        airport[get_airport()]->block_flight();
    }
    void resume_flight()
    {
		airport[get_airport()]->resume_flight();
	}
    void add_flight()
    {  
		

        airport[get_airport()]->add_new_flight();
		
    }

    void restrict_it()
    {
        airport[get_airport()]->restrict_seats();
    }

    void schdule_flight()
    {
		airport[get_airport()]->change_schedule();
	}

    int get_airport()
    {
        int airport_name;


        // Add some style to the airport selection
        cout << "\n\n";
     
        cout << "--------------------------------------------------\n";
        cout << "|        Please Select  Airport                   |\n";
        cout << "--------------------------------------------------\n";
        cout << "|  1. Islamabad North Airport                     |\n";
        cout << "|  2. Islamabad South Airport                     |\n";
        cout << "|  3. Lahore North Airport                        |\n";
        cout << "|  4. Lahore South Airport                        |\n";
        cout << "|  5. Karachi North Airport                       |\n";
        cout << "|  6. Karachi South Airport                       |\n";
        cout << "|  7. Peshawar North Airport                      |\n";
        cout << "|  8. Peshawar South Airport                      |\n";
        cout << "|  9. Quetta North Airport                        |\n";
        cout << "|  10. Quetta South Airport                       |\n";
        cout << "--------------------------------------------------\n";

        int choice;
        try {
            cin >> choice;
            if (!cin)
                throw 1;
        }
        catch (int x) {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            
        }
        switch (choice)
        {
        case 1:
            airport_name = 0;
            break;
        case 2:
            airport_name = 1;
            break;
        case 3:
            airport_name = 2;
            break;
        case 4:
            airport_name = 3;
            break;
        case 5:
            airport_name = 4;
            break;
        case 6:
            airport_name = 5;
            break;
        case 7:
            airport_name = 6;
            break;
        case 8:
            airport_name = 7;
            break;
        case 9:
            airport_name = 8;
            break;
        case 10:
            airport_name = 9;
            break;
        default:
            cout << "Invalid Choice";
            break;
        }
        cout << endl;
        return airport_name;
    }

    void booking(Passenger * P)
    {
        string date;
        
        cout << "Enter the Date (DD/MM/YY)\n";
        cin >> date;
        
        int airport_name=get_airport();
        int choice;
        cout << "1. International Flight\n";
        cout << "2. Domestic Flight\n";
        string passport, visa;
        string temp;
        Flight * f;
        f = new Flight();

        cin >> choice;





        switch (choice)
        {
        case 1:
        {
            do {
                cout << "Enter Passport Number\n";
                cin >> passport;
            } while (!isValidPassport(passport));
            do {
                cout << "Enter Visa Number\n";
                cin >> visa;

            } while (!isValidVisa(visa));

            P->setPassport(passport);
            P->setVisa(visa);

            international_flight_details(airport[airport_name]);

            cout << "Enter Flight Number\n";

            cin >> temp;

            f = searchFlight(temp, airport[airport_name]);

            while (f == NULL)
            {
                cout << "Flight Not Found\n";
                cout << "Enter Flight Number\n";
                cin >> temp;
                f = searchFlight(temp, airport[airport_name]);
            }

            f->book();

            cout << "\nPrize: ";
            cout << "\tTravel Prize: " << f->get_total_hours() * 20000;
            cout << "\tTax: " << f->get_total_hours() * 20000 * 0.1;

            float total = f->get_total_hours() * 20000 + f->get_total_hours() * 20000 * 0.1;
            cout << "\nDo you have Booked Previous Month. (Y/N)\n";
            char c;
            cin >> c;

            if (c == 'Y' || c == 'y')
            {
                total = total - total * 0.1;
            }
            P->set_ticket_prize(total);
            cout << "\tTotal Prize: " << P->get_ticket_prize();
            cout << "\n\n";
            add_booking(P, f, date);
            Book[total_bookings - 1].print();
            cout << "Confirm Booking? (Y/N)\n";
            cin >> c;
            P->setprize(P->getprize() - P->get_ticket_prize());












        }

        break;
        case 2:
        {
            do {
                cout << "Enter Passport Number\n";
                cin >> passport;
            } while (!isValidPassport(passport));


            P->setPassport(passport);
            P->setVisa("NULL");

            local_flight_details(airport[airport_name]);

            cout << "Enter Flight Number\n";

            cin >> temp;

            f = searchFlight(temp, airport[airport_name]);

            while (f == NULL)
            {
                cout << "Flight Not Found\n";
                cout << "Enter Flight Number\n";
                cin >> temp;
                f = searchFlight(temp, airport[airport_name]);
            }

            f->book();

            cout << "\nPrize: ";
            cout << "\tTravel Prize: " << f->get_total_hours() * 10000;
            cout << "\tTax: " << f->get_total_hours() * 10000 * 0.05;
            float total = f->get_total_hours() * 10000 + f->get_total_hours() * 10000 * 0.05;
            cout << "\nDo you have Booked Previous Month. (Y/N)\n";
            char c;
            cin >> c;

            if (c == 'Y' || c == 'y')
            {
                total = total - total * 0.1;
            }
            P->set_ticket_prize(total);
            cout << "\tTotal Prize: " << P->get_ticket_prize();
            cout << "\n\n";
            add_booking(P, f, date);
            Book[total_bookings - 1].print();
            cout << "Confirm Booking? (Y/N)\n";
            cin >> c;
            P->setprize(P->getprize() - P->get_ticket_prize());




        }
            break;
           default:
            cout << "Invalid Choice";
            break;




        }

        


    }

    bool isValidPassport(string passportNumber) {
        // Check that the passport number has 9 characters
        if (passportNumber.length() != 9) {
            return false;
        }

        // Check that the first two characters are letters
        if (!isalpha(passportNumber[0]) || !isalpha(passportNumber[1])) {
            return false;
        }

        // Check that the remaining characters are digits
        for (int i = 2; i < passportNumber.length(); i++) {
            if (!isdigit(passportNumber[i])) {
                return false;
            }
        }

        // If all checks pass, the passport number is valid
        return true;
    }

    bool isValidVisa(string visaNumber) {
        // Check that the visa number has 9 characters
        if (visaNumber.length() != 9) {
            return false;
        }

        // Check that the first two characters are letters
        if (!isalpha(visaNumber[0]) || !isalpha(visaNumber[1])) {
            return false;
        }

        // Check that the remaining characters are digits
        for (int i = 2; i < visaNumber.length(); i++) {
            if (!isdigit(visaNumber[i])) {
                return false;
            }
        }

        // If all checks pass, the visa number is valid
        return true;
    }

    Flight* searchFlight(string flightNumber, Airport* airport) {
		// Search for the flight in the airport
        for (int i = 0; i < 15 ; i++)
        {
            if (airport->getFlight(i)->get_Flight_number() == flightNumber)
            {
				return airport->getFlight(i);
			}
		}
		// If the flight is not found, return NULL
		return NULL;
	}

    void cancel_booking(Passenger * P)
    {
        int i;
        for (i = 0; i < total_bookings; i++)
        {
            if (Book[i].get_ID() == P->getID())
            {
				Book[i].cancel_Booking(P);
				break;
			}
		}
        if (i == total_bookings)
        {
			cout << "No Booking Found\n";
		}
    }

    void direct_cancel(Passenger * B)
    {
		int i;
        for (i = 0; i < total_bookings; i++)
        {
            if (Book[i].get_ID() == B->getID())
            {
                Book[i].direct_cancel(B);
            }
        }
    }


    void view_ticket(Passenger * P)
    {
        int i;

       

        for (i = 0; i < total_bookings; i++)
        {
           
          
            if (Book[i].get_ID() == P->getID())
            {
				Book[i].print();
				break;
                
			}
		}
        if (i == total_bookings)
        {
			cout << "No Booking Found\n";
		}
    }

    
    string get_password()
    {
        string password = "";  // store the password string
        char ch;  // store the user's input character

        cout << "Enter your password: ";

        // loop until user presses the Enter key
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') {  // handle backspace key
                if (!password.empty()) {
                    password.pop_back();  // remove the last character from password string
                    _putch('\b');  // move the cursor back one position
                    _putch(' ');  // overwrite the character with a blank space
                    _putch('\b');  // move the cursor back one position again
                }
            }
            else {
                password += ch;  // add the input character to password string
                _putch('*');  // print an asterisk on the console
            }
        }
        return password;
    }


};


int NAFS::total_admins = 0;
int NAFS::total_passengers = 0;
int Booking::total = 0;
int Booking::ID=0;
int NAFS::total_bookings = 0;


