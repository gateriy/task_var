// Task_2 (Observer).cpp 

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

//интерфейс наблюдателя
class Observer 
{
public:

    virtual void onWarning(const std::string& message) {};
    virtual void onError(const std::string& message) {};
    virtual void onFatalError(const std::string& message) {};

    virtual ~Observer() {};

protected:
    std::string _way_file{ "D:\\С++\\Project\\VSC\\prj_netologiy_yandex\\Pattern\\Task_3\\file_1.txt" };
};

// Интерфейс субъекта
class Subject {
public:
    virtual void Warning(const std::string& message) {};
    virtual void Error(const std::string& message) {};
    virtual void FatalError(const std::string& message) {};

    virtual ~Subject() {}
};

//Cубъект наблюдаемый класс
class Message_station : public Subject
{
public:

    void Register_Observer(Observer* metod_observer) {
        observers_.push_back(metod_observer);  
     }
        
    void RemoveObserver(Observer* metod_observer) {
        auto it = std::remove(observers_.begin(), observers_.end(), metod_observer);
        observers_.erase(it, observers_.end());
    }
    
    void Warning(const std::string& message)  override {
        for (auto obs : observers_) {           
            obs->onWarning(_text_warning);
        }
    }

    void Error(const std::string& message) override {
        for (auto obs : observers_) {
            obs->onError(_text_error);            
        }
    }

    void FatalError(const std::string& message) override {
        for (auto obs : observers_) {
             obs->onFatalError(_text_fatal_error);            
        }
    }


    void set_messages(const std::string& message1, const std::string& message2, const std::string& message3) {
        _text_warning = message1;
        _text_error = message2;
        _text_fatal_error = message3;

        Warning(_text_warning);  // Оповещение всех наблюдателей
        Error(_text_error);  // Оповещение всех наблюдателей
        FatalError(_text_fatal_error);  // Оповещение всех наблюдателей
    }

protected:
    std::string _text_warning, _text_error, _text_fatal_error;
    std::vector<Observer*> observers_;
};

// класс - наблюдатель реализующий вывод в консоль
class Metod_On_Warning : public Observer
{
public:
    void onWarning(const std::string& message) override {

        std::cout << message << "\t\t" << __FUNCTION__<<std::endl;
        std::cout << std::endl;
    };
};

// класс - наблюдатель реализующий вывод в файл
class Metod_On_Error : public Observer
{
public:
    void onError(const std::string& message) override {

        std::ofstream  f_oupen(_way_file, std::ios::app); // открыли файл по заданному пути на запись
        if (f_oupen.is_open())
        {
            f_oupen << message << std::endl;
            f_oupen.close();
            std::cout << "ЛОГ файл успешно записан!" << "\t" << __FUNCTION__  << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
        }
    };
};

// класс - наблюдатель реализующий вывод в консоль и в файл
class Metod_ON_Fatal_Error : public Observer
{
public:

    void onFatalError(const std::string& message) override {

        std::cerr << message << "\t\t" << __FUNCTION__ << std::endl;

        std::ofstream  f_oupen(_way_file, std::ios::app); // открыли файл по заданному пути на запись
        if (f_oupen.is_open())
        {
            f_oupen << message << std::endl;
            f_oupen.close();
            std::cout << "ЛОГ файл успешно записан!" << "\t" << __FUNCTION__ << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
        }
    };
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   // Observer obs;
    Message_station observed_obj;
    Metod_On_Warning warning;
    Metod_On_Error error;
    Metod_ON_Fatal_Error fatal_error;

    observed_obj.Register_Observer(&warning);
    observed_obj.Register_Observer(&error);
    observed_obj.Register_Observer(&fatal_error);

    // Первое обновление
    std::cout << "<<< Обновление 1 >>>" << std::endl;
    observed_obj.set_messages("Предупреждение 1", "Ошибка 1", "Фатальна ошибка 1");
    // Второе обновление
    std::cout << "<<< Обновление 2 >>>" << std::endl;
    observed_obj.set_messages("Предупреждение 2", "Ошибка 2", "Фатальна ошибка 2");
    //третье обновление
    std::cout << "<<< Обновление 3 >>>" << std::endl;
    observed_obj.set_messages("Предупреждение 3", "Ошибка 3", "Фатальна ошибка 3");

    observed_obj.RemoveObserver(&warning);
    observed_obj.RemoveObserver(&error);
    observed_obj.RemoveObserver(&fatal_error);
}
