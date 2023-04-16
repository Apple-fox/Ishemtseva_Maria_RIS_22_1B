#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;
int collis = 0;
string names[10] = { "Борислав", "Василий", "Ярослав", "Эрнест", "Архип", "Спиридон", "Илларион", "Федот", "Роберт", "Александр" };
string surnames[10] = {"Михеев", "Карпов", "Самсонов", "Королёв", "Гришин", "Третьяков", "Громов", "Юдин", "Муравьёв", "Ермаков" };
string last_names[10] = { "Авенирович", "Вонифатович", "Игнатьевич", "Лаврентьевич", "Памфильевич", "Протасович", "Феофилактович", "Антипович", "Валериевич", "Арсениевич" };
string phones[10] = { "89820568317", "89522750080", "89230830754", "89943366719", "89629427448", "89871106348", "89038496205", "89829922085", "89322008547", "89064204539"};
string dates[10] = { "1990.12.03", "1984.09.10", "2003.10.06", "2000.03.31", "2001.02.22", "2016.11.17", "1992.02.09", "1974.04.02", "1991.02.02", "2002.12.12" };
struct human {
	human() {
		fio = "NULL";
		date = "NULL";
		number = "NULL";
	}
	string fio;
	string date;
	string number;
};

int random_num() {
	return rand() % 10;
}
struct hash_table {
	human* arr;
	hash_table(int size) {
		arr = new human[size];
	}
	~hash_table() {
		delete[] arr;
	}

	void add(human temp, int size);
	void pop(string date, int size);
	void find_index(string date, int n);
};

int get_date(string str) {
	return stoi(str.substr(0, 4)) + stoi(str.substr(5, 2)) + stoi(str.substr(8, 2));
}

string randon_fio() {
	return surnames[random_num()] + " " + names[random_num()] + " " + last_names[random_num()];
}

string random_phone() {
	return phones[random_num()];
}

string random_date() {
	return dates[random_num()];
}

void humans(human* arr, int count) {
	for (int i = 0; i < count; i++) {
		arr[i].fio = randon_fio();
		arr[i].date = random_date();
		arr[i].number = random_phone();
	}
}

int hash_function(string str, int size) {
	double f = 0.344 * get_date(str);
	double g = (f - int(f)) * size;
	return int(g);
}

void hash_table::add(human tmp, int n) {
	int idx = hash_function(tmp.date, n);
	int hash = idx;
	if (arr[idx].fio == "NULL") {
		arr[idx] = tmp;
		return;
	}
	else {
		while (idx < n) {
			if (arr[idx].fio == "NULL") {
				arr[idx] = tmp;
				return;
			}
			idx++;
			collis++;
		}
		if (idx >= n) {
			idx = 0;
			collis++;\
			while (idx < hash) {
				if (arr[idx].fio == "NULL") {
					arr[idx] = tmp;
					return;		
				}
				idx++;
				collis++;
			}
		}
	}
}

void hash_table::find_index(string date, int n) {
	int idx = hash_function(date, n);
	int hash = idx;
	while (arr[idx].date != date && idx < n) {
		idx++;
	}
	if (idx >= n) {
		idx = 0;
		while (arr[idx].date != date && idx < hash) {
			idx++;
		}
		if (idx >= hash) {
			cout << "Человек с датой рождения - " << date << " нет.\n";
		}
	}
	else {
		cout << "Человек с датой рождения - " << date << " содержится по индексу " << idx << endl;
	}

}

void show_info(human temp) {
	cout << "ФИО: " << temp.fio << endl;
	cout << "Дата рождения: " << temp.date << endl;
	cout << "Телефон: " << temp.number << endl;
}
void show(hash_table* table, int n) {
	for (int i = 0; i < n; i++) {
		show_info(table->arr[i]);
	}
}
void arr_hum(human* arr, int n) {
	for (int i = 0; i < n; i++) {
		show_info(arr[i]);
	}
}

void hash_table::pop(string date, int n) {
	int idx = hash_function(date, n);
	if (arr[idx].date == date) {
		arr[idx] = human();
		return;
	}
	else {
		while (idx < n) {
			if (arr[idx].date == date) {
				arr[idx] = human();
				return;
			}
			idx++;
		}
		if (idx >= n) {
			idx = 0;
			while (idx < n) {
				if (arr[idx].date == date) {
					arr[idx] = human();
					return;
				}
				idx++;
			}
		}
	}
}
int maaaaain() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n;
	for (int rt = 0; rt < 3; rt++) {
		cout << "Введите количество элементов: ";
		cin >> n;
		human* arr = new human[n];
		hash_table table(n);
		humans(arr, n);
		for (int i = 0; i < n; i++) {
			table.add(arr[i], n);
		}
		show(&table, n);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		table.find_index("1990.12.03", n);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		table.pop("1990.12.03", n);
		show(&table, n);
		cout << "\nКоличество коллизий для " << n << " записей: " << collis << endl;

		delete[] arr;
	}
	return 0;
}