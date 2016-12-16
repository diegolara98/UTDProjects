//
// Created by user on 10/6/2016.
//

#ifndef PROJECT2_RECEIPT_H
#define PROJECT2_RECEIPT_H


class receipt
{
public:
    receipt(unsigned int drinkId, double amount, int quantity, double currprice);
    bool success() const;
    bool insufficient() const;
    bool empty() const;
    double getchange() const;
    int quant;
    double totalmoney;
    unsigned int Id;
    double price;
};


#endif //PROJECT2_RECEIPT_H
