For my Introduction to C Programming class, we were given a project to create a program that functions as a basic vending machine. The use of pass by reference and pass by value is what enabled the different functions to come together and work as a one program. This is mainly seen with the use of the pointer 'double *balance'. The program itself relied on user input/out and control structures such as loops and the switch statement to progress throughout the program. The gretting function is meant to greet the user. The order function will collect user input input to make an order. View hand will display the amount of money in the user's wallet. The transaction function handles deals with the transactions and is proofed in case a user has unsufficient funds. Pull money will add money to the user balance. Finally the display function will display the available beverage items. Overall, this design allows the program to remain organized. 

Instruction: 
1. gcc magicSodaMachine.c -o magic_soda_machine
2. ./magic_soda_machine

The program will greet you and explain the vending machine concept. You will start with a balance of $0. A menu will be displayed with options to order, view balance, display vending options, add money, and exit. Follow the on-screen instructions to interact with the vending machine.

1. Order from the Unlimited Vending Machine:
  Select 'O' or 'o' to view and order beverages.
  Follow the prompts to select a beverage and complete the transaction if you have enough balance.

2. View Your Current Balance:
  Select 'V' or 'v' to see how much money you currently have in your balance.

3. Display Vending Machine Options:
  Select 'D' or 'd' to display the available beverage options and their prices.

4. Grab Money from Unlimited Wallet:
  Select 'G' or 'g' to add money to your balance from an unlimited wallet.
  Choose the amount to add ($1, $5, or $10).

5. Exit the Program:
  Select 'E' or 'e' to exit the program.
  Your balance will be displayed before exiting.

