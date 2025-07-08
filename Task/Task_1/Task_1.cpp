п»ї// Task_1.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
//

#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>
#include <string>
#include <chrono>
//#include <mutex>

/*
Р—Р°РґР°РЅРёРµ 1
РћС‡РµСЂРµРґСЊ РєР»РёРµРЅС‚РѕРІ
Р’Р°Рј РЅСѓР¶РЅРѕ СЃРѕР·РґР°С‚СЊ РїСЂРёР»РѕР¶РµРЅРёРµ, РєРѕС‚РѕСЂРѕРµ РёРјРёС‚РёСЂСѓРµС‚ РѕС‡РµСЂРµРґСЊ РІ РѕРєРѕС€РєРѕ. 
Р”Р»СЏ СЌС‚РѕРіРѕ РЅСѓР¶РЅРѕ СЃРѕР·РґР°С‚СЊ РґРІР° РїРѕС‚РѕРєР°, СЂР°Р±РѕС‚Р°СЋС‰РёРµ СЃ РѕРґРЅРѕР№ СЂР°Р·РґРµР»СЏРµРјРѕР№ РїРµСЂРµРјРµРЅРЅРѕР№.

РџРµСЂРІС‹Р№ РїРѕС‚РѕРє РёРјРёС‚РёСЂСѓРµС‚ РєР»РёРµРЅС‚Р°: СЂР°Р· РІ СЃРµРєСѓРЅРґСѓ РѕРЅ РѕР±СЂР°С‰Р°РµС‚СЃСЏ Рє СЃС‡С‘С‚С‡РёРєСѓ 
РєР»РёРµРЅС‚РѕРІ Рё СѓРІРµР»РёС‡РёРІР°РµС‚ РµРіРѕ РЅР° 1. РњР°РєСЃРёРјР°Р»СЊРЅРѕРµ РєРѕР»РёС‡РµСЃС‚РІРѕ РєР»РёРµРЅС‚РѕРІ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ РїР°СЂР°РјРµС‚СЂРёР·РёСЂРѕРІР°РЅРѕ.

Р’С‚РѕСЂРѕР№ РїРѕС‚РѕРє РёРјРёС‚РёСЂСѓРµС‚ РѕРїРµСЂР°С†РёРѕРЅРёСЃС‚Р°: СЂР°Р· РІ 2 СЃРµРєСѓРЅРґС‹ РѕРЅ РѕР±СЂР°С‰Р°РµС‚СЃСЏ 
Рє СЃС‡С‘С‚С‡РёРєСѓ РєР»РёРµРЅС‚РѕРІ Рё СѓРјРµРЅСЊС€Р°РµС‚ РµРіРѕ РЅР° 1. В«РћРїРµСЂР°С†РёРѕРЅРёСЃС‚В» СЂР°Р±РѕС‚Р°РµС‚ РґРѕ РїРѕСЃР»РµРґРЅРµРіРѕ РєР»РёРµРЅС‚Р°.
*/
//std::mutex mt;

class in_out {
public:

	void SetColor(int textColor, int bgColor)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
	}

	void SetCursor(int x, int y) {
	
		COORD position = { x,y }; //РїРѕР·РёС†РёСЏ x Рё y
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}

	void in_data(const int& var_x) {
		while(count <= var_x) {
			std::this_thread::sleep_for(std::chrono::seconds(1));			
			++count;			
			SetColor(5, 0);
			SetCursor(0, 3);
			std::cout << "РћС‡РµСЂРµРґСЊ РєР»РёРЅС‚РѕРІ: " << count;

		}
	};

	void out_data() {

		while (count >= 0) {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			
			SetColor(5, 0);
			SetCursor(0, 4);
			std::cout << "РћС‡РµСЂРµРґСЊ РѕРїРµСЂР°С†РёРѕРЅРёСЃС‚Р°:     ";
			SetCursor(0, 4);
			std::cout << "РћС‡РµСЂРµРґСЊ РѕРїРµСЂР°С†РёРѕРЅРёСЃС‚Р°: " << count;
		
			--count;
		}

	};

private:
	int count{ 0 };
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	in_out in_out_1;

	std::cout << "РљРѕР»РёС‡РµСЃС‚РІРѕ РІРѕР·РјРѕР¶РЅС‹С… РїРѕС‚РѕРєРѕРІ: " << std::thread::hardware_concurrency() << std::endl;
	std::cout << std::endl;

	std::thread t1([&in_out_1]() {in_out_1.in_data(10); });
	std::thread t2([&in_out_1]() {in_out_1.out_data(); });

	t1.join();
	t2.join();

	std::cout << std::endl;
	in_out_1.SetColor(1, 0);
}
