# oob_project

This is a code implementation of a flight reservation system. The system consists of several
classes including account, Admin, Passenger, Flight, and Airport.
The account class is a parent class and has several member variables such as First, Second,
usernames, password, age, CNIC, card_number, card_holder_name, expiry_date, CVV,
dependant, and prize. It has default and parameterized constructors, getters, and setters for all
member variables. The class also has a register_user function that registers a new user with a
username, password, age, CNIC, and dependant.
The Admin class is a child class of the account class and has an additional member variable
admin_access. It has a default constructor and a parameterized constructor that initializes
member variables. It also has a function edit_information that allows the admin to edit the
information of a registered user.
The Passenger class is also a child class of the account class and has several member
variables including Destination, Departure, date, visa, Passport, ID, dependant_name,
dependant_cnic, dependant_relation, and ticket_prize. It has a default constructor and a
parameterized constructor that initializes member variables. The class also has a function
edit_information that allows the passenger to edit their information and a print function that
displays the passenger's information.
The Flight class has member variables such as Destination, Departure, start_Time,
end_Time, Flight_number, total_hours, local, business, seats, row, col, is blocked, indirect,
D1, and visited. It has default and parameterized constructors, a book function that books a
seat, a cancel function that cancels a seat, a print function that displays flight information, and
a restrict function that restricts a seat.
The Airport class has member variables such as name, flights, and numFlights. It has a
parameterized constructor that initializes the name variable. It also has functions such as
addFlight, removeFlight, add_new_flight, check_flight, short_details, block_flight, and
resume_flight. The addFlight function adds a new flight to the airport, the removeFlight
function removes a flight from the airport, the add_new_flight function adds a new flight to
the airport, the check_flight function checks whether a flight exists in the airport or not, the
short_details function displays short details of all flights, the block_flight function blocks a
flight, and the resume_flight function resumes a blocked flight.
In the implementation, OOP concepts such as inheritance, virtual functions, polymorphism,
operator overloading, and friend functions are used. The account, Admin, and Passenger
classes use inheritance where the child classes inherit member variables and functions from
the parent class. The account class also has a pure virtual function print that is overridden in
the child classes. The Passenger class also uses a friend function operator<< that overloads
the << operator to display the passenger's prize. The Airport class uses polymorphism where
a pointer to the Flight class is used as a parameter to the addFlight function. The Flight class
also uses operator overloading where the << operator is overloaded to display flight
information.
