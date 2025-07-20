п»ї// Task_1.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
//

#include <iostream>
#include<random>
#include <future>
#include <thread>
#include <Windows.h>
//#include <algorithm>

 //С„СѓРЅРєС†РёСЏ РїРѕРёСЃРєР° РјРёРЅРёРјСѓРјР° СЃ РІС‹РІРѕРґРѕРј СЂРµР·СѓР»СЊС‚Р°С‚Р° РІ Р±СѓРґСѓС‰РµРј РІ promise
void select_min(int arr[], int size, int min, std::promise<int> result_prom) {

    for (int j = min + 1; j < size; j++) {

        if (arr[j] < arr[min])
            min = j;
    }
    result_prom.set_value(min);
}

//С„СѓРЅРєС†РёСЏ СЃРѕСЂС‚РёСЂРѕРІРєРё СЃ Р·Р°РїСѓСЃРєРѕРј РїРѕС‚РѕРєР° Рё РІС‹РІРѕРґРѕРј РёР· РЅРµРіРѕ СЂРµР·СѓР»СЊС‚Р° РїРѕ С„СѓРЅРєС†РёРё РїРѕРёСЃРєР° РјРёРЅРёРјСѓРјР°
void select_sort(int arr[], int size) {

    int min_x{ 0 };
    for (int i = 0; i < (size - 1); i++) {

        //СЃРѕР·РґР°РЅРёРµ СЃРІСЏР·РєРё promise Рё future
        std::promise<int> prom_1;
        std::future<int> future_select_min = prom_1.get_future();
        //С„СѓРЅРєС†РёСЏ РїРѕРёСЃРєР° РјРёРЅРёРјСѓРјР° Р·Р°РїСѓСЃРєР°РµРјР°СЏ РІ РѕС‚РґРµР»СЊРЅРѕРј РїРѕС‚РѕРєРµ (СЂРµР°Р»РёР·Р°С†РёСЏ Р·Р°РїСѓСЃРєР° С‡РµСЂРµР· Р»СЏРјР±РґСѓ)
        std::thread thr_select_min([&]() {select_min(arr, size, i, std::move(prom_1)); });
        //РІС‹РІРѕРґ Р·РЅР°С‡РµРЅРёРµ РёР· РїРѕС‚РѕРєР° Рё РїСЂРёСЃРІРѕРµРЅРёРµ РїРµСЂРµРјРµРЅРЅРѕР№ РІ С‚РµРєСѓС‰РµРј РїРѕС‚РѕРєРµ РјРµС‚РѕРґРѕРј get()
        min_x = future_select_min.get();
        //РѕСЃС‚Р°РЅРѕРІРєР° РѕСЃРЅРѕРІРЅРѕРіРѕ РїРѕС‚РѕРєР°
        thr_select_min.join();

        std::swap(arr[min_x], arr[i]);
    }
}

void print_arr(const int arr[], const int& size) {

    for (int i = 0; i < size; ++i) {
        std::cout << "[" << arr[i] << "]\t";

    }
    std::cout << std::endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size_x{ 300 };
    int arr[size_x];

    for (int i = 0; i < size_x; ++i) {
        arr[i] = std::rand()%100;
    }
    std::cout << "РњР°СЃСЃРёРІ РґРѕ СЃРѕСЂС‚РёСЂРѕРІРєРё: " << std::endl;
    print_arr(arr, size_x);

    select_sort(arr, size_x);
    std::cout << "РњР°СЃСЃРёРІ РїРѕСЃР»Рµ СЃРѕСЂС‚РёСЂРѕРІРєРё: " << std::endl;
    print_arr(arr, size_x);

}

