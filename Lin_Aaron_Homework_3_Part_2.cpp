// Aaron Lin
// 10/20/2024
// Homework 3 Part 2

#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
 
//Beginning of Code
int main()
{
    //Setup Variables
    ifstream transaction; //input file
    ofstream banknote; //output file
    double bal, trans, tDeposit, tWithdraw;
    char type, dollar = '$';

    //Opens Input & Output Files
    transaction.open("trans.txt"); 
    banknote.open("banknote.txt");

    //Setup Starting Balance
    transaction >> bal;   
    banknote << setprecision(2) << fixed;
    banknote << "Starting Balance: " << bal << endl << endl;
    banknote << setfill('.');
    banknote << right << "Type" << setw(13) << "Amount" << setw(20) << "Balance" << endl;

    //Runs Repeatedly Until the End of the File
    while(!transaction.eof()) 
    {
        transaction >> type >> trans; //sets the value for type and trans

        switch(type) //switches depedning on the type
        {
            case 'W': //if type = W
                bal -= trans; //subtract trans off the bal
                tWithdraw += trans; //add trans to tWithdraw
                banknote << right << type << setw(13) << dollar << trans << setw(20) << dollar << bal << endl;
                break; //ends the case
            case 'D': //if type = D
                bal += trans; //add trans to tDeposit
                tDeposit += trans; //add trans to tDeposit
                banknote << right << type << setw(13) << dollar << trans << setw(20) << dollar << bal << endl;
                break; //ends the case
        }
    }

    //Prints out the ending balance, total withdraw, and total deposit
    banknote << "\nEnding Balance: " << dollar << bal << endl;
    banknote << "Total Withdraws: " << dollar << tWithdraw << endl;
    banknote << "Total Deposits: " << dollar << tDeposit << endl;

    //Closes Input & Output Files   
    transaction.close();
    banknote.close();

    return 0; //ends the code
}
