/**
 * @author Kieni Edojah
 * @version 1.0
*/

#include <iostream>
#include <fstream> //enable file handling
#include <string>
#include <vector>
using namespace std;

void registration();    //declare function for user registration
void login();           //declare function for user login
void forgot();          //declare function to help user recover forgotten password
void back();            //declare function to help user navigate back to main menu or exit the program

int main()
{
    int choice;         //variable which will accept user input
    cout<<"\t\t\t_______________________________________________\n\n\n";
    cout<<"\t\t\t       Welcome to the Main Menu Page           \n\n\n";
    cout<<"\t\t\t _______________    MENU _____________________ \n\n\n";
    cout<<"";
    cout<<"\t\t\t|  Press 1 to REGISTER                     |"<<endl;
    cout<<"\t\t\t|  Press 2 to LOGIN                        |"<<endl;
    cout<<"\t\t\t|  Press 3 if you forgot your PASSWORD     |"<<endl;
    cout<<"\t\t\t|  Press 4 to EXIT                         |"<<endl;
    cout<<"\n\t\t\t Please enter your choice:  ";
    cin>>choice;                   //user input assigned to variable
    cout<<endl;
    
    
        switch(choice)                //call function or exit program depending on user input
    {
        case 1:                  //call registration function if user input is 1
            registration();
            break;

        case 2:                  //call login function if user input is 2
            login();
            break;

        case 3:
            forgot();          //call forgot function if user input is 3
            break;

        case 4:                 //Close the application if user input is 4
            cout<<"\t\t\t Thank You! \n\n";
            break;

        default:                //Redirect user to main menu if user input is invalid
            system("cls");
            cout<<endl<<endl<<"\t\t\t Please select from the options given below \n"<<endl<<endl;
            main();
    } 
    
    
    
    return 0;
    }
    
/**
 * This function  logs a previously registered user in.
 * 
*/

void login()
{

    system("cls");

    int count;
    string userId, password, id, pass;  //define variables which will take user input


    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    
    cout<<"\t\t\t Please enter your username and password: "<<endl<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;                        //variable userId is assigned user defined input
    cout<<endl;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;                      //variable password is assigned user defined input

    ifstream input("records.txt");      //creates and opens a file stream

    while(input>>id>>pass)              //checks the file for specified variables
    {
        if(id==userId && pass==password)    //checks if user input matches file records and sets a variable to 1
        {
             count = 1;
            system("cls");
        }
    }
         input.close();
        if(count==1)
        {
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t"<<userId<<endl<<endl;
            cout<<"\t\t\t\t Your LOGIN is successful"<<endl<<endl<<"\t\t\t\t Thanks for logging in!"<<endl<<endl;
            back();
        }
    
        else{
            system("cls");
            cout<<endl<<endl;           //if condition is false, an error message is displayed to user
            cout<<"\t\t\t\t LOGIN ERROR"<<endl<<endl<<"\t\t\t\t Please check your username and password."<<endl<<endl;
            back();                     //user can choose to return to main menu or exit.
        }
    }



/**
 * This function registers a new user's username and password
*/
void registration()
{

    system("cls");
    int count;
    string ruserId, rpassword, rid, rpass;      //Declare user defined variables and file stream variables
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"\t\t\t Enter username: ";                //Request user input
    cin>>ruserId;                                   //Assign user input to variable
    cout<<endl<<endl<<"\t\t\t Enter password: ";    //Request user input
    cin>>rpassword;                                 //Assign user input to variable

    ifstream input;
    input.open("records.txt");          //open file stream to check file content

    while(input>>rid>>rpass)
    {
        if(rid==ruserId)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count==1)
    {
            cout<<endl<<endl<<"\t\t\t\t"<<ruserId<<":  User already exists."<<endl<<endl<<"\t\t\t\t\t Please LOGIN."<<endl<<endl;
        back();
        }
         else{
            ofstream f1;
            f1.open("records.txt", ios::app);
            f1<<ruserId<<" "<<rpassword<<endl;
            system("cls");
            cout<<endl<<endl<<"\t\t\t\t Registration is successful!"<<endl<<endl;
      back();
        }
    

}


/**
 * This function helps a registered user recover his password
*/
void forgot()
{

    system("cls");

    int option;
    
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t Forgot your password? "<<endl<<endl;
    cout<<"\t\t\t\t Press 1 to search your id by username"<<endl;
    cout<<"\t\t\t\t Press 2 to go back to the main menu"<<endl<<endl;
    cout<<"\t\t\t\t Enter your choice: ";
    cin>>option;
    system("cls");
    cout<<endl<<endl;
    switch(option)
    {
        case 1:
        {
            int count = 0;
            string suserId, sId,spassword, spass;
            cout<<endl<<"\t\t\t\t Enter your username: ";
            cin>>suserId;

            ifstream input;
            input.open("records.txt");
            while(input>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count =1;
                    system("cls");
                }
            }
            input.close();

            if(count==1)
            {
                cout<<endl<<"\t\t\t\tUser exists"<<endl<<endl;
                cout<<"\t\t\t\t Enter your new password:  ";
                cin>>spassword;

                vector<string>v;
                string str;
                ifstream f;
                f.open("records.txt");
                while(f>>str)
                {
                    v.push_back(str);
                }
                f.close();
                for (int i=0;i<v.size();i++){
                    
                    if (v.at(i)==suserId){
                        v.at(i+1)=spassword;
                    }
                 //   cout<<endl<<v.at(i)<<endl;
                    
                }
                ofstream f1;
                f1.open("replace.txt", ios::out);
                for (int i=0;i<v.size();i++){
                    if(i%2==0){
                        f1<<v.at(i)<<" ";
                    }
                    else{
                        f1<<v.at(i)<<endl;
                    }
                }
                f1.close();

/* 
* The next few lines are the process for copying the contents of the new file into the existing records file
*/                 

                string ch;
                ifstream f2;
                f2.open("replace.txt");
                ofstream f3;
                f3.open("records.txt", ios::out);
                while (!f2.eof()) {
 
                 // extracting the content of
                 // first file line by line
                     getline(f2, ch);
 
                 // writing content to second
                 // file line by line
                      f3 << ch << endl;
                }
 
                 // closing the files
               f2.close();
               f3.close();

               system("cls");
               cout<<endl<<endl;
               cout<<"\t\t\t\t Password changed successfully"<<endl<<endl;
               remove("replace.txt");
               back();
               

            }
            else
            {
                cout<<endl<<"\t\t\t\t Sorry your account is not found!"<<endl<<endl;
                back();
            }
            break;
        }

        case 2:
        {
            main();
            break;
        }

        default:
            cout<<endl<<"\t\t\t\t Wrong choice! Please try again"<<endl<<endl;
            forgot();
    }
}

/* 
* This function helps a user redirect to main menu or exit te program
*/
void back()
{
    cout<<"\t\t\t\t Press 1 to return to MAIN MENU"<<endl<<endl;
                cout<<"\t\t\t\t Press 2 to exit program"<<endl<<endl;
                int nxt;
                cout<<"\t\t\t\t Enter your choice: ";
                cin>>nxt;

                switch(nxt)
                {
                    case 1:
                    system("cls");
                    main();
                    break;

                    case 2:
                    exit(0);
                    break;

                    default:
                    cout<<endl<<endl<<"\t\t\t\t ERROR! Invalid input. Please try again";
                }
}
