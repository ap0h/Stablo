#pragma once
#include "Node.h"
static int counter;
class BStablo
{
private:
	Node * root;
	long broj_elemenata;
public:
	BStablo();
	~BStablo();
	void preorder();
	void postorder();
	void LevelOrder(); //stampa cvorove po nivoima
	void insert(int el);
	int count(Node*p); //vraca broj cvorova stabla ciji je koren p
	int count();
	int broji(int &suma, int &sl, int &sr); //vraca broj cvorova koji imaju dva cvora u levom i desnom podstablu ili samo u nekom od ta dva
	Node * findMaximal(); //vraca cvor koj ima najvecu razliku izmedju levo i desno podstablo
	int Visina();//vraca visinu stabla
	int moment(); // tezina svih cvorova
	int tezina(); // takodje vraca tezinu svih, kod u jednoj liniji xD
	void brisiListove();
	BStablo * mirror(); //kopiju stabla koje je mirror this-a
	int desna_deca(); // listove koji su desna deca
	int leva_deca(); // listove koji su leva deca
	void ispisi_listove();
	int MaxValue(); //maksimalnu tezinu cvora
	bool isBalanced(); //vraca true ako je stablo balansirano, stablo je balansirano ako je razlika u visini izmedju bilo koja dva cvora najvise 1
	int leftPathmax(Node **start); //najduzi levi put vraca duzinu parametar cvor od koga pocinje najduzi put ako ne postoji vraca KOREN
	Node ** nadji();  //trazi prvi cvor cija je vrednost veca od srednje vrednosti svoje dece, cim nadje dalje ne trazi, preorder koriscen
	int Sum(int min, int max); //vraca sumu cvorova koji su u opsegu (min,max)
	int deleteRightLeaves(); //brise listove koji su u desnom podstablu 
	int brisi_desnu_decu_listovi(); // a ova brise listove koji su desna deca svog roditelja u celom podstablu
	int countGreater(int value);//broji cvorove cija je vrednost veca od zadate
	Node **findCommonAncestor(int a, int b); //nalazi zajednickog predaka od cvorove koji imaju vrednost a i b
private:
	//pomocne funkcije za ove iznad, posto su rekurzivne, ove iznad pozivaju njih
	int findCommonAncestor(int a, int b, Node**p, Node *root);
	int countGreater(Node *p, int value);
	void brisi_desna_deca(Node*root, int &s);
	Node * nadji(Node *root);
	void Sum(Node *root, int min, int max, int &suma, int dubina);
	void preorder(Node *p);
	void postorder(Node *p);
	void deleteTree(Node* p);
	int dif(Node *p,int &razlika);
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
