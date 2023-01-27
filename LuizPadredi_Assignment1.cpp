/*
Author: Luiz Padredi
Date: 01/25/2023
Assignment 1: Coin Dispenser Machine
Repository: https://github.com/Padredilg/Coin-Converter
*/

//FIXME -- Set Cap to like 1000 dollars or something.

#include <iostream>

using namespace std;

void promptForChoice();
void amountToCoin();
void coinToAmount();
void askForNewConversion();
int collectCoinCount();

const double quarterConstant = 0.25;
const double dimeConstant = 0.10;
const double nickelConstant = 0.05;
const double pennyConstant = 0.01;


int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Hello user!"
         << endl << endl
         << "What kind of conversion are you looking to do?" << endl;

    promptForChoice();

    cout << "Thank you for using!" << endl
         << "Goodbye!" << endl;

    return 0;
}

/*
 This function collects the user input, and calls other functions to handle conversion accordingly.
*/
void promptForChoice(){
    cout << "Please select the number corresponding to the service you are looking for."
         << endl << endl
         << "1 - Convert dollar amount into coins" << endl
         << "2 - Convert coins into dollar amount" << endl
         << "0 - Exit."
         << endl << endl;

    int choice;
    cin >> choice;


    while (cin.fail() || choice < 0 || choice > 2){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "That is not a valid entry."
             << endl << endl
             << "Please select the number corresponding to the service you are looking for."
             << endl << endl
             << "1 - Convert dollar amount into coins" << endl
             << "2 - Convert coins into dollar amount" << endl
             << "0 - Exit."
             << endl << endl;

        cin >> choice;
    }

    cout << "You chose: " << choice << endl << endl;

    switch (choice){
        case 1:
            amountToCoin();
            break;
        case 2:
            coinToAmount();
            break;
        case 0:
            break;
        default:

            promptForChoice();
    }

    return;
}

/*
This function handles the scenario when user wants to convert from an amount to a distribution of coins.
*/
void amountToCoin(){
    cout << "================================================================================"
         << endl << endl
         << "AMOUNT --> COINS"
         << endl << endl
         //improve this verbiage
         << "Please enter the dollar amount in the format '$X.XX' that you would like to receive in coins." << endl
         << "(Do not include commas or any special characters other than a period to declare cents)"
         << endl << endl
         << "Amount: $";

    double dollarAmount;
    cin >> dollarAmount;


    while (cin.fail() || dollarAmount < 0 || dollarAmount > 1000){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input

        if(dollarAmount > 1000){
            cout << endl << "WOAH! I am just a coin dispenser, I can't convert that much money for you!"
                 << endl << "Why would you even wanna hold that many coins?! I can go as far as 1000, but that's about it!"
                 << endl << endl
                 << "Please Try Again" << endl
                 << "(Do not include commas or any special characters other than a period to declare cents)"
                 << endl << endl
                 << "Amount: $";
        }
        else{
            cout << endl << "You can only enter positive numbers. Try again."
                 << endl << endl
                 << "Amount: $";
        }

        cin >> dollarAmount;
    }


    cout << "You entered: $" << dollarAmount << endl << endl;

    if(dollarAmount > 0){
    //    First convert the input amount into cents: $5.42 * 100
        int centAmount = dollarAmount * 100;
    //    First the larger coin, quarters
    //    542 / 25 ----> 21 quarters
    //    542 % 25 ----> 17 cents of change
        int quarterCount = centAmount / 25;
        centAmount = centAmount % 25;
    //    Next comes dime.
    //    17 / 10 ---- > 1 dime
    //    17 % 10 -----> 7 cents of change
        int dimeCount = centAmount / 10;
        centAmount = centAmount % 10;
    //    After that comes nickels
    //    7 / 5 -----> 1
    //    7 % 5 -------> 2
        int nickelCount = centAmount / 5;
        centAmount = centAmount % 5;
    //    Finally, pennies
    //     2 pennies are what’s left.

    //    The next step is displaying the original dollar amount along with the coin designations and
    //    their number.
        if(quarterCount > 0)
            cout << "Quarter count = " << quarterCount << endl;
        if(dimeCount > 0)
            cout << "Dime count = " << dimeCount << endl;
        if(nickelCount > 0)
            cout << "Nickel count = " << nickelCount << endl;
        if(centAmount > 0)
            cout << "Penny count = " << centAmount << endl;

        cout << endl
             << "Cool! Given your $" << dollarAmount << ", you have $"
             << quarterCount * quarterConstant << " worth of quarters, $"
             << dimeCount * dimeConstant << " worth of dimes, $"
             << nickelCount * nickelConstant << " worth of nickels, and $"
             << centAmount * pennyConstant << " worth of pennies!"
             << endl << endl
             << "**Cha-ching**!!!!"
             << endl << endl;
    }
    else{ //user input 0
        cout << "Very funny. Here are your coins, oh, wait, there are none!" << endl;
    }

    askForNewConversion();
    return;
}

/*
This function handles the scenario when user wants to convert from coins to a total amount.
*/
void coinToAmount(){
    cout << "================================================================================"
         << endl << endl
         << "COINS --> AMOUNT"
         << endl << endl
         << "Please enter the quantity of each coin denomination to calculate the dollar amount."
         << endl << endl
         << "Quantity of Quarters: ";
    int quarterCount = collectCoinCount();

    cout << "Quantity of Dimes: ";
    int dimeCount = collectCoinCount();

    cout << "Quantity of Nickels: ";
    int nickelCount = collectCoinCount();

    cout << "Quantity of Pennies: ";
    int pennyCount = collectCoinCount();

    int centAmount = (quarterCount * 25) + (dimeCount * 10) + (nickelCount * 5) + pennyCount;
//    For example 135 cents: 135 / 100 = 1  (dollars) and 135 % 100 = 35 (cents).
    int dollars = centAmount / 100;
    int cents = centAmount % 100;

    cout << endl
         << "Your total is $" << dollars << " and " << cents << " cents."
         << endl << endl;

    askForNewConversion();

    return;
}

/*
This function verifies if the user would like to do a new conversion.
*/
void askForNewConversion(){

    cout << "================================================================================"
         << endl << endl
         << "Would you like to do another conversion?" << endl
         << "Please select the number corresponding to the service you are looking for."
         << endl << endl
         << "1 - Yes" << endl
         << "2 - No"
         << endl << endl;

    int choice;
    cin >> choice;

    while (cin.fail() || choice < 0 || choice > 2){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "That is not a valid entry."
             << endl << endl
             << "Would you like to do another conversion?" << endl
             << "Please select the number corresponding to the service you are looking for."
             << endl << endl
             << "1 - Yes" << endl
             << "2 - No"
             << endl << endl;

        cin >> choice;
    }

    cout << "You chose: " << choice << endl << endl;

    switch (choice){
        case 1:
            promptForChoice();
            break;
        case 2:
            break;
        default:
            cout << "That is not a valid entry." << endl << endl;
            askForNewConversion();
    }

    return;
}

/*
//This function ensures that the user has input a non-negative int.
*/
int collectCoinCount() {
    int coinCount;
    cin >> coinCount;
    while (cin.fail() || coinCount < 0 || coinCount > 1000){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input


        if(coinCount > 1000){
            cout << endl << "That's a lot of coins!"
                 << endl << "I am doing my best here okay? Just work with me please."
                 << endl << "I can process up to 1000 at a time. Please enter the number of coins again." << endl << endl;
        }
        else{
            cout << endl << "You can only enter positive numbers. Try again." << endl << endl;
        }


        cin >> coinCount;
    }
    return coinCount;
}
