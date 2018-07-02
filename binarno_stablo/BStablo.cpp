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


int BStablo::dif(Node * p, int & sl, int & sd, int & max, bool &t)
{
	int levo = 0, desno = 0;
	if (!p) return 0;
	levo = dif(p->getleft(), sl, sd, max, t);
	desno = dif(p->getright(), sl, sd, max, t);
	if (p->getleft() == NULL && p->getleft() == NULL)
	{
		return 1;
	}



	int dif = abs(levo - desno);

	if (dif > max)
	{
		max = dif;
		if (max > 1) t = false;
	}

	sl = levo;
	sd = desno;

	return sl + sd + 1;

}

bool BStablo::isBalanced()
{
	int sl = 0, sd = 0, max = 0;
	bool jeste = true;
	int m = dif(root, sd, sl, max, jeste);
	return jeste;
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