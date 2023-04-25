#include "Tree.h"

Tree::Tree()
{
	beg = nullptr;
	size = 0;
	cur = 0;
}

Tree::~Tree()
{
	if (beg != nullptr) delete[] beg;
	beg = nullptr;
}

Tree::Tree(int n)
{
	beg = new Object* [n]; 
	cur = 0;
	size = n;
}

void Tree::GetName()
{
	Object** p = beg;
	for (int i = 0; i < cur; i++) 
	{
		cout << (*p)->GetName() << endl;
		p++;
	}
}

void Tree::Add()
{
	Object* p;
	cout << "1.Print." << endl;	
	cout << "2.Magazin.\n>" << endl;
	int f;
	cin >> f;
	if (f == 1)				//���������� ������� ������ Print
	{ 
		Print* a = new (Print);
		a->Input();			//���� �������� ��������� 
		p = a;
		if (cur < size) 
		{
			beg[cur] = p;	//���������� � ������ 
			cur++;
		}
	}
	else if (f == 2)		//���������� ������� ������ Magazin 
	{ 
		Magazin* b = new Magazin;
		b->Input();
		p = b;
		if (cur < size) 
		{
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

void Tree::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;    //��������� �� ��������� ���� Object 
	for (int i = 0;i < cur;i++)	
	{
		(*p)->Show();   //����� ������ Show() 
		p++;			//����������� ��������� �� ��������� ������
	}
}

int Tree::operator ()()
{
	return cur;
}

void Tree::Del()
{
	if (cur == 0) return; //���� ������
	cur--;
}