#include <stdio.h>
#include "myBank.h"

double Bank[RAWS][COL]={0};

void open(double amount){
    amount= changeNumber(amount);
    int runner;
    for(runner=0;runner<50;runner++){
        if(Bank[1][runner]==0){
            Bank[0][runner]=amount;
            Bank[1][runner] =1;
            printf("Your new number account is:%d \n",runner+901);
            return;
        }
    }
    printf("The bank is full at the moment. \n");
    return;
}
void balance(int account){
    if(Bank[1][account-901] == 1){
        printf("Your balance is:%lf \n",Bank[0][account-901]);
        return;
    }
    printf("This account number is closed. \n");
    return;
}
void deposit(int account,double amount){
    amount= changeNumber(amount);
    if(Bank[1][account-901]==1){
        Bank[0][account-901]+=amount;
        printf("Your new balance is: %lf \n",Bank[0][account-901]);
    }
    else printf("the account number is closed. \n");
    
}
void withdrawal(int account,double amount){
    amount= changeNumber(amount);
    if(Bank[1][account-901] == 1){
        if(Bank[0][account-901] >=amount){
            Bank[0][account-901]-=amount;
            printf("Your new balance is: %lf \n",Bank[0][account-901]);
        }
        else {
            printf("You dont have enugh money. \n");
        
        }
    }
    else printf("the account number is closed. \n");
    
}
void close(int account){
    if(Bank[1][account-901]==1){
        Bank[0][account-901]=0;
        Bank[1][account-901]=0;
        printf("Account has been closed.\n");
    }
    else printf("The account is allready closed.\n");
}
void interest(double percent){
    int runner;
    for(runner=0;runner<50;runner++){
        if(Bank[1][runner]==1){
            double inter = changeNumber((percent*Bank[0][runner])/100.0);
            Bank[0][runner]+=inter;
        }
    }

}
void print(){           
    int runner;
    for(runner=0;runner<50;runner++){
        if(Bank[1][runner]==1){
            printf(" number account is: %d   Your balanca is:%lf \n",runner+901,Bank[0][runner]);
        }
    }
}
void deleteAll(){
    int runner;
    for(runner=0;runner<50;runner++){
        Bank[1][runner]=0;
        Bank[0][runner]=0;
    }    
    printf("All the accounts have been closed.");
}
double changeNumber(double x){
    x=x*100;
    x=(int)x;
    x=x/100;
    return x;
}