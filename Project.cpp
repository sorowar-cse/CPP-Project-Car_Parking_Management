/*
Assalamu'alaikum,  this is the Car Parking Project of C201032_Sorowar_Mahabub
*/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Carparking Class
class carparking
{
public:
    void control_panel();
    void add_car();
    void show_car();
    void check_carbill();
    void edit_car();
    void del_car();
};

// Function to display the menus
void carparking::control_panel()
{
    cout.width(180);
    system("cls");
    cout << "Dear Audience, Assalamu'alaikum" << endl;
    cout << "Welcome to our Car Parking Management System ";
    cout << "\n\n\t\t\t\tCONTROL PANEL";
    cout << "\n\n1. Add Car(s)";
    cout << "\n2. Show Car(s)";
    cout << "\n3. Search bills for a Car ";
    cout << "\n4. Edit Car Record";
    cout << "\n5. Delete Car Record";
    cout << "\n6. Exit";

    cout << "\n\n\t\t\tDeveloper\n\t\tMd. Sorowar Mahabub Rabby";
    cout << "\n\tM.ID: C201032, Dept. of CSE, IIUC. Cell: 01834-756433";
    cout << "\n\tEmail: sorowarmahabub.bsc.cse.iiuc@gmail.com";
}

// Function to add car
void carparking::add_car()
{
    system("cls");
    fstream file;
    double bill;
    string c_name, a_name, c_id;
    cout << "\n\n\t\t\t\tAdd Car(s)";
    cout << "\n\nCar ID: ";
    cin >> c_id;
    cout << "\n*Company Name must be a single word!";
    cout << "\nCar's Company Name: ";
    cin >> c_name;
    cout << "\n*Author's Name must be a single word!";
    cout << "\nCar's Author Name: ";
    cin >> a_name;
    cout << "\nBill of Car: ";
    cin >> bill;

    // Open file in append or output mode
    file.open("D:// car.txt", ios::out | ios::app);
    file << " " << c_id << " " << c_name << " " << a_name << " " << bill << "\n";
    file.close();
}



// Function to display car
void carparking::show_car()
{
    system("cls");
    fstream file;
    int bill;
    string c_name, c_id, a_name;
    cout << "\n\n\t\t\t\t\tAll CAR lists are in the following";

    // Open the file in input mode
    file.open("D:// car.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else
    {
        cout << "\n\n\nCar ID\t\tCar's Company Name" << "\t\tCar's Author Nane\t\tBill of Car(s)\n\n";
        file >> c_id >> c_name;
        file >> a_name >> bill;

        // Till end of file is reached
        while (!file.eof())
        {
            cout << " " << c_id
                 << "\t\t" << c_name
                 << "\t\t\t\t" << a_name
                 << "\t\t\t\t" << bill
                 << "\n\n";
            file >> c_id >> c_name;
            file >> a_name >> bill;
        }

        system("pause");

        // Close the file
        file.close();
    }
}

// Function to check the car
void carparking::check_carbill()
{
    system("cls");
    fstream file;
    int bill, count = 0;
    string c_id, c_name, a_name, c_idd;

    cout << "\n\n\t\t\t\tCheck Bills for the respected Car";

    // Open the file in input mode
    file.open("D:// car.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";

    else
    {
        cout << "\n\nCar ID : ";
        cin >> c_idd;
        file >> c_id >> c_name;
        file >> a_name >> bill;

        while (!file.eof())
        {
            if (c_idd == c_id)
            {
                system("cls");
                cout << "\n\n\t\t\t\tCheck Bills for the Car";
                cout << "\n\Car ID: " << c_id;
                cout << "\nCar's Company Name: " << c_name;
                cout << "\nCar's Author Name: " << a_name;
                cout << "\nBill of the Car: " << bill;
                cout << endl << endl;
                count++;
                break;
            }

            file >> c_id >> c_name;
            file >> a_name >> bill;
        }

        system("pause");
        file.close();

        if (count == 0)
            cout << "\n\n\t\tSorry\nRequested Car ID not Found...!";
    }
}


// Function to edit the car
void carparking::edit_car()
{
    system("cls");
    fstream file, file1;
    int bill, no_co, count = 0;
    string c_name, c_na, a_name;
    string a_na, c_idd, c_id;

    cout << "\n\n\t\t\t\tEdit Car Record";
    file1.open("D:// car1.txt", ios::app | ios::out);
    file.open("D:// car.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";

    else
    {
        cout << "\n\nCar ID : ";
        cin >> c_id;
        file >> c_idd >> c_name;
        file >> a_name >> bill;

        // Till end of file is reached
        while (!file.eof())
        {
            if (c_id == c_idd)
            {
                system("cls");
                cout << "\t\t\t\tEdit Car Record";
                cout << "\n\nNew Car's Company Name: ";
                cin >> c_na;
                cout << "\nCar's Author Name: ";
                cin >> a_na;
                cout << "\nBill of the Car: ";
                cin >> no_co;

                file1 << " " << c_id << " " << c_na << " " << a_na << " " << no_co << "\n\n";
                count++;
            }

            else
                file1 << " " << c_idd << " " << c_name << " " << a_name << " " << bill << "\n\n";

            file >> c_idd >> c_name;
            file >> a_name >> bill;
        }

        if (count == 0)
            cout << "\n\nRequested Car ID not Found...!";
    }

    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("D:// car.txt");
    rename("D:// car1.txt", "D:// car.txt");
}

// Function to delete car
void carparking::del_car()
{
    system("cls");
    fstream file, file1;
    int bill, count = 0;
    string c_id, c_idd, c_name, a_name;
    cout << "\n\n\t\t\t\tDelete a Car";

    // Append file in output mode
    file1.open("D:// car1.txt", ios::app | ios::out);
    file.open("D:// car.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";

    else
    {
        cout << "\n\nCar ID : ";
        cin >> c_id;
        file >> c_idd >> c_name;
        file >> a_name >> bill;

        while (!file.eof())
        {
            if (c_id == c_idd)
            {
                system("cls");
                cout << "\n\n\t\t\t\tDelete a Car";
                cout << "\n\nRequested Car is Deleted Successfully...!\n\n";
                count++;
            }

            else
                file1 << " " << c_idd << " " << c_name << " " << a_name << " " << bill << "\n\n";

            file >> c_idd >> c_name;
            file >> a_name >> bill;
        }

        if (count == 0)
            cout << "\n\nRequested Car ID not Found...!";
    }

    system("pause");

    // Close the file
    file.close();
    file1.close();

    remove("D:// car.txt");
    rename("D:// car1.txt", "D:// car.txt");
}

// Function for car parking record
void carparkingRec()
{
    int ch;
    char x;
    carparking c;

    while (1)
    {
        c.control_panel();
        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            do {
                c.add_car();
                cout << "\n\nWant to add another Car? (only press: y/n): ";
                cin >> x;
            } while (x == 'y'|| x == 'Y');
            break;

        case 2:
            c.show_car();
            break;

        case 3:
            c.check_carbill();
            break;

        case 4:
            c.edit_car();
            break;

        case 5:
            c.del_car();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE!!\n";
        }
    }
}

// MAIN CODE
int main()
{
    // CALLING THE FUNCTION
    carparkingRec();

    return 0;
}
