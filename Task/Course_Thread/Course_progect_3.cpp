п»ї// Course_progect_3.cpp : РџРѕС‚РѕРєРѕР±РµР·РѕРїР°СЃРЅР°СЏ РѕС‡РµСЂРµРґСЊ.
#include "Course_progect_3.h"

void func_1() {
    std::this_thread::sleep_for(std::chrono::microseconds(700));
    std::cout << RED << " Р Р°Р±РѕС‡РёР№ РїРѕС‚РѕРє С„СѓРЅРєС†РёСЏ 1 - id = " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << RESET << std::endl;
};

void func_2() {
    std::this_thread::sleep_for(std::chrono::microseconds(500));
    std::cout << GREEN << " Р Р°Р±РѕС‡РёР№ РїРѕС‚РѕРє С„СѓРЅРєС†РёСЏ 2 - id = " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << RESET << std::endl;
};

void func_3() {
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    std::cout << PUR << " Р Р°Р±РѕС‡РёР№ РїРѕС‚РѕРє С„СѓРЅРєС†РёСЏ 3 - id = " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << RESET << std::endl;
};

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Course_progect_3.cpp : РџРѕС‚РѕРєРѕР±РµР·РѕРїР°СЃРЅР°СЏ РѕС‡РµСЂРµРґСЊ" << std::endl;

    thread_pool<std::function<void(void)> >aaa;

    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        aaa.addFuncToPool(func_1);
        std::this_thread::sleep_for(std::chrono::microseconds(5000));
        aaa.addFuncToPool(func_2);
    }

 // std::cout << RESET << "Р—Р°РіСЂСѓР·РєР° С„СѓРЅРєС†РёР№ 1 Р·Р°РІРµСЂС€РµРЅР° main id " << std::this_thread::get_id() << std::endl;
           
  aaa.addFuncToPool(func_3);
  aaa.addFuncToPool(func_3);
  aaa.addFuncToPool(func_3);
  aaa.addFuncToPool(func_3);
  aaa.addFuncToPool(func_3);
  aaa.addFuncToPool(func_3);
  aaa.addFuncToPool(func_3);
  aaa.addFuncToPool(func_3);

 //std::cout << RESET << "Р—Р°РіСЂСѓР·РєР° С„СѓРЅРєС†РёР№ 2 Р·Р°РІРµСЂС€РµРЅР° main id " << std::this_thread::get_id() << std::endl;

 //std::this_thread::sleep_for(std::chrono::milliseconds(4000));
}