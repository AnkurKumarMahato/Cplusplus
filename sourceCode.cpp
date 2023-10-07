#include<iostream>
using namespace std;

// costPerOrder(arg1,arg2) function returns the total cost for one order
// arg1 is the input id, for example, 1 is input id for noodles, 4 is for chicken roll
// arg2 is the input quantity, like 4 chicken rolls

int costPerOrder(int input, int quantity){
   int totalCost = 0; // this is the total cost for one order placed and not the entire transaction
    switch (input) // switch takes input id as parameter for comparsion and executes code as per id
    {
    case 1:
        totalCost += 40*quantity; // cost of ordering 'quantity' number of noodles, for example 3 noodles
                                  // then 'quantity' = 3
        break;
    case 2:
        totalCost += 70*quantity; //cost of ordering 'quantity' number of fried rice
        break;
    case 3:    
        totalCost += 120*quantity; //cost of ordering 'quantity' number of biryani
        break;
    case 4:
        totalCost += 60*quantity; //cost of ordering 'quantity' number of chicken roll
        break;
    case 5:
        totalCost += 20*quantity; //cost of ordering 'quantity' number of soft drink
        break;     
    default: cout<<"Invalid input!!!"; // If the user orders something which is not in the menu, then error msg
        break;
    }

   return totalCost;
}
// viewMenu() function returns an integer value for each time the user enters another order,
//suppose the user wants 4 noodles, 3 biryani, 6 chicken rolls then
// in first order, noodles are mentioned, once done then again the user is asked if any other orders are 
// to be placed, the user then inputs 'y' and places order for biryani and then again for chicken rolls

int viewMenu(){
    int input,quantity;
    cout<<"\t\t\t*************************MENU*************************\n\n";
    
    cout<<"1.) Noodles\t         Rs 40/-\n";
    cout<<"2.) Fried Rice\t         Rs 70/-\n";
    cout<<"3.) Biryani\t         Rs 120/-\n";
    cout<<"4.) Chicken Roll\t Rs 60/-\n";
    cout<<"5.) Soft Drink\t         Rs 20/-\n";
    cout<<"Please select what you want to order: ";
    cin>>input;
    cout<<"How many do you want to order of this type? ";
    cin>>quantity;
    return costPerOrder(input,quantity); 
    // costPerOrder(arg1,arg2) takes two parameters and returns the total cost for that order
    // when another order is placed, new cost is returned, hence the total is kept tracked properly
}


//starting point of the program
int main() {
    int bill = 0; // initializing the bill as zero for one transaction

    // Displaying the name of the place
    cout<<"\t\t\t*************WELCOME TO FOOD PALACE*************\n";
    cout<<"___________________________________________________________________________________________________\n\n\n";

    int invalidCount = 0;
// asking if the customer wants to place a order
// if he/she presses 'y' then another order is prompted until 'n' is pressed to break the infinite loop
// once the loop is breaks, the bill is generated and order placed message is displayed on the screen
    while(true){
        char ch;
        cout<<"\nDo you want to place an order ? Press ('Y' for yes /'N' for no): ";
        cin>>ch;
        if(ch == 'Y' || ch == 'y' ){
            bill += viewMenu(); 
            // bill stores the cost for entire transaction whereas viewMenu() returns value for one particular
            // order only
            // for example,
            // transaction = 3 chicken rolls, 2 soft drinks, 4 biryani
            // here one order is 3 chicken rolls
            // then another order is 2 soft drinks
            // then finally last order is 4 biryani, after this user presses 'n' and no more orders are asked
            // to keep the code clean and simple, we make a function call to view the menu whenever user wants
            // to place a new order and add it to the entire transaction
        }

        //viewMenu() returns the order cost for that current order
        else if(ch == 'N' || ch == 'n') break;
        // In case the user inputs invalid values for equal to or more than 3 times, then the program is 
        // terminated using the exit(1) function to break the infinte loop 
        else {
            cout<<"Invalid input!!\n";
            invalidCount++;
            if(invalidCount >= 3) {
                cout<<"Too many invalid inputs! Try later!";
                exit(1);
            }
        }
    }

    // once the infinite loop breaks when the user inputs 'n' for no further orders, then the orders are acknowledged
    // and the total bill is generated for the entire transaction for that user
    cout<<"\n\nYour order has been placed successfully!\n\n\n";
    cout<<"Your total bill is : Rs "<<bill<<"\n\n";
    char isReview;
    // asking for review a is a common way of improving the services, hence included
    cout<<"Would you like to give us a review? Press ('Y' for yes /'N' for no) ";
    cin>>isReview;
    string review = "";
    //if the user opts to give review, then his review is taken as an input and the same is acknowledged
    if(isReview == 'Y' || isReview == 'y'){
        string text;
        cout<<"Please give your valuable review :\n\n";
        cin>>text;
        review += text;
        cout<<"\n\nThank you for your review!! Cheers!\n\n\n";
    }
    //before ending the entire process, a thank you note is generated for the user before exit
    cout<<"___******************Thank you for visiting Food Palace!******************___";
    return 0;
}