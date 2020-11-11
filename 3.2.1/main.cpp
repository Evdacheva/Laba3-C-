/*��������� ��� ������� 3 ������������ ������ � 2, ������� ��� ��� ������ �� ���������� �������, � ������������ � ���������. 
��������� � ��������� ����������� ����� ������������ �������. 
� ������� ������� ������������������ ���������� ����������, 
����������� � RTTI �� ������� 3-4 �������� �������, �� �������� � �������� 1. */
#include <iostream>
#include "Magazin.h"
#include "ITaxPayment.h"
#include "Pharmacy.h"
#include "Shop.h"
using namespace std;
//������������ ���������� ����������, ������������ � RTTI
//2 ������ � 1 �����, ������������������ ����������� payTax()
// � ��� ����� ������������������ ����� ���������)))))))
void main() {
	setlocale(0, "RUSSIAN");
	Shop * shop[3];
	shop[0] = new Magazin("ATB", "Semashka Avenue 41b", 2003, Shop::getTypeWork(1));
	shop[1] = new Pharmacy("Narodnaya", "Snegnoe", 2015, Shop::getTypeWork(1));
	shop[2] = new Pharmacy("Arnica", "Torez", 2007, Shop::getTypeWork(0));
	//�������������� ������������ payTax()
	shop[0]->sale(100);
	shop[1]->sale(100);
	shop[2]->sale(100);
	shop[0]->printProfit();
	shop[1]->printProfit();
	shop[2]->printProfit();
	//������������ RTTI � ������������, � ���������� ����������
	for (int i = 0; i < 3; i++) {
		ITaxPayment* tax = dynamic_cast<ITaxPayment*>(shop[i]);
		cout <<"����� �� �������: "<< tax->payTax() << endl;
	}

	system("pause");}