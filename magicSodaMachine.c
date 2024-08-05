
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

void greeting();                                 // welcomes the user
void order(double *balance);                     // collects the users order
void viewHand(double *balance);                  // displays user's balance
void transaction(double *balance, double price); // handles the transaction
void pullMoney(double *balance);                 // adds money to the user's hand
void displayVendingOptions();                    // displays the beverage items

int main()
{
        greeting(); // function to greet the user
        double balance = 0; // starting the balance from zero since the user hasn't taken any from the unlimited wallet yet 

        while (1)
        {
            char option; // calls function to be used from user input 
            
            printf("*****************************************************\n");
            printf("Please select one of the following options.\n");
            printf("O: Order from the unlimited vending machine.\n");
            printf("V: View what you have in your hand currently.\n");
            printf("D: Display what the unlimited vending machine contains.\n");
            printf("G: Grab money out of unlimited wallet\n");
            printf("E: Exit\n");
            printf("*****************************************************\n");
            printf("Please select what you would like to do.\n");
            printf("Option Selected: ");
            scanf(" %c", &option); // collects input from the user to be used for the menu

            // lines 26 - 37 essentially displays the face of the menu driven function
            // lines 39 - 82 is essentially what makes the menu work 
                switch (option)
                {
                    case 'V': 
                    case 'v':
                        viewHand(&balance); // calls the function that allows the user to see how much money they have in their hand 
                        continue; // returns to the menu when the function is completed

                    case 'D':
                    case 'd':
                        printf("You selected the view vending machine option.\n");
                        printf("Here are the options!\n");
                        displayVendingOptions(); // calls the function that displays the vending option
                        continue; // returns to the menu when the function is completed

                    case 'O':
                    case 'o':
                        printf("You have selected to order something from the unlimited vending machine.\n"); 
                        printf("*****************************************************\n");
                        printf("Here are the options!\n"); 
                        order(&balance); // calls the function that allows the user to order something from the vending machine 
                        continue; // returns to the menu when the function is completed

                    case 'E':
                    case 'e':
                        printf("*****************************************************\n");
                        printf("Thank you for visiting the unlimited vending machine!\n");
                        printf("You have $%.2lf in your hand. Make sure to put that back into your unlimited wallet.\n", balance); /* displays the current amount of money that the user has in their hand */ 
                        printf("Have a great day!\n"); 
                        exit(0); //exits the entire program

                    case 'G': 
                    case 'g': 
                        pullMoney(&balance); // calls the function that allows the user to grab money from the unlimited wallet 
                        continue; // returns to the menu when the function is completed
                    
                    default:
                        printf("\nInvalid input. Please enter a valid input.\n"); 
                        continue; // returns to the menu when the function is completed
                }
        }

        return 0;
}

void greeting() // greets the user
{       
        printf("Welcome to the Unlimited Vending Machine\n");
        printf("We have an unlimted variety of drinks.\n");
        printf("With your unliminted wallet, you will never run out of cash!\n");
        printf("What would you like to order today?\n");
}

void displayVendingOptions() // displays the drink options for the user to choose from as well as their prices
{
        printf("*****************************************************\n");
        printf("1. Sprite        $2.50\n");
        printf("2. Coca-Cola     $2.50\n");
        printf("3. Water         $2.00\n");
        printf("4. Gatorade      $3.00\n");
        printf("5. Diet Cola     $2.55\n");
        printf("6. Fanta         $2.55\n");
        printf("7. Root Beer     $1.50\n");
        printf("8. Dr. Pepper    $1.55\n");
        printf("*****************************************************\n");
}

void viewHand(double *balance)
{  
        printf("You selected to see how much cash you have in your hand currently.\n");
        printf("*****************************************************\n");
        printf("You have $%.2lf in your hand currently.\n", *balance); // displays the current amount of money the user has in their hand 
        printf("*****************************************************\n");
} 

void pullMoney(double *balance)
{     
    int num; // decalred integer to be used for user input 
    while(1) // while loop is used just in case the user enters an incorrect input
    { 
        printf("*****************************************************\n"); 
        printf("How much would you like to pull from the unlimited wallet?\n"); 
        printf("1: $1.00\n"); 
        printf("2: $5.00\n"); 
        printf("3: $10.00\n"); 
        printf("Option Selected: "); 
        scanf("%d", &num); // takes input from the user 

           switch (num)
            {
                case 1:
                    printf("$1.00 has been added to your hand successfully!\n"); 
                    printf("*****************************************************\n");
                    *balance += 1.00; // adds 1 dollar to the user's balance 
                    break; // breaks out of the while loop 

                case 2: 
                    printf("$5.00 has been added to your hand successfully!\n"); 
                    printf("*****************************************************\n");
                    *balance += 5.00; // adds 5 dollars to the user's balance 
                    break; // breaks out of the while loop

                case 3: 
                    printf("$10.00 has been added to your hand successfully!\n"); 
                    printf("*****************************************************\n");
                    *balance += 10.00; // adds 10 dollars to the user's balance 
                    break; // breaks out of the while loop
                
                default:
                    printf("Please insert a valid option!\n"); 
                    continue; // returns to be beginning of the loop if user makes an invalid input
            }       
    }



}

void transaction(double *balance, double price)
{
        printf("Beginning Transaction Process.\n");  
        while (price > *balance) // loops the pull money function until the value of balance is greater than the drink price 
        {
            printf("You do not have enough in your account.\n"); 
            printf("Please pull more money from the unlimited wallet.\n"); 
            pullMoney(balance); // calls the function to pull money
        }
        printf("You have $%.2lf in your hand before transaction.\n", *balance); //displays the amount of moeny the user has
        printf("Putting $%.2lf into the vending machine.\n", price); // displays the amount of money the user is putting into the vending machine 
        printf("Transaction was sucessful!\n"); 
        printf("You now have $%.2lf in your hand.\n", *balance -= price); /* updates and shows the remaining balance (subtracts the value of price taken from the order function and subtracts it from the current value of balance) */ 
        printf("*****************************************************\n");

}

void order(double *balance)
{   
        double price; // declares double to be used for drink prices (will be used in the transaction function) 
        int selection; // declares integer to be used for user input 
        while (1)
        {
            displayVendingOptions(); // calls function to display the drink options and prices 
            printf("What would you like today?\n");
            printf("Option Selected: ");
            scanf("%d", &selection); // takes input from the user 

            switch (selection) // determines which case/drink to go to based on user input 
            {
                case 1:
                    price = 2.50; // the price of the Sprite 
                    printf("Sprite has been selected. Total cost is $2.50\n"); 
                    transaction(balance, price); // calls the function that makes transactions 
                    break;

                case 2:
                    price = 2.50; // the price of Coca-Cola 
                    printf("Coca-Cola has been selected. Total cost is $2.50\n"); 
                    transaction(balance, price); // calls the function that makes transactions 
                    break;

                case 3:
                    price = 2.00; // the price of water 
                    printf("Water has been selected. Total cost is $2.00\n"); 
                    transaction(balance, price); // calls the function that makes transactions 
                    break;

                case 4:
                    price = 3.00; // the price of gatorade 
                    printf("Gatorade has been selected. Total cost is $3.00\n"); 
                    transaction(balance, price); // calls the function that makes transactions 
                    break;

                case 5:
                    price = 2.55; // the price of Diet Cola 
                    printf("Diet Cola has been selected. Total cost is $2.55\n"); 
                    transaction(balance, price); // calls the function that makes transactions 
                    break;

                case 6:
                    price = 2.55; // the price of Fanta 
                    printf("Fanta has been selected. Total cost is $2.55\n"); 
                    transaction(balance, price); // calls the function that makes transactions 
                    break;

                case 7:
                    price = 1.50; // the price of Root Beer 
                    printf("Root Beer has been selected. Total cost is $1.50\n"); 
                    transaction(balance, price); // calls the function that makes transactions 
                    break;

                case 8:
                    price = 1.55; // the price of Dr. Pepper 
                    printf("Dr. Pepper has been selected. Total cost is $1.55\n");
                    transaction(balance, price); // calls the function that makes transactions 
                    break;
                
                default:
                    printf("Invalid input. Please try again.\n"); 
                    continue; // returns to be beginning of the loop if user makes an invalid input
            }

        break; // breaks out of the loop when the function is switch function is completed

        }
}
