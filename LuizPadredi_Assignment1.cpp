/*
Author: Luiz Padredi
Date: 01/24/2023
Assignment 1: Coin Dispenser Machine
*/

/*
    a)  What are inputs to the program? Declare all the input values as appropriate types.
    b)  Create a prompting message to prompt the user to input their coin denominations.
    c)  What’s the expected output? Declare appropriate variables for to store the results.
    d)  What’s the algorithm to solve the problem? How do you relate the inputs to the output?
        • Make use of the arithmetic operators to solve this problem.
        • To separate the dollars and cents use the % and / operator respectively.
            For the above example 135 cents: 135 / 100 = 1  (dollars) and 135 % 100 = 35 (cents).
    e)  Display the outputs in an informative manner.
*/

#include <iostream>

using namespace std;

void promptForChoice();
void amountToCoin();
void coinToAmount();
void askForNewConversion();
int collectIntInput();
double collectDoubleInput();

int main()
{
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

    int choice = collectIntInput();
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
            cout << "That is not a valid entry." << endl << endl;
            promptForChoice();
    }

    return;
}

/*
This function handles the scenario when user wants to convert from an amount to a distribution of coins.
*/
void amountToCoin(){
    cout << "AMOUNT --> COINS"
         << endl << endl
         << "Please enter the dollar amount in the format '$X.XX' that you would like to receive in coins: ";

    double amount = collectDoubleInput();
    cout << "You entered: " << amount << endl << endl;


    /*
    In the first part, the machine asks for the dollar amount of coin change that the user
    would need. For an input of $5.42 the machine dispenses the following:
    - 21 quarters
    - 1 dime
    - 1 nickel
    - 2 pennies
    */
    //obs: so while it can dispense higher coins, do it

    //PART 1
    /*
    Write a program that would prompt the user to input some value in dollars and cents in
    the format of $x.xx and figures out the equivalent number of coins.

    First convert the input amount into cents: $x.xx * 100

    Then decide on the coin designations by following the algorithm below:

    $5.42 is equivalent to 542 cents.

    First the larger coin, quarters
    542 / 25 ----> 21 quarters
    542 % 25 ----> 17 cents of change

    Next comes dime.
    17 / 10 ---- > 1 dime
    17 % 10 -----> 7 cents of change

    After that comes nickels
    7 / 5 -----> 1
    7 % 5 -------> 2
    Finally, pennies
     2 pennies are what’s left.

    The next step is displaying the original dollar amount along with the coin designations and
    their number.
    */

    askForNewConversion();
    //would you like to do a new conversion? -- Y or N -- if Y, promptForChoice
    return;
}

/*
This function handles the scenario when user wants to convert from coins to a total amount.
*/
void coinToAmount(){
    cout << "COINS --> AMOUNT" << endl << endl;

    //PART 2
    /*
    Your coin dispenser should also work the other way around, by receiving coins it would
    determine  the  dollar  value.  Write  another  program  that  allows  the  user  to  enter  how
    many  quarters,  dimes,  nickels,  and  pennies  they  have  and  then  outputs  the  monetary
    value of the coins in dollars and cents.

    For example, if the user enters 4 for the number of quarters, 3 for the number of dimes,
    and 1 for the number of nickels, then the program should output that the coins are worth
    $1 dollar and 35 cents.
    (Sum all, then deal with remaining cents after)
    */

    askForNewConversion();
    //would you like to do a new conversion? -- Y or N -- if Y, promptForChoice
    return;
}

//FIXME -- Fix case when user inputs more than one char. -- create function that checks type of input and if not an int it assumes 0.
/*
This function verifies if the user would like to do a new conversion.
*/
void askForNewConversion(){

    cout << "Would you like to do another conversion?" << endl
         << "Please select the number corresponding to the service you are looking for."
         << endl << endl
         << "1 - Yes" << endl
         << "2 - No"
         << endl << endl;

    int choice = collectIntInput();
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
This function ensures that the user has input an int.
*/
int collectIntInput() {
    int choice;
    cin >> choice;
    while (cin.fail() || choice < 0){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << endl << "You can only enter positive numbers. Try again." << endl;
        cin >> choice;
    }
    return choice;
}

double collectDoubleInput() {
    double amount;
    cin >> amount;
    while (cin.fail() || amount < 0){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << endl << "You can only enter positive numbers. Try again." << endl;
        cin >> amount;
    }
    return amount;
}
