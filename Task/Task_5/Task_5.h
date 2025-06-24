//#pragma once
// Task_5.h : включаемый файл для стандартных системных включаемых файлов

#pragma once
#ifndef TASK_5_H
#define TASK_5_H

#include <iostream>
#include <exception>
#include <string>
#include <Windows.h>
#include <vector>
//#include <sstream>
#include <utility>

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/Transaction.h>
#include <Wt/Dbo/backend/Postgres.h>

//#pragma execution_character_set( "utf-8" )

//#include "pqxx/pqxx"

class io_db_pq {

public:

	//очистка консоли и кодировка
	void InteractiveVarTask();

private:
	bool exit{ true };
	bool var_correct{ false };
	std::string text{};
	enum class tables;
	std::string number_task{ };
	int var_n{ 0 };

	bool ExitProgram();
	void ConsolLang1251();
	void VarTaskNumber();
	void check_str_to_int(std::string& text);

	std::vector<std::string> var_text{
		"Укажите что необходимо сделать:",
		"0 - повторить выбор или выйти из программы",
		"1 - создать структуру БД(таблицы)",
		"2 - добавить нового клиента",
		"3 - добавить телефон нового клиента",
		"4 - изменить данные о клиенте",
		"5 - удалить телефон у существующего клиента",
		"6 - удалить существующего клиента",
		"7 - найти клиента по — имени",
		"8 - найти клиента по — фамилии",
		"9 - найти клиента по — email",
		"10 - найти клиента по — телефону",
		"11 - удалить таблицы базы данных",
		"12 - не реализован (запас)"
	};
	std::vector<std::string> var_numbe{ "0","1","2","3","4","5","6","7","8","9","10","11","12" };

	void method_1();
	void method_2();
	void method_3();
	void method_4();
	void method_5();
	void method_6();
	void method_7();
	void method_8();
	void method_9();
	void method_10();
	void method_11();
	void method_12();
};


#endif // !TASK_5_H