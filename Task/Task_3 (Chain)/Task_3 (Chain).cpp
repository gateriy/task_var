п»ї// Task_3 (Chain).cpp 

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>


//С‡РµС‚С‹СЂРµ С‚РёРїР° СЃРѕРѕР±С‰РµРЅРёР№: РїСЂРµРґСѓРїСЂРµР¶РґРµРЅРёРµ, oС€РёР±РєР°, С„Р°С‚Р°Р»СЊРЅР°СЏ РѕС€РёР±РєР°, РЅРµРёР·РІРµСЃС‚РЅРѕРµ СЃРѕРѕР±С‰РµРЅРёРµ.
class Type {

private:

    std::string _way_file{ "D:\\РЎ++\\Project\\VSC\\prj_netologiy_yandex\\Pattern\\Task_3\\file_1.txt" };

public:

     std::string& message_warning(const std::string& text) const {
        std::cout << text <<"\t"<< __FUNCTION__ << std::endl;
        std::cout << std::endl;
        std::string text_1 = text;
        return text_1;
    };

     std::string& message_error(const std::string& text) const {
         std::cout << text <<"\t\t"<< __FUNCTION__ << std::endl;
         std::string text_1 = text;

         std::ofstream  f_oupen(_way_file, std::ios::app); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° Р·Р°РїРёСЃСЊ
         if (f_oupen.is_open())
         {
             f_oupen << text << std::endl;
             f_oupen.close();
             std::cout << "Р›РћР“ С„Р°Р№Р» СѓСЃРїРµС€РЅРѕ Р·Р°РїРёСЃР°РЅ!" << std::endl;
             std::cout << std::endl;
         }
         else {
             std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
         }
         return text_1;
    };

     std::string& message_fatal_error(const std::string& text) const {

         try {
             throw 1;
         }
         catch (int& n) {
             std::cout << text << "\t\t" << __FUNCTION__ << std::endl;
             std::cout << std::endl;
             std::string text_1 = text;
             return text_1;
         }         

    };

     std::string& message_unknown(const std::string& text) const {

         try {
             throw 1;
         }
         catch (...) {
             std::cout << text << "\t\t" << __FUNCTION__ << std::endl;
             std::cout << std::endl;
             std::string text_1 = text;
             return text_1;
         }
    };
};

//РѕР±С‰РёР№ РєР»Р°СЃСЃ РѕР±С‰РµРіРѕ Р±Р»РѕРєР° СЃРѕРѕР±С‰РµРЅРёСЏ
class LogMessage : public Type {
private:
    std::string _text{""};
    std::vector<std::string> _type_mess{ "Warning", "Error", "Fatal Error", "Unknown" };

public:
    const std::string& message()  {
        _text = " <<< РџСЂРµРґСѓРїСЂРµР¶РґРµРЅРёРµ РѕР± РѕС€РёР±РєРµ >>> ";
        return _text ;
    }; 

    std::string Get_Type_mes(int i) {
        return _type_mess.at(i);
    };
};

// РђР±СЃС‚СЂР°РєС‚РЅС‹Р№ РєР»Р°СЃСЃ РѕР±СЂР°Р±РѕС‚С‡РёРєР°
class Handler {
public:
    virtual void setNextHandler(Handler* handler) = 0;
    virtual void handleRequest(const std::string& request) = 0;
};
// РљРѕРЅРєСЂРµС‚РЅС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє 1
class Handler_Warning : public Handler {
private:
    Handler* nextHandler = nullptr;
    LogMessage type_mess;
    std::string _text_mess{""};
    int _i_mes{ 0 };
public:

    Handler_Warning(const std::string text, int i) : _text_mess(text), _i_mes(i) {};

    void setNextHandler(Handler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override {
        if (request == type_mess.Get_Type_mes(_i_mes)) {
            type_mess.message_warning(type_mess.message()+_text_mess);
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
        else {
            std::cout << "РќРё РѕРґРёРЅ РѕР±СЂР°Р±РѕС‚С‡РёРє РЅРµ СЃРјРѕРі РѕР±СЂР°Р±РѕС‚Р°С‚СЊ Р·Р°РїСЂРѕСЃ: " << request << std::endl;
        }
    }
};
// РљРѕРЅРєСЂРµС‚РЅС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє 2
class Handler_Error : public Handler {
private:
    Handler* nextHandler = nullptr;
    LogMessage type_mess;
    std::string _text_mess{""};
    int _i_mes{ 0 };
public:

    Handler_Error(const std::string text, int i) : _text_mess(text), _i_mes(i) {};

    void setNextHandler(Handler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override {
        if (request == type_mess.Get_Type_mes(_i_mes)) {
            type_mess.message_error(type_mess.message() + _text_mess);
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
        else {
            std::cout << "РќРё РѕРґРёРЅ РѕР±СЂР°Р±РѕС‚С‡РёРє РЅРµ СЃРјРѕРі РѕР±СЂР°Р±РѕС‚Р°С‚СЊ Р·Р°РїСЂРѕСЃ: " << request << std::endl;
        }
    }
};
// РљРѕРЅРєСЂРµС‚РЅС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє 3
class Handler_Fatal_Error : public Handler {
private:
    Handler* nextHandler = nullptr;
    LogMessage type_mess;
    std::string _text_mess{""};
    int _i_mes{ 0 };
public:

    Handler_Fatal_Error(const std::string text, int i) : _text_mess(text), _i_mes(i) {};

    void setNextHandler(Handler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override {
        if (request == type_mess.Get_Type_mes(_i_mes)) {
            type_mess.message_fatal_error(type_mess.message() + _text_mess);
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
        else {
            std::cout << "РќРё РѕРґРёРЅ РѕР±СЂР°Р±РѕС‚С‡РёРє РЅРµ СЃРјРѕРі РѕР±СЂР°Р±РѕС‚Р°С‚СЊ Р·Р°РїСЂРѕСЃ: " << request << std::endl;
        }
    }
};
// РљРѕРЅРєСЂРµС‚РЅС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє 4
class Handler_Unknown : public Handler {
private:
    Handler* nextHandler = nullptr;
    LogMessage type_mess;
    std::string _text_mess{};
    int _i_mes{ 0 };
public:

    Handler_Unknown(const std::string text, int i) : _text_mess(text), _i_mes(i) {};

    void setNextHandler(Handler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override {
        if (request == type_mess.Get_Type_mes(_i_mes)) {
            type_mess.message_unknown(type_mess.message() + _text_mess);
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
        else {
            std::cout << "РќРё РѕРґРёРЅ РѕР±СЂР°Р±РѕС‚С‡РёРє РЅРµ СЃРјРѕРі РѕР±СЂР°Р±РѕС‚Р°С‚СЊ Р·Р°РїСЂРѕСЃ: " << request << std::endl;
        }
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Handler* handler_warning = new Handler_Warning("Р’РЅРёРјР°РЅРёРµ РїСЂРµРґСѓРїСЂРµР¶РґРµРЅРёРµ!!!",0);
    Handler* handler_error = new Handler_Error("РћС€РёР±РєР° error !!!",1);
    Handler* handler_fatal_error = new Handler_Fatal_Error("Р¤Р°С‚Р°Р»СЊРЅР°СЏ РѕС€РёР±РєР° !!!",2);
    Handler* handler_unknown = new Handler_Unknown("РќРµРёР·РІРµСЃС‚РЅР°СЏ РѕС€РёР±РєР° !?",3);

    handler_fatal_error->setNextHandler(handler_error);
    handler_error->setNextHandler(handler_warning);
    handler_warning->setNextHandler(handler_unknown);

    handler_fatal_error->handleRequest("Fatal Error");
    handler_fatal_error->handleRequest("Error");
    handler_fatal_error->handleRequest("Warning");
    handler_fatal_error->handleRequest("Unknown");
    handler_fatal_error->handleRequest("&!!!&");   
}

