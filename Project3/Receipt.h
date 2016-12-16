//
// Created by user on 10/11/2016.
//

#ifndef PROJECT3_RECEIPT_H
#define PROJECT3_RECEIPT_H


class Receipt
{
public:
    Receipt(unsigned int drinkId, double amount, int quantity, double currprice);
    bool success() const;
    bool insufficient() const;
    bool empty() const;
    double getChange() const;
    int quant;
    double totalmoney;
    unsigned int Id;
    double price;

};


#endif //PROJECT3_RECEIPT_H
