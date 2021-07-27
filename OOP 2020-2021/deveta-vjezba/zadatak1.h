template <typename T>
void swapaj(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename A>
void sort(A* niz, int velicina)
{
	for (int i = 0; i < velicina - 1; i++)
	{
		if (isalpha(niz[i]))
		{
			niz[i]=tolower(niz[i]);
		}
	}
	for (int i = 0; i < velicina - 1; i++)
	{
		for (int j = velicina - 1; i < j; j--)
		{
			if (niz[j] < niz[j - 1])
			{
				swapaj(niz[j], niz[j - 1]);
			}
		}
	}
}

template<>
void sort(char* niz, int velicina)
{
	for (int i = 0; i < velicina - 1; i++)
	{
		for (int j = velicina - 1; i < j; j--)
		{
			if (niz[j] < niz[j - 1])
			{
				swapaj(niz[j], niz[j - 1]);
			}
		}
	}
}