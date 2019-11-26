#include <stdio.h>
#include "myBank.h"
double Matrix[RAWS][COL]={0};

void open(double amount){
    amount=amount*100;
    amount=(int)amount;
    amount=amount/100;
    int runner;
    for(runner=0;runner<50;runner++){
        if(Matrix[1][runner]==0){
            Matrix[0][runner]=amount;
            Matrix[1][runner] =1;
            printf("Your new number account is:%d \n",runner+901);
            return;
        }
    }
    printf("The bank is full at the moment. \n");
    return;
}
void balance(int account){
    if(Matrix[1][account-901] == 1){
        printf("Your balance is:%lf \n",Matrix[0][account-901]);
        return;
    }
    printf("This account number is closed. \n");
    return;
}
void deposit(int account,double amount){
    amount=amount*100;
    amount=(int)amount;
    amount=amount/100;
    if(Matrix[1][account-901]==1){
        Matrix[0][account-901]+=amount;
        printf("Your new balance is: %lf \n",Matrix[0][account-901]);
    }
    else printf("the account number is closed. \n");
    
}
void withdrawal(int account,double amount){
    amount=amount*100;
    amount=(int)amount;
    amount=amount/100;
    if(Matrix[1][account-901] == 1){
        if(Matrix[0][account-901] >=amount){
            Matrix[0][account-901]-=amount;
            printf("Your new balance is: %lf \n",Matrix[0][account-901]);
        }
        else {
            printf("You dont have enugh money. \n");
        
        }
    }
    else printf("the account number is closed. \n");
    
}
void close(int account){
    if(Matrix[1][account-901]==1){
        Matrix[0][account-901]=0;
        Matrix[1][account-901]=0;
        printf("Account has been closed.\n");
    }
    else printf("The account is allready closed.\n");
}
void interest(double percent){
    int runner;
    for(runner=0;runner<50;runner++){
        if(Matrix[1][runner]==1){
            Matrix[0][runner]+=(percent*Matrix[0][runner])/100.0;
        }
    }

}
void print(){           
    int runner;
    for(runner=0;runner<50;runner++){
        if(Matrix[1][runner]==1){
            printf(" number account is: %d   Your balanca is:%lf \n",runner+901,Matrix[0][runner]);
        }
    }
}
void deleteAll(){
    int runner;
    for(runner=0;runner<50;runner++){
        Matrix[1][runner]=0;
        Matrix[0][runner]=0;
    }    
    
}