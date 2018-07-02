#include <iostream>
#include "BStablo.h"
#include "Node.h"
#include "Heap.h"

using namespace std;


int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}



int main(int argc, char *argv[])
{
	BStablo stablo;

	stablo.insert(2);
	stablo.insert(3);
	stablo.insert(11);
	stablo.insert(4);
	stablo.insert(12);
	stablo.insert(1);
	stablo.insert(15);

	/*
	stablo.insert(6);
	stablo.insert(4);
	stablo.insert(3);
	*/
	int s = 0;
	int lev = 0, des = 0;
	cout << "Broj cvorova sa 2 predaka: " << stablo.broji(s, lev, des) << endl;
	Node * cvor = stablo.findMaximal();
	cout << "Visina stabla: " << stablo.Visina() << endl;
	cout << "Moment stabla: " << stablo.moment() << endl;
	cout << "Tezina stabla: " << stablo.tezina() << endl;
	cout << "====================================" << endl;
	BStablo* novo = stablo.mirror();
	//	stablo.ispisi_listove();
	cout << endl << "Broj listova koji su desna deca je: " << stablo.desna_deca() << endl;
	cout << endl << "Broj listova koji su leva deca je: " << stablo.leva_deca() << endl;
	cout << "====================================" << endl;
	cout << "Maksimalni je: " << stablo.MaxValue() << endl;
	cout << stablo.isBalanced() << endl;
	//stablo.brisiListove();
	//cout << "Tezina stabla: " << stablo.tezina() << endl;
	//stablo.LevelOrder();
	Node **poc;
	poc = new Node*;
	//stablo.leftPathmax(poc);
	poc = stablo.nadji();
	cout << "Ovo: " << stablo.Sum(1, 4) << endl;
	return 0;
}