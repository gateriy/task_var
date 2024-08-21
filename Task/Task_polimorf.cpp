// Task_polimorf.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// // задачи 1,2,3

#include <iostream>
#include <string>
#include <Windows.h>
//#include <vector>
//#include <fstream> //для работы с файлами
//#include<algorithm>

void Task_1();
void Task_2();
void Task_3();

//сласс общих методов для заданий
class AllConfigTask {

public:
	

	template <typename text, typename data>
	void Output(const text& A, const  data& B) {
		//std::cout << std::endl;
		std::cout << A << B << std::endl;
		//std::cout << std::endl;
	}

	template <typename text, typename data>
	data Input_X(const text& A, const data& B) {
		data var{ B };
		std::cout << A;
		std::cin >> var;
		return var;
	}

	void InteractiveVarTask(const std::string& v_text) {

		ConsolLang1251();

		do {
			std::cout << "\033c";//очистка консоли
			text = v_text;

			VarTaskNumber();

		} while (ExitProgram());
	}

private:
	std::string number_task{ };
	bool exit = true;
	std::string text{};

	enum class Task {
		exit_0,
		task_1,
		task_2,
		task_3
	};

	void VarTaskNumber() {

		std::cout << text;

		do {


			std::cin >> number_task;
			std::cout << std::endl;

			if (number_task == "1" || number_task == "2" || number_task == "3" || number_task=="0") {

				std::cout << "\033c";//очистка консоли

				//if(number_task != "0") {
					std::cout << "Task " << number_task << ":" << std::endl;
					std::cout << "-----------------------------------------" << std::endl;
				//}
				switch (stoi(number_task))
				{
				case(static_cast<int>(Task::task_1)):
					Task_1();
					exit = false;
					break;
				case(static_cast<int>(Task::task_2)):
					Task_2();
					exit = false;
					break;
				case(static_cast<int>(Task::task_3)):
					Task_3();
					exit = false;
					break;
				case(static_cast<int>(Task::exit_0)):	
					std::cout << "\033c";//очистка консоли
					exit = false;
					break;
				}
			}
			else {
				std::cout << "Incorrect data!" << std::endl;
				std::cout << std::endl;
				continue;
			}
		} while (exit);
	}

	bool ExitProgram()
	{

		char exit_Y_N{};

		do
		{
			//std::cout << std::endl;
			std::cout << "Exit programm (Y/N): ";
			std::cin >> exit_Y_N;
			std::cout << std::endl;

			if (exit_Y_N == 'Y' || exit_Y_N == 'y') {
				return false;
				break;
			}
			else if (exit_Y_N == 'N' || exit_Y_N == 'n') {
				return true;
				break;
			}
			else {
				std::cout << "Incorrect data!" << std::endl;
				continue;
			}

		} while (true);
	}

	void ConsolLang1251() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}
};

//task 1

/*
В этом задании вы построите первую простую иерархию классов для заданной предметной области.
Предметная область выглядит следующим образом: есть сущность фигура. Фигуры бывают двух типов: 
треугольник и четырёхугольник. У фигуры есть количество сторон. Для неизвестной фигуры будем 
считать это количество равным нулю. У треугольника три стороны, у четырёхугольника четыре стороны. 
У любой фигуры мы хотим узнавать количество её сторон, но мы не должны быть способны изменить количество 
сторон для заданной фигуры извне.
Задача: спроектировать и реализовать классы, описывающие предметную область. 
Продемонстрируйте их работу: создайте по одному экземпляру каждого класса и выведите 
информацию о количестве его сторон на консоль.

Пример работы программы
Консоль

Количество сторон:
Фигура: 0
Треугольник: 3
Четырёхугольник: 4

Вам нужно создать три класса: для фигуры, треугольника и четырёхугольника. 
Назовём их Figure, Triangle и Quadrangle.
Классы Triangle и Quadrangle будут наследовать класс Figure.
Для хранения информации о количестве сторон создайте поле sides_count в классе Figure. 
Оно будет защищённым, чтобы нельзя было изменить его извне, но можно изменить значение в наследниках. 
Либо оно может быть приватным, и тогда вам нужно передавать информацию о количестве сторон через конструктор.
Для доступа к информации о количестве сторон создайте публичный метод get_sides_count в классе Figure. 
Он будет унаследован обоими фигурами.
Для правильной инициализации информации о количестве сторон создайте конструкторы в классах, 
в которых присвойте нужное значение полю sides_count. Если вы сделали sides_count защищённым, 
можете присвоить значение прямо в конструкторе. Если приватным, то нужно создать в классе Figure 
защищённый конструктор с параметром (количество сторон) и публичный конструктор без параметров, 
который будет вызывать свой защищённый конструктор с параметром. Защищённый конструктор должны 
будут вызывать дочерние классы в своих публичных конструкторах без параметров.
Также для удобства вывода названия фигуры можно создать защищённое поле name в классе Figure 
с соответствующим методом get_name и заполнением значения в каждом классе. В Figure это будет «Фигура» и т. д.
*/

//классы для задания 1

class Figure {

public:
	Figure(int a, std::string c) :sides_count(a), text_var(c)
	{}

	int get_sides_count() { return sides_count; }
	std::string get_text_var() { return text_var;}

protected:
	int sides_count{};
	std::string text_var{};

};

class Triangle : public Figure {

public:
	Triangle(int x, std::string y) : Figure(x, y)
	{}

private:

};

class Quadrangle : public Figure {

public:
	Quadrangle(int x, std::string y) : Figure(x, y)
	{}

private:

};

//ПРИМЕЧАНИЕ (!!!!!!!!!!!!):
// Задачи 2 и 3 реализованны на базе едтной вложенноси классов ниже, 
// но с учетом отличных требований к задачам
// при реализации классов (некоторые функции за счет это частично дублируются)
// при разворачивании объектов уже в функциях Task_2() и Task_3() код сформирован 
// под уже конечные условия задач.

/*task 2
  
В этом задании вы усложните иерархию классов для усложнённой предметной области.
У вас появляется информация о длине сторон и углах ваших фигур, 
а также несколько более конкретных фигур. Теперь в треугольнике вы должны 
хранить информацию о длине всех его трёх сторон (a, b, c) и значениях его трёх углов (A, B, C). 
В четырёхугольнике вы храните информацию о длине его четырёх сторон (a, b, c, d) 
и значениях его четырёх углов (A, B, C, D).
Также у вас появляются более конкретные фигуры:

Вы должны иметь возможность узнать у каждой фигуры длины её сторон и значения её углов, 
но извне вы не должны быть способны изменить длины сторон и углы.
Не должно быть возможности создать фигуры, не удовлетворяющие перечисленным условиям. 
Например, нельзя создать квадрат с разными углами. Геометрические соотношения проверять не нужно. 
Например, сумма углов в треугольнике может быть не равна 180.
Задача: спроектировать и реализовать классы, описывающие предметную область. 
Продемонстрируйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран 
информацию о длинах её сторон и величине её углов. Значения используйте произвольные.
Инициализацию длин сторон и величин углов нужно выполнить с помощью вызова базовых конструкторов.
Для вывода информации о фигуре создайте функцию print_info, 
которая будет принимать в качестве аргумента указатель на базовый класс фигуры.

Что использовать для решения.
Нужно создать класс для каждой фигуры.
Иерархия наследования для более конкретных фигур может различаться. 
Например, параллелограмм будет наследоваться от четырёхугольника, 
прямоугольник и ромб — от параллелограмма. Было бы логично квадрат 
унаследовать от ромба и прямоугольника, ведь он является и тем, и другим. 
Но вы помните, что стоит избегать множественного наследования, поэтому унаследуйте 
его либо от прямоугольника, либо от ромба на ваше усмотрение.
Для хранения информации о длинах сторон и величинах углов создайте поля a, b, c и A, B, C 
в классе треугольника и соответствующие им get_ методы, а в классе четырёхугольника 
создайте поля a, b, c, d и A, B, C, D и соответствующие им get_ методы.
У вас появятся разные конструкторы. Например, у конструктора класса треугольника будет 6 
параметров — три для длин сторон и три для углов. 
У конструктора класса прямоугольного треугольника будет 5 параметров — угол C у него всегда равен 90. 
У класса равностороннего треугольника конструктор будет принимать только один параметр — это длина его сторон.
*/

/* task 3

Теперь ваши фигуры должны уметь немного больше:
выводить информацию о себе;
проверять правильность своих данных.

Ваши фигуры:
фигура (количество сторон равно 0);
треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равны, углы A и C равны);
равносторонний треугольник (все стороны равны, все углы равны 60);
четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
квадрат (все стороны равны, все углы равны 90);
параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
ромб (все стороны равны, углы A,C и B,D попарно равны).

Вы должны иметь возможность попросить фигуру вывести информацию о себе на консоль,
а также узнать, является ли фигура правильной, то есть выполняются ли условия, указанные в списке выше.

Информация о фигуре включает в себя:
название фигуры;
количество сторон;
длины её сторон, если есть;
величины её углов, если есть;
является ли фигура правильной.

Задача: спроектировать и реализовать классы, описывающие предметную область.
Продемонструйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о фигурах.
Реализуйте методы вывода на консоль и проверки правильности фигуры с помощью виртуальных
функций и переопределений. Используйте вызов базовой версии метода.
Ваша задача — работать с экземплярами дочерних классов полиморфно,
то есть с помощью указателя на базовый класс.

Что использовать для решения.
Вам нужно создать в классе фигуры два виртуальных метода — void print_info() и bool check().
Для фигуры будет выводиться только информация об имени, правильности и количестве сторон.
Для треугольника и четырёхугольника добавится информация о длине сторон и величине углов.
Чтобы не дублировать код, используйте в переопределении метода print_info базовую версию из класса фигуры.
Метод check будет переопределяться в каждом классе, так как у каждой фигуры в иерархии наследования
добавляются новые условия. Чтобы не терять результаты проверки из класса родителя и не дублировать код,
вызывайте базовую версию метода check. Таким образом, вам нужно проверить сумму углов в треугольнике
только в классе треугольника, наследникам нужно проверить только свои условия и вызвать базовую
версию из класса треугольник. А вот в классе треугольник вызывать базовую версию не надо, потому
что класс фигура проверяет количество сторон на равенство нулю, а в классе треугольник и в наследниках их будет 3.
*/

//классы для заданий 2 и 3

class Figure2 {

public:
	Figure2() {};

	Figure2(double a, double b, double c, double d, double A, double B, double C, double D) :
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{}

	//функция используется по условиям для 2 задания
	void get_var() {

		std::cout << text_var << std::endl;
		if (count >= 1 && count < 5) {
			std::cout << "Стороны: а = " << a << " b = " << b << " c = " << c <<  std::endl;
			std::cout << "Углы: A = " << A << " B = " << B << " C = " << C <<  std::endl;
		}
		if (count >= 5 && count <= 9) {
			std::cout << "Стороны: а = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
			std::cout << "Углы: A = " << A << " B = " << B << " C = " << C << " D = " << D << std::endl;
		}
		std::cout << std::endl;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void virtual print_info() {

		std::cout << text_var << std::endl;

		if (check() == true) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Не правильная" << std::endl;
		}
		std::cout << "Количество сторон: 0" << std::endl;
		std::cout << std::endl;
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool virtual check() { return true; };

protected:
	double a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 }, A{ 0 }, B{ 0 }, C{ 0 }, D{ 0 };
	std::string text_var{"Фигура:"};
	int count{ 0 };//используется для задания 2
	//int number_of_sides{ 0 };

	void get_var_task_3(int number_of_sides) {

		std::cout << "Количество сторон: "<< number_of_sides << std::endl;

		if (count >= 1 && count < 5) {
			std::cout << "Стороны: а = " << a << " b = " << b << " c = " << c << std::endl;
			std::cout << "Углы: A = " << A << " B = " << B << " C = " << C << std::endl;
		}
		if (count >= 5 && count <= 9) {
			std::cout << "Стороны: а = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
			std::cout << "Углы: A = " << A << " B = " << B << " C = " << C << " D = " << D << std::endl;
		}
		std::cout << std::endl;
	}
};

class Triangle2 :public Figure2 {
//треугольник(стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
public:
	Triangle2(double a, double b, double c, double A, double B, double C) :
		Figure2 (a, b, c, 0, A, B, C, 0)
	{
		//d = 0;
		//D = 0;
		text_var = "Треугольник: ";
		count = 1;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(3);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if ((A + B + C) == 180) {
			return true;
		}
		else {
			return false;
		}
	}

};

class RightAngledTriangle : public Triangle2{
//прямоугольный треугольник
//прямоугольный треугольник(угол C всегда равен 90);
public:
	RightAngledTriangle (double a, double b, double c, double A, double B) : 
		Triangle2 (a, b, c, A, B, 90)
	{
		d = 0;
		D = 0;
		//C = 90;
		text_var = "Прямоугольный треугольник: ";
		count = 2;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(3);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if ((C == 90) && ((A + B + C) == 180)) {
			return true;
		}
		else {
			return false;
		}
	}
};

class IsoscelesTriangle : public Triangle2 {
//равнобедренный треугольник (стороны a и c равны, углы A и C равны);
//равнобедренный треугольник(стороны a и c равны, углы A и C равны);

public:
	IsoscelesTriangle(double a, double b, double A, double B) :
		Triangle2(a, b, c, A, B, C)
	{
		d = 0;
		D = 0;
		c = a;
		C = A;
		text_var = "Равнобедренный треугольник: ";
		count = 3;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(3);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if ((C == A) && ((A + B + C) == 180) && (a==c)) {
			return true;
		}
		else {
			return false;
		}
	}
};

class AnEquilateralTriangle : public Triangle2 {
//равносторонний треугольник (все стороны равны, все углы равны 60);
//равносторонний треугольник(все стороны равны, все углы равны 60);
public:
	AnEquilateralTriangle(double a) :
		Triangle2(a, b, c, A, B, C)
	{
		c = a;
		b = a;
		C = 60;
		A = 60;
		B = 60;
		text_var = "Равносторонний треугольник: ";
		count = 4;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(3);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if ((A == 60) && (B == 60) && (C == 60) && (a==b)&&(a==c)&&(b==c)) {
			return true;
		}
		else {
			return false;
		}
	}

};

class Quadrangle2 : public Figure2 {
//четырехугольник
//четырёхугольник(стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
public:
	Quadrangle2(double a, double b, double c, double d, double A, double B, double C, double D) :
		Figure2 (a, b, c, d, A, B, C, D)
	{
		text_var = "Четырехугольник" ;
		count = 5;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(4);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if ((A + B + C + D) == 360) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Rectangle1 : public Quadrangle2 {
//прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
//прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
public:
	Rectangle1(double a, double b) :
		Quadrangle2(a, b, c, d, A, B, C, D)
	{
		c = a;
		d = b;
		C = 90;
		A = 90;
		B = 90;
		D = 90;
		text_var = "Прямоугольник: ";
		count = 6;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(4);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if (a==c && b==d && A==90 && B==90 && C==90 && D==90) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Square : public Rectangle1 {
//квадрат(все стороны равны, все углы равны 90);
//квадрат(все стороны равны, все углы равны 90);
public:
	Square(double a) :
		Rectangle1(a, b)
	{
		b = a;
		d = a;
		text_var = "Квадрат: ";
		count = 7;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(4);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if (a == c && b == d && c == b && A == 90 && B == 90 && C == 90 && D == 90) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Parallelogram : public Quadrangle2 {
//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
public:
	Parallelogram(double a, double b, double A, double B) :
		Quadrangle2(a, b, c, d, A, B, C, D)
	{
		c = a;
		d = b;
		C = A;
		D = B;
		text_var = "Параллелограмм: ";
		count = 8;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(4);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if (a == c && b == d && (a + c) == (b + d) && A == C && B == D && (A + C) == (B + D)) {
			return true;
		}
		else {
			return false;
		}
	}


};

class Rhomb : public Parallelogram {
//ромб(все стороны равны, углы A, C и B, D попарно равны).
//ромб(все стороны равны, углы A, C и B, D попарно равны).
public:
	Rhomb(double a, double A, double B) :
		Parallelogram(a, b, A, B)
	{
		b = a;
		d = b;
		text_var = "Ромб: ";
		count = 9;
	}

	//функция вывода в консоль используется по условиям для 3 задания
	void print_info() override {

		std::cout << text_var << std::endl;
		if (check() == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		get_var_task_3(4);
	};

	//функция проверки правильности используется по условиям для 3 задания
	bool check() override {

		if (a == c && b == d && c == b && A == C && B == D && (A+C)==(B+D)) {
			return true;
		}
		else {
			return false;
		}
	}
};

//----------------------------------------------------------------------------------------------------

//task_1 функция используемая для задания 1
void Task_1() {

	std::cout << std::endl;

	Figure figure(0, "Фигура: ");
	std::cout << figure.get_text_var() << figure.get_sides_count() << std::endl;

	Quadrangle quadrangle(3, "Треугольник: ");
	std::cout << quadrangle.get_text_var() << quadrangle.get_sides_count() << std::endl;

	Triangle triangle(4, "Четырехугольник: ");
	std::cout << triangle.get_text_var() << triangle.get_sides_count() << std::endl;

	std::cout << std::endl;
};

//task_2 функции используемые для задания 2
void print_info(Figure2* x) { x->get_var(); }
void Task_2() {
	std::cout << std::endl;
	
	Triangle2 triangle2(10, 20, 30, 50, 60, 70);
	RightAngledTriangle rightAngledTriangle (10, 20, 30, 50, 60);
	IsoscelesTriangle isoscelesTriangle (10, 20, 50, 60);
	AnEquilateralTriangle anEquilateralTriangle (30);

	Quadrangle2 quadrangle2(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle1 rectangle1(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhomb rhomb(30, 30, 40);

	print_info(&triangle2);
	print_info(&rightAngledTriangle);
	print_info(&isoscelesTriangle);
	print_info(&anEquilateralTriangle);

	print_info(&quadrangle2);
	print_info(&rectangle1);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rhomb);
}

//task_3 функции используемые для задания 3
void print_info2(Figure2* x) { x->print_info(); }
void Task_3() {

	std::cout << std::endl;

	Figure2 figure;
	Triangle2 triangle2(10, 20, 30, 50, 60, 70);
	RightAngledTriangle rightAngledTriangle(10, 20, 30, 50, 60);
	RightAngledTriangle rightAngledTriangle2(10, 20, 30, 50, 40);
	IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
	AnEquilateralTriangle anEquilateralTriangle(30);

	Quadrangle2 quadrangle2(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle1 rectangle1(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhomb rhomb(30, 30, 40);

	figure.print_info();
	print_info2(&triangle2);
	print_info2(&rightAngledTriangle);
	print_info2(&rightAngledTriangle2);
	print_info2(&isoscelesTriangle);
	print_info2(&anEquilateralTriangle);

	print_info2(&quadrangle2);
	print_info2(&rectangle1);
	print_info2(&square);
	print_info2(&parallelogram);
	print_info2(&rhomb);
	
}

//----------------------------------------------------------------------------------------------------

int main() {

	AllConfigTask config_task;
	config_task.InteractiveVarTask("Input numder task Polimorf (1, 2, 3) or \"0\" exit: " );
	
}