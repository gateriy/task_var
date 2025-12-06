п»ї// Task_1 (command).cpp 

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>


class ElectronicDevice {
private:
    std::string _name;
public:

    ElectronicDevice(std::string name) : _name(name){}

    void turn_on() {
        std::cout << _name << " is now ON" << std::endl;
    }

    void turn_off() {
        std::cout << _name << " is now OFF" << std::endl;
    }
};

class Command
{
public:
    virtual void execute() = 0;
};

class TurnOnCommand :public Command
{        
     ElectronicDevice& _device;

 public:   

     TurnOnCommand(ElectronicDevice& device) : _device(device) {}

     void execute() override
     {
         _device.turn_on();
     }
};

class TurnOffCommand :public Command
{
    ElectronicDevice& _device;

public:

    TurnOffCommand(ElectronicDevice& device) : _device(device) {}
    void execute() override
    {
        _device.turn_off();
    }
};

class RemoteControl
{
    std::vector<Command*> _commands;

public:
    void add_command(Command* command)
    {
        _commands.push_back(command);
    }

    void press_button(size_t slot)
    {
        if (slot <= _commands.size() && !_commands.empty())
        {
            _commands[slot]->execute();
        }
    }

    void clear_command() 
    {
        _commands.clear();
    }
};

//---------------------------------

class LogDevice {
    
public:

   // LogDevice(std::string name) : _name(name) {}
    LogDevice() {};

    void message_console() {
        std::cout << "messag -> " << _name << std::endl;
    }

    void message_file() {
        std::cout << "file -> " << _name << std::endl;

        std::ofstream  f_oupen("D:\\РЎ++\\Project\\VSC\\prj_netologiy_yandex\\Pattern\\Task_3\\file_1.txt", std::ios::app); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° Р·Р°РїРёСЃСЊ
        if (f_oupen.is_open()) 
        {
            f_oupen << _name << std::endl;            
            f_oupen.close();
            std::cout << "Р¤Р°Р№Р» СѓСЃРїРµС€РЅРѕ Р·Р°РїРёСЃР°РЅ!" << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
        }
    }    
    std::string _name;
};

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class MessageCommand :public LogCommand
{
    LogDevice& _log_device;

public:
    MessageCommand(LogDevice& device) : _log_device(device) {}

    void print(const std::string& message) override
    {
        _log_device._name = message;
        _log_device.message_console();
    }
};

class FileCommand :public LogCommand
{
    LogDevice& _log_device;

public:
    FileCommand(LogDevice& device) : _log_device(device) {}

    void print(const std::string& message) override
    {
        _log_device._name = message;        
        _log_device.message_file();
    }
};

class RemoteControlLog
{
    std::vector<LogCommand*> _commands;

public:
    void add_command(LogCommand* command)
    {
        _commands.push_back(command);
    }

    void press_button(size_t slot, const std::string message)
    {
        if (slot <= _commands.size() && !_commands.empty())
        {
            _commands[slot]->print(message);
        }
    }

    void clear_command()
    {
        _commands.clear();
    }
};

//---------------------------------

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "------------------_Task_1------------------" << std::endl;
    LogDevice mes;
    LogDevice fil;

    RemoteControlLog remote_log;

    remote_log.add_command(new FileCommand(fil));
    remote_log.add_command(new FileCommand(fil));
    remote_log.add_command(new MessageCommand(mes));
    remote_log.add_command(new MessageCommand(mes));

    remote_log.press_button(0, "Text in file 1");
    remote_log.press_button(1, "Text in file 2");
    remote_log.press_button(2, "message - text 1");
    remote_log.press_button(3, "message - text 2");

    std::cout << "--------------------------------------------" << std::endl;
  
    ElectronicDevice TV("TV");
    ElectronicDevice Radio("Radio");
    RemoteControl remote;
    remote.add_command(new TurnOnCommand(TV));
    remote.add_command(new TurnOnCommand(Radio));
    remote.add_command(new TurnOffCommand(TV));
    remote.add_command(new TurnOffCommand(Radio));
    remote.press_button(0);
    remote.press_button(2);
    remote.press_button(1);
    remote.press_button(3);
    remote.press_button(0);
    remote.press_button(1);
    remote.press_button(2);
    remote.press_button(3);

    remote.clear_command();
}

