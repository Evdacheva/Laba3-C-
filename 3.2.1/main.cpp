/*Дополнить код задания 3 лабораторной работы № 2, написав еще два класса по предметной области, в соответствии с вариантом. 
Продумать и корректно реализовать схему наследования классов. 
В главной функции продемонстрировать применение интерфейса, 
полиморфизм и RTTI на примере 3-4 объектов классов, по аналогии с заданием 1. */
#include <iostream>
#include "Magazin.h"
#include "ITaxPayment.h"
#include "Pharmacy.h"
#include "Shop.h"
using namespace std;
//демонстрация применения интерфейса, полиморфизма и RTTI
//2 аптеки и 1 бутик, продемонстрировать полиморфизм payTax()
// и все можно продемонстрировать одним действием)))))))
void main() {
	setlocale(0, "RUSSIAN");
	Shop * shop[3];
	shop[0] = new Magazin("ATB", "Semashka Avenue 41b", 2003, Shop::getTypeWork(1));
	shop[1] = new Pharmacy("Narodnaya", "Snegnoe", 2015, Shop::getTypeWork(1));
	shop[2] = new Pharmacy("Arnica", "Torez", 2007, Shop::getTypeWork(0));
	//демонстрирация полиморфизма payTax()
	shop[0]->sale(100);
	shop[1]->sale(100);
	shop[2]->sale(100);
	shop[0]->printProfit();
	shop[1]->printProfit();
	shop[2]->printProfit();
	//демонстрация RTTI и полиморфизма, и применения интерфейса
	for (int i = 0; i < 3; i++) {
		ITaxPayment* tax = dynamic_cast<ITaxPayment*>(shop[i]);
		cout <<"Налог на прибыль: "<< tax->payTax() << endl;
	}

	system("pause");}