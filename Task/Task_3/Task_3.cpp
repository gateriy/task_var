п»ї/*
Р—Р°РґР°РЅРёРµ 3
Р—Р°С‰РёС‰С‘РЅРЅС‹Р№ РѕР±РјРµРЅ РґР°РЅРЅС‹РјРё
РЎРѕР·РґР°Р№С‚Рµ РєР»Р°СЃСЃ Data, СЃРѕРґРµСЂР¶Р°С‰РёР№ РІ РєР°С‡РµСЃС‚РІРµ РїРѕР»РµР№ СЃРєР°Р»СЏСЂРЅС‹Рµ РґР°РЅРЅС‹Рµ Рё РјСЊСЋС‚РµРєСЃ.
РЎРѕР·РґР°Р№С‚Рµ С„СѓРЅРєС†РёСЋ swap, РєРѕС‚РѕСЂР°СЏ РїСЂРёРЅРёРјР°РµС‚ СЃСЃС‹Р»РєРё РЅР° РґРІР° РѕР±СЉРµРєС‚Р° РєР»Р°СЃСЃР° Data Рё РѕР±РјРµРЅРёРІР°РµС‚ РёС… РјРµСЃС‚Р°РјРё.
Р’ С„СѓРЅРєС†РёСЏС… РЅСѓР¶РЅРѕ СЃРЅР°С‡Р°Р»Р° Р·Р°С…РІР°С‚РёС‚СЊ РјСЊСЋС‚РµРєСЃС‹ РѕР±РѕРёС… РѕР±СЉРµРєС‚РѕРІ, Р° Р·Р°С‚РµРј РІС‹РїРѕР»РЅРёС‚СЊ РѕР±РјРµРЅ РґР°РЅРЅС‹РјРё.
Р РµР°Р»РёР·СѓР№С‚Рµ С‚СЂРё РІР°СЂРёР°РЅС‚Р° СЌС‚РѕР№ С„СѓРЅРєС†РёРё : РїСЂРё РїРѕРјРѕС‰Рё lock, scoped_lock Рё unique_lock.
*/

#include <iostream>
#include <string>
#include <thread>
#include <utility>
#include <Windows.h>
#include <chrono>
#include <mutex>
#include <functional>
#include <exception>




void SetCursor(int x, int y) {

    COORD position = { x,y }; //РїРѕР·РёС†РёСЏ x Рё y
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

class Data {

public:

    Data() {}

    Data(const int long_math, const int blocks,  const std :: string  text)     
    {

        mt.lock();
        this->_thr_blocks = blocks;
        this->_long_math = long_math;
        this->_text = text;
        mt.unlock();

    }

    ~Data() {};

    void threads_x() {
        _vec_lambda.clear();
        _threads.clear();

        //СЃРѕР·РґР°РЅРёРµ РІРµРєС‚РѕСЂР° Р»СЏРјР±Рґ - РѕС‚РґРµР»СЊРЅРѕ С‡С‚РѕР±С‹ РёРјРµС‚СЊ РіРёР±РєРѕСЃС‚СЊ РІ СЃРёСЃС‚РµРјРµ
        for (int i = 0; i < _thr_blocks; ++i) {
            _vec_lambda.push_back(([this, i]() {  math_block(i); }));
        }

        //СЃРѕР·РґР°РЅРёРµ РІРµРєС‚РѕСЂР° РїРѕС‚РѕРєРѕРІ СЃ РѕРґРЅРѕРІСЂРµРјРµРЅРЅРѕР№ РёРЅРёС†РёР°Р»РёР·Р°С†РёРµР№ РІ РїРѕС‚РѕРєР°С… С„СѓРЅРєС†РёР№ РёР· РІРµРєРєС‚РѕСЂР° Р»СЏРјР±Рґ
        for (const auto& s : _vec_lambda) {
            _threads.emplace_back(s);
        }

        //РѕСЃС‚Р°РЅРѕРІРєР° РІС‹РїРѕР»РЅРµРЅРёСЏ РґР°Р»СЊРЅРµР№С€РµРіРѕ РєРѕРґР° РґРѕ Р·Р°РІРµСЂС€РµРЅРёСЏ СЂР°Р±РѕС‚С‹ РїРѕС‚РѕРєРѕРІ
        for (auto& t : _threads) {
            t.join();
        }
    }

    //РёРјРёС‚Р°С‚РѕСЂ СЂР°СЃС‡РµС‚Р°
    void math_block(const int& number_th) {
        //РёРјРёРјС‚Р°С†РёСЏ СЂР°СЃС‡РµС‚Р° СЃ Р·Р°С…РІР°С‚РѕРј Рё РІС‹РІРѕРґРѕРј РѕР±С‰РµР№ РїРµСЂРµРјРµРЅРЅРѕР№
        int consol_x{ 0 };

        mt1.lock();

        std::cout << _text<< " Id: " << std::this_thread::get_id() << " РџРѕС‚РѕРє: " << number_th << "\t";         

        for (int i = 0; i < _long_math; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            _count = i;
            std::cout << "-";
        }
        std::cout << "\tРїРѕС‚РѕРє Р·Р°РІРµСЂС€РµРЅ, СЃС‡РµС‚: " << _count;
        std::cout << std::endl;
        mt1.unlock();
    }

    std::mutex mt, mt1;

    int _thr_blocks{ 0 };
    int _long_math{ 0 };
    std::string _text;
    
private:
    int _count{ 0 };//РѕР±С‰Р°СЏ  РїРµСЂРµРјРµРЅРЅР°СЏ
    std::vector<std::function<void(void)>> _vec_lambda; //РІРµРєС‚РѕСЂ РґР»СЏ Р»СЏРјР±Рґ 
    std::vector<std::thread> _threads;//РІРµРєС‚РѕСЂ РґР»СЏ РїРѕС‚РѕРєРѕРІ
};

void swap_x_y_1(Data& x, Data& y) {
    //РёРјРёС‚Р°С†РёСЏ Р±Р»РѕРєРёСЂРѕРІРєРё Рё Р·Р°С…РІР°С‚Р° РјСЋС‚РµРєСЃРѕРІ Р±Р»РѕРєРёСЂСѓСЋС‰РёС… РёРЅРёС†РёР°С†РёСЋ РєР»СЋС‡РµРІС‹С… РїРѕР»РµР№ РєР»Р°СЃСЃР°

    //x.mt.lock();
    //y.mt.lock();
    lock(x.mt, y.mt);

    std::cout << "Р”Рѕ РѕР±РјРµРЅР° РґР°РЅРЅС‹РјРё РјРµР¶РґСѓ РѕР±СЉРµРєС‚Р°РјРё" << std::endl;
    std::cout << x._text << " РґР»РёРЅР°: " << x._long_math << " Р±Р»РѕРєРѕРІ: " << x._thr_blocks << std::endl;
    std::cout << y._text << " РґР»РёРЅР°: " << y._long_math << " Р±Р»РѕРєРѕРІ: " << y._thr_blocks << std::endl;

    std::swap(x._thr_blocks, y._thr_blocks);
    std::swap(x._long_math, y._long_math);

    std::cout << "РџСЃР»Рµ РѕР±РјРµРЅР° РґР°РЅРЅС‹РјРё РјРµР¶РґСѓ РѕР±СЉРµРєС‚Р°РјРё" << std::endl;
    std::cout << x._text << " РґР»РёРЅР°: " << x._long_math << " Р±Р»РѕРєРѕРІ: " << x._thr_blocks << std::endl;
    std::cout << y._text << " РґР»РёРЅР°: " << y._long_math << " Р±Р»РѕРєРѕРІ: " << y._thr_blocks << std::endl;
    std::cout << std::endl;

    x.threads_x();
    std::cout << std::endl;
    y.threads_x();
    std::cout << std::endl;

    x.mt.unlock();
    y.mt.unlock();
}

void swap_x_y_2(Data& x, Data& y) {
    //РёРјРёС‚Р°С†РёСЏ Р±Р»РѕРєРёСЂРѕРІРєРё Рё Р·Р°С…РІР°С‚Р° РјСЋС‚РµРєСЃРѕРІ Р±Р»РѕРєРёСЂСѓСЋС‰РёС… РёРЅРёС†РёР°С†РёСЋ РєР»СЋС‡РµРІС‹С… РїРѕР»РµР№ РєР»Р°СЃСЃР°
    std::scoped_lock lock1(x.mt, y.mt);

    std::cout << "Р”Рѕ РѕР±РјРµРЅР° РґР°РЅРЅС‹РјРё РјРµР¶РґСѓ РѕР±СЉРµРєС‚Р°РјРё" << std::endl;
    std::cout << x._text << " РґР»РёРЅР°: " << x._long_math << " Р±Р»РѕРєРѕРІ: " << x._thr_blocks << std::endl;
    std::cout << y._text << " РґР»РёРЅР°: " << y._long_math << " Р±Р»РѕРєРѕРІ: " << y._thr_blocks << std::endl;

    std::swap(x._thr_blocks, y._thr_blocks);
    std::swap(x._long_math, y._long_math);

    std::cout << "РџСЃР»Рµ РѕР±РјРµРЅР° РґР°РЅРЅС‹РјРё РјРµР¶РґСѓ РѕР±СЉРµРєС‚Р°РјРё" << std::endl;
    std::cout << x._text << " РґР»РёРЅР°: " << x._long_math << " Р±Р»РѕРєРѕРІ: " << x._thr_blocks << std::endl;
    std::cout << y._text << " РґР»РёРЅР°: " << y._long_math << " Р±Р»РѕРєРѕРІ: " << y._thr_blocks << std::endl;
    std::cout << std::endl;

    x.threads_x();
    std::cout << std::endl;
    y.threads_x();
    std::cout << std::endl;

}

void swap_x_y_3(Data& x, Data& y) {
    // РёРјРёС‚Р°С†РёСЏ Р±Р»РѕРєРёСЂРѕРІРєРё Рё Р·Р°С…РІР°С‚Р° РјСЋС‚РµРєСЃРѕРІ Р±Р»РѕРєРёСЂСѓСЋС‰РёС… РёРЅРёС†РёР°С†РёСЋ РєР»СЋС‡РµРІС‹С… РїРѕР»РµР№ РєР»Р°СЃСЃР°
    std::unique_lock<std::mutex> lock_1(x.mt,std::defer_lock);
    std::unique_lock<std::mutex> lock_2(y.mt, std::defer_lock);
    std::lock(lock_1, lock_2);

    std::cout << "Р”Рѕ РѕР±РјРµРЅР° РґР°РЅРЅС‹РјРё РјРµР¶РґСѓ РѕР±СЉРµРєС‚Р°РјРё" << std::endl;
    std::cout << x._text << " РґР»РёРЅР°: " << x._long_math << " Р±Р»РѕРєРѕРІ: " << x._thr_blocks << std::endl;
    std::cout << y._text << " РґР»РёРЅР°: " << y._long_math << " Р±Р»РѕРєРѕРІ: " << y._thr_blocks << std::endl;

    std::swap(x._thr_blocks, y._thr_blocks);
    std::swap(x._long_math, y._long_math);

    std::cout << "РџСЃР»Рµ РѕР±РјРµРЅР° РґР°РЅРЅС‹РјРё РјРµР¶РґСѓ РѕР±СЉРµРєС‚Р°РјРё" << std::endl;
    std::cout << x._text << " РґР»РёРЅР°: " << x._long_math << " Р±Р»РѕРєРѕРІ: " << x._thr_blocks << std::endl;
    std::cout << y._text << " РґР»РёРЅР°: " << y._long_math << " Р±Р»РѕРєРѕРІ: " << y._thr_blocks << std::endl;
    std::cout << std::endl;

    x.threads_x();
    std::cout << std::endl;
    y.threads_x();
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string text{ "y" };
    bool go_x{ false };     

    do {

        try {
            std::cout << "\033[2J";

            Data a1(40, 2, "РћР±СЉРµРєС‚ 1");
            Data a2(10, 5, "РћР±СЉРµРєС‚ 2");

           // swap_x_y_1(a1, a2);
            
            //РёРјРёРјС‚Р°С†РёСЏ РѕР±РјРµРЅР° РєР»СЋС‡РµРІС‹РјРё РїР°СЂР°РјРµС‚СЂР°РјРё РєР»Р°СЃСЃР° РІ СЂР°Р·РЅС‹С… РѕС‚РґРµР»СЊРЅС‹С… 
            // РїРѕС‚РѕРєР°С… РґР»СЏ РѕС‚СЂР°Р±РѕС‚РєРё РІР·Р°РёРјРЅРѕРіРѕ РїРµСЂРµС…РІР°С‚Р° РјСЋС‚РµРєСЃРѕРІ
            std::cout << std::endl;
            std::cout << "--- РџРµСЂРІС‹Р№ РІР°СЂРёР°РЅС‚ РїРµСЂРµС…РІР°С‚Р° РјСЋС‚РµРєСЃРѕРІ lock() ---" << std::endl;
            std::cout << std::endl;

            std::cout << "< РџРµСЂРІС‹Р№ РѕР±РјРµРЅ РІ РїРµСЂРІРѕРј РїРѕС‚РѕРєРµ >" << std::endl;
            std::thread th1_1([&]() {swap_x_y_1(a1, a2); });
            std::cout << "< Р’С‚РѕСЂРѕР№ РѕР±РјРµРЅ РІРѕ РІС‚РѕСЂРѕРј РїРѕС‚РѕРєРµ >" << std::endl;
            std::thread th2_1([&]() {swap_x_y_1(a1, a2); });
            th1_1.join();
            th2_1.join();

            std::cout << "--------------------------------------------------------------------------------" << std::endl;

            std::cout << std::endl;
            std::cout << "--- Р’С‚РѕСЂРѕР№ РІР°СЂРёР°РЅС‚ РїРµСЂРµС…РІР°С‚Р° РјСЋС‚РµРєСЃРѕРІ scoped_lock ---" << std::endl;
            std::cout << std::endl;

            std::cout << "< РџРµСЂРІС‹Р№ РѕР±РјРµРЅ РІ РїРµСЂРІРѕРј РїРѕС‚РѕРєРµ >" << std::endl;
            std::thread th1_2([&]() {swap_x_y_2(a1, a2); });
            std::cout << "< Р’С‚РѕСЂРѕР№ РѕР±РјРµРЅ РІРѕ РІС‚РѕСЂРѕРј РїРѕС‚РѕРєРµ >" << std::endl;
            std::thread th2_2([&]() {swap_x_y_2(a1, a2); });
            th1_2.join();
            th2_2.join();

            std::cout << "--------------------------------------------------------------------------------" << std::endl;

            std::cout << std::endl;
            std::cout << "--- РўСЂРµС‚РёР№ РІР°СЂРёР°РЅС‚ РїРµСЂРµС…РІР°С‚Р° РјСЋС‚РµРєСЃРѕРІ unique_lock ---"<<std::endl;
            std::cout << std::endl;

            std::cout << "< РџРµСЂРІС‹Р№ РѕР±РјРµРЅ РІ РїРµСЂРІРѕРј РїРѕС‚РѕРєРµ >" << std::endl;
            std::thread th1_3([&]() {swap_x_y_3(a1, a2); });
            std::cout << "< Р’С‚РѕСЂРѕР№ РѕР±РјРµРЅ РІРѕ РІС‚РѕСЂРѕРј РїРѕС‚РѕРєРµ >" << std::endl;
            std::thread th2_3([&]() {swap_x_y_3(a1, a2); });
            th1_3.join();
            th2_3.join();
   
            std::cout << std::endl;
            for (int i = 0; i < 50; ++i) {
                std::cout << "--";
            }
            std::cout << std::endl;
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "РќРµ РёР·РІРµСЃС‚РЅРѕРµ РёСЃРєР»СЋС‡РµРЅРёРµ!" << std::endl;
        }

        std::cout << "РџСЂРѕРґРѕР»Р¶РёС‚СЊ? Р’РµРµРґРёС‚Рµ y/n: ";
        std::cin >> text;

        if (text == "y") {
            go_x = true;
        }
        else {
            go_x = false;

        }

    } while (go_x);
}
