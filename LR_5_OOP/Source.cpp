#include <iostream>
#include <cstdlib>
#include <cstdio>
#define N 25
using namespace ::std;

class participant {
protected:
	char competition[N];
	char school[N];
	char name[N];
	int age = 0;

public:
	string school_c;
	string name_c;

	~participant()
	{
		cout << endl << "end of program" << endl;
	}

	int size_c()
	{
		int i;
		for (i = 0; competition[i] != '\0'; i++)
		{
			;
		}
		return i;
	}

	int size_n()
	{
		int j;
		for (j = 0; name[j] != '\0'; j++)
		{
			;
		}
		return j;
	}
	int size_s()
	{
		int k;
		for (k = 0; school[k] != '\0'; k++)
		{
			;
		}
		return k;
	}
	virtual void input_data()
	{
		cout << " Input name of competition" << endl << " ";
		cin >> competition;
		cout << endl << " Input name of school" << endl << " ";
		cin >> school;
		school_c = school;
		cout << endl << " Input name of participant" << endl << " ";
		cin >> name;
		name_c = name;
		cout << endl << " Input age of participant" << endl << " ";
		cin >> age;
		getchar();
	}
	virtual void output_data()
	{
		cout << "\n\n\n___________________________________________";
		cout << "\n Output data about participant" << endl;
		cout << endl << " Name of competition : " << competition << endl;
		cout << endl << " Name of school : " << school << endl;
		cout << endl << " Name of participant : " << name << endl;
		cout << endl << " Age of participant : " << age << endl;
	}
};

class medalist : public participant
{
private:
	string medal[N];
public:
	int count_m = 0;
	int intput_medals()
	{
		int i;
		cout << endl << "Input medals (input 'stop' in new string if you want to stop)" << endl;
		for (i = 0; ; i++)
		{
			cout << " ";
			cin >> medal[i];
			if (medal[i] == "gold")
			{
				continue;
			}
			else if (medal[i] == "silver")
			{
				continue;
			}
			else if (medal[i] == "bronze")
			{
				continue;
			}
			else if (medal[i] == "stop")
			{
				break;
			}
			else
			{
				printf("wrong medal\n");
				cin >> medal[i];
			}
		}
		count_m = i;
		cout << endl << endl;
		return i;
	}

	void input_data()override
	{
		participant::input_data();
		intput_medals();
	}

	int output_medals()
	{
		printf("\n Output medals\n");
		int j;
		for (j = 0; j < 10; j++)
		{
			if (medal[j] != "stop")
			{
				cout << " Medal : " << medal[j] << " " << endl << endl;
			}
			else
			{
				break;
			}
		}
		cout << "count of medals :" << j;
		return j;
	}
	void output_data() override
	{
		participant::output_data();
		output_medals();
	}
};

class Prizewinner : public participant
{
private:
	int place[N];
	string prize[N];
public:
	int count_p = 0;
	int input_pri()
	{
		int i;
		cout << endl << "Input place(>= 4 and <=10) (input '-1' in new string if you want to stop)" << endl;
		for (i = 0; ; i++)
		{
			cout << " ";
			cin >> place[i];
			if (place[i] >= 4 && place[i] <= 9)
			{
				char temp = place[i] + 48;
				prize[i] = "diploma for the place : ";
				prize[i] += temp;
				continue;
			}
			else if (place[i] == 10)
			{
				prize[i] = "diploma for the place : 10";
				continue;
			}
			else if (place[i] == -1)
			{
				break;
			}
			else
			{
				printf("wrong place\n");
				cin >> place[i];
			}
		}
		count_p = i;
		cout << endl << endl;
		return i;
	}
	void input_dat()override
	{
		participant::input_data();
		input_pri();
	}
	int output_medali()
	{
		printf("\n Output places\n");
		int j;
		for (j = 0; ; j++)
		{
			if (place[j] != -1)
			{
				cout << " place : " << place[j] << endl << " prize : " << prize[j] << " " << endl << endl;
			}
			else
			{
				break;
			}
		}
		cout << "count of places : " << j;
		return j;
	}
	void output_data() override
	{
		participant::output_data();
		output_medali();
	}
};

void sorting(participant* ar[], medalist* arr, Prizewinner* arrr, int n)
{
	int  n1 = 0, n2 = 0;
	int* arro = new int[n];
	for (int i = 0, k = 0; i < n; i++)
	{
		if (arr[i].count_m > 0)
		{
			n2++;
			arro[k] = arr[i].count_m;
			k++;
		}
		if (arrr[i].count_p > 0)
		{
			n1++;
			arro[k] = arrr[i].count_p;
			k++;
		}
	}

	participant* temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if ((arro[j] < arro[j + 1]))
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;

				int tempor = arro[j];
				arro[j] = arro[j + 1];
				arro[j + 1] = tempor;
			}
		}
	}
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

void info(medalist* arr, Prizewinner* arrr, int m)
{
	string copy, n_copy;
skip:cout << "\n\n\n___________________________________________";
	cout << "\n Input name of school and name of participant" << endl << " ";
	cin >> copy;
	cout << " ";
	cin >> n_copy;
	int check = 0;
	int i;
	for (i = 0; i < m; i++)
	{
		if (copy == arr[i].school_c || copy == arrr[i].school_c)
		{
			check = 1;
			break;
		}
	}
	while (check == 0)
	{
		cout << endl << " " << "this school is not listed" << endl << " ";
		cin >> copy;
		for (i = 0; i < m; i++)
		{
			if (copy == arr[i].school_c || copy == arrr[i].school_c)
			{
				check = 1;
				break;
			}
		}
	}

	int j;
	for (j = 0; j < m; j++)
	{
		if (n_copy == arr[j].name_c || n_copy == arrr[j].name_c)
		{
			check = 1;
			break;
		}
	}
	while (check == 0)
	{
		cout << endl << " " << "this participant is not listed" << endl << " ";
		cin >> n_copy;
		for (j = 0; j < m; j++)
		{
			if (n_copy == arr[j].school_c || n_copy == arrr[j].school_c)
			{
				check = 1;
				break;
			}
		}
	}
	if (i != j)
	{
		puts(" Mistake, name of school or name of participant is incorrect");
		goto skip;
	}
	else
	{
		int co;
		printf("\n Inputed pupil's awards: ");
		if (arrr[i].school_c == copy)
		{
			co = arrr[i].output_medali();
		}
		if (arr[i].school_c == copy)
		{
			co = arr[i].output_medals();
		}
	}
}

int main()
{
	int count;
	string str;
	cout << " Input count of participant : ";
	cin >> count;
	participant** ar;
	ar = new participant * [count * 2];
	Prizewinner* parr = new Prizewinner[count];
	medalist* marr = new medalist[count];

	for (int i = 0; i < count; i++)
	{
		cout << " Type(\"prize\" if input prizewinner, \"medal\" id input medalist ) : ";
		cin >> str;
		if (str == "prize")
		{
			ar[i] = &parr[i];
			ar[i]->input_data();
			continue;
		}
		if (str == "medal")
		{
			ar[i] = &marr[i];
			ar[i]->input_data();
			continue;
		}
	}
	sorting(ar, marr, parr, count);
	cout << " After sorting" << endl;
	for (int k = 0; k < count; k++)
	{
		ar[k]->output_data();
		cout << "\n___________________________________________";
	}
	cout << "\n";
	info(marr, parr, count);
	(void)getchar();
	(void)getchar();
	(void)getchar();
	delete[] parr;
	delete[] marr;
	delete[] ar;
	return 0;
}
//Створити базовий клас УЧАСНИК УЧНІВСЬКИХ ЗМАГАНЬ
//(задаються назва змагання, дані про учня).
//Створити похідні класи МЕДАЛІСТ (задається ранг медалі: золота, срібна чи бронзова) 
//та ПРИЗЕР (задаються зайняте місце і назва призу). Для введених даних про учасників змагань 
//відсортувати учнів за спаданням сумарної кількості нагород різних типів і вивести дані про нагороди, здобуті заданим учнем школи.
//Для перевірки використати масив вказівників на об’єкти базового класу, яким присвоїти адреси об’єктів похідних класів