//
// Created by user on 10/6/2016.
//

#include "receipt.h"

receipt::receipt(unsigned int drinkId, double amount, int quantity, double currprice)
{
    Id=drinkId;
    totalmoney=amount;
    quant=quantity;
    price=currprice;
}

bool receipt::empty() const
{
  bool value=false;
  if (quant==0)
        value=true;
  return value;
}

double receipt::getchange() const
{
    double change;
    if(success())
    change=totalmoney-price;
    else
    change=0.0;
    return change;
}

bool receipt::insufficient() const
{
    bool value=false;
    if(price>totalmoney)
        value=true;
    return value;
}

bool receipt::success() const
{
    bool value=false;
    if(price<=totalmoney)
        value=true;
    return value;
}