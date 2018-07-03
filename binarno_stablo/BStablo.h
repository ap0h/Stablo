#pragma once
#include "Node.h"
static int counter;
class BStablo
{
	public:
	Node * root;
	long broj_elemenata;
public:
	BStablo();
	~BStablo();
	void preorder();
	void postorder();
	void LevelOrder(); //stampa cvorove po nivoima
	void insert(int el);
	int count(Node*p); //vraca broj cvorova
	int count();
	int broji(int &suma, int &sl, int &sr); //vraca broj cvorova koji imaju dva cvora u levom i desnom podstablu ili samo u nekom od ta dva
	Node * findMaximal(); //vraca cvor koj ima najvecu razliku izmedju levo i desno podstablo
	int Visina();
	int moment(); // tezina svih cvorova
	int tezina();
	void brisiListove();
	BStablo * mirror(); //kopiju stabla koje je mirror this-a
	int desna_deca(); // listove koji su desna deca
	int leva_deca(); // listove koji su leva deca
	void ispisi_listove();
	int MaxValue(); //maksimalnu tezinu cvora
	bool isBalanced(); //vraca true ako je stablo balansirano
	int leftPathmax(Node **start); //najduzi levi put vraca duzinu parametar cvor od koga pocinje najduzi put ako ne postoji vraca KOREN
	Node ** nadji();
	int Sum(int min, int max);
	int deleteRightLeaves();
	int brisi_desnu_decu_listovi();
private:
	void brisi_desna_deca(Node*root, int &s);
	Node * nadji(Node *root);
	void Sum(Node *root, int min, int max, int &suma, int dubina);
	void preorder(Node *p);
	void postorder(Node *p);
	void deleteTree(Node* p);
	int dif(Node *p, int &sl, int &sd, int &max, bool &t);
	int findMaximal(Node *p, int &max, Node &maxN, int &sumalevo, int &sumadesno);
	int broji(Node *p, int &suma, int &sl, int &sr);
	int Visina(Node *p);
	int moment(Node *p);
	int tezina(Node *p);
	Node * brisiListove(Node *p);
	Node * mirror(Node *p);
	void desna_deca(Node *p, int &s);
	void leva_deca(Node *root, int &s);
	void ispisi_listove(Node* koren);
	int max(Node *root);
	void printGivenLevel(Node* p, int level);
	int leftMax(Node *p, int &left, int &max, Node **maxNode);
	int delRightLeaves(Node *root, int &br_obrisanih);
};
