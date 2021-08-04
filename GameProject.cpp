#include <iostream>
#include <string> // Needed to use strings like player name
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;

void rules()
{
    system("cls");
    cout << "\t\t======NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the bet money\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

int main(){
	string PlayerName;
	int balance;    // stores player's balance 
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // this function "Seed" or" generate" the random generator
    cout << "\n\n\n\t\t\t\t========WELCOME TO NUMBER GUESSING GAME=======\n";
    cout << "\n\n\tWhat's your Name : ";
    cin>>PlayerName;
    cout << "\n\n\tEnter the starting balance to play game : $";
    cin >> balance;
    
    do{
    	rules();
    	cout<<"\n\n\tYour current balance is $ " << balance << "\n";
    	// next do loop to get bet amount
    	 do
        {
            cout << "\tHey, " <<PlayerName<<" enter the bet amount : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "\tBetting balance can't be more than current balance!\n"
                       <<"\n\tRe-enter balance\n ";
        }while(bettingAmount > balance);
        
        // this loop to get random number from player
		do
        {
            cout << "\tGuess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        
        // now rand() function generate random number and assign to variable dice
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            cout << "\n\n\tYou are lucky!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "\tOops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<PlayerName<<", You have balance of $ " << balance << "\n";
        
        if(balance == 0)
        {
            cout << "\tYou have no money to play again ";
            break;
        }
        cout << "\n\n\tDo you want to play again (y/n) ? ";
        cin >> choice;
	}while(choice =='Y'|| choice=='y');
	
	cout << "\n\n";
    cout << "\n\nThanks for playing the game.\nYour balance is $ " << balance << "\n\n";
    return 0;
}
