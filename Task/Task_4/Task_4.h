п»ї// Task_4.h : РІРєР»СЋС‡Р°РµРјС‹Р№ С„Р°Р№Р» РґР»СЏ СЃС‚Р°РЅРґР°СЂС‚РЅС‹С… СЃРёСЃС‚РµРјРЅС‹С… РІРєР»СЋС‡Р°РµРјС‹С… С„Р°Р№Р»РѕРІ

#pragma once
#ifndef TASK_4_H
#define TASK_4_H

#include <iostream>
#include <exception>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>

#include "pqxx/pqxx"

class io_db_pq {

public:

	//РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё Рё РєРѕРґРёСЂРѕРІРєР°
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
		"РЈРєР°Р¶РёС‚Рµ С‡С‚Рѕ РЅРµРѕР±С…РѕРґРёРјРѕ СЃРґРµР»Р°С‚СЊ:",
		"0 - РїРѕРІС‚РѕСЂРёС‚СЊ РІС‹Р±РѕСЂ РёР»Рё РІС‹Р№С‚Рё РёР· РїСЂРѕРіСЂР°РјРјС‹",
		"1 - СЃРѕР·РґР°С‚СЊ СЃС‚СЂСѓРєС‚СѓСЂСѓ Р‘Р”(С‚Р°Р±Р»РёС†С‹)",
		"2 - РґРѕР±Р°РІРёС‚СЊ РЅРѕРІРѕРіРѕ РєР»РёРµРЅС‚Р°",
		"3 - РґРѕР±Р°РІРёС‚СЊ С‚РµР»РµС„РѕРЅ РЅРѕРІРѕРіРѕ РєР»РёРµРЅС‚Р°",
		"4 - РёР·РјРµРЅРёС‚СЊ РґР°РЅРЅС‹Рµ Рѕ РєР»РёРµРЅС‚Рµ",
		"5 - СѓРґР°Р»РёС‚СЊ С‚РµР»РµС„РѕРЅ Сѓ СЃСѓС‰РµСЃС‚РІСѓСЋС‰РµРіРѕ РєР»РёРµРЅС‚Р°",
		"6 - СѓРґР°Р»РёС‚СЊ СЃСѓС‰РµСЃС‚РІСѓСЋС‰РµРіРѕ РєР»РёРµРЅС‚Р°",
		"7 - РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ вЂ” РёРјРµРЅРё",
		"8 - РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ вЂ” С„Р°РјРёР»РёРё",
		"9 - РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ вЂ” email",
		"10 - РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ вЂ” С‚РµР»РµС„РѕРЅСѓ",
		"11 - СѓРґР°Р»РёС‚СЊ С‚Р°Р±Р»РёС†С‹ Р±Р°Р·С‹ РґР°РЅРЅС‹С…",
		"12 - РЅРµ СЂРµР°Р»РёР·РѕРІР°РЅ (Р·Р°РїР°СЃ)"
	};
	std::vector<std::string> var_numbe{ "0","1","2","3","4","5","6","7","8","9","10","11","12"};

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


#endif // !TASK_4_H