#ifndef _MYBANK_H_
#define _MYBANK_H_

#define RAWS 2
#define COL 50

extern double Bank[RAWS][COL];

void open(double);
void balance(int);
void deposit(int,double);
void withdrawal(int,double);
void close(int);
void interest(double);
void print();
void deleteAll();
double changeNumber(double);

#endif