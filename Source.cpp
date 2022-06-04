#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include <conio.h>
#include <windows.h>
#include<stdio.h>
#include<ctype.h>

using namespace std;

//admin
void admin_login();
void admin_page();
void add_trip();
void update_trips();
void delete_trips();
void admin_show_reservations();
void admin_show_user();

//user
void user_page();
void user_login();
void registr();
void forgot();
void reserve_a_trip(char[25]);
void change_reservation(char[25]);
void user_reservations_history(char[25]);
void user_cancel_reservation(char[25]);
void updatetrip(char ID[25], char NUM[25], int num);

//others
void successful(char[25]);
bool checkmail(char[25]);
bool unique(char[25]);
void credit_card();
void cash();
void mobile_payments();
bool checkphone(char phonenum[25]);



struct date {

    int month;
    int day;
    int year;
};

struct datee
{
    char day[25];
    char month[25];
    char year[25];
};


bool CheckDate(datee);

struct trip {
    int id;
    string destination;
    date start_date;
    date end_date;
    string transportation;
    string hotel_name;
    char hotel_address[20];
    int max_no_reservation;
    int no_of_reservations = 0;
    double trip_cost;
} t;

struct TripInfo
{
    char id[25];
    char destination[25];
    char startdate[25];
    char enddate[25];
    char transportation[25];
    char h_name[25];
    char h_address[25];
    char maxnum[25];
    char numof[25];
    char cost[25];
};

struct ReservationsInfo
{
    char username[25];
    char id[25];
    char destination[25];
    datee startdate;
    char enddate[25];
    char transportation[25];
    char h_name[25];
    char h_address[25];
    char maxnum[25];
    char numof[25];
    char cost[25];
    char numofpeople[25];
    char payment[25];
};

struct reservation {
    int people_no;
    int payment_method;

};

struct card {
    string card_name;
    int card_number;
    string month;
    int year;
    string security_code;
};


int main()
{

    cout << "                              \t\t WELCOME TO TOURIST RESERVATION SYSTEM\n\n\n";
    cout << "                                   \t    TOURIST RESERVATION SOFTWARE\n\n\n";
    cout << "                                     \t      PRESS ENTER TO CONTINUE....\n\n";
    if (cin.get() == '\n') {
        system("cls");
        int choice;
        cout << "\n Who are You?\n";
        cout << "1. ADMIN\n";
        cout << "2. USER\n\n";
        cout << "Enter any other key for exit\n\n\n";
        cout << "Enter Your Option\n";
        cin >> choice;
        switch (choice) {
        case 1:
            admin_login();
            break;
        case 2:
            user_page();
            break;
        default:
            exit(0);
        }
    }

}


void admin_login() {
    system("CLS");
    int charcount = 0;
    char ch;
    string username;
    string admin_username = "fcis_asu";
    char correct[] = "fcis2024";
    int trials = 0;
    bool verified = true;

    do
    {
        cout << "Enter your username:";
        cin >> username;
        cout << "Enter your password:";
        ch = _getch();
        int i = 0;
        verified = true;

        while (ch != '\r')
        {
            cout << "*";
            if (ch != correct[i++])
                verified = false;
            ch = _getch();
        }

        if (!verified) {
            cout << "\nWrong password !" << endl;
            trials++;
        }
        else if (verified && username == admin_username)
        {
            cout << "\nLogin successfully" << endl;
            admin_page();
        }
        else
            cout << "\nWrong Username" << endl;
        trials++;
    } while (!verified && trials <= 3 && username == admin_username || !verified && trials <= 3 || username != admin_username && trials <= 3);


}

void admin_page() {
    system("cls");
    int choice;
    cout << "                              \t\t WELCOME ADMIN\n\n\n";
    cout << "                                   \t    MENU\n\n\n";
    cout << "1.ADD TRIPS" << endl;
    cout << "2.UPDATE TRIPS INFORMATIONS" << endl;
    cout << "3.DELETE TRIPS" << endl;
    cout << "4.SHOW ALL RESERVATIONS" << endl;
    cout << "5.SHOW ALL USERS" << endl;
    cout << "6.LOGOUT" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        add_trip();
        break;
    case 2:
        update_trips();
        break;
    case 3:
        delete_trips();
        break;
    case 4:
        admin_show_reservations();
        break;
    case 5:
        admin_show_user();
        break;
    case 6:
        main();
        break;
    default:
        system("cls");
        cout << "You've made a mistake , give it a try again\n" << endl;
        main();
    }

}

void add_trip() {

    system("CLS");

    fstream out_file;
    bool flag = true;
    do {
        cout << "\nTrip ID: ";
        cin >> t.id;
        cout << "\nDestination: ";
        cin >> t.destination;

        cout << "\nStart Date (dd/mm/yyyy) \n";
        cin >> t.start_date.day >> t.start_date.month >> t.start_date.year;
        cout << "\nEnd Date (dd/mm/yyyy)\n";
        cin >> t.end_date.day >> t.end_date.month >> t.end_date.year;

        cout << "\nTransportation: ";
        cin >> t.transportation;
        cout << "\nHotel Name: ";
        cin >> t.hotel_name;
        cout << "\nHotel Address: ";
        cin.ignore();
        cin.getline(t.hotel_address, 20);
        cout << "\nMax No.Reservations: ";
        cin >> t.max_no_reservation;
        cout << "\nTrip Cost: ";
        cin >> t.trip_cost;


        out_file.open("trips.txt", ios::app);
        if (out_file.is_open())
        {
            bool flag = true;
            out_file << "\n\nTrip ID:" << t.id << endl;
            out_file << "Destination:" << t.destination << endl;
            out_file << "Start Date:" << t.start_date.day << "/" << t.start_date.month << "/" << t.start_date.year << endl;
            out_file << "End Date:" << t.end_date.day << "/" << t.end_date.month << "/" << t.end_date.year << endl;
            out_file << "Transportation:" << t.transportation << endl;
            out_file << "Hotel Name:" << t.hotel_name << endl;
            out_file << "Hotel Address:" << t.hotel_address << endl;
            out_file << "Max No.Reservations:" << t.max_no_reservation << endl;
            out_file << "Number of Reservations:" << t.no_of_reservations << endl;
            out_file << "Trip Cost:" << t.trip_cost;
            system("CLS");
        }
        out_file.close();
        cout << "Would you like to enter another trip? \n 1.Yes \n 2.No" << endl;
        int x;
        cin >> x;
        system("CLS");
        if (x != 1) {
            flag = false;
        }

    } while (flag == true);
    int menu;
    cout << "\npress 1 to return to main menu\n";
    cin >> menu;
    if (menu == 1) {
        admin_page();
    }
    else
        exit(0);
}


void update_trips() {

    fstream out_file;
    char id[25], idinfo[25], destination[25], destinationinfo[25], startdate[25], startdateinfo1[25], startdateinfo2[25], startdateinfo3[25], enddate[25], enddateinfo1[25], enddateinfo2[25], enddateinfo3[25], transportation[25], transportationinfo[25], hotelname[25], hotelnameinfo[25], hoteladress[50], hoteladressinfo[25], maxnum[25], maxnuminfo[25],/* resnum[25], resnuminfo[25]*/ tripcost[25], tripcostinfo[25], a[25];
    int count = 1, count1 = 0;
    char resnum[25], resnuminfo[25];

    out_file.open("Trips.txt", ios::in);
    fstream temp;
    temp.open("temp.txt", ios::out);

    cout << "please enter id " << endl;

    cin >> a;



    while (!out_file.eof())
    {


        out_file.getline(id, 25, ':');
        out_file.getline(idinfo, 25);
        out_file.getline(destination, 25, ':');
        out_file.getline(destinationinfo, 25);
        out_file.getline(startdate, 25, ':');
        out_file.getline(startdateinfo1, 25, '/');
        out_file.getline(startdateinfo2, 25, '/');
        out_file.getline(startdateinfo3, 25);
        out_file.getline(enddate, 25, ':');
        out_file.getline(enddateinfo1, 25, '/');
        out_file.getline(enddateinfo2, 25, '/');
        out_file.getline(enddateinfo3, 25);
        out_file.getline(transportation, 25, ':');
        out_file.getline(transportationinfo, 25);
        out_file.getline(hotelname, 25, ':');
        out_file.getline(hotelnameinfo, 25);
        out_file.getline(hoteladress, 25, ':');
        out_file.getline(hoteladressinfo, 25);
        out_file.getline(maxnum, 25, ':');
        out_file.getline(maxnuminfo, 25);
        out_file.getline(resnum, 25, ':');
        out_file.getline(resnuminfo, 25);
        out_file.getline(tripcost, 25, ':');
        out_file.getline(tripcostinfo, 25);


        bool flag = true;

        if (strcmp(a, idinfo) == 0)


        {



            cout << "please enter new destination" << endl;
            cin >> destinationinfo;

            cout << "please enter new start date " << endl;
            cin >> startdateinfo1 >> startdateinfo2 >> startdateinfo3;

            cout << "please enter new end date " << endl;
            cin >> enddateinfo1 >> enddateinfo2 >> enddateinfo3;

            cout << "please enter new mean of transportation" << endl;
            cin >> transportationinfo;

            cout << "please enter new hotel name" << endl;
            cin >> hotelnameinfo;

            cout << "please enter new hotel address" << endl;
            cin >> hoteladressinfo;

            cout << "please enter new maximum number of seats" << endl;
            cin >> maxnuminfo;

            cout << "please enter new number of reservations" << endl;
            cin >> resnuminfo;

            cout << "please enter new trip cost " << endl;
            cin >> tripcostinfo;

            temp << "\nId" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "number of reservations" << ":" << resnuminfo << endl << "Tripcost" << ":" << tripcostinfo;

        }
        else
        {

            temp << "\nId" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "number of reservations" << ":" << resnuminfo << endl << "Tripcost" << ":" << tripcostinfo;


        }

        count++;
    }
    temp.close();
    out_file.close();




    out_file.open("Trips.txt", ios::out);
    temp.open("temp.txt", ios::in);

    while (!temp.eof())
    {

        temp.getline(id, 25, ':');
        temp.getline(idinfo, 25);
        temp.getline(destination, 25, ':');
        temp.getline(destinationinfo, 25);
        temp.getline(startdate, 25, ':');
        temp.getline(startdateinfo1, 25, '/');
        temp.getline(startdateinfo2, 25, '/');
        temp.getline(startdateinfo3, 25);
        temp.getline(enddate, 25, ':');
        temp.getline(enddateinfo1, 25, '/');
        temp.getline(enddateinfo2, 25, '/');
        temp.getline(enddateinfo3, 25);
        temp.getline(transportation, 25, ':');
        temp.getline(transportationinfo, 25);
        temp.getline(hotelname, 25, ':');
        temp.getline(hotelnameinfo, 25);
        temp.getline(hoteladress, 25, ':');
        temp.getline(hoteladressinfo, 50);
        temp.getline(maxnum, 25, ':');
        temp.getline(maxnuminfo, 25);
        temp.getline(resnum, 25, ':');
        temp.getline(resnuminfo, 25);
        temp.getline(tripcost, 25, ':');
        temp.getline(tripcostinfo, 25);

        out_file << "\nId" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "number of reservations" << ":" << resnuminfo << endl << "Tripcost" << ":" << tripcostinfo;

        count1++;



    }

    temp.close();
    out_file.close();

    system("CLS");
    cout << "       \tDONE!       " << endl;

    remove("temp.txt");

    int menu;
    cout << "\npress 1 to return to main menu\n";
    cin >> menu;
    if (menu == 1) {
        admin_page();
    }
    else
        exit(0);

}


void delete_trips()
{
    system("CLS");
    char id[25];
    char destination[25];
    char startdate[25];
    char enddate[25];
    char transportation[25];
    char h_name[25];
    char h_address[25];
    char maxnum[25];
    char numof[25];
    char cost[25];
    char ID[25];
    int counter = 1, x, y;
    bool flag = false;

    fstream trips;
    fstream temp;

    do
    {
        trips.open("trips.txt", ios::in);
        temp.open("Temp.txt", ios::out);
        TripInfo t;
        cout << "Please enter the ID of the trip you want to delete:";
        cin >> ID;
        while (!trips.eof())
        {
            trips.getline(id, 25, ':');
            trips.getline(t.id, 25);
            trips.getline(destination, 25, ':');
            trips.getline(t.destination, 25);
            trips.getline(startdate, 25, ':');
            trips.getline(t.startdate, 25);
            trips.getline(enddate, 25, ':');
            trips.getline(t.enddate, 25);
            trips.getline(transportation, 25, ':');
            trips.getline(t.transportation, 25);
            trips.getline(h_name, 25, ':');
            trips.getline(t.h_name, 25);
            trips.getline(h_address, 25, ':');
            trips.getline(t.h_address, 25);
            trips.getline(maxnum, 25, ':');
            trips.getline(t.maxnum, 25);
            trips.getline(numof, 25, ':');
            trips.getline(t.numof, 25);
            trips.getline(cost, 25, ':');
            trips.getline(t.cost, 25);




            if (!strcmp(t.id, ID))
                continue;
            else
            {
                if (counter != 1)
                    temp << endl;
                temp << "Trip ID:" << t.id << endl << "Destination:" << t.destination << endl << "Start Date :" << t.startdate << endl << "End Date :" << t.enddate << endl << "Transportation :" << t.transportation << endl << "Hotel Name :" << t.h_name << endl << "Hotel Address :" << t.h_address << endl << "Max No.Reservations :" << t.maxnum << endl << "Number of Reservations :" << t.numof << endl << "Trip Cost :" << t.cost;
            }
            counter++;
        }
        trips.close();
        temp.close();

        trips.open("Trips.txt", ios::out);
        temp.open("Temp.txt", ios::in);
        counter = 1;

        while (!temp.eof())
        {
            temp.getline(id, 25, ':');
            temp.getline(t.id, 25);
            temp.getline(destination, 25, ':');
            temp.getline(t.destination, 25);
            temp.getline(startdate, 25, ':');
            temp.getline(t.startdate, 25);
            temp.getline(enddate, 25, ':');
            temp.getline(t.enddate, 25);
            temp.getline(transportation, 25, ':');
            temp.getline(t.transportation, 25);
            temp.getline(h_name, 25, ':');
            temp.getline(t.h_name, 25);
            temp.getline(h_address, 25, ':');
            temp.getline(t.h_address, 25);
            temp.getline(maxnum, 25, ':');
            temp.getline(t.maxnum, 25);
            temp.getline(numof, 25, ':');
            temp.getline(t.numof, 25);
            temp.getline(cost, 25, ':');
            temp.getline(t.cost, 25);

            if (counter != 1)
                trips << endl;
            trips << "Trip ID:" << t.id << endl << "Destination:" << t.destination << endl << "Start Date :" << t.startdate << endl << "End Date :" << t.enddate << endl << "Transportation :" << t.transportation << endl << "Hotel Name :" << t.h_name << endl << "Hotel Address :" << t.h_address << endl << "Max No.Reservations :" << t.maxnum << endl << "Number of Reservations :" << t.numof << endl << "Trip Cost :" << t.cost;

            counter++;
        }
        trips.close();
        temp.close();
        remove("Temp.txt");

        system("cls");
        cout << "\tCancelation successful!" << endl;
        cout << "Would you like to cancel another trip?\n1.Yes\n2.No" << endl;
        cin >> x;
        system("CLS");
        if (x == 1)
            flag = true;
        else
            flag = false;

    } while (flag == true);

    int menu;
    cout << "\npress 1 to return to main menu\n";
    cin >> menu;
    if (menu == 1) {
        admin_page();
    }
    else
        exit(0);

}


void admin_show_reservations() {

    system("CLS");

    int choice;
    fstream reservation;
    char id[20], input_user[20], info1[20], people[20], method[20], user_name[20], info13[20], destination[20], date1[20], date2[20], transportation[20], name[20], address[20], max[30], num[30], cost[20], info2[20], info3[20], info4[20], info5[20], info6[20], info7[20], info8[20], info9[20], info10[20], info11[20], info12[20];

    cout << "\n1.Show all trips reservations\n";
    cout << "2.Show specific trip reservations\n\n";
    cout << "Enter any other key for exit\n\n\n";
    cout << "\n\nEnter Your Option\n";
    cin >> choice;
    if (choice == 1) {

        reservation.open("reservations.txt", ios::in);
        if (reservation.is_open()) {
            string line;
            while (getline(reservation, line)) {
                cout << line << endl;
            }
            reservation.close();
        }
        int menu;
        cout << "\npress 1 to return to main menu\n";
        cin >> menu;
        if (menu == 1) {
            admin_page();
        }
        else
            exit(0);

    }
    else if (choice == 2) {
        char trip_id[10];
        cout << "Enter trip id: ";
        cin >> trip_id;
        reservation.open("reservations.txt", ios::in);
        while (!reservation.eof()) {
            reservation.getline(user_name, 20, ':');
            reservation.getline(info1, 20);
            reservation.getline(id, 20, ':');
            reservation.getline(info2, 20);
            reservation.getline(destination, 20, ':');
            reservation.getline(info3, 20);
            reservation.getline(date1, 20, ':');
            reservation.getline(info4, 20);
            reservation.getline(date2, 20, ':');
            reservation.getline(info5, 20);
            reservation.getline(transportation, 20, ':');
            reservation.getline(info6, 20);
            reservation.getline(name, 20, ':');
            reservation.getline(info7, 20);
            reservation.getline(address, 20, ':');
            reservation.getline(info8, 20);
            reservation.getline(max, 30, ':');
            reservation.getline(info9, 20);
            reservation.getline(num, 30, ':');
            reservation.getline(info10, 20);
            reservation.getline(cost, 20, ':');
            reservation.getline(info11, 20);
            reservation.getline(people, 20, ':');
            reservation.getline(info12, 20);
            reservation.getline(method, 20, ':');
            reservation.getline(info13, 20);

            if (!strcmp(trip_id, info2)) {
                cout << user_name << ": " << info1 << endl << id << ": " << info2 << endl << destination << ": " << info3 << endl << date1 << ": " << info4 << endl << date2 << ": " << info5 << endl << transportation << ": " << info6 << endl << name << ": " << info7 << endl << address << ": " << info8 << endl << max << ": " << info9 << endl << num << ": " << info10 << endl << cost << ": " << info11 << endl << people << ": " << info12 << endl << method << ": " << info13 << endl << endl;

            }

        }
        int menu;
        cout << "\npress 1 to return to main menu\n";
        cin >> menu;
        if (menu == 1) {
            admin_page();
        }
        else
            exit(0);




    }
    else
        exit(0);
}

void admin_show_user() {

    system("CLS");

    int choice;
    fstream users;
    char id[20], input_user[20], info1[20], people[20], method[20], user_name[20], info13[20], destination[20], date1[20], date2[20], transportation[20], name[20], address[20], max[30], num[30], cost[20], info2[20], info3[20], info4[20], info5[20], info6[20], info7[20], info8[20], info9[20], info10[20], info11[20], info12[20];

    cout << "\n1.Show all users\n";
    cout << "2.Show users with certain reservations\n\n";
    cout << "Enter any other key for exit\n\n\n";
    cout << "\nEnter Your Option\n";
    cin >> choice;
    if (choice == 1) {
        users.open("database.txt", ios::in);
        if (users.is_open()) {
            string line;
            while (getline(users, line)) {
                cout << line << endl;

            }
        }
        int menu;
        cout << "\npress 1 to return to main menu\n";
        cin >> menu;
        if (menu == 1) {
            admin_page();
        }
        else
            exit(0);
    }
    else if (choice == 2) {
        char trip_id[10];
        cout << "Enter trip id: ";
        cin >> trip_id;
        users.open("reservations.txt", ios::in);
        if (users.is_open()) {
            while (!users.eof()) {
                users.getline(user_name, 20, ':');
                users.getline(info1, 20);
                users.getline(id, 20, ':');
                users.getline(info2, 20);
                users.getline(destination, 20, ':');
                users.getline(info3, 20);
                users.getline(date1, 20, ':');
                users.getline(info4, 20);
                users.getline(date2, 20, ':');
                users.getline(info5, 20);
                users.getline(transportation, 20, ':');
                users.getline(info6, 20);
                users.getline(name, 20, ':');
                users.getline(info7, 20);
                users.getline(address, 20, ':');
                users.getline(info8, 20);
                users.getline(max, 30, ':');
                users.getline(info9, 20);
                users.getline(num, 30, ':');
                users.getline(info10, 20);
                users.getline(cost, 20, ':');
                users.getline(info11, 20);
                users.getline(people, 20, ':');
                users.getline(info12, 20);
                users.getline(method, 20, ':');
                users.getline(info13, 20);

                if (!strcmp(trip_id, info2)) {
                    cout << endl << user_name << ": " << info1 << endl;
                }
            }

            int menu;
            cout << "\npress 1 to return to main menu\n";
            cin >> menu;
            if (menu == 1) {
                admin_page();
            }
            else
                exit(0);

        }
    }
    else
        exit(0);
}





void user_page() {
    system("cls");
    int choice;
    cout << "                              \t\t WELCOME USER\n\n\n";
    cout << "                                   \t    MENU\n\n\n";
    cout << "1.LOGIN" << endl;
    cout << "2.REGISTER" << endl;
    cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
    cout << "4.Exit" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        user_login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "Thanks for using our traveling agency\n";
        exit(0);
        break;
    default:
        system("cls");
        cout << "You've made a mistake , give it a try again\n" << endl;
        main();
    }
}









void user_login()
{

    fstream reservation;
    char username[20], name[20], user_pw[20], pw[20], user[20], pass[20];
    int count = 0;
    bool flag = false;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    reservation.open("database.txt", ios::in);
    while (!reservation.eof()) {
        reservation.getline(username, 20, ':');
        reservation.getline(name, 20);
        reservation.getline(user_pw, 20, ':');
        reservation.getline(pw, 20);

        if (!strcmp(name, user) && !strcmp(pw, pass)) {
            flag = true;
        }
    }

    system("CLS");

    if (flag == true)
    {
        cout << "\n\tHello " << user << "\nLOGIN SUCCESSFUL\nWe're glad that you're here.\nThanks for logging in\n";
        cin.get();
        cin.get();
        successful(user);

    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        int menu;
        cout << "\npress 1 to return to main menu\n";
        cin >> menu;
        if (menu == 1) {
            user_login();
        }
        else
            exit(0);

    }



}




void registr()
{

    string  reg_pass, firstName, lastName;
    bool flag = true, flag2 = true, flagp = true;
    char email[25], address[25], reg_user[25], phone_no[11];
    system("cls");
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "\nEnter Last Name: ";
    cin >> lastName;
    cout << "\nEnter User Name: ";
    do
    {

        if (flag2 == false)
            cout << "Username already taken. Please enter a unique username:" << endl;
        cin >> reg_user;
        flag2 = unique(reg_user);

    } while (flag2 == false);

    cout << "\nEnter User Address: ";
    cin.ignore();
    cin.getline(address, 25);
    cout << "\nEnter Phone No.: ";
    do
    {

        cin >> phone_no;
        flagp = checkphone(phone_no);
        if (flagp == false)
            cout << "Invalid phone number! Please try again." << endl;

    } while (flagp == false);

    cout << "\nEnter Email: ";
    do
    {
        cin >> email;
        flag = checkmail(email);
        if (flag == false)
            cout << "Invalid e-mail.\nPlease re-enter your e-mail." << endl;

    } while (flag == false);

    cout << "\nEnter User Password: ";
    cin >> reg_pass;

    /* ofstream reserve("reservations.txt", ios::app);
     reserve << "username:" << reg_user;*/
    ofstream reg("database.txt", ios::app);
    reg << "\nusername:" << reg_user << endl;
    reg << "password:" << reg_pass << endl;
    reg << "User Phone:" << phone_no << endl;
    reg << "User Email:" << email;
    reg << endl;
    system("cls");
    cout << "\n\nRegistration Sucessful\n\n";
    successful(reg_user);


}




void forgot()
{
    int ch;
    fstream reservation;
    char username[20], name[20], user_pw[20], pw[20], search_user[20];

    system("cls");
    cout << "         \n      Forgotten ? We're here for help\n\n\n";
    cout << "1.Search by username" << endl;
    cout << "2.Search by password" << endl;
    cout << "3.Main menu" << endl;
    cout << "Enter your choice :";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        bool flag = false;
        cout << "\nEnter your remembered username :";
        cin >> search_user;

        reservation.open("database.txt", ios::in);
        while (!reservation.eof()) {
            reservation.getline(username, 20, ':');
            reservation.getline(name, 20);
            reservation.getline(user_pw, 20, ':');
            reservation.getline(pw, 20);


            if (!strcmp(name, search_user)) {
                cout << "\n\nHurray, account found";
                cout << "\nYour password is " << pw;
                cin.get();
                cin.get();
                user_page();
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();
            user_page();

        }
        break;
    }
    case 2:
    {
        char searchpass[20];
        bool flag = false;
        cout << "\nEnter the remembered password :";
        cin >> searchpass;

        reservation.open("database.txt", ios::in);
        while (!reservation.eof()) {
            reservation.getline(username, 20, ':');
            reservation.getline(name, 20);
            reservation.getline(user_pw, 20, ':');
            reservation.getline(pw, 20);

            if (!strcmp(pw, searchpass)) {
                cout << "\nYour password is found in the database \n";
                cout << "\nYour username is : " << name;
                cin.get();
                cin.get();
                user_page();
                flag = true;
                break;
            }

        }
        if (flag == false)
        {
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();
            main();

        }
    }
    case 3:
    {
        cin.get();
        user_page();
    }
    default:
    {
        cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
        forgot();
    }
    }
}

bool checkphone(char phonenum[11])
{
    bool flag = true;
    for (int i = 0; i < 11; i++)
    {

        if (!isdigit(phonenum[i]))
            flag = false;
    }
    return flag;
}


bool checkmail(char email[25])
{
    bool flag = false;
    for (int i = 0; i < 25; i++)
    {
        if (email[i] == '@')
            flag = true;
    }
    return flag;

}



bool unique(char userName[25])
{
    char username[20], name[20], user_pw[20], pw[20];
    bool flag = true;
    fstream reservation;
    reservation.open("database.txt", ios::in);
    while (!reservation.eof()) {
        reservation.getline(username, 20, ':');
        reservation.getline(name, 20);
        reservation.getline(user_pw, 20, ':');
        reservation.getline(pw, 20);
        if (!strcmp(name, userName))
            flag = false;
    }

    return flag;
}



void successful(char username[25]) {

    system("CLS");

    int choice;
    cout << "1.Reserve a trip \n";
    cout << "2.Change a reservation \n";
    cout << "3.Reservations history \n";
    cout << "4.Cancel reservation \n";
    cout << "5.logout\n";
    cout << "\n Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        reserve_a_trip(username);
        break;
    case 2:
        change_reservation(username);
        break;
    case 3:
        user_reservations_history(username);
        break;
    case 4:
        user_cancel_reservation(username);
        break;
    case 5:
        cout << "\nthanks for using our agency";
        exit(0);
        break;
    default:
        cout << "RESERVATION FAILED \n";
        break;
    }

}



void reserve_a_trip(char username[25]) {

    system("CLS");

    fstream reservations, trips;
    reservation r1;
    int ans;
    char id[30], info1[30], x[10], destination[20], date1[20], date2[20], transportation[20], name[20], address[20], max[30], num[30], cost[20], info2[20], info3[20], info4[20], info5[20], info6[20], info7[20], info8[20], info9[20], info10[20];
    bool flag = false;

    cout << "press 1 to see available trips\n";
    cin >> ans;
    if (ans == 1) {
        trips.open("trips.txt", ios::in);
        if (trips.is_open()) {
            string line;
            while (getline(trips, line)) {
                cout << line << endl;
            }
            trips.close();
        }
    }
    cout << "Enter trip id: ";
    cin >> x;

    trips.open("trips.txt", ios::in);
    while (!trips.eof()) {
        trips.getline(id, 30, ':');
        trips.getline(info1, 30);
        trips.getline(destination, 20, ':');
        trips.getline(info2, 20);
        trips.getline(date1, 20, ':');
        trips.getline(info3, 20);
        trips.getline(date2, 20, ':');
        trips.getline(info4, 20);
        trips.getline(transportation, 20, ':');
        trips.getline(info5, 20);
        trips.getline(name, 20, ':');
        trips.getline(info6, 20);
        trips.getline(address, 20, ':');
        trips.getline(info7, 20);
        trips.getline(max, 30, ':');
        trips.getline(info8, 20);
        trips.getline(num, 30, ':');
        trips.getline(info9, 20);
        trips.getline(cost, 20, ':');
        trips.getline(info10, 20);

        if (!strcmp(x, info1)) {
            system("cls");
            cout << id << ": " << info1 << endl << destination << ": " << info2 << endl << date1 << ": " << info3 << endl << date2 << ": " << info4 << endl << transportation << ": " << info5 << endl << name << ": " << info6 << endl << address << ": " << info7 << endl << max << ": " << info8 << endl << num << ": " << info9 << endl << cost << ": " << info10 << endl << endl;
            flag = true;
            break;
        }
    }

    if (flag == true) {
        reservations.open("reservations.txt", ios::app);
        if (reservations.is_open()) {

            bool flagx = true;
            do
            {
                cout << "\nPlease enter number of the people: ";
                cin >> r1.people_no;
                cout << endl;



                if ((atoi(info9) + r1.people_no) < atoi(info8))
                {
                    reservations << "\nUsername:" << username << endl << id << ":" << info1 << endl << destination << ":" << info2 << endl << date1 << ":" << info3 << endl << date2 << ":" << info4 << endl << transportation << ":" << info5 << endl << name << ":" << info6 << endl << address << ":" << info7 << endl << max << ":" << info8 << endl << num << ":" << info9 << endl << cost << ":" << info10 << endl;
                    reservations << "No. of people:" << r1.people_no << endl;
                    flagx = true;
                }
                else if (atoi(info9) == atoi(info8))
                {
                    cout << "Sorry! There aren't any spots left on this trip!\nWould you like to choose another trip?\n1.Yes\n2.No" << endl;
                    int r;
                    cin >> r;
                    if (r == 1)
                        reserve_a_trip(username);
                    else
                        successful(username);
                }
                else
                {
                    cout << "Sorry! There aren't enough spots left on this trip!\nthere are only " << atoi(info8) - atoi(info9) << " seat left" << endl;
                    cout << "Would you like to:\n1.Change number of people\n2.Reserve another trip\n3.Exit" << endl;
                    int m;
                    cin >> m;
                    if (m == 1)
                        flagx = false;
                    else if (m == 2)
                        reserve_a_trip(username);
                    else
                        successful(username);

                }
            } while (flagx == false);
            //    atoi(info9)+ r1.people_no;
            //	cout << info9;
            system("CLS");
            cout << "\tRESERVATION SUCCESSFUL!\n\n\n\n";


            cout << "   <<< Choose your payment method >>> \n \n";
            cout << "1- Debit or Credit Card \n";
            cout << "2- cash \n";
            cout << "3- mobile payments \n";
            cin >> r1.payment_method;

        }

        switch (r1.payment_method) {

        case 1:
            credit_card();
            break;
        case 2:
            cash();
            break;
        case 3:
            mobile_payments();
            break;
        default:
            cout << "     PAYMENT FAILED \n";
            break;
        }
        reservations.close();

        //////////////////////////////////////////////////////////////////////////////////////
     /*fstream out_file;
        char id[25], idinfo[25], destination[25], destinationinfo[25], startdate[25], startdateinfo1[25], startdateinfo2[25], startdateinfo3[25], enddate[25], enddateinfo1[25], enddateinfo2[25], enddateinfo3[25], transportation[25], transportationinfo[25], hotelname[25], hotelnameinfo[25], hoteladress[50], hoteladressinfo[25], maxnum[25], maxnuminfo[25],/* resnum[25], resnuminfo[25], tripcost[25], tripcostinfo[25], a[25];
        int count = 1 , newnum;
        char resnum[25], resnuminfo[25];
        bool flagg = true;

        out_file.open("trips.txt", ios::in);
        fstream temp;
        temp.open("temp.txt", ios::out);



        while (!out_file.eof())
        {


            out_file.getline(id, 25, ':');
            out_file.getline(idinfo, 25);
            out_file.getline(destination, 25, ':');
            out_file.getline(destinationinfo, 25);
            out_file.getline(startdate, 25, ':');
            out_file.getline(startdateinfo1, 25, '/');
            out_file.getline(startdateinfo2, 25, '/');
            out_file.getline(startdateinfo3, 25);
            out_file.getline(enddate, 25, ':');
            out_file.getline(enddateinfo1, 25, '/');
            out_file.getline(enddateinfo2, 25, '/');
            out_file.getline(enddateinfo3, 25);
            out_file.getline(transportation, 25, ':');
            out_file.getline(transportationinfo, 25);
            out_file.getline(hotelname, 25, ':');
            out_file.getline(hotelnameinfo, 25);
            out_file.getline(hoteladress, 25, ':');
            out_file.getline(hoteladressinfo, 25);
            out_file.getline(maxnum, 25, ':');
            out_file.getline(maxnuminfo, 25);
            out_file.getline(resnum, 25, ':');
            out_file.getline(resnuminfo, 25);
            out_file.getline(tripcost, 25, ':');
            out_file.getline(tripcostinfo, 25);


            if (strcmp(x, idinfo) == 0)


            {
                newnum = r1.people_no + atoi(resnuminfo);

                if (count != 1)
                    temp << endl << endl;

                temp << "Id" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "Number of reservations" << ":" << newnum << endl << "Tripcost" << ":" << tripcostinfo;

            }
            else
            {
                if (count != 1)
                    temp << endl << endl;

                temp << "Id" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "Number of reservations" << ":" << resnuminfo << endl << "Tripcost" << ":" << tripcostinfo;


            }

            count++;
        }
        temp.close();
        out_file.close();


        count = 1;

        out_file.open("trips.txt", ios::out);
        temp.open("temp.txt", ios::in);

        while (!temp.eof())
        {

            temp.getline(id, 25, ':');
            temp.getline(idinfo, 25);
            temp.getline(destination, 25, ':');
            temp.getline(destinationinfo, 25);
            temp.getline(startdate, 25, ':');
            temp.getline(startdateinfo1, 25, '/');
            temp.getline(startdateinfo2, 25, '/');
            temp.getline(startdateinfo3, 25);
            temp.getline(enddate, 25, ':');
            temp.getline(enddateinfo1, 25, '/');
            temp.getline(enddateinfo2, 25, '/');
            temp.getline(enddateinfo3, 25);
            temp.getline(transportation, 25, ':');
            temp.getline(transportationinfo, 25);
            temp.getline(hotelname, 25, ':');
            temp.getline(hotelnameinfo, 25);
            temp.getline(hoteladress, 25, ':');
            temp.getline(hoteladressinfo, 50);
            temp.getline(maxnum, 25, ':');
            temp.getline(maxnuminfo, 25);
            temp.getline(resnum, 25, ':');
            temp.getline(resnuminfo, 25);
            temp.getline(tripcost, 25, ':');
            temp.getline(tripcostinfo, 25);

            if (count != 1)
                out_file << endl << endl;

            out_file << "Id" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "Number of reservations" << ":" << resnuminfo << endl << "Tripcost" << ":" << tripcostinfo;

            count++;



        }

        temp.close();
        out_file.close();
        remove("temp.txt");*/
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    else
        cout << "RESERVATION FAILED\n";

    cout << endl << endl;
    cout << "Press 1 to go back to main menu" << endl;
    int o;
    cin >> o;
    if (o == 1)
        successful(username);

}


void updatetrip(char ID[25], char NUM[25], int num)
{
    fstream out_file;
    char id[25], idinfo[25], destination[25], destinationinfo[25], startdate[25], startdateinfo1[25], startdateinfo2[25], startdateinfo3[25], enddate[25], enddateinfo1[25], enddateinfo2[25], enddateinfo3[25], transportation[25], transportationinfo[25], hotelname[25], hotelnameinfo[25], hoteladress[50], hoteladressinfo[25], maxnum[25], maxnuminfo[25],/* resnum[25], resnuminfo[25]*/ tripcost[25], tripcostinfo[25], a[25];
    int count = 1, dff;
    char resnum[25], resnuminfo[25];
    bool flagg = true;

    out_file.open("trips.txt", ios::in);
    fstream temp;
    temp.open("temp.txt", ios::out);



    while (!out_file.eof())
    {


        out_file.getline(id, 25, ':');
        out_file.getline(idinfo, 25);
        out_file.getline(destination, 25, ':');
        out_file.getline(destinationinfo, 25);
        out_file.getline(startdate, 25, ':');
        out_file.getline(startdateinfo1, 25, '/');
        out_file.getline(startdateinfo2, 25, '/');
        out_file.getline(startdateinfo3, 25);
        out_file.getline(enddate, 25, ':');
        out_file.getline(enddateinfo1, 25, '/');
        out_file.getline(enddateinfo2, 25, '/');
        out_file.getline(enddateinfo3, 25);
        out_file.getline(transportation, 25, ':');
        out_file.getline(transportationinfo, 25);
        out_file.getline(hotelname, 25, ':');
        out_file.getline(hotelnameinfo, 25);
        out_file.getline(hoteladress, 25, ':');
        out_file.getline(hoteladressinfo, 25);
        out_file.getline(maxnum, 25, ':');
        out_file.getline(maxnuminfo, 25);
        out_file.getline(resnum, 25, ':');
        out_file.getline(resnuminfo, 25);
        out_file.getline(tripcost, 25, ':');
        out_file.getline(tripcostinfo, 25);

        dff = (atoi(resnuminfo) - num + atoi(NUM));

        if (strcmp(ID, idinfo) == 0)


        {
            do
            {
                if (dff > atoi(maxnuminfo))
                {
                    cout << "There aren't enough spots left on this trip please enter another number" << endl;
                    cin >> NUM;
                    flagg = false;
                }
                else
                {
                    flagg = true;
                }

                dff = (atoi(resnuminfo) - num + atoi(NUM));

            } while ((flagg == false));

            if (count != 1)
                temp << endl << endl;

            temp << "Id" << ":" << ID << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "number of reservations" << ":" << dff << endl << "Tripcost" << ":" << tripcostinfo;

        }
        else
        {
            if (count != 1)
                temp << endl << endl;

            temp << "Id" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "number of reservations" << ":" << resnuminfo << endl << "Tripcost" << ":" << tripcostinfo;


        }

        count++;
    }
    temp.close();
    out_file.close();


    count = 1;

    out_file.open("trips.txt", ios::out);
    temp.open("temp.txt", ios::in);

    while (!temp.eof())
    {

        temp.getline(id, 25, ':');
        temp.getline(idinfo, 25);
        temp.getline(destination, 25, ':');
        temp.getline(destinationinfo, 25);
        temp.getline(startdate, 25, ':');
        temp.getline(startdateinfo1, 25, '/');
        temp.getline(startdateinfo2, 25, '/');
        temp.getline(startdateinfo3, 25);
        temp.getline(enddate, 25, ':');
        temp.getline(enddateinfo1, 25, '/');
        temp.getline(enddateinfo2, 25, '/');
        temp.getline(enddateinfo3, 25);
        temp.getline(transportation, 25, ':');
        temp.getline(transportationinfo, 25);
        temp.getline(hotelname, 25, ':');
        temp.getline(hotelnameinfo, 25);
        temp.getline(hoteladress, 25, ':');
        temp.getline(hoteladressinfo, 50);
        temp.getline(maxnum, 25, ':');
        temp.getline(maxnuminfo, 25);
        temp.getline(resnum, 25, ':');
        temp.getline(resnuminfo, 25);
        temp.getline(tripcost, 25, ':');
        temp.getline(tripcostinfo, 25);

        if (count != 1)
            out_file << endl << endl;

        out_file << "Id" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel address" << ":" << hoteladressinfo << endl << "Maximum number of seats" << ":" << maxnuminfo << endl << "number of reservations" << ":" << resnuminfo << endl << "Tripcost" << ":" << tripcostinfo;

        count++;



    }

    temp.close();
    out_file.close();
    remove("temp.txt");

}


void change_reservation(char u1[25]) {
    fstream reservations, temp;





    reservations.open("reservations.txt", ios::in);
    char  username[25], usernameinfo[25], id[25], idinfo[25], destination[25], destinationinfo[25], startdate[25], startdateinfo1[25], startdateinfo2[25], startdateinfo3[25], enddate[25], enddateinfo1[25], enddateinfo2[25], enddateinfo3[25], transportation[25], transportationinfo[25], hotelname[25], hotelnameinfo[25], hoteladress[50], hoteladressinfo[25], maxnum[25], maxnuminfo[25], resnum[25], resnuminfo[25], tripcost[25], tripcostinfo[25], a[25], numberofpeople[25], numberofpeopleinfo[25], payment[25], paymentinfo[25];
    int count = 1, num;

    temp.open("temp2.txt", ios::out);
    cout << "would you like to see your reservations? y/n\n";
    char e;
    cin >> e;
    if (e == 'y' || e == 'Y')
        user_reservations_history(u1);

    cout << "please enter trip id you want to update :" << endl;
    cin >> a;


    while (!reservations.eof())
    {
        reservations.getline(username, 25, ':');
        reservations.getline(usernameinfo, 25);
        reservations.getline(id, 25, ':');
        reservations.getline(idinfo, 25);
        reservations.getline(destination, 25, ':');
        reservations.getline(destinationinfo, 25);
        reservations.getline(startdate, 25, ':');
        reservations.getline(startdateinfo1, 25, '/');
        reservations.getline(startdateinfo2, 25, '/');
        reservations.getline(startdateinfo3, 25);
        reservations.getline(enddate, 25, ':');
        reservations.getline(enddateinfo1, 25, '/');
        reservations.getline(enddateinfo2, 25, '/');
        reservations.getline(enddateinfo3, 25);
        reservations.getline(transportation, 25, ':');
        reservations.getline(transportationinfo, 25);
        reservations.getline(hotelname, 25, ':');
        reservations.getline(hotelnameinfo, 25);
        reservations.getline(hoteladress, 25, ':');
        reservations.getline(hoteladressinfo, 25);
        reservations.getline(maxnum, 25, ':');
        reservations.getline(maxnuminfo, 25);
        reservations.getline(resnum, 25, ':');
        reservations.getline(resnuminfo, 25);
        reservations.getline(tripcost, 25, ':');
        reservations.getline(tripcostinfo, 25);
        reservations.getline(numberofpeople, 25, ':');
        reservations.getline(numberofpeopleinfo, 25);
        reservations.getline(payment, 25, ':');
        reservations.getline(paymentinfo, 25);


        num = atoi(numberofpeopleinfo);

        bool flag = true, flagg = true;
        if (strcmp(a, idinfo) == 0 && strcmp(u1, usernameinfo) == 0) {
            cout << "please enter your modification number :" << endl;
            cout << "1.Transportation" << endl;
            cout << "2.Number of people" << endl;
            cout << "3.Payment method" << endl;
            int ch;
            cin >> ch;

            switch (ch)
            {
            case 1:
                cout << "please enter new mean of transportation" << endl;
                cin >> transportationinfo;
                break;
            case 2:
                cout << "Please enter new number of people" << endl;
                cin >> numberofpeopleinfo;
                updatetrip(idinfo, numberofpeopleinfo, num);
                break;
            case 3:
                cout << "please enter new payment method " << endl;
                cin >> paymentinfo;
                break;




            default:
                cout << "wrong choice !" << endl;


                break;
            }

            temp << "\nUsername" << ":" << usernameinfo << endl << "Trip ID" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel Address" << ":" << hoteladressinfo << endl << "Max No. of Reservations" << ":" << maxnuminfo << endl << "Number of reservations" << ":" << resnuminfo << endl << "Trip cost" << ":" << tripcostinfo << endl << "Number of people" << ":" << numberofpeopleinfo << endl << "Payment method" << ":" << paymentinfo;

        }
        else
        {

            temp << "\nUsername" << ":" << usernameinfo << endl << "Trip ID" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel Address" << ":" << hoteladressinfo << endl << "Max No. of Reservations" << ":" << maxnuminfo << endl << "Number of reservations" << ":" << resnuminfo << endl << "Trip cost" << ":" << tripcostinfo << endl << "Number of people" << ":" << numberofpeopleinfo << endl << "Payment method" << ":" << paymentinfo;
        }

    }
    count++;

    temp.close();
    reservations.close();


    reservations.open("reservations.txt", ios::out);
    temp.open("temp2.txt", ios::in);
    count = 1;
    while (!temp.eof())
    {

        temp.getline(username, 25, ':');
        temp.getline(usernameinfo, 25);
        temp.getline(id, 25, ':');
        temp.getline(idinfo, 25);
        temp.getline(destination, 25, ':');
        temp.getline(destinationinfo, 25);
        temp.getline(startdate, 25, ':');
        temp.getline(startdateinfo1, 25, '/');
        temp.getline(startdateinfo2, 25, '/');
        temp.getline(startdateinfo3, 25);
        temp.getline(enddate, 25, ':');
        temp.getline(enddateinfo1, 25, '/');
        temp.getline(enddateinfo2, 25, '/');
        temp.getline(enddateinfo3, 25);
        temp.getline(transportation, 25, ':');
        temp.getline(transportationinfo, 25);
        temp.getline(hotelname, 25, ':');
        temp.getline(hotelnameinfo, 25);
        temp.getline(hoteladress, 25, ':');
        temp.getline(hoteladressinfo, 25);
        temp.getline(maxnum, 25, ':');
        temp.getline(maxnuminfo, 25);
        temp.getline(resnum, 25, ':');
        temp.getline(resnuminfo, 25);
        temp.getline(tripcost, 25, ':');
        temp.getline(tripcostinfo, 25);
        temp.getline(numberofpeople, 25, ':');
        temp.getline(numberofpeopleinfo, 25);
        temp.getline(payment, 25, ':');
        temp.getline(paymentinfo, 25);

        if (count != 1)
            reservations << endl << endl;
        reservations << "Username" << ":" << usernameinfo << endl << "Trip ID" << ":" << idinfo << endl << "Destination" << ":" << destinationinfo << endl << "Startdate" << ":" << startdateinfo1 << '/' << startdateinfo2 << '/' << startdateinfo3 << endl << "Enddate" << ":" << enddateinfo1 << '/' << enddateinfo2 << '/' << enddateinfo3 << endl << "Transportation" << ":" << transportationinfo << endl << "Hotelname" << ":" << hotelnameinfo << endl << "Hotel Address" << ":" << hoteladressinfo << endl << "Max No. of Reservations" << ":" << maxnuminfo << endl << "Number of reservations" << ":" << resnuminfo << endl << "Trip cost" << ":" << tripcostinfo << endl << "Number of people" << ":" << numberofpeopleinfo << endl << "Payment method" << ":" << paymentinfo;

        count++;
    }
    temp.close();
    reservations.close();

    cout << "     done!     " << endl;
    remove("temp2.txt");
}


void user_reservations_history(char username[25]) {

    system("CLS");

    fstream history;
    char id[20], input_user[20], info1[20], people[20], method[20], user_name[20], info13[20], destination[20], date1[20], date2[20], transportation[20], name[20], address[20], max[30], num[30], cost[20], info2[20], info3[20], info4[20], info5[20], info6[20], info7[20], info8[20], info9[20], info10[20], info11[20], info12[20];


    history.open("reservations.txt", ios::in);
    if (history.is_open()) {
        while (!history.eof()) {
            history.getline(user_name, 20, ':');
            history.getline(info1, 20);
            history.getline(id, 20, ':');
            history.getline(info2, 20);
            history.getline(destination, 20, ':');
            history.getline(info3, 20);
            history.getline(date1, 20, ':');
            history.getline(info4, 20);
            history.getline(date2, 20, ':');
            history.getline(info5, 20);
            history.getline(transportation, 20, ':');
            history.getline(info6, 20);
            history.getline(name, 20, ':');
            history.getline(info7, 20);
            history.getline(address, 20, ':');
            history.getline(info8, 20);
            history.getline(max, 30, ':');
            history.getline(info9, 20);
            history.getline(num, 30, ':');
            history.getline(info10, 20);
            history.getline(cost, 20, ':');
            history.getline(info11, 20);
            history.getline(people, 20, ':');
            history.getline(info12, 20);
            history.getline(method, 20, ':');
            history.getline(info13, 20);

            if (!strcmp(username, info1)) {
                cout << id << ": " << info2 << endl << destination << ": " << info3 << endl << date1 << ": " << info4 << endl << date2 << ": " << info5 << endl << transportation << ": " << info6 << endl << name << ": " << info7 << endl << address << ": " << info8 << endl << max << ": " << info9 << endl << num << ": " << info10 << endl << cost << ": " << info11 << endl << people << ": " << info12 << endl << method << ": " << info13 << endl << endl;

            }

        }
        cout << "\npress 1 to return to main menu\n2 to cancel a trip\n3 to update a trip\n";
        int e;
        cin >> e;
        if (e == 1)
            successful(username);
        else if (e == 2)
            user_cancel_reservation(username);
        else if (e == 3)
            change_reservation(username);

    }
}


void user_cancel_reservation(char username[25]) {


    fstream trips;
    fstream reservations;
    fstream temp;
    TripInfo t;
    ReservationsInfo r;
    char ID[25];
    char id[25];
    char destination[25];
    char startdate[25];
    char enddate[25];
    char transportation[25];
    char h_name[25];
    char h_address[25];
    char maxnum[25];
    char numof[25];
    char cost[25];
    char empty[25];
    char User[25];
    char numofpeople[25];
    char payment[25];
    int counter = 1, x, numofint, y;
    bool flag = false, flag2 = true;

    cout << "would you like to see your reservations? y/n\n";
    char e;
    cin >> e;
    if (e == 'y' || e == 'Y')
        user_reservations_history(username);




    do
    {
        system("CLS");
        cout << "Please enter the ID ofthe trip you want to cancel: ";
        cin >> ID;


        reservations.open("reservations.txt", ios::in);
        temp.open("Temp.txt", ios::out);

        while (!reservations.eof())
        {
            reservations.getline(User, 25, ':');
            reservations.getline(r.username, 25);
            reservations.getline(id, 25, ':');
            reservations.getline(r.id, 25);
            reservations.getline(destination, 25, ':');
            reservations.getline(r.destination, 25);
            reservations.getline(startdate, 25, ':');
            reservations.getline(r.startdate.day, 10, '/');
            reservations.getline(r.startdate.month, 10, '/');
            reservations.getline(r.startdate.year, 10);
            reservations.getline(enddate, 25, ':');
            reservations.getline(r.enddate, 25);
            reservations.getline(transportation, 25, ':');
            reservations.getline(r.transportation, 25);
            reservations.getline(h_name, 25, ':');
            reservations.getline(r.h_name, 25);
            reservations.getline(h_address, 25, ':');
            reservations.getline(r.h_address, 25);
            reservations.getline(maxnum, 25, ':');
            reservations.getline(r.maxnum, 25);
            reservations.getline(numof, 25, ':');
            reservations.getline(r.numof, 25);
            reservations.getline(cost, 25, ':');
            reservations.getline(r.cost, 25);
            reservations.getline(numofpeople, 25, ':');
            reservations.getline(r.numofpeople, 25);
            reservations.getline(payment, 25, ':');
            reservations.getline(r.payment, 25);


            if (!strcmp(r.username, username) && !strcmp(r.id, ID))
            {
                flag2 = CheckDate(r.startdate);
                if (flag2 == false)
                {
                    reservations.close();
                    reservations.open("reservations.txt");
                    break;
                    cout << "bleh";
                }

            }


            if (!strcmp(r.username, username) && !strcmp(r.id, ID) && flag2 == true)
            {
                continue;
            }
            else
            {
                if (!(counter == 1))
                    temp << endl;
                temp << "Username:" << r.username << endl << "\nTrip ID:" << r.id << endl << "Destination:" << r.destination << endl << "Start Date :" << r.startdate.day << "/" << r.startdate.month << "/" << r.startdate.year << endl << "End Date :" << r.enddate << endl << "Transportation :" << r.transportation << endl << "Hotel Name :" << r.h_name << endl << "Hotel Address :" << r.h_address << endl << "Max No.Reservations :" << r.maxnum << endl << "Number of Reservations :" << r.numof << endl << "Trip Cost :" << r.cost << endl << "Number of people:" << r.numofpeople << endl << "Payment method:" << r.payment;

            }
            counter++;
        }

        reservations.close();
        temp.close();
        if (flag2 == true)
        {

            reservations.open("reservations.txt", ios::out);
            temp.open("Temp.txt", ios::in);
            counter = 1;

            while (!temp.eof())
            {
                temp.getline(User, 25, ':');
                temp.getline(r.username, 25);
                temp.getline(id, 25, ':');
                temp.getline(r.id, 25);
                temp.getline(destination, 25, ':');
                temp.getline(r.destination, 25);
                temp.getline(startdate, 25, ':');
                temp.getline(r.startdate.day, 10, '/');
                temp.getline(r.startdate.month, 10, '/');
                temp.getline(r.startdate.year, 10);
                temp.getline(enddate, 25, ':');
                temp.getline(r.enddate, 25);
                temp.getline(transportation, 25, ':');
                temp.getline(r.transportation, 25);
                temp.getline(h_name, 25, ':');
                temp.getline(r.h_name, 25);
                temp.getline(h_address, 25, ':');
                temp.getline(r.h_address, 25);
                temp.getline(maxnum, 25, ':');
                temp.getline(r.maxnum, 25);
                temp.getline(numof, 25, ':');
                temp.getline(r.numof, 25);
                temp.getline(cost, 25, ':');
                temp.getline(r.cost, 25);
                temp.getline(numofpeople, 25, ':');
                temp.getline(r.numofpeople, 25);
                temp.getline(payment, 25, ':');
                temp.getline(r.payment, 25);

                if (counter != 1)
                    reservations << endl;

                reservations << "Username:" << r.username << endl << "\nTrip ID:" << r.id << endl << "Destination:" << r.destination << endl << "Start Date :" << r.startdate.day << "/" << r.startdate.month << "/" << r.startdate.year << endl << "End Date :" << r.enddate << endl << "Transportation :" << r.transportation << endl << "Hotel Name :" << r.h_name << endl << "Hotel Address :" << r.h_address << endl << "Max No.Reservations :" << r.maxnum << endl << "Number of Reservations :" << r.numof << endl << "Trip Cost :" << r.cost << endl << "Number of people:" << r.numofpeople << endl << "Payment method:" << r.payment;

                counter++;

            }

            reservations.close();
            temp.close();
            remove("Temp.txt");


            trips.open("trips.txt", ios::in);
            temp.open("Temp.txt", ios::out);
            counter = 1;


            while (!trips.eof())
            {

                trips.getline(id, 25, ':');
                trips.getline(t.id, 25);
                trips.getline(destination, 25, ':');
                trips.getline(t.destination, 25);
                trips.getline(startdate, 25, ':');
                trips.getline(t.startdate, 25);
                trips.getline(enddate, 25, ':');
                trips.getline(t.enddate, 25);
                trips.getline(transportation, 25, ':');
                trips.getline(t.transportation, 25);
                trips.getline(h_name, 25, ':');
                trips.getline(t.h_name, 25);
                trips.getline(h_address, 25, ':');
                trips.getline(t.h_address, 25);
                trips.getline(maxnum, 25, ':');
                trips.getline(t.maxnum, 25);
                trips.getline(numof, 25, ':');
                trips.getline(t.numof, 25);
                trips.getline(cost, 25, ':');
                trips.getline(t.cost, 25);



                if (!strcmp(t.id, ID))
                {
                    numofint = (atoi(t.numof)) - atoi(r.numofpeople);
                    if (counter != 1)
                        temp << endl;
                    temp << "Trip ID:" << t.id << endl << "Destination:" << t.destination << endl << "Start Date :" << t.startdate << endl << "End Date :" << t.enddate << endl << "Transportation :" << t.transportation << endl << "Hotel Name :" << t.h_name << endl << "Hotel Address :" << t.h_address << endl << "Max No.Reservations :" << t.maxnum << endl << "Number of Reservations :" << numofint << endl << "Trip Cost :" << t.cost;

                }
                else
                {
                    if (counter != 1)
                        temp << endl;
                    temp << "Trip ID:" << t.id << endl << "Destination:" << t.destination << endl << "Start Date :" << t.startdate << endl << "End Date :" << t.enddate << endl << "Transportation :" << t.transportation << endl << "Hotel Name :" << t.h_name << endl << "Hotel Address :" << t.h_address << endl << "Max No.Reservations :" << t.maxnum << endl << "Number of Reservations :" << t.numof << endl << "Trip Cost :" << t.cost;
                }
                counter++;
            }

            trips.close();
            temp.close();

            trips.open("trips.txt", ios::out);
            temp.open("Temp.txt", ios::in);
            counter = 1;

            while (!temp.eof())
            {
                temp.getline(id, 25, ':');
                temp.getline(t.id, 25);
                temp.getline(destination, 25, ':');
                temp.getline(t.destination, 25);
                temp.getline(startdate, 25, ':');
                temp.getline(t.startdate, 25);
                temp.getline(enddate, 25, ':');
                temp.getline(t.enddate, 25);
                temp.getline(transportation, 25, ':');
                temp.getline(t.transportation, 25);
                temp.getline(h_name, 25, ':');
                temp.getline(t.h_name, 25);
                temp.getline(h_address, 25, ':');
                temp.getline(t.h_address, 25);
                temp.getline(maxnum, 25, ':');
                temp.getline(t.maxnum, 25);
                temp.getline(numof, 25, ':');
                temp.getline(t.numof, 25);
                temp.getline(cost, 25, ':');
                temp.getline(t.cost, 25);

                if (counter != 1)
                    trips << endl;
                trips << "Trip ID:" << t.id << endl << "Destination:" << t.destination << endl << "Start Date :" << t.startdate << endl << "End Date :" << t.enddate << endl << "Transportation :" << t.transportation << endl << "Hotel Name :" << t.h_name << endl << "Hotel Address :" << t.h_address << endl << "Max No.Reservations :" << t.maxnum << endl << "Number of Reservations :" << t.numof << endl << "Trip Cost :" << t.cost;
                counter++;
            }

            trips.close();
            temp.close();
            remove("Temp.txt");

            system("CLS");
            cout << "\tTrip Cancled Successfully";
        }
        //system("CLS");
        if (flag2 == false)
            cout << "Can't cancel trip less than a week before departure." << endl;
        flag2 = true;
        cout << "\n\nWould you like to cancel another trip?\n1.Yes\n2.No" << endl;
        cin >> x;

        if (x == 1)
            flag = true;
        else
            flag = false;


    } while (flag == true);

    cout << "Please press 1 to go back to main menu" << endl;
    int m;
    cin >> m;
    if (m == 1)
        successful(username);
}


bool CheckDate(datee d)
{
    SYSTEMTIME a;
    GetLocalTime(&a);
    int difference = 0;
    int monthdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int day, month, year;
    day = atoi(d.day);
    month = atoi(d.month);
    year = atoi(d.year);
    bool flag = false;

    if (month == a.wMonth)
        difference = day - a.wDay;
    else
    {
        for (int i = a.wMonth; i < month; i++)
        {
            difference += monthdays[i];
        }
        difference += day - a.wDay;
    }
    cout << difference;
    if (difference > 7 || year > a.wYear)
    {
        flag = true;
        cout << "sdfg";
    }
    else
    {
        flag = false;
        cout << "no";
    }

    return flag;
}


void credit_card() {


    card c1;
    fstream reservations;

    cout << "NAME ON CARD: ";
    cin >> c1.card_name;

    cout << "CARD NUMBER: ";
    cin >> c1.card_number;

    cout << "SECURITY CODE: ";
    cin >> c1.security_code;

    cout << "MONTH: ";
    cin >> c1.month;

    cout << "YEAR: ";
    cin >> c1.year;

    if (c1.year < 2021) {
        cout << "   PAYMENT FAILED \n";
    }
    else {
        reservations.open("reservations.txt", ios::app);
        reservations << "Payment method:Debit or Credit Card";
        cout << "     CONFIRMED PAYMENT \n";
        cout << "         SUCCESS\n";
        cout << "check your email for a booking confirmation.we'll see you soon!";

    }

}



void cash() {
    fstream reservations;
    reservations.open("reservations.txt", ios::app);
    reservations << "Payment method:cash";
    cout << "     please pay your cash \n";
    cout << "     CONFIRMED PAYMENT \n";

}



void mobile_payments() {
    fstream reservations;
    int phone_number;

    reservations.open("reservations.txt", ios::app);
    reservations << "Payment method:mobile payments";
    cout << "PHONE NUMBER: ";
    cin >> phone_number;
    cout << endl;
    cout << "     CONFIRMED PAYMENT \n";
    cout << "         SUCCESS\n";
    cout << "check your email for a booking confirmation.we'll see you soon!";
}
