// CS313_Zexian_Lin_hw2_OrderSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "OrderSystem.h"

using namespace std;
int main()
{
    srand(time(0));
    OrderSystem* store = new OrderSystem();
    int simulation_time = 10000;
    store->processing(simulation_time);
}

