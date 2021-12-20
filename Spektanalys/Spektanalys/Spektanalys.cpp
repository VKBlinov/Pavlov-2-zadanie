// Spektanalys.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

int main()
{
	//Создаем файловый поток и связываем его с файлом
	ifstream in("3a.dat");
	if (in.is_open())
	{
		ofstream fout;
		fout.open("out.txt");
		//Если открытие файла прошло успешно
		int n = 20000;
		int dl = n / 3;
		double n1 = dl;
		int m = 1;
		double* x = new double[n];

		//Считаем матрицу из файла
		for (int i = 0; i < n; i++)
			//for (int j = 0; j < m; j++)
		{
			in >> x[i];
		}

		//Выведем матрицу
		/*for (int i = 0; i < n; i++)
		{

				cout << x[i] << "\t";
			cout << "\n";
		}*/
		double dF = 0.01;
		double dt = 0.03;
		double k = 1 / (2*dt);
		cout << k;

		complex<double> j(0, -1);
		for (double df = 0; df < k; df += dF)
		{
			complex<double> sum(0, 0);
			for (int i = 0; i < n; i++)
			{
				double i1 = i;
				double N = n;
				sum = x[i] * exp((j * 6.28 * i1 * df)/N);
			}
			sum *= dt;
			//fout << df << " " << sum.real() << " " << sum.imag()<<"\n";
			fout << df << " " << sqrt(pow(sum.real(), 2) + pow(sum.imag(), 2)) << "\n";
		}
		
		fout.close();
		in.close();//под конец закроем файла
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "File not found";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
