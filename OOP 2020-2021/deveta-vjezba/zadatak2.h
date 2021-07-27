using namespace std;

template <typename Stek>
class Stack
{
private:
	Stek* niz;
	int logicka_velicina;
	int fizicka_velicina;
public:
	Stack()
	{
		logicka_velicina = 10;
		fizicka_velicina = 0;
		niz = new int [logicka_velicina];
	}
	void push(Stek a)
	{
		++fizicka_velicina;
		niz[fizicka_velicina] = a;
	}
	void pop()
	{
		--fizicka_velicina;
	}
	void is_empty()
	{
		if (fizicka_velicina == 0)
		{
			cout << "Stack je prazan" << endl;
		}
	}
};