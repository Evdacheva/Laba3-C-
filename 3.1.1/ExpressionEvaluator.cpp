#include "ExpressionEvaluator.h"
#include <iostream>
#include <ios>
#include <fstream>
using namespace std;

int ExpressionEvaluator::number = 0;
ExpressionEvaluator::ExpressionEvaluator() {
	nOperands = 20;
	operands = new double [nOperands] {0.0};
}
ExpressionEvaluator::ExpressionEvaluator(int n) {
	nOperands = n;
	operands = new double [n] {0.0};
}
//Присвоить значение value одному операнду на позиции pos:
void ExpressionEvaluator::setOperand(int pos, double value) {
	if (pos > nOperands) {						
		double* temp = new double[pos] {0.0};	
		for (int i = 0; i < nOperands; i++)		
			temp[i] = operands[i];				
		temp[pos - 1] = value;					
		nOperands = pos;						
		delete[]operands;						
		operands = new double[nOperands];		
		for (int i = 0; i < nOperands; i++)		
			operands[i] = temp[i];
		delete[]temp;							
	}
	else {										
		double* temp = new double[pos];			
		operands[pos - 1] = value;				
		int count = 0 , n = nOperands;			
		for (int i = 0; i < n; i++) {			
			count++;
			if (operands[i] == 0)
				continue;
			nOperands = count;					
		}
		for (int i = 0; i < nOperands; i++)		
			temp[i] = operands[i];
		delete[]operands;						
		operands = new double[nOperands];		
		for (int i = 0; i < nOperands; i++)		
			operands[i] = temp[i];
		//delete[]temp;							//освобождаем память
	}
}

void ExpressionEvaluator::setOperands(double ops[], int N) {
	delete[]operands;
	nOperands = N;
	operands = new double[N];
	for (int i = 0; i < N; i++)
		operands[i] = ops[i];
}
//Реализация интерфейса ILoggable:

void ExpressionEvaluator::logToScreen() {
	string filename = "log.txt"; 
	ifstream log(filename, ios_base::in);
	char *temp = new char[50];
	log.getline(temp,50);
	cout << temp;
}
//Добавление записи лога всего выражения в файл лога:
void ExpressionEvaluator::logToFile(string filename) {
	ofstream log(filename, ios_base::app || ios::ate);
	number++;
	/*
	for (int i = 0; i<nOperands; i++) {
		log << operands[i] << " ";
		if (i = nOperands-1) {
			log << endl;
		}
	}*/
	log.close();
}
ExpressionEvaluator::~ExpressionEvaluator() {
	delete []operands;
}
