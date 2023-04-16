#include <iostream>
#include <string>
#include <Windows.h>
#include <map>
#include <fstream>
using namespace std;

void chet() {
	int n;
	int a, maxi = 0;
	cout << "Введите количество элементов в массиве: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Введите элементы массива" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > maxi) maxi = a;
		arr[i] = a;
	}
	int* sort_arr = new int[maxi];
	for (int i = 1; i < maxi + 1; i++) {
		sort_arr[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		sort_arr[arr[i]]++;
	}
	int y = 0;
	for (int i = 1; i < maxi + 1; i++) {
		if (sort_arr[i] > 0) {
			for (int j = 0; j < sort_arr[i]; j++) {
				arr[y] = i;
				y++;
			}
		}
	}
	cout << "Массив отсортированный подсчетом: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void hoara() {
	int a, n;
	cout << "Введите количество элементов в массиве: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Введите элементы массива" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[i] = a;
	}
	int i = 0, j = n-1, sr = 0, tmp;
	bool f = false;
	while (sr < n) {
		if (arr[i] >= arr[sr]) {
			j = n - 1;
			while (arr[j] >= arr[sr] && j > sr) {
				j--;
			}
			if (i != j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;	
			}
			i++;
		}
		if (arr[i] < arr[sr]) {
			i++;
		}
		for (int y = sr; y < n; y++) {
			if (arr[y] < arr[sr]){
				f = true;
			}
		}
		if (!f || i > n) {
			i = 0;
			sr++;
		}
	}
	cout << "Массив отсортированный методом Хоара(быстрой сортировкой)\n";
	for (int iu = 0; iu < n; iu++) {
		cout << arr[iu] << " ";
	}
	cout << endl;
}

void straight_sea() {
	string str1, str2;
	cout << "Введите строку: ";
	cin.get();
	getline(cin, str1);
	cout << "Введите подстроку, которую надо найти: ";
	getline(cin, str2);
	int n = str1.length(), m = str2.length(), index = 0;
	bool f = false;
	int t = 0;
	for (int i = 0; i <= n-m; i++) {
		for (int j = 0; j < m; j++) {
			if (str1[i + j] == str2[j]) {
				t++;
			}
		}
		if (t == m and !f) {
			index = i;
			f = true;
		}
		t = 0;
	}
	if (index != 0) cout << "Подстрока смещена относительно начала на " << ++index << " символов." << endl;
	else cout << "Подстрока не найдена!\n";
}

void bol_mur() {
	map <char, int> mp;
	string str, substr;
	cout << "Введите строку: ";
	cin.get();
	getline(cin, str);
	cout << "Введите подстроку: ";
	getline(cin, substr);
	int len = substr.length(), len_str = str.length();
	int k = len-1;
	int i = len_str-1;
	while (i > -1 && k > -1) {
		if (str[i] == substr[k]) {
			mp[substr[k]] = len_str - i - 1;
			k--;
			i--;
		}
		else i--;
	}
	mp[substr[len - 1]] = len;
	bool flag = false;
	int y1 = len-1, y2 = y1, smech = 0;
	while (y1 <= y2 && y1 < len && y2 < len_str && y1 > -1 && y2 > -1) {
		if (substr[y1] != str[y2]) {
			for (int z = 0; z < len; z++) {
				if (substr[z] == str[y2]) {
					flag = true;
				}
			}
			if (flag) {
				smech += mp[str[y2]];
				y2 = smech + len - 1;
			}
			else {
				smech += len;
				y2 = smech + len - 1;
			}
			y1 = len-1;
		}
		else {
			y1--;
			y2--;
		}
	}
	if (y1 == -1) cout << "Подстрока смещена относительно начала на " << smech+1 << " символов.\n";
	else cout << "Подстрока не найдена!";
}

void interpol() {
	int n;
	int a, maxi = 0;
	cout << "Введите количество элементов в массиве: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Введите элементы массива" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > maxi) maxi = a;
		arr[i] = a;
	}
	int* sort_arr = new int[maxi];
	for (int i = 1; i < maxi + 1; i++) {
		sort_arr[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		sort_arr[arr[i]]++;
	}
	int y = 0;
	for (int i = 1; i < maxi + 1; i++) {
		if (sort_arr[i] > 0) {
			for (int j = 0; j < sort_arr[i]; j++) {
				arr[y] = i;
				y++;
			}
		}
	}
	cout << "Введите элемент, который нужно найти: ";
	int find = 0;
	cin >> find;
	bool flag = false;
	int left = 0, right = n-1;
	int fin = left + ((find - arr[left]) * (right - left) / (arr[right] - arr[left]));
	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	while (!flag && left < right - 1) 
	{
		if (arr[fin] != find)
		{
			if (arr[fin] > find)
			{
				right = fin;
				fin = left + ((find - arr[left]) * (right - left) / (arr[right] - arr[left]));
			}
			else 
			{
				left = fin+1;
				fin = left + ((find - arr[left]) * (right - left) / (arr[right] - arr[left]));
			}
		}
		else 
		{
			flag = true;
		}
	}
	if (flag) cout << "Индекс искомого элемента: " << fin << endl;
	else cout << "Элемент не найден!" << endl;
}

void prefix(string substr, int len_sub, int* pref)
{
	int len = 0;

	pref[0] = 0;

	int i = 1;
	while (i < len_sub)
	{
		if (substr[i] == substr[len])
		{
			len++;
			pref[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = pref[len - 1];
			}
			else
			{
				pref[i] = 0;
				i++;
			}
		}
	}
}


void knut() {
	string str;
	string substr;
	bool f = false;
	cout << "Введите строку: ";
	cin.get();
	getline(cin, str);
	cout << "Введите подстроку: ";
	getline(cin, substr);
	int len = str.length();
	int len_sub = substr.length();

	int* pref = new int[len_sub];

	prefix(substr, len_sub, pref);

	int i = 0;
	int j = 0;

	while ((len - i) >= (len_sub - j))
	{
		if (substr[j] == str[i])
		{
			j++;
			i++;
		}

		if (j == len_sub)
		{
			cout << "Индекс первого символа подстроки в строке:" << i - j << endl;
			j = pref[j - 1];
			f = true;
		}

		else if (i < len && substr[j] != str[i])
		{
			if (j != 0)
			{
				j = pref[j - 1];
			}
			else
			{
				i = i + 1;
			}
		}
	}
	if (!f) cout << "Подстрока не найдена\n";
}

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = start + (end - start) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

void merge(int arr[], int left, int mid, int right)
{
	int leftRange = mid - left + 1;
	int rightRange = right - mid;

	int* leftArr = new int[leftRange];
	int* rightArr = new int[rightRange];

	for (int i = 0; i < leftRange; i++)
	{
		leftArr[i] = arr[left + i];
	}
	for (int i = 0; i < rightRange; i++)
	{
		rightArr[i] = arr[mid + 1 + i];
	}

	int leftIndex = 0;
	int rightIndex = 0;
	int mergeIndex = left;

	while (leftIndex < leftRange && rightIndex < rightRange)
	{
		if (leftArr[leftIndex] <= rightArr[rightIndex])
		{
			arr[mergeIndex] = leftArr[leftIndex];
			leftIndex++;
		}
		else
		{
			arr[mergeIndex] = rightArr[rightIndex];
			rightIndex++;
		}
		mergeIndex++;
	}

	while (leftIndex < leftRange)
	{
		arr[mergeIndex] = leftArr[leftIndex];
		leftIndex++;
		mergeIndex++;
	}
	while (rightIndex < rightRange)
	{
		arr[mergeIndex] = rightArr[rightIndex];
		rightIndex++;
		mergeIndex++;
	}

	delete[] leftArr;
	delete[] rightArr;
}

void bucketSort() {
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	const int num = 10;
	const int arr_len = 10;
	int buckets[num][arr_len];
	int bucketSizes[num] = { 0 };
	for (int i = 0; i < n; i++) {
		int index = arr[i] / num;
		buckets[index][bucketSizes[index]] = arr[i];
		bucketSizes[index]++;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 1; j < bucketSizes[i]; j++) {
			int temp = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > temp) {
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = temp;
		}
	}

	int index = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < bucketSizes[i]; j++) {
			arr[index++] = buckets[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void distribution(string path1, string path2, string main_path)
{
	ofstream f1, f2;
	ifstream mainf;
	string temp, cur;
	int itemp, icur;
	f1.open(path1);
	f2.open(path2);
	mainf.open(main_path);
	if (!f1.is_open() || !f2.is_open())
	{
		cout << "Не удалось открыть файл" << endl;
	}
	else
	{
		bool firstfile = true;
		mainf >> cur;
		while (!mainf.eof())
		{
			if (firstfile)
			{
				f1 << cur << "\n";
				temp = cur;
				mainf >> cur;
				if (mainf.eof())
				{
					f1 << "/" << "\n";
					return;
				}
				itemp = stoi(temp);
				icur = stoi(cur);
				while (itemp <= icur)
				{
					if (mainf.eof())
					{
						f1 << "/" << "\n";
						return;
					}
					f1 << cur << "\n";
					temp = cur;
					mainf >> cur;
					itemp = stoi(temp);
					icur = stoi(cur);
				}
				f1 << "/" << "\n";
				firstfile = false;
			}
			else
			{
				f2 << cur << "\n";
				temp = cur;
				mainf >> cur;
				if (mainf.eof())
				{
					f2 << "/" << "\n";
					return;
				}
				itemp = stoi(temp);
				icur = stoi(cur);
				while (itemp <= icur)
				{
					if (mainf.eof())
					{
						f2 << "/" << "\n";
						return;
					}
					f2 << cur << "\n";
					temp = cur;
					mainf >> cur;
					itemp = stoi(temp);
					icur = stoi(cur);
				}
				f2 << "/" << "\n";
				firstfile = true;
			}
		}
	}
	f1.close();
	f2.close();
	mainf.close();
}

void merge(string path1, string path2, string main_path)
{
	distribution(path1, path2, main_path);
	ifstream f1, f2;
	ofstream mainf;
	string temp1, temp2;
	int itemp1, itemp2;
	f1.open(path1);
	f2.open(path2);
	mainf.open(main_path);
	if (!f1.is_open() || !f2.is_open())
	{
		cout << "Не удалось открыть файл" << endl;
	}
	else
	{
		while (!(f1.eof()))
		{
			f1 >> temp1;
			f2 >> temp2;
			if (temp2 == "")
			{
				return;
			}
			while (temp1 != "/" || temp2 != "/")
			{
				if (temp1 == "/")
				{
					mainf << temp2 << "\n";
					f2 >> temp2;
				}
				else if (temp2 == "/")
				{
					mainf << temp1 << "\n";
					f1 >> temp1;
				}
				else
				{
					itemp1 = stoi(temp1);
					itemp2 = stoi(temp2);
					if (itemp1 <= itemp2)
					{
						mainf << temp1 << "\n";
						f1 >> temp1;
					}
					else
					{
						mainf << temp2 << "\n";
						f2 >> temp2;
					}
				}
			}
		}
	}
	f1.close();
	f2.close();
	mainf.close();
	merge(path1, path2, main_path);
}

void shell() {
	int n, d, j, tmp;
	cout << "Введите размер массива: ";
	cin >> n;
	int* a = new int[n];
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d = n / 2;
	while (d > 0) {
		for (int i = 0; i < n - d; i++) {
			j = i;
			while (j >= 0 and a[j] > a[j + d]) {
				tmp = a[j];
				a[j] = a[j + d];
				a[j + d] = tmp;
				j -= d;
			}
		}
		d = d / 2;
	}
	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	delete[] a;
}


int maihghghgn() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int fg = 12;
	int n, a, maxi = 0;
	string str1, str2;
	while (fg != 0) {
		cout << "Сортировки - 1, поиск - 2, выход - 0\n";
		cin >> fg;
		if (fg == 1) {
			cout << "1 - Подсчет, 2 - Хоара, 3 - Слияние, 4 - блочная, 5 - Шелл, 6 - естественная\\двухфазная\n";
			cin >> fg;
			if (fg == 1) chet();
			if (fg == 2) hoara();
			if (fg == 3) {
				int n;
				cout << "Введите длину массива: ";
				cin >> n;
				int* arr = new int[n];
				for (int i = 0; i < n; ++i)
				{
					cin >> arr[i];
				}
				mergeSort(arr, 0, n - 1);
				for (int i = 0; i < n; ++i)
				{
					cout << arr[i] << " ";
				}
				delete[] arr;
				cout << endl;
			}
			if (fg == 4) bucketSort();
			if(fg == 5) shell();
			if (fg == 6) {
				int size, current;
				string result = "result.txt", buff = "buffer.txt", datafile = "data.txt", temp;
				ofstream data;
				ifstream res;
				cout << "Введите размер массива: ";
				cin >> size;
				cout << "Введите элементы массива:\n" << endl;

				data.open(datafile);
				for (int i = 0; i < size; i++)
				{
					cin >> current;
					data << current << "\n";
				}
				data.close();
				merge(result, buff, datafile);
				cout << "Отсортированный массив: " << endl;
				res.open(result);
				for (int i = 0; i < size; i++)
				{
					res >> temp;
					cout << temp << " ";
				}
				res.close();
				cout << endl;
			}
		}

		if (fg == 2) {
			cout << "1 - Прямой, 2 - Бойлер, 3 - Интерпол, 4 - Кнут Моррис Пратт\n";
			cin >> fg;
			if (fg == 1) straight_sea();
			if (fg == 2) bol_mur();
			if (fg == 3) interpol();
			if (fg == 4) knut();
		}
	}
	return 0; //Сделать: 
	//Сдать: 8 лаба, отчеты для всего, Шелл, естественная, 11 лаба: (стеки, очереди), списки: (однонаправленный, двунаправленный).
	//Сделано: 8 лаба, прямой поиск, интерполяционный поиск, бойера-мура поиск, быстрая сортировка, сортировка подсчетом, сортировка слиянием, Поиск Кнут, блочная сортировка, Шелл, естественная?11 лаба: (стеки, очереди), списки: (однонаправленный, двунаправленный).
	// От Поляковой: Хеш-таблицы, списки, стеки, очереди, простые сортировки, шелл, хоара, двухфазная
	//Гит хаб: списки, стеки, очереди, хеш и остальное чудо
}