#pragma once

template<class T>
class Heap
{
private:
	T * niz;
	int duzina;
	int br_elem; // ovo je promenljiva END koja drzi indeks poslednjeg cvora u stablu
	void swap(T &a, T &b) { T pom = a; a = b; b = pom; }
public:
	Heap(int n)
	{
		br_elem = 0;
		duzina = n;
		niz = new T[n];
	}
	Heap() :Heap(7)
	{
	}

	void insert(T el)
	{
		int rod;
		br_elem++;
		int ptr = br_elem;
		while (ptr > 1)
		{
			rod = ptr / 2;
			if (el >= niz[rod])
			{
				niz[ptr] = el;
				return;
			}

			niz[ptr] = niz[rod];
			ptr = rod;
		}
		niz[1] = el;
	}

	int Delete()
	{
		T e = niz[1]; //pamtim koj brisem da bi ga vratila funkcija kad zavrsi sve
		T posl = niz[br_elem];
		br_elem--;
		if (br_elem == -1)
			throw "Heap je prazan!";
		int rod = 1;
		int levo = 2;
		int desno = 3;
		niz[1] = posl; // poslednji na mesto korena, jer njega brisem
		while (desno <= br_elem) //sad uspotavljam svojstvo hipa ako je naruseno
		{

			if (niz[rod] < niz[levo] && niz[rod] <= niz[desno])//ako roditelj ima manju vrednost od dece onda izlazi iz funkcije sve je ok
			{
				return e;
			}

			if (niz[levo] < niz[desno])//ako jeste levi postaje roditelj
			{
				swap(niz[levo], niz[rod]);
				rod = levo;
				levo = 2 * rod;
				desno = levo + 1;
			}
			else
			{
				swap(niz[desno], niz[rod]);
				rod = desno;
				levo = 2 * rod;
				desno = levo + 1;
			}

		}
		if (levo == br_elem && niz[rod] > niz[levo])
		{
			swap(niz[rod], niz[levo]);
		}
		return e;
	}

	void Sort(T *sortiran, int n)
	{
		//sortiran = new T[br_elem];

		for (int i = 0; i < n; i++)
			this->insert(sortiran[i]);


		for (int i = 0; i < n; i++)
			sortiran[i] = Delete();

	}

	void Update(int val, int add);

	void ToMaxHeap()
	{




	}






};

template<class T>
void Heap<T>::Update(int val, int add)
{
	int i = 1;
	while (i <= br_elem && niz[i] != val)
		i++;
	if (i > br_elem) throw "Trazeni element ne postoji";
	niz[i] += add;

	if (i != 1)
	{
		if (niz[i] >= niz[i / 2]) return;
	}
	else
	{
		if (br_elem >= 3)
		{
			int rod = 1, levo = 2, desno = 3;
			if (niz[levo] >= niz[desno])
			{
				swap(niz[desno], niz[rod]);
				i = desno;
			}
			else
			{
				swap(niz[levo], niz[rod]);
				i = levo;
			}
		}


	}

	bool dalje = true;

	while (dalje)
	{
		if (niz[i] < niz[i / 2])
		{
			int pom = niz[i];
			niz[i] = niz[i / 2];
			niz[i / 2] = pom;
			i /= 2;
		}
		else
			dalje = false;
	}

}
