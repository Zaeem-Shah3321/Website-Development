#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;    
////////////////////HEADERS//////////

void printHeader ();
void siginHeader();
void adminsignupHeader();
void adminSignInHeader();
void signupHeader();
void studentSignInHeader();
void studentSignupHeader();

//////////////////SIGN IN // SIGNUP//////////////////////

string mainMenu();
string signup();
bool signinAdminOption(int,string [],string [] , string , string);
bool signinStudentOption(string , string , int, string [] , string [] , string[], string[]);
void signUpStudent(int&, string [] , string [] , string [] , string []);
string admin();
string student();
string signinoptions();

/////////////////////ADMIN RESPONSIBILITIES//////////////

string addbook(int&,string[],string[],string [],string[],int[]);
bool removebook(int,string[],string[],string [],string[],int[]);
void viewbooks(int,string[],string[],string [],string[],int[]);
string addStudent(int& , string[], string[], string[], string[]);
bool removestudent(int , string[], string[], string[], string[]);
void viewstudents(int , string[], string[], string[], string[]);
string issueBook(int,int,string[],string[],string[],string [] ,string[],int[] , string[] , string[] ,int&, string[] , string []);
string searchbookbyauthor(int,string [],string [],string[], string[],int[]);
string searchbook(int,string[],string[],string [], string[],int[]);
string addAdmin(int&,string[],string []);
void record(int  ,string [] , string [] , string [] , string []);
int returnBook(int, int ,string [], string [],int []);

////////////////////FOR PASSWORD//////////////////

string getAnonymousPass();

///////////////////STUDENT RESPONSIBILITIES//////

void history(string [], int  , string [] ,  string [] , string [] , string [] ,int, string[] , string[]);
void viewprofile( string [] , string [] , string [] , string []);
string changepassword(string []);
string changename(string []);

/////////////////SAVE DATA////////////////////

void savebooks(int ,string [],string [],string [], string [],int []);
void savestudents(int , string [] , string [] , string [] , string []);
void saverecord(int  ,string [] , string []  , string [] , string []);
void saveadmins(int, string [] , string []);

///////////////////LOAD DATA//////////////////////

void loadstudents(int& , string [] , string [] , string [] , string []);
void loadadmins(int&, string [] , string []);
void loadbooks(int& ,string [],string [],string [], string [],int[]);
void loadrecord(int&  ,string [] , string [] , string [] , string []);
string getdata(string  , int );

///////////////////FOR COLOURS///////////////////

string setcolor(unsigned short color);

//////////////////ADDITIONAL VARIABLES////////

int del  = 0;
int currentIndex = 0;

/////////////START OF PROGRAM////////////

main ()
{

/////////////////////ADMINs////////////////////////////////////

    int count = 0;
    string names[100] = {};
    string passwords[100] = {};

    loadadmins(count,names,passwords);
    
///////////////STUDENTS///////////////////////////////////////

    int studentcount = 0;
    string studentnames[100] = {};
    string studentRollNumbers[100] = {};
    string studentPasswords[100] = {};
    string studentDepts[100] = {};

    loadstudents(studentcount,studentnames,studentRollNumbers,studentPasswords,studentDepts);


//////////////////////BOOKS/////////////////////////////////////

    int bookcount = 0;
    string booknames [100] = {};
    string booklocations [100] = {};
    string bookauthor [100] = {};
    string bookcopies [100] = {};
    int bookavailables[100] = {};

///////////////////BOOK ISSUE DETAILS/////////////////////////

    int issuecount = 0;
    string issuedate[100] = {};
    string returndate[100] = {};

    loadbooks(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
    
/////////////////////////////////////////////////////////////////


string naMes[100] = {};
string boOks[100] = {};

loadrecord(issuecount ,naMes ,boOks ,  issuedate, returndate);

///////////////////////////////////////////////////////////

//////////////////////////////////SIGN IN//////////////////////////
logout:
    string opt;                
    string role = "";
    while (opt != "3")
    {
        /////////////////////////////////////SING IN FOR ADMIN//////////////

        opt = mainMenu();
        if (opt == "1")
        {
            system ("cls");
            siginHeader();
            cout << endl;
            cout << endl; 

            string oo = signinoptions();
            if (oo == "1")
            {
                system ("cls");
                adminSignInHeader();
                cout << endl;
                cout << endl;
                string un = "";
                cout << "\t \t \t \t \t \t \t \t \t \t Enter Username.. ";
                cin >> un;
                string pass;
                cout << "\t \t \t \t \t \t \t \t \t \t Password.. ";
                pass = getAnonymousPass(); 

                bool found = signinAdminOption(count, names ,passwords , un, pass);
                if (found)
                {
                    role = "admin";
                    break;
                }
            }
            else if (oo == "2")
            {
    ///////////////////////////////////////////////SING IN FOR STUDENT//////////////////////////////

                system ("cls");         
                studentSignInHeader();
                cout << endl;
                cout << endl;
                string uns;
                cout << "\t \t \t \t \t \t \t \t \t \t Enter Username.. ";
                cin >> uns;
                string passs;
                cout << "\t \t \t \t \t \t \t \t \t \t Password.. ";
                passs = getAnonymousPass(); 

               bool found = signinStudentOption(uns , passs , studentcount, studentnames , studentRollNumbers , studentPasswords , studentDepts);
               if (found)
               {
                role = "student";
                break;
               }
            }
        }

    /////////////////////////////////////////////SIGN UP FOR STUDENT//////////////////////////////////////////

        if (opt == "2")
        {
            string optsignUp = signup();
            if (optsignUp == "1")
            {
                signUpStudent(studentcount , studentnames , studentRollNumbers , studentPasswords , studentDepts);
            }
    
        }

    ///////////////////////////////////EXIT/////////////////////////////

        if (opt == "3")
        {
            savestudents(studentcount , studentnames , studentRollNumbers , studentPasswords , studentDepts);
            savebooks(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            saveadmins(count,names,passwords);
            saverecord(issuecount ,naMes,boOks ,issuedate , returndate);
            return 0;
        }
    }
    ////////////////////////////////////////FOR ADMINS///////////////////////////////////////////
    if (role == "admin")
    {
        string adminoption;
admin:
        while (true)
        {
            adminoption = admin();
            if (adminoption == "1")
            {
                addbook(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (adminoption == "2")
            {
                viewbooks(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (adminoption == "3")
            {
                removebook(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (adminoption == "4")
            {
               addStudent(studentcount , studentnames , studentRollNumbers , studentPasswords , studentDepts);
            }
            else if (adminoption == "5")
            {
                viewstudents(studentcount , studentnames , studentRollNumbers , studentPasswords , studentDepts);
            }
            else if (adminoption == "6")
            {
                removestudent(studentcount , studentnames , studentRollNumbers , studentPasswords , studentDepts);
            }
            else if (adminoption == "7")
            {
                issueBook(bookcount,studentcount,studentnames,booknames,booklocations,bookauthor ,bookcopies,bookavailables , boOks , naMes ,issuecount, issuedate , returndate);
            }
            else if (adminoption == "8")
            {
                searchbook(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (adminoption == "9")
            {
                searchbookbyauthor(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (adminoption == "10")
            {
                addAdmin(count,names,passwords);
            }
            else if (adminoption == "11")
            {
                record(issuecount , boOks ,naMes ,issuedate ,returndate);
            }
            else if (adminoption == "12")
            {
                returnBook(bookcount, studentcount,studentnames,  booknames,bookavailables);
            }
            else if (adminoption == "13")
            {
               goto logout;
            }
            else 
            {   
                cout << "\t \t \t \t \t \t \t \t \t \t Invalid Option.." << endl;
                cout << "\t \t \t \t \t \t \t \t \t \t Press Any Key to Continue.." << endl;
                getch();
                goto admin;
            }
        }
    }
    /////////////////////////////////////FOR STUDENTS///////////////////////////////////////////

    else if (role == "student")
    {
        string studentOption;
student:        
        while (true)
        {
            studentOption = student();
            if(studentOption == "1")
            {
                searchbook(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (studentOption == "2")
            {
                searchbookbyauthor(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (studentOption == "3")
            {
                viewbooks(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
            }
            else if (studentOption == "4")
            {
                history(booknames, studentcount ,  studentnames , studentPasswords , boOks , naMes , issuecount , issuedate , returndate);
            }
            else if (studentOption == "5")
            {
                viewprofile(studentnames , studentRollNumbers ,studentPasswords,studentDepts);
            }
            else if (studentOption == "6")
            {
                changepassword(studentPasswords);
            }
            else if (studentOption == "7")
            {
                changename(studentnames);
            }
            else if (studentOption == "8")
            {
               goto logout;
            }
             else 
            {   
                cout << "\t \t \t \t \t \t \t \t \t \t Invalid Option.." << endl;
                cout << "\t \t \t \t \t \t \t \t \t \t Press Any Key to Continue.." << endl;
                getch();
                goto student;
            }
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
string signinoptions()
{
        string oo;
        cout << "\t \t \t \t \t \t \t \t \t \t 1. SignIn as Admin.. " << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t 2. SignIn as Student.. " << endl;
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Enter Your Option.. ";
        cin >> oo;
        return oo;
}

string mainMenu()
{
    string opt;
    system ("cls");
    printHeader();
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 1. Sign In..  " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 2. Sign Up..  " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 3. Exit..  " << endl;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Your Option.. ";
    cin >> opt;
    return opt;
}
bool signinAdminOption(int count, string names[] , string passwords[] , string un,string pass )
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if ((un == names[i] && pass == passwords[i]))
        {
            found = true;
        }
 
    }
    if (found == false)
    {
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t User not found..." << endl;        
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Press any key to go back.." << endl;
        getch();
    }
    return found;

}
bool signinStudentOption(string uns, string passs , int studentcount, string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{ 
    bool found = false;
    for (int i = 0; i < studentcount; i++)
    {
        if ((uns == studentnames[i] && passs == studentPasswords[i]))
        {
            found = true;
            currentIndex = i;
            break;
        }
 
    }
    if (found == false)
    {
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t User not found in database..." << endl;  
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Press any key to go back..";
        getch();
    }
    return found;
}
string signup()
{
    system ("cls");
    signupHeader();
    cout << endl;
    cout << endl;

    string o;
    cout << "\t \t \t \t \t \t \t \t \t \t 1. SignUp as Student.. " << endl;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Your Option.. ";
    cin >> o;
    return o;
}
void signUpStudent(int &studentcount, string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{
start:
    system ("cls");
    studentSignupHeader();
    cout << endl;
    cout << endl;

    string stname, stdeprt, stpass;
    string stroll;

    cout << "\t \t \t \t \t \t \t \t \t \t Enter Username.. ";
    cin >> stname;
    
    cout << "\t \t \t \t \t \t \t \t \t \t User Password.. ";
    cin >> stpass;

    cout << "\t \t \t \t \t \t \t \t \t \t Enter Your Roll Number.. ";
    cin >> stroll;

    cout << "\t \t \t \t \t \t \t \t \t \t Enter Your Department.. ";
    cin >> stdeprt;


    for (int i = 0; i < studentcount; i++)
    {
        if ((stname == studentnames[i] && stroll == studentRollNumbers[i]) || stroll == studentRollNumbers[i])
        {
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
            Sleep(700);
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Student already exist.. " << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
            getch();
            goto start;
        }
    }    

    studentnames[studentcount] = stname;
    studentRollNumbers[studentcount] = stroll;
    studentPasswords[studentcount] = stpass;
    studentDepts[studentcount] = stdeprt;
    studentcount++;

    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
    Sleep(700);
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Signed Up Sucessfully.. ";
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
    getch();
}
string addAdmin(int &count,string names[],string passwords[])
{
startadmin:
    system ("cls");
    adminsignupHeader();
    cout << endl;
    cout << endl;

    string password, role, name; 

    cout << "\t \t \t \t \t \t \t \t \t \t Enter Username.. ";
    cin >> name;
    
    cout << "\t \t \t \t \t \t \t \t \t \t User Password.. ";
    cin >> password ;

    for (int i = 0; i < count; i++)
    {
        if (name == names[i] && password == passwords[i])
        {
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
            Sleep(700);    
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t User already exist.. ";
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
            getch();
            goto startadmin;
        }
    }    
        

        names[count] = name;
        passwords[count] = password;
        count++;

    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
    Sleep(700);
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Admin Added Sucessfully.. " << endl;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
    getch();
}  
string getAnonymousPass()
{
    char singleLetter;
    string completeWord;
    while(true)
    {
        singleLetter = getch();
        if (singleLetter == '\r')
            break;
        cout << "*";
        completeWord += singleLetter;
    }
    return completeWord;
}
string admin()
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    string option;
    cout << "\t \t \t \t \t \t \t \t \t \t 1. Add Book.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 2. View Books.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 3. Remove Book.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 4. Add Student.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 5. View Students.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 6. Remove Student.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 7. Issue Book.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 8. Search Book.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 9. Search Book By Author.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 10. Add Admin.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 11. View Records.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 12. Return Book.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 13. Log Out.. " << endl;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Your Option.." ;
    cin >> option;
    return option;
}
string addbook(int &bookcount,string booknames[],string booklocations[],string bookauthor[] ,string bookcopies[],int bookavailables[])
{
book:    
    string name, location , author ,copy;
    int available;
    
       
        bool stop = false;
        while(!stop)
        {
            system("cls");
            printHeader();
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Enter The Name Of Book.. ";
            cin >> name;
            cout << "\t \t \t \t \t \t \t \t \t \t Enter The Location Of Book.. ";
            cin >> location;
            cout << "\t \t \t \t \t \t \t \t \t \t Enter The Name OF the Author of Book.. ";
            cin >> author;
            cout << "\t \t \t \t \t \t \t \t \t \t Enter The Total Number Of Copies Of Book.. ";
            cin >> copy;
            cout << "\t \t \t \t \t \t \t \t \t \t Enter The Number Of Copies Available.. ";
            cin >> available;

            for (int x = 0 ; x < bookcount ; x++)
            {
                if (name == booknames[x])
                {
                    cout << endl;
                    cout << endl;
                    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
                    Sleep(700);
                    cout << endl;
                    cout << endl;
                    cout << "\t \t \t \t \t \t \t \t \t \t Book Already Exist..";
                    cout << endl;
                    cout << endl;
                    cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
                    getch();
                    goto book;
                }
            }
            booknames[bookcount] = name;        
            booklocations[bookcount] = location;  
            bookauthor[bookcount] = author;      
            bookcopies[bookcount] = copy;        
            bookavailables[bookcount] = available;        
            bookcount++;

            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
            Sleep(700);
            cout << endl;
            cout << endl;
            cout << "\t \t \t \t \t \t \t \t \t \t Book Added Successfully..";
            cout << endl;
            cout << endl;
            


            int proceed;
            cout << "\t \t \t \t \t \t \t \t \t \t Do you want to continue?  1 for (Yes) 2 for (No).. ";
            cin >> proceed;
        if (proceed == 2)
        {
            stop = true;
        }
    }
}

bool removebook(int bookcount,string booknames[],string booklocations[],string bookauthor[] ,string bookcopies[],int bookavailables[])
{
    del = 1;
    viewbooks(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
    int sr;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Sr. NO of book you want to remove.";
    cin >> sr;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
    Sleep(700);
    cout << endl;    
    cout << endl;    
    cout << "\t \t \t \t \t \t \t \t \t \t Book removed sucessfully..";  
    Sleep(1000); 
    booknames[sr] = "";
    del = 0;
    viewbooks(bookcount,booknames,booklocations,bookauthor ,bookcopies,bookavailables);
}
string addStudent(int &studentcount, string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{  
student:    
    bool stop = false;
    while(!stop)
    {
        system("cls");
        printHeader();
        cout << endl;
        cout << endl;
        string nam ;
        string rollno ;
        string dept , passw; 
        cout << "\t \t \t \t \t \t \t \t \t \t Enter The Name Of Student.. ";
        cin >> nam;
        cout << "\t \t \t \t \t \t \t \t \t \t Enter The Password Of Student.. ";
        cin >> passw;
        cout << "\t \t \t \t \t \t \t \t \t \t Enter The Roll Number Of Student.. ";
        cin >> rollno;
        cout << "\t \t \t \t \t \t \t \t \t \t Enter The Department Of Student.. ";
        cin >> dept;

         for (int x = 0 ; x < studentcount ; x++)
            {
                if ((nam == studentnames[x] && rollno == studentRollNumbers[x]) || rollno == studentRollNumbers[x])
                {
                    cout << endl;
                    cout << endl;
                    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
                    Sleep(700);
                    cout << endl;
                    cout << endl;
                    cout << "\t \t \t \t \t \t \t \t \t \t Student Already Exist..";
                    cout << endl;
                    cout << endl;
                    cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
                    getch();
                    goto student;
                }
            }

        studentnames[studentcount] = nam;
        studentRollNumbers[studentcount] = rollno;
        studentPasswords[studentcount] = passw;
        studentDepts[studentcount] = dept;
        studentcount++;

        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
        Sleep(700); 
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Student Added Successfully..";
        cout << endl;
        cout << endl;
 
        int proceed;
        cout << "\t \t \t \t \t \t \t \t \t \t Do you want to continue?  1 for (Yes) 2 for (No).. ";
        cin >> proceed;
        if (proceed == 2)
        {
            stop = true;
        }
    }
}
void viewbooks(int bookcount,string booknames[],string booklocations[],string bookauthor[] ,string bookcopies[],int bookavailables[])
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    cout << "Serial No. \tBook Name \t     Book Location \t  Author \t Total Copies \t Copies Available" << endl;
    for (int x = 0 ; x < bookcount ; x++)
    {
        if (booknames[x] != "")
            cout << x << "\t" << "\t" << booknames[x] << "\t" << "\t" << "\t"<<  booklocations[x] << "\t" << "\t   " << bookauthor[x] << "\t" << "\t    " << bookcopies[x] << "\t" << "\t     "<<bookavailables[x] << endl;
    }
    if (del == 0)
    {
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
        getch();
    }
}
void viewstudents(int studentcount, string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    cout << "Roll No. \tStudent Name \t Student's Department" << endl;
    for (int x = 0 ; x < studentcount ; x++)
    {
         if (studentnames[x] != "")
        cout << studentRollNumbers[x] << "\t" << "\t" << studentnames[x] << "\t" << "\t" << "\t"<<  studentDepts[x]<< endl;
    }
    if (del == 0)
    {
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue.. ";
    getch();
    }
}

bool removestudent(int studentcount, string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{
    del = 1;
    viewstudents(studentcount , studentnames , studentRollNumbers , studentPasswords , studentDepts);
    int srn;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Roll No. of Student you want to remove..";
    cin >> srn;
    studentnames[srn - 1] = "";
    del = 0;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
    Sleep(700);
    cout << endl;    
    cout << "\t \t \t \t \t \t \t \t \t \t Student removed sucessfully..";  
    Sleep(1000);  
    viewstudents(studentcount , studentnames , studentRollNumbers , studentPasswords , studentDepts);
}

string issueBook(int bookcount, int studentcount,string studentnames[], string booknames[],string booklocations[],string bookauthor[], string bookcopies[],int bookavailables[] , string boOks[] , string naMes[] ,int &issuecount , string issuedate[] , string returndate[])
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    string stdName;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Name of Student.. " ;
    cin >> stdName;

    string book;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter book name.. ";
    cin >> book;

    string issudate;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Issue Date.. ";
    cin >> issudate;

    string returdate;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Return date..";
    cin >> returdate; 


    int bookIdx = 0;
    bool bookFound = false;
    for (int i = 0; i < bookcount; i++)
    {
        if (booknames[i] == book)
        {
            bookFound = true;
            bookIdx = i;
            break;
        }
    }
    if (!bookFound)
    {
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Please Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Book does'nt exist.." << endl;
    }
    int stdIdx = 0;
    bool userFound = false;
    for (int i = 0; i < studentcount; i++)
    {
        if (studentnames[i] == stdName)
        {
            userFound = true;
            stdIdx = i;
            break;
        }
    }
    if (!userFound)
    {
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Please Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t User does'nt exist.." ;
    }

    if (bookFound && userFound)
    {
        bookavailables[bookIdx]--;
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Please Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Book Issued Sucessfully..";
        cout << endl;
        boOks[issuecount] = book;
        naMes[issuecount] = stdName;
        issuedate[issuecount] = issudate;
        returndate[issuecount] = returdate;
        issuecount++;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue..";
    }
    getch();
}


string searchbook(int bookcount,string booknames[],string booklocations[],string bookauthor[], string bookcopies[],int bookavailables[])
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    string snm;
    cout << "\t \t \t \t \t \t \t Enter the name of the book you are looking for.. ";
    cin >> snm;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
    Sleep(700);
    cout << endl;
    cout << endl;
    bool found = false;
    cout << "Serial No. \tBook Name \t     Book Location \t  Book Author \t Total Copies \t Copies Available" << endl;
    for (int i = 0; i < bookcount; i++)
    {
        if (booknames[i] == snm)
        {
            cout << i << "\t" << "\t" << booknames[i] << "\t" << "\t" << "\t"<<  booklocations[i] << "\t" << "\t"  << "\t" <<bookauthor[i] << "\t" << "\t" << bookcopies[i] << "\t" << "\t"<<bookavailables[i] << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \tPlease Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Book does'nt exist.." ;
    }
 
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue...";  
    getch();
}
string searchbookbyauthor(int bookcount,string booknames[],string booklocations[],string bookauthor[], string bookcopies[],int bookavailables[])
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    string snm;
    cout << "\t \t \t \t \t \t \t Enter the name of the Author you are looking for.. ";
    cin >> snm;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Please wait a moment..";
    Sleep(700);
    cout << endl;
    cout << endl;
    bool found = false;
    cout << "Serial No. \tBook Name \t     Book Location \t Author \t Total Copies \t Copies Available" << endl;
    for (int i = 0; i < bookcount; i++)
    {
        if (bookauthor[i] == snm)
        {
            cout << i << "\t" << "\t" << booknames[i] << "\t" << "\t" << "\t"<<  booklocations[i] << "\t" << "\t   "  <<bookauthor[i] << "\t" << "\t"  << "\t"<< bookcopies[i] << "\t" << "\t"<<bookavailables[i] << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \tPlease Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Author not found.." ;
    }
 
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue...";  
    getch();
}
string student()
{
    system("cls");
    printHeader();
    string opti;
    cout << endl;
    cout << endl;    
    cout << "\t \t \t \t \t \t \t \t \t \t 1. Search Book.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 2. Search Book by Author.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 3. View All Books.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 4. View History.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 5. View Profile.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 6. Change Password.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 7. Change Username.. " << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t 8. Log Out.. " << endl;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Your Option.." ;
    cin >> opti; 
    return opti;
}
void savestudents(int studentcount, string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{
    string data = "";
    fstream file;
    file.open("Student.txt" , ios::out);
    for(int x = 0 ; x < studentcount ; x++)
    { 
        if (x == studentcount - 1)
            data +=  studentnames[x] + "," + (studentRollNumbers[x] )+ "," + studentPasswords[x] + "," + studentDepts[x];
        else
            data +=  studentnames[x] + "," + (studentRollNumbers[x] )+ "," + studentPasswords[x] + "," + studentDepts[x] + "\n";
        file << data;
        data = "" ;
    }
    file.close();
}
void loadstudents(int &studentcount, string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{
    string data = "";
    fstream file;
    file.open("Student.txt" , ios::in);
    while (!file.eof())
    {
        getline(file, data);
        studentnames[studentcount] = getdata(data , 0);
        studentRollNumbers[studentcount] = getdata(data , 1);
        studentPasswords[studentcount] = getdata(data , 2);
        studentDepts[studentcount] = getdata(data , 3);
        studentcount++;
    }
    
    file.close();
}
string getdata(string data , int comma)
{
    int count = 0;
    string result = "";
    for (int x = 0 ; x < data.length() ; x++)
    {
        if (data[x] == ',')
        {
            count++;
        }
        else if (count == comma)
        {
            result += data[x];
        }
        else if (count > comma)
        {
            break;
        }
    }
    return result;
}
void savebooks(int bookcount,string booknames[],string booklocations[],string bookauthor[], string bookcopies[],int bookavailables[])
{
    string data = "";
    fstream file;
    file.open("Book.txt" , ios::out);
    for(int x = 0 ; x < bookcount ; x++)
    { 
        if (x == bookcount - 1)
            data +=  booknames[x] + "," + (booklocations[x] ) + "," + bookauthor[x] + "," + (bookcopies[x]) + "," + to_string(bookavailables[x]);
        else
            data +=  booknames[x] + "," + (booklocations[x] ) + "," + bookauthor[x] + "," + (bookcopies[x]) + "," + to_string(bookavailables[x]) + "\n";
        file << data;
        data = "" ;
    }
    file.close();
}
void loadbooks(int &bookcount,string booknames[],string booklocations[],string bookauthor[], string bookcopies[],int bookavailables[])
{
    string data = "";
    fstream file;
    file.open("Book.txt" , ios::in);
    while (!file.eof())
    {
        getline(file, data);
        booknames[bookcount] = getdata(data , 0);
        booklocations[bookcount] = getdata(data , 1);
        bookauthor[bookcount] = getdata(data , 2);
        bookcopies[bookcount] =  getdata(data , 3);
        bookavailables[bookcount] = stoi(getdata(data , 4));
        bookcount++;
    }
    file.close();
}
void saveadmins(int count, string names[] , string passwords[])
{
    string data = "";
    fstream file;
    file.open("Admin.txt" , ios::out);
    for(int x = 0 ; x < count ; x++)
    { 
        if (x == count - 1)
            data +=  names[x] + "," + passwords[x]; 
        else
            data +=  names[x] + "," + passwords[x] + "\n";
        file << data;
        data = "" ;
    }
    file.close();
}
void loadadmins(int &count, string names[] , string passwords[])
{
    string data = "";
    fstream file;
    file.open("Admin.txt" , ios::in);
    while (!file.eof())
    {
        getline(file, data);
        names[count] = getdata(data , 0);
        passwords[count] = getdata(data , 1);
        count++;
    }
    file.close();
}
void history(string booknames[], int studentcount , string studentnames[] ,  string studentPasswords[] , string boOks[] , string naMes[] , int issuecount , string issuedate[] , string returndate[]) 
{
    system("cls");
    printHeader();
    string nameS;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \tConfirm Your Name and Password to view history..";
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter your name..";
    cin >> nameS;
    string passwordS;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Your password..";
    cin >> passwordS;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Please Wait a moment.." << endl;
    Sleep(700);
    bool found = false;
    for (int x = 0 ; x < studentcount ; x++)
    {
        if (nameS == studentnames[x] && passwordS == studentPasswords[x])
        {
            found = true;
        }
    }
    cout << "\t \t \t \t \t \t \t \t \t \t Your History Is Given Below.." << endl;
    cout << endl;
    cout << endl;
    cout << "Books \t \t \t Date Of Issue \t \t \t Date Of Return" << endl;
    if (found == true)
    {
        for (int x = 0 ; x < issuecount ; x++)
        {
            if (nameS == naMes[x])
            {
                cout << boOks[x] << "\t \t \t \t" << issuedate[x] << "\t \t \t \t"<< returndate[x]<< endl;
            }
        }
    }
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press Any Key To Continue..";
    getch();
    if (found == false)
    {
        cout << "\t \t \t \t \t \t \t \t \t \t Wrong Username or Password..";
    }
}
void record(int issuecount ,string boOks[] , string naMes[] , string issuedate[] , string returndate[])
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    cout << "Student Name \t \t Book Name \t \t Date of Issue \t \t Date of Return" << endl; 
    for (int x = 0 ; x < issuecount ; x++)
    {
        cout << naMes[x] << "\t \t \t " << boOks[x] << "\t \t    \t" << issuedate[x] << "\t \t \t" << returndate[x] << endl; 
    }
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press Any Key To Continue.. " ;
    getch();
}
int returnBook(int bookcount, int studentcount,string studentnames[], string booknames[],int bookavailables[])
{
    system("cls");
    printHeader();
    cout << endl;
    cout << endl;
    string stdName;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter Name of Student.. " ;
    cin >> stdName;

    string book;
    cout << "\t \t \t \t \t \t \t \t \t \t Enter book name.. ";
    cin >> book;
  
    int bookIdx = 0;
    bool bookFound = false;
    for (int i = 0; i < bookcount; i++)
    {
        if (booknames[i] == book)
        {
            bookFound = true;
            bookIdx = i;
            break;
        }
    }
    if (!bookFound)
    {
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \tPlease Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \tBook does'nt exist.." << endl;
    }
    int stdIdx = 0;
    bool userFound = false;
    for (int i = 0; i < studentcount; i++)
    {
        if (studentnames[i] == stdName)
        {
            userFound = true;
            stdIdx = i;
            break;
        }
    }
    if (!userFound)
    {
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Please Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t User does'nt exist.." ;
    }

    if (bookFound && userFound)
    {
        bookavailables[bookIdx]++;
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Please Wait A Moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Book Returned Sucessfully..";
        cout << endl;
        cout << endl;
        cout << "\t \t \t \t \t \t \t \t \t \t Press any key to continue..";
    }
    getch();
}
void saverecord(int issuecount ,string naMes[] ,string boOks[] , string issuedate[] , string returndate[])
{
    string data = "";
    fstream file;
    file.open("Records.txt" , ios::out);
    for(int x = 0 ; x < issuecount ; x++)
    { 
        if (x == issuecount - 1)
            data +=  naMes[x]  + "," + boOks[x] + "," + issuedate[x] + "," + returndate[x];
        else
            data +=  naMes[x]  + "," + boOks[x] + "," + issuedate[x] + "," + returndate[x] + "\n";
        file << data;
        data = "" ;
    }
    file.close();
}
void loadrecord(int &issuecount ,string naMes[] ,string boOks[] , string issuedate[] , string returndate[])
{
    string data = "";
    fstream file;
    file.open("Records.txt" , ios::in);
    while (!file.eof())
    {
        getline(file, data);
        naMes[issuecount] = getdata(data , 0);
        boOks[issuecount] = getdata(data , 1);
        issuedate[issuecount] = getdata(data , 2);
        returndate[issuecount] = getdata(data , 3);
        issuecount++;
    }
    file.close();
}
void viewprofile( string studentnames[] , string studentRollNumbers[] , string studentPasswords[] , string studentDepts[])
{
    system("cls");
    printHeader();
    cout <<  "\t \t \t \t \t \t \t \t \t \t Your Information is given below" << endl;
    cout << endl;
    cout << endl;
    cout <<  "\t \t \t \t \t \t \t \t \t \t Name: " << studentnames[currentIndex] << endl;
    cout <<  "\t \t \t \t \t \t \t \t \t \t Roll No: " << studentRollNumbers[currentIndex] << endl;
    cout <<  "\t \t \t \t \t \t \t \t \t \t Pasword: " << studentPasswords[currentIndex] << endl;
    cout <<  "\t \t \t \t \t \t \t \t \t \t Department: " << studentDepts[currentIndex] << endl;
    getch();
}
string changepassword(string studentPasswords[])
{
    system("cls");
    printHeader();
    cout << endl;
    string pasw;
    cout << "\t \t \t \t \t \t \t \t \t \t Re-Enter Your Password..";
    cin >> pasw;
    string newpass;
    if (pasw == studentPasswords[currentIndex])
    {
        cout << "\t \t \t \t \t \t \t \t \t \t Enter New Password..";
        cin >> newpass;
        cout <<  "\t \t \t \t \t \t \t \t \t \t Please Wait A moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout <<  "\t \t \t \t \t \t \t \t \t \t Password Changed Sucessfuly..";
        studentPasswords[currentIndex] = newpass;
    }
    else if (pasw != studentPasswords[currentIndex])
    {
        cout <<  "\t \t \t \t \t \t \t \t \t \t Please Wait A moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout <<  "\t \t \t \t \t \t \t \t \t \t Wrong Password..";
    }
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press Any Key To Continue.. " ;
    getch();
}
string changename(string studentnames[])
{
    system("cls");
    printHeader();
    cout << endl;
    string nme;
    cout << "\t \t \t \t \t \t \t \t \t \t Re-Enter Your Name..";
    cin >> nme;
    string newname;
    
    if (nme == studentnames[currentIndex])
    {
        cout << "\t \t \t \t \t \t \t \t \t \t Enter New Name..";
        cin >> newname;
        cout <<  "\t \t \t \t \t \t \t \t \t \t Please Wait A moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout <<  "\t \t \t \t \t \t \t \t \t \t Name Changed Sucessfuly..";
        studentnames[currentIndex] = newname;
    }
    else if (nme != studentnames[currentIndex])
    {
        cout <<  "\t \t \t \t \t \t \t \t \t \t Please Wait A moment..";
        Sleep(700);
        cout << endl;
        cout << endl;
        cout <<  "\t \t \t \t \t \t \t \t \t \t Wrong Name..";
    }
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t \t \t \t \t Press Any Key To Continue.. " ;
    getch();
}
string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);   
    return"";
}
void printHeader()
{
    setcolor(2);
    cout << R"(                                                      __           __                                                           )" << endl; 
    cout << R"(                                                     /\ \       __/\ \                                                          )" << endl; 
    cout << R"(                                                     \ \ \     /\_\ \ \____  _ __    __     _ __   __  __                       )" << endl; 
    cout << R"(                                                      \ \ \  __\/\ \ \ '__`\/\`'__\/'__`\  /\`'__\/\ \/\ \                      )" << endl; 
    cout << R"(                                                       \ \ \L\ \\ \ \ \ \L\ \ \ \//\ \L\.\_\ \ \/ \ \ \_\ \                     )" << endl; 
    cout << R"(                                                        \ \____/ \ \_\ \_,__/\ \_\\ \__/.\_\\ \_\  \/`____ \                    )" << endl; 
    cout << R"(                                                         \/___/   \/_/\/___/  \/_/ \/__/\/_/ \/_/   `/___/> \                   )" << endl; 
    cout << R"(                                                                                                       /\___/                   )" << endl; 
    cout << R"(                                                                                                       \/__/                    )" << endl; 
    cout << R"(                                                                                                                       __       )" << endl; 
    cout << R"(                                           /'\_/`\                                                                    /\ \__    )" << endl; 
    cout << R"(                                          /\      \     __      ___      __       __      __    ___ ___      __    ___\ \ ,_\   )" << endl; 
    cout << R"(                                          \ \ \__\ \  /'__`\  /' _ `\  /'__`\   /'_ `\  /'__`\/' __` __`\  /'__`\/' _ `\ \ \/   )" << endl; 
    cout << R"(                                           \ \ \_/\ \/\ \L\.\_/\ \/\ \/\ \L\.\_/\ \L\ \/\  __//\ \/\ \/\ \/\  __//\ \/\ \ \ \_  )" << endl; 
    cout << R"(                                            \ \_\\ \_\ \__/.\_\ \_\ \_\ \__/.\_\ \____ \ \____\ \_\ \_\ \_\ \____\ \_\ \_\ \__\ )" << endl; 
    cout << R"(                                             \/_/ \/_/\/__/\/_/\/_/\/_/\/__/\/_/\/___L\ \/____/\/_/\/_/\/_/\/____/\/_/\/_/\/__/ )" << endl; 
    cout << R"(                                                                                  /\____/                                       )" << endl; 
    cout << R"(                                                                                  \_/__/                                        )" << endl; 
    cout << R"(                                                                 ____                     __                                    )" << endl; 
    cout << R"(                                                                /\  _`\                  /\ \__                                 )" << endl; 
    cout << R"(                                                                \ \,\L\_\  __  __    ____\ \ ,_\    __    ___ ___               )" << endl; 
    cout << R"(                                                                 \/_\__ \ /\ \/\ \  /',__\\ \ \/  /'__`\/' __` __`\             )" << endl; 
    cout << R"(                                                                   /\ \L\ \ \ \_\ \/\__, `\\ \ \_/\  __//\ \/\ \/\ \            )" << endl; 
    cout << R"(                                                                   \ `\____\/`____ \/\____/ \ \__\ \____\ \_\ \_\ \_\           )" << endl; 
    cout << R"(                                                                    \/_____/`/___/> \/___/   \/__/\/____/\/_/\/_/\/_/           )" << endl; 
    cout << R"(                                                                               /\___/                                           )" << endl; 
    cout << R"(                                                                               \/__/                                            )" << endl; 
    setcolor(6);
}

void signupHeader()
{
    setcolor(2);
    cout << R"(                                                                ____                        __  __                )"<<endl;
    cout << R"(                                                               /\  _`\   __                /\ \/\ \               )"<<endl;
    cout << R"(                                                               \ \,\L\_\/\_\     __     ___\ \ \ \ \  _____       )"<<endl;
    cout << R"(                                                                \/_\__ \\/\ \  /'_ `\ /' _ `\ \ \ \ \/\ '__`\     )"<<endl;
    cout << R"(                                                                  /\ \L\ \ \ \/\ \L\ \/\ \/\ \ \ \_\ \ \ \L\ \    )"<<endl;
    cout << R"(                                                                  \ `\____\ \_\ \____ \ \_\ \_\ \_____\ \ ,__/    )"<<endl;
    cout << R"(                                                                   \/_____/\/_/\/___L\ \/_/\/_/\/_____/\ \ \/     )"<<endl;
    cout << R"(                                                                                 /\____/                \ \_\     )"<<endl;
    cout << R"(                                                                                 \_/__/                  \/_/     )"<<endl;    
    setcolor(6);
}
void adminsignupHeader()
{
    setcolor(2);
    cout << R"(                                                                      ______      __                                                )" << endl;
    cout << R"(                                                                     /\  _  \    /\ \              __                               )" << endl;
    cout << R"(                                                                     \ \ \L\ \   \_\ \    ___ ___ /\_\    ___                       )" << endl;
    cout << R"(                                                                      \ \  __ \  /'_` \ /' __` __`\/\ \ /' _ `\                     )" << endl;
    cout << R"(                                                                       \ \ \/\ \/\ \L\ \/\ \/\ \/\ \ \ \/\ \/\ \                    )" << endl;
    cout << R"(                                                                        \ \_\ \_\ \___,_\ \_\ \_\ \_\ \_\ \_\ \_\                   )" << endl;
    cout << R"(                                                                         \/_/\/_/\/__,_ /\/_/\/_/\/_/\/_/\/_/\/_/                   )" << endl;
    cout << R"(                                                                                                                                    )" << endl;
    cout << R"(                                                                      ____                        __  __                            )" << endl;
    cout << R"(                                                                     /\  _`\   __                /\ \/\ \                           )" << endl;
    cout << R"(                                                                     \ \,\L\_\/\_\     __     ___\ \ \ \ \  _____                   )" << endl;
    cout << R"(                                                                      \/_\__ \\/\ \  /'_ `\ /' _ `\ \ \ \ \/\ '__`\                 )" << endl;
    cout << R"(                                                                        /\ \L\ \ \ \/\ \L\ \/\ \/\ \ \ \_\ \ \ \L\ \                )" << endl;
    cout << R"(                                                                        \ `\____\ \_\ \____ \ \_\ \_\ \_____\ \ ,__/                )" << endl;
    cout << R"(                                                                         \/_____/\/_/\/___L\ \/_/\/_/\/_____/\ \ \/                 )" << endl;
    cout << R"(                                                                                       /\____/                \ \_\                 )" << endl;
    cout << R"(                                                                                       \_/__/                  \/_/                 )" << endl;     
    setcolor(6);     
}

void adminSignInHeader()
{
    setcolor(2);
    cout << R"(                                                                        ______      __                                    )" << endl;
    cout << R"(                                                                       /\  _  \    /\ \              __                   )" << endl;
    cout << R"(                                                                       \ \ \L\ \   \_\ \    ___ ___ /\_\    ___           )" << endl;
    cout << R"(                                                                        \ \  __ \  /'_` \ /' __` __`\/\ \ /' _ `\         )" << endl;
    cout << R"(                                                                         \ \ \/\ \/\ \L\ \/\ \/\ \/\ \ \ \/\ \/\ \        )" << endl;
    cout << R"(                                                                          \ \_\ \_\ \___,_\ \_\ \_\ \_\ \_\ \_\ \_\       )" << endl;
    cout << R"(                                                                           \/_/\/_/\/__,_ /\/_/\/_/\/_/\/_/\/_/\/_/       )" << endl;
    cout << R"(                                                                                                                          )" << endl;
    cout << R"(                                                                        ____                        ______                )" << endl;
    cout << R"(                                                                       /\  _`\   __                /\__  _\               )" << endl;
    cout << R"(                                                                       \ \,\L\_\/\_\     __     ___\/_/\ \/     ___       )" << endl;
    cout << R"(                                                                        \/_\__ \\/\ \  /'_ `\ /' _ `\ \ \ \   /' _ `\     )" << endl;
    cout << R"(                                                                          /\ \L\ \ \ \/\ \L\ \/\ \/\ \ \_\ \__/\ \/\ \    )" << endl;
    cout << R"(                                                                          \ `\____\ \_\ \____ \ \_\ \_\/\_____\ \_\ \_\   )" << endl;
    cout << R"(                                                                           \/_____/\/_/\/___L\ \/_/\/_/\/_____/\/_/\/_/   )" << endl;
    cout << R"(                                                                                         /\____/                          )" << endl;
    cout << R"(                                                                                         \_/__/                           )" << endl;
    setcolor(6);
}
void siginHeader()
{
    setcolor(2);
    cout << R"(                                                                       ____                        ______                                            )"<< endl;
    cout << R"(                                                                      /\  _`\   __                /\__  _\                                           )"<< endl;
    cout << R"(                                                                      \ \,\L\_\/\_\     __     ___\/_/\ \/     ___                                   )"<< endl;
    cout << R"(                                                                       \/_\__ \\/\ \  /'_ `\ /' _ `\ \ \ \   /' _ `\                                 )"<< endl;
    cout << R"(                                                                         /\ \L\ \ \ \/\ \L\ \/\ \/\ \ \_\ \__/\ \/\ \                                )"<< endl;
    cout << R"(                                                                         \ `\____\ \_\ \____ \ \_\ \_\/\_____\ \_\ \_\                               )"<< endl;
    cout << R"(                                                                          \/_____/\/_/\/___L\ \/_/\/_/\/_____/\/_/\/_/                               )"<< endl;
    cout << R"(                                                                                        /\____/                                                      )"<< endl;
    cout << R"(                                                                                        \_/__/                                                        )"<< endl;
    setcolor(6);       
}
void studentSignInHeader()
{
    setcolor(2);
    cout << R"(                                                            ____    __                __                 __                  )" << endl;
    cout << R"(                                                           /\  _`\ /\ \__            /\ \               /\ \__               )" << endl;
    cout << R"(                                                           \ \,\L\_\ \ ,_\  __  __   \_\ \     __    ___\ \ ,_\              )" << endl;
    cout << R"(                                                            \/_\__ \\ \ \/ /\ \/\ \  /'_` \  /'__`\/' _ `\ \ \/              )" << endl;
    cout << R"(                                                              /\ \L\ \ \ \_\ \ \_\ \/\ \L\ \/\  __//\ \/\ \ \ \_             )" << endl;
    cout << R"(                                                              \ `\____\ \__\\ \____/\ \___,_\ \____\ \_\ \_\ \__\            )" << endl;
    cout << R"(                                                               \/_____/\/__/ \/___/  \/__,_ /\/____/\/_/\/_/\/__/            )" << endl;
    cout << R"(                                                                                                                             )" << endl;
    cout << R"(                                                                       ____                        ______                    )" << endl;
    cout << R"(                                                                      /\  _`\   __                /\__  _\                   )" << endl;
    cout << R"(                                                                      \ \,\L\_\/\_\     __     ___\/_/\ \/     ___           )" << endl;
    cout << R"(                                                                       \/_\__ \\/\ \  /'_ `\ /' _ `\ \ \ \   /' _ `\         )" << endl;
    cout << R"(                                                                         /\ \L\ \ \ \/\ \L\ \/\ \/\ \ \_\ \__/\ \/\ \        )" << endl;
    cout << R"(                                                                         \ `\____\ \_\ \____ \ \_\ \_\/\_____\ \_\ \_\       )" << endl;
    cout << R"(                                                                          \/_____/\/_/\/___L\ \/_/\/_/\/_____/\/_/\/_/       )" << endl;
    cout << R"(                                                                                        /\____/                              )" << endl;
    cout << R"(                                                                                        \_/__/                               )" << endl;
    setcolor(6);
}
void studentSignupHeader()
{
    setcolor(2);
    cout << R"(                                                             ____    __                __                 __               )" << endl;
    cout << R"(                                                            /\  _`\ /\ \__            /\ \               /\ \__            )" << endl;
    cout << R"(                                                            \ \,\L\_\ \ ,_\  __  __   \_\ \     __    ___\ \ ,_\           )" << endl;
    cout << R"(                                                             \/_\__ \\ \ \/ /\ \/\ \  /'_` \  /'__`\/' _ `\ \ \/           )" << endl;
    cout << R"(                                                               /\ \L\ \ \ \_\ \ \_\ \/\ \L\ \/\  __//\ \/\ \ \ \_          )" << endl;
    cout << R"(                                                               \ `\____\ \__\\ \____/\ \___,_\ \____\ \_\ \_\ \__\         )" << endl;
    cout << R"(                                                                \/_____/\/__/ \/___/  \/__,_ /\/____/\/_/\/_/\/__/         )" << endl;
    cout << R"(                                                                                                                           )" << endl;
    cout << R"(                                                                                                                           )" << endl;
    cout << R"(                                                                        ____                        __  __                 )" << endl;
    cout << R"(                                                                       /\  _`\   __                /\ \/\ \                )" << endl;
    cout << R"(                                                                       \ \,\L\_\/\_\     __     ___\ \ \ \ \  _____        )" << endl;
    cout << R"(                                                                        \/_\__ \\/\ \  /'_ `\ /' _ `\ \ \ \ \/\ '__`\      )" << endl;
    cout << R"(                                                                          /\ \L\ \ \ \/\ \L\ \/\ \/\ \ \ \_\ \ \ \L\ \     )" << endl;
    cout << R"(                                                                          \ `\____\ \_\ \____ \ \_\ \_\ \_____\ \ ,__/     )" << endl;
    cout << R"(                                                                           \/_____/\/_/\/___L\ \/_/\/_/\/_____/\ \ \/      )" << endl;
    cout << R"(                                                                                         /\____/                \ \_\      )" << endl;
    cout << R"(                                                                                         \_/__/                  \/_/      )" << endl;
    setcolor(6);
}