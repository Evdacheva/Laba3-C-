#include "Magazin.h"



Magazin::Magazin(char* sName, char* sAddress, int sYear, TypeWork t){
	shop.name = sName;
	shop.address = sAddress;
	shop.year = sYear;
	shop.NShop = number++;
	shop.profit = 0;
	establihment = {};
	typeWork = t;
	if (typeWork == 1) {
		time_of_work[0] = 8;
		time_of_work[1] = 21;
	}
	action_clients = 0;
}
int Magazin::payTax() {
	return int(0.25*establihment.back()) + nalog;
}
void Magazin::sale(int sum) {
	establihment.push_back(sum);
	shop.profit += sum - payTax();
}


Magazin::~Magazin()
{
}
