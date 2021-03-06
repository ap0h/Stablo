#include "BStablo.h"

BStablo::BStablo()
{
	root = NULL;
	broj_elemenata = 0;
	counter = 0;
}
BStablo::~BStablo()
{
	deleteTree(root);
}

void BStablo::deleteTree(Node * p)
{
	if (p != NULL)
	{
		deleteTree(p->getleft());
		deleteTree(p->getright());
		delete p;
	}
}

void BStablo::insert(int el)
{
	Node * p = root, *prev = NULL;
	while (p != NULL)
	{
		prev = p;
		if (*p < el)
		{
			p = p->getright();
		}
		else
		{
			p = p->getleft();
		}
	}
	if (root == NULL)
		root = new Node(el);
	else if (*prev < el)
		prev->setright(new Node(el));
	else
		prev->setleft(new Node(el));
	broj_elemenata++;
}

int BStablo::count(Node *p)
{
	int count = 1;

	if (p->getleft() != NULL) {
		count += this->count(p->getleft());
	}
	if (p->getright() != NULL) {
		count += this->count(p->getright());
	}
	return count;

}


int BStablo::count()
{
	return count(root);
}

//Funkcija vraca broj cvorova koji u svom podstablu levom ili desnom ili u oba imaju tacno 2 cvora
///*Funkcija vraca broj cvorova koji u svom podstablu levom ili desnom ili u oba imaju tacno 2 cvora///
int BStablo::broji(int &suma, int &sl, int &sr)
{

	broji(root, suma, sl, sr);
	return suma;
}

int BStablo::broji(Node * p, int &suma, int &sl, int &sr)
{
	int slevo = 0, sdesno = 0; // ovo ce bude lokalna na nivou cvora
	if (p == NULL) return 0;  //ako je stablo prazno

	if (p->getleft() == NULL && p->getright() == NULL) return 1; //ako je cvor list

	slevo = broji(p->getleft(), suma, sl, sr); //rekurzivni poziv za levo podstablo i ovo slevo vidi samo tekuci cvor
	sdesno = broji(p->getright(), suma, sl, sr); // ove rekurzivne za levo i desno mi postavljaju za tekuci cvor levo  i desno sumu

	sl = slevo; //sumu tekuceg cvora za levo podstablo prenosim funkciji po referenci da bi tu vrednost videli svi cvorovi
	sr = sdesno;
	if (sl == 2 || sr == 2 || (sl + sr == 2)) suma++;

	return sl + sr + 1;
	//ovo mi vraca i onda to se prakticno za tekuci postavlja u lokalne slevo i sdesno, a preko referencu onda 
}	//upisujem u sl i sr lokalne vrednosti. Jer kad bi umesto slevo i sdesno imao samo sl i sr onda bi mi dok ide u dubinu

	//rekurzija menjala sl i sr i onda ne bi dobijao tacno

void BStablo::preorder()
{
	preorder(root);
}
void BStablo::postorder()
{
	postorder(root);
}
void BStablo::preorder(Node *p)
{
	if (p != NULL)
	{
		p->visit();
		preorder(p->getleft());
		preorder(p->getright());
	}
}

void BStablo::postorder(Node *p)
{
	if (p != NULL)
	{
		preorder(p->getleft());
		preorder(p->getright());
		p->visit();
	}
}

Node * BStablo::findMaximal()
{
	Node *cvor = new Node;
	int max, sl = 0, sd = 0;
	findMaximal(root, max, *cvor, sl, sd);
	return cvor;
}

int BStablo::Visina()
{
	int h = Visina(root);
	return h;
}


int BStablo::findMaximal(Node * p, int & max, Node & maxN, int &sl, int &sd)
{
	int slevo = 0, sdesno = 0; // ovo ce bude lokalna na nivou cvora
	if (p == NULL) return 0;  //ako je stablo prazno
	if (p->getleft() == NULL && p->getright() == NULL) return p->getKey(); //ako je cvor list

	slevo = findMaximal(p->getleft(), max, maxN, sl, sd); //rekurzivni poziv za levo podstablo i ovo slevo vidi samo tekuci cvor
	sdesno = findMaximal(p->getright(), max, maxN, sl, sd); // ove rekurzivne za levo i desno mi postavljaju za tekuci cvor levo  i desno sumu

	int dif = abs(slevo - sdesno);
	Node *maxc;
	maxc = p;
	if (dif > max)
	{
		max = dif;
		maxN = *maxc;
	}
	sl = slevo;
	sd = sdesno;

	return sl + sd + p->getKey();
}

int BStablo::Visina(Node * p)
{
	int levo = 0, desno = 0;
	if (p == NULL) return 0;
	if (p->getleft() == NULL && p->getright() == NULL)
	{
		return 1;
	}
	levo = Visina(p->getleft());
	desno = Visina(p->getright());

	if (levo > desno)
	{
		return levo + 1;
	}
	return desno + 1;
}


int BStablo::moment(Node * p)
{
	return	(p == NULL) ? 0 : moment(p->getleft()) + moment(p->getright()) + 1;
}


int BStablo::moment()
{
	return moment(root);
}
int BStablo::tezina(Node *p)
{
	return (p == NULL) ? 0 : tezina(p->getleft()) + tezina(p->getright()) + p->getKey();
}
int BStablo::tezina()
{
	return tezina(root);
}

Node * BStablo::brisiListove(Node *p)
{
	if (!p) return NULL;
	if (p->getleft() == NULL && p->getright() == NULL) { // ako je list
		delete p;
		broj_elemenata--;
		return NULL;
	}
	p->setleft(brisiListove(p->getleft()));
	p->setright(brisiListove(p->getright()));
	return p;
}

void BStablo::brisiListove()
{
	brisiListove(root);
}
BStablo * BStablo::mirror()
{

	BStablo *novo = new BStablo;
	Node *novi = new Node;
	novo->root = mirror(root);

	return novo;
}


Node * BStablo::mirror(Node * p)
{

	if (p == NULL) return NULL;

	Node *novi = new Node;

	novi->setKey(p->getKey());

	novi->setright(mirror(p->getleft()));
	novi->setleft(mirror(p->getright()));
	return novi;
}

void BStablo::ispisi_listove()
{
	ispisi_listove(root);
}

void BStablo::ispisi_listove(Node* koren)
{
	if (koren == NULL) return;

	if (koren->getleft() == NULL && koren->getright() == NULL)
		std::cout << koren->getKey() << " ";

	ispisi_listove(koren->getleft());
	ispisi_listove(koren->getright());
}
int BStablo::desna_deca()
{
	int suma = 0;
	desna_deca(root, suma);
	return suma;
}

void  BStablo::desna_deca(Node *root, int &s)
{
	int leva = 0, desna = 0;
	if (!root) return;

	desna_deca(root->getleft(), s);
	desna_deca(root->getright(), s);


	if (root->getright() != NULL) {
		if ((root->getright()->getleft() == NULL && root->getright()->getright() == NULL))
		{
			s++;
			std::cout << "List je br: " << root->getright()->getKey() << " ";
			return;
		}
	}

}

int BStablo::leva_deca()
{
	int suma = 0;
	leva_deca(root, suma);
	return suma;
}

void BStablo::leva_deca(Node* root, int &suma)
{
	int levo = 0;
	int desno = 0;
	if (!root) return;

	leva_deca(root->getleft(), suma);
	leva_deca(root->getright(), suma);


	if (root->getleft() != NULL)
	{
		if (root->getleft()->getleft() == NULL && root->getleft()->getright() == NULL)
		{
			std::cout << "List je br: " << root->getleft()->getKey() << " ";
			suma++;
			return;
		}
	}

}


int BStablo::MaxValue()
{

	return max(root);
}

int BStablo::max(Node *root)
{
	if (!root) return 0;


	int levo = max(root->getleft());
	int desno = max(root->getright());

	int maxs = root->getKey();
	if (root->getleft() == NULL && root->getright() == NULL)
	{
		return root->getKey();
	}


	if (levo > desno)
	{
		if (levo > maxs)
			maxs = levo;
	}
	else
		if (desno > maxs)
			maxs = desno;

	return maxs;
}
//svaki cvor mi treba zna razliku od njegovo levo idesno podstablu 

int BStablo::dif(Node * p,int & razlika)//cilj mi je da nadjem max razliku u broju cvorova od levo i desno podstablo
{	//za svaki cvor i ako je ona veca od 1 onda nije balanisarno ako u suprotnom jeste
	if (!p) return 0;
	
	if (!p->getleft() && !p->getright()) return 1;

	int levo = dif(p->getleft(), razlika);
	int desno = dif(p->getright(), razlika);

	int razl = abs(levo - desno);
	if (razl > razlika) razlika = razl;
	return levo + desno + 1;
}

bool BStablo::isBalanced()
{
	int razlika = 0;
	int s = dif(root, razlika); // funkcija vraca ukupan broj cvorova, a razlika predstavlja max razliku 
	return (razlika > 1) ? false : true;
}

void BStablo::LevelOrder()
{
	int h = Visina();
	for (int i = 1; i <= h; i++)
		printGivenLevel(root, i);
}

void BStablo::printGivenLevel(Node *p, int level)
{
	if (!p) return;
	if (level == 1)
		std::cout << p->getKey() << " ";
	else if (level > 1)
	{
		printGivenLevel(p->getleft(), level - 1);
		printGivenLevel(p->getright(), level - 1);
	}

}

int BStablo::leftMax(Node *p, int &left, int &max, Node **maxNode)
{
	if (!p || (!p->getleft() && !p->getright()))
	{
		*maxNode = root;
		return 0;
	}


	if (p->getleft() != NULL)
	{
		if (!p->getleft()->getleft() && !p->getleft()->getright())
		{
			*maxNode = p;
			return 1;
		}

	}

	int levo = leftMax(p->getleft(), left, max, maxNode);
	int desno = leftMax(p->getright(), left, max, maxNode);
	left = levo;
	if (left > max)
	{
		max = left;
		*maxNode = p;
	}

	return 1 + left;
}

int BStablo::leftPathmax(Node **start)
{
	int m; int left = 0;
	int max;
	m = leftMax(root, left, max, start);
	return m;
}

Node ** BStablo::nadji()
{
	Node **p = new Node*;
	*p = nadji(root);
	return p;
}

Node * BStablo::nadji(Node *p) //trazi prvi cvor cija je vrednost veca od srednje vrednosti svoje dece
{
	if (!p) return NULL;
	std::cout << "key: " << p->getKey() << std::endl;
	if (!p->getright() && !p->getleft()) return NULL;

	if (p->getleft() != NULL && p->getright() != NULL)
	{
		float sr = (float)(p->getleft()->getKey() + p->getright()->getKey()) / (float)2;
		if ((float)p->getKey() > sr)
		{
			return p;
		}
	}

	Node *levo = nadji(p->getleft());
	Node *desno = nadji(p->getright());
	if (levo != NULL) return levo;
	else if (desno != NULL) return desno;
	return NULL;
}
int BStablo::Sum(int min, int max)
{
	int suma = 0;
	Sum(root, min, max, suma, 0);
	return suma;
}

void BStablo::Sum(Node *root, int min, int max, int &suma, int dubina)
{
	if (!root) return;

	if (!root->getleft() && !root->getright())
	{
		if (dubina > min && dubina < max) suma += root->getKey();
		return;
	}
	Sum(root->getleft(), min, max, suma, dubina + 1);
	Sum(root->getright(), min, max, suma, dubina + 1);

	if (dubina > min && dubina < max) suma += root->getKey();

}


int BStablo::delRightLeaves(Node * root, int & br_obrisanih)
{
	if (!root) return NULL;
	if (!root->getleft() && !root->getright())
	{
		delete root;
		br_obrisanih++;
		return NULL;
	}
	root->setleft(delRightLeaves(root->getleft(), br_obrisanih));
	root->setright(delRightLeaves(root->getright(), br_obrisanih));
	return br_obrisanih;
}

int BStablo::deleteRightLeaves()
{
	int br_obr = 0;
	return  delRightLeaves(root->getright(), br_obr);
}


void  BStablo::brisi_desna_deca(Node *root, int &s)
{
	int leva = 0, desna = 0;
	if (!root) return;

	if (root->getright() != NULL) {
		if ((root->getright()->getleft() == NULL && root->getright()->getright() == NULL))
		{
			s++;
			//std::cout << "List je br: " << root->getright()->getKey() << " ";
			delete root->getright();
			root->setright(NULL);
			return;
		}
	}
	brisi_desna_deca(root->getleft(), s);
	brisi_desna_deca(root->getright(), s);
}

int BStablo::brisi_desnu_decu_listovi()
{
	int s = 0;
	brisi_desna_deca(root, s);
	return s;
}


int BStablo::countGreater(Node *p, int value)
{
	if (!p) return 0;
	if (!p->getleft() && !p->getright())
	{
		if (p->getKey() > value) return 1;
		else
			return 0;
	}

	int desno = countGreater(p->getright(), value);
	int levo = countGreater(p->getleft(), value);
	
	return (p->getKey() > value) ? (levo + desno + 1) : levo+desno;
}

int BStablo::countGreater(int value)
{
	return countGreater(root, value);
}

Node ** BStablo::findCommonAncestor(int a, int b)
{
	Node **p = new Node*;
	int nebitno = findCommonAncestor(a, b, p, root);
	return p;
}


int BStablo::findCommonAncestor(int a, int b, Node ** p, Node * root)
{
	if (!root) return NULL;
	if (!root->getleft() && !root->getright())
	{
		if (root->getKey() == a || root->getKey() == b)
		{
			return root->getKey();
		}
		return NULL;
	}
	int levo = findCommonAncestor(a, b, p, root->getleft());
	int desno = findCommonAncestor(a, b, p, root->getright());
	int rootkey = root->getKey();
	if (rootkey == a) // koren jedank sa a i ili levo ili desno podstablo vratilo b, naso sam cvor
	{
		if (levo == b || desno == b) 
		{
			*p = root;
			return rootkey;
		}
	}
	else if (rootkey == b) // koren jedak sa be i ili levo ili desno podstablo vratilo a, naso sam cvor
	{
		if (levo == a || desno == a)
		{
			*p = root;
			return rootkey;
		}
	}
	else if (levo != NULL && desno != NULL)//treci slucaj ako su i levo i desno vratili nesto sto nije nula, onda su sigurno vratili a i b
	{ // pod pretpostavkom da se cvorovi ne ponavljaju i da se ne unosi ista vrednost za a i za b
		*p = root;
		return rootkey;
	}
	else if (levo != NULL) // ako nije izaso negde iznad ostao je slucaj ili da je levo vratilo, ili desno, ako nije nista od toga onda su obra
	{		//vratila NULL
		return levo;
	}
	else if (desno != NULL)
	{
		return desno;
	}
	return NULL; 
}