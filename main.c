#include <stdio.h>
#include "myBank.h"

int main(){
    
    double amount=0;
    int account=0;
    int x =0;
    int y =0;
    printf("Wellcome to myBank,we support several action: \n 1)Open account nummber press O.\n 2)Check your account balance press B. \n 3)Deposit money to your account press D. \n 4)Withdrawl money from account press W. \n 5)Close an account press C. \n 6)Raise interest press I. \n 7) Print all te open account press P. \n 8)Close all count and leave program press E. \n");
    char ch='M';
    while(ch!='E'){
        printf("Choose an action: O,W,B,D,C,I,P,E \n");
        printf("Transaction Type: \n");
        scanf(" %c" , &ch);
        switch (ch)
        {
        case 'O': printf("Initial deposit:");
            if((scanf(" %lf",&amount))!=1 || amount<0){
                printf("ERR:Change amount please.\n");
            }
            else open(amount);
            break;
        
        case 'B':printf("Please enter your account number: \n");
            if((scanf(" %d",&account))!= 1 ||account>950 || account < 901){
                printf("ERR:Wrong account number.\n");
            }
            else balance(account);
            break;
        
        case 'D':printf("Plese enter your account numebr:\n");
            x =scanf(" %d" , &account);
            printf("Please enter the amount you want to deposit:\n");
            y = scanf(" %lf",&amount); 
            if(x!=1 || y!=1 ||amount<0 || account>950|| account<901){
                printf("ERR:Wrong information.\n");
            }
            else deposit(account,amount);
            break;

        case 'W':printf("Please enter your account number:\n");
            x = scanf(" %d", &account);
            printf("Please enter the amount you want to withdrawl:\n");
            y = scanf(" %lf", &amount);
             if(x!=1 || y!= 1 ||amount<0 || account>950|| account<901){
                printf("ERR:Wrong information.\n");
            }
            else withdrawal(account,amount);
            break;
        
        case 'C':printf("which account do you want to close?\n");
            if((scanf(" %d",&account))!=1 || account>950 || account<901){
                printf("Wrong account number.\n");
            }
            else close(account);
            break;

        case 'I':printf("What the interest percent u want to up?\n");
            if((scanf(" %lf",&amount))!=1 || amount<0){
                printf("ERR:Change interest rate.\n");
            }
            else interest(amount);
            break;

        case 'P':print();
            break;

        case 'E': deleteAll();
            break;     
        
        default:printf("Wrong input,there is not Transaction like this.\n");
            break;
        }
    }
 
   
     
    return 0;
}