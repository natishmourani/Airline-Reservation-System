#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void mainmenu();

class Management{
public:
    Management(){
        mainmenu();
    }
};

class Details{
public:
    string name, gender;
    string phonenumber;
    int age;
    string address;
    int cusid;

    void information(){
            cout << "\nENTER THE CUSTOMER ID: ";
    while (true){
        cin >> cusid;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer for CUSTOMER ID: ";
        } else{
            break;
        }
    }

    cout << "ENTER THE NAME: ";
    cin.ignore(); 
    getline(cin, name);

    cout << "ENTER THE PHONE NUMBER: ";
    while (true) {
        cin >> phonenumber;
        if (cin.fail() || phonenumber.find_first_not_of("0123456789") != string::npos ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid phone number (digits only): ";
        } else {
            break;
        }
    }

    cout << "ENTER THE AGE: ";
    while (true){
        cin >> age;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number for AGE: ";
        } else if(age <= 0 || age > 120){
            cout << "Invalid input. Please enter a valid number for AGE: ";
        } else{
        	break;
		}
    }

    cout << "ADDRESS: ";
    cin.ignore(); 
    getline(cin, address);

    cout << "GENDER: ";
    while (true){
    	cin >> gender;
    	if (cin.fail() || (gender != "M" && gender != "F" && gender != "m" && gender != "f")) {
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	cout << "Invalid input. Please enter male or female (m/f): ";
    	} else {
        	break;
    	}
	}

    cout << "\nYOUR DETAILS ARE SAVED WITH US\n" << endl;
}
    

    friend ostream& operator<<(ostream& os,  Details dt);
    friend istream& operator>>(istream& is, Details dt);

};
ostream& operator<<(ostream& os,  Details dt){
    os << "\nCUSTOMER ID: " << dt.cusid << endl;
    os << "NAME: " << dt.name << endl;
    os << "PHONE NUMBER: " << dt.phonenumber << endl;
    os << "AGE: " << dt.age << endl;
    os << "ADDRESS: " << dt.address << endl;
    os << "GENDER: " << dt.gender << endl;
    return os;
}

istream& operator>>(istream& is, Details dt){
    cout << "\nENTER THE CUSTOMER ID: ";
    is >> dt.cusid;
    cout << "ENTER THE NAME: ";
    is >> dt.name;
    cout << "ENTER THE PHONE NUMBER: ";
    is >> dt.phonenumber;
    cout << "ENTER THE AGE: ";
    is >> dt.age;
    cout << "ADDRESS: ";
    is.ignore();
    getline(is, dt.address);
    cout << "GENDER: ";
    is >> dt.gender;
    return is;
}

class Registration{
public:
    static int choice;
    static float charges;
    int choicel;
    int back;
    
    void flights(){
        string flightarr[] = { "KARACHI", "LAHORE", "ISLAMABAD", "QUETTA","PESHAWAR","SKARDU" };
        for (int i = 0; i < 6; i++) {
            cout << (i + 1) << ". Flight to " << flightarr[i] << endl;
        }
        cout << "\nWELCOME TO THE AIRLINES!" << endl;
        cout << "PRESS THE NUMBER OF THE CITY TO WHICH YOU WANT TO BOOK THE FLIGHT: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "WELCOME TO KARACHI-AIRLINE\n" << endl;
                cout << "YOUR COMFORT IS OUR PRIORITY. ENJOY YOUR FLIGHT!" << endl;
                cout << "FOLLOWING ARE THE FLIGHTS TO KARACHI\n" << endl;

                cout << "1. KHI-65\n\t09-06-2024 6:00 pm 3hrs RS. 30000" << endl;
                cout << "2. KHI-101\n\t09-06-2024 12:00 am 2hrs RS. 32000" << endl;
                cout << "3. KHI-009\n\t15-06-2024 1:00 pm 2.5hrs RS. 35000" << endl;

                cout << "\nSELECT THE FLIGHT YOU WANT TO BOOK: ";
                cin >> choicel;

                if (choicel == 1) {
                    charges = 30000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT KHI-65" << endl;
                } else if (choicel == 2) {
                    charges = 32000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT KHI-101" << endl;
                } else if (choicel == 3) {
                    charges = 35000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT KHI-009" << endl;
                } else {
                    cout << "Invalid input, shifting to the previous menu" << endl;
                    flights();
                }
                cout << "PRESS ANY KEY TO GO BACK TO MAIN MENU ";
                cin >> back;
                if (back == 1) {
                    mainmenu();
                } else {
                    mainmenu();
                }
                break;
            }
            case 2: {
                cout << "WELCOME TO LAHORE-AIRLINE\n" << endl;
                cout << "YOUR COMFORT IS OUR PRIORITY. ENJOY YOUR FLIGHT!" << endl;
                cout << "FOLLOWING ARE THE FLIGHTS TO LAHORE\n" << endl;

                cout << "1. LHR-001\n\t26-06-2024 6:00 pm 2hrs RS. 29000" << endl;
                cout << "2. LHR-099\n\t18-06-2024 12:00 am 2.5hrs RS. 26000" << endl;
                cout << "3. LHR-655\n\t15-06-2024 1:00 pm 2.5hrs RS. 30000" << endl;

                cout << "\nSELECT THE FLIGHT YOU WANT TO BOOK: ";
                cin >> choicel;

                if (choicel == 1) {
                    charges = 29000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT LHR-001" << endl;
                } else if (choicel == 2) {
                    charges = 26000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT LHR-099" << endl;
                } else if (choicel == 3) {
                    charges = 30000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT LHR-655" << endl;
                } else {
                    cout << "Invalid input, shifting to the previous menu" << endl;
                    flights();
                }
                cout << "PRESS ANY KEY TO GO BACK TO MAIN MENU ";
                cin >> back;
                if (back == 1) {
                    mainmenu();
                } else {
                    mainmenu();
                }
                break;
            }
            case 3: {
                cout << "WELCOME TO ISLAMABAD-AIRLINE\n" << endl;
                cout << "YOUR COMFORT IS OUR PRIORITY. ENJOY YOUR FLIGHT!" << endl;
                cout << "FOLLOWING ARE THE FLIGHTS TO ISLAMABAD\n" << endl;

                cout << "1. ISL-500\n\t09-06-2024 6:00 pm 3hrs RS. 16000" << endl;
                cout << "2. ISL-007\n\t09-09-2024 12:00 am 2hrs RS. 19000" << endl;
                cout << "3. ISL-321\n\t15-12-2024 1:00 pm 2.5hrs RS. 20000" << endl;

                cout << "\nSELECT THE FLIGHT YOU WANT TO BOOK: ";
                cin >> choicel;

                if (choicel == 1) {
                    charges = 16000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT ISL-500" << endl;
                } else if (choicel == 2) {
                    charges = 19000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT ISL-007" << endl;
                } else if (choicel == 3) {
                    charges = 20000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT ISL-321" << endl;
                } else {
                    cout << "Invalid input, shifting to the previous menu" << endl;
                    flights();
                }
                cout << "PRESS ANY KEY TO GO BACK TO MAIN MENU ";
                cin >> back;
                if (back == 1) {
                    mainmenu();
                } else {
                    mainmenu();
                }
                break;
            }
            case 4: {
                cout << "WELCOME TO QUETTA-AIRLINE\n" << endl;
                cout << "YOUR COMFORT IS OUR PRIORITY. ENJOY YOUR FLIGHT!" << endl;
                cout << "FOLLOWING ARE THE FLIGHTS TO QUETTA\n" << endl;

                cout << "1. QTA-65\n\t09-06-2024 6:00 pm 3hrs RS. 30000" << endl;
                cout << "2. QTA-101\n\t09-06-2024 12:00 am 2hrs RS. 32000" << endl;
                cout << "3. QTA-009\n\t15-06-2024 1:00 pm 2.5hrs RS. 35000" << endl;

                cout << "\nSELECT THE FLIGHT YOU WANT TO BOOK: ";
                cin >> choicel;

                if (choicel == 1) {
                    charges = 30000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT QTA-65" << endl;
                } else if (choicel == 2) {
                    charges = 32000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT QTA-101" << endl;
                } else if (choicel == 3) {
                    charges = 35000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT QTA-009" << endl;
                } else {
                    cout << "Invalid input, shifting to the previous menu" << endl;
                    flights();
                }
                cout << "PRESS ANY KEY TO GO BACK TO MAIN MENU ";
                cin >> back;
                if (back == 1) {
                    mainmenu();
                } else {
                    mainmenu();
                }
                break;
            }
             case 5: {
                cout << "WELCOME TO PESHAWAR-AIRLINE\n" << endl;
                cout << "YOUR COMFORT IS OUR PRIORITY. ENJOY YOUR FLIGHT!" << endl;
                cout << "FOLLOWING ARE THE FLIGHTS TO PESHAWAR\n" << endl;

                cout << "1. PHS-65\n\t09-06-2024 6:00 pm 3hrs RS. 30000" << endl;
                cout << "2. PHS-101\n\t09-06-2024 12:00 am 2hrs RS. 32000" << endl;
                cout << "3. PHS-009\n\t15-06-2024 1:00 pm 2.5hrs RS. 35000" << endl;

                cout << "\nSELECT THE FLIGHT YOU WANT TO BOOK: ";
                cin >> choicel;

                if (choicel == 1) {
                    charges = 30000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT PHS-65" << endl;
                } else if (choicel == 2) {
                    charges = 32000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT PHS-101" << endl;
                } else if (choicel == 3) {
                    charges = 35000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT PHS-009" << endl;
                } else {
                    cout << "Invalid input, shifting to the previous menu" << endl;
                    flights();
                }
                cout << "PRESS ANY KEY TO GO BACK TO MAIN MENU ";
                cin >> back;
                if (back == 1) {
                    mainmenu();
                } else {
                    mainmenu();
                }
                break;
            }
             case 6: {
                cout << "WELCOME TO SKARDU-AIRLINE\n" << endl;
                cout << "YOUR COMFORT IS OUR PRIORITY. ENJOY YOUR FLIGHT!" << endl;
                cout << "FOLLOWING ARE THE FLIGHTS TO SKARDU\n" << endl;

                cout << "1. SDU-65\n\t09-06-2024 6:00 pm 3hrs RS. 30000" << endl;
                cout << "2. SDU-101\n\t09-06-2024 12:00 am 2hrs RS. 32000" << endl;
                cout << "3. SDU-009\n\t15-06-2024 1:00 pm 2.5hrs RS. 35000" << endl;

                cout << "\nSELECT THE FLIGHT YOU WANT TO BOOK: ";
                cin >> choicel;

                if (choicel == 1) {
                    charges = 30000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT SDU-65" << endl;
                } else if (choicel == 2) {
                    charges = 32000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT SDU-101" << endl;
                } else if (choicel == 3) {
                    charges = 35000;
                    cout << "\nYOU HAVE SUCCESSFULLY BOOKED THE FLIGHT SDU-009" << endl;
                } else {
                    cout << "Invalid input, shifting to the previous menu" << endl;
                    flights();
                }
                cout << "PRESS ANY KEY TO GO BACK TO MAIN MENU ";
                cin >> back;
                if (back == 1) {
                    mainmenu();
                } else {
                    mainmenu();
                }
                break;
            }
            default: {
                cout << "Invalid input, shifting to the main menu!" << endl;
                mainmenu();
                break;
            }
        }
    }
};

int Registration::choice;
float Registration::charges;

class Ticket{
public:
    void bill(const vector<Details>& passengers){
        cout << "\n____INVOICE____\n" << endl;
        for (const auto& passenger : passengers){
            ofstream outf("passenger_" + to_string(passenger.cusid) + ".txt");
            if (outf.is_open()){
                outf << "\n____INVOICE____\n" << endl;
                outf << "CUSTOMER ID: " << passenger.cusid << endl;
                outf << "NAME: " << passenger.name << endl;
                outf << "PHONE NUMBER: " << passenger.phonenumber << endl;
                outf << "AGE: " << passenger.age << endl;
                outf << "ADDRESS: " << passenger.address << endl;
                outf << "GENDER: " << passenger.gender << endl;
                outf << "\nDescription\n" << endl;
                
                if (Registration::choice == 1){
        		    outf << "Destination: KARACHI" << endl;
        		}else if (Registration::choice == 2){
        		    outf << "Destination: LAHORE" << endl;
        		}else if (Registration::choice == 3){
        	    	outf << "Destination: ISLAMABAD" << endl;
        		}else if (Registration::choice == 4){
        	    	outf << "Destination: QUETTA" << endl;
        		}else if (Registration::choice == 5){
        	    	outf << "Destination: PESHAWAR" << endl;
        		}else if (Registration::choice == 6){
        	    	outf << "Destination: SKARDU" << endl;
        		}
                
                outf << "Flight cost: " << fixed << setprecision(2) << Registration::charges << endl;
                outf.close();
                cout << "\nINVOICE FOR " << passenger.name << " GENERATED AND SAVED AS passenger_" << passenger.cusid << ".txt\n" << endl;
            } else{
                cout << "Unable to open file for passenger ID " << passenger.cusid << endl;
            }
        }
    }
};

vector<Details> passengers;

void mainmenu(){
    int lchoice;
    int back;
    Registration r;
    Ticket t;

    cout << "\t\t\t                      GALAXY AIRWAYS                     \n" << endl;
    cout << "\t\t\t  ______________________MAIN MENU_________________________" << endl;
    cout << "\t\t\t  ________________________________________________________" << endl;
    cout << "\t\t\t |                                                        |" << endl;
    cout << "\t\t\t |      Press 1 to add customer details                   |" << endl;
    cout << "\t\t\t |      Press 2 for flight registration                   |" << endl;
    cout << "\t\t\t |      Press 3 to generate ticket                        |" << endl;
    cout << "\t\t\t |      Press 4 to exit                                   |" << endl;
    cout << "\t\t\t |                                                        |" << endl;
    cout << "\t\t\t |________________________________________________________|\n" << endl;

    cout << "Enter your choice: ";
    cin >> lchoice;

    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input, Please try again. " << endl;
        return mainmenu();
    }

    switch (lchoice){
        case 1: {
            int num_passengers;
            cout << "Enter the number of passengers: ";
            cin >> num_passengers;

            if (cin.fail() || num_passengers < 1){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number of passengers.\nReturning to main menu...\n";
                return mainmenu();
            }

            for (int i = 0; i < num_passengers; ++i){
                Details d;
                cout << "\nEnter details for passenger " << i + 1 << ":" << endl;
                d.information();
                passengers.push_back(d);
            }
            cout << "Press any key to go back to main menu: ";
            cin >> back;
            return mainmenu();
        }

        case 2: {
            if (passengers.empty()) {   // ✅ cannot register flight without passengers
                cout << "You must add customer details first before registering a flight!\n";
                return mainmenu();
            }
            r.flights();
            break;
        }

        case 3: {
            if (passengers.empty()) {   // ✅ must add customer first
                cout << "You must add customer details before generating a ticket!\n";
                return mainmenu();
            }
            if (Registration::choice == 0) {  // ✅ must register flight first
                cout << "You must register a flight before generating a ticket!\n";
                return mainmenu();
            }

            t.bill(passengers);    
            cout << "Your tickets are printed, you can collect them.\n" << endl;
            cout << "Press any key to go back to main menu: ";
            cin >> back;
            return mainmenu();
        }

        case 4: {
            cout << "\n\n\t_________THANK YOU_________\n" << endl;
            break;
        }

        default: {
            cout << "Invalid input, please try again.\nReturning to main menu...\n";
            return mainmenu();
        }
    }
}



int main(){
	
    cout << endl << endl; 
    cout << "\t\t     ************************************************************" << endl;
    cout << "\t\t     *                                                          *" << endl;
    cout << "\t\t     *                      OOP PROJECT                         *" << endl;
    cout << "\t\t     *              AIRLINE REGISTRATION SYSTEM                 *" << endl;
    cout << "\t\t     *                                                          *" << endl;
    cout << "\t\t     *           Developed by:                                  *" << endl;
    cout << "\t\t     *             Natish                                       *" << endl;
    cout << "\t\t     *             Basil Shaukat                                *" << endl;
    cout << "\t\t     *             Ali Amir                                     *" << endl;
    cout << "\t\t     *                                                          *" << endl;
    cout << "\t\t     *       _____________________________________________      *" << endl;
    cout << "\t\t     *                                                          *" << endl;
    cout << "\t\t     *         Welcome to the Airline Registration System       *" << endl;
    cout << "\t\t     *         Please follow the instructions to proceed        *" << endl;
    cout << "\t\t     *                                                          *" << endl;
    cout << "\t\t     ************************************************************" << endl;
    cout << endl << endl << endl;

    Management m;
    
    return 0;
}
