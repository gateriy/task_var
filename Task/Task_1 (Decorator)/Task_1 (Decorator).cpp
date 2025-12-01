// Task_1 (Decorator).cpp 

#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

/*

### Задание 1

В программу рендеринга HTML из лекции (раздел про паттерн «Декоратор») 
добавьте новые классы для декорирования текста.

class Paragraph : ...

    auto text_block = new Paragraph(new Text());
text_block->render("Hello world");

>> > <p>Hello world< / p>
```

```
class Reversed : ...

    auto text_block = new Reversed(new Text());
text_block->render("Hello world");

>> > dlrow olleH
```

```
class Link : ...

    auto text_block = new Link(new Text());
text_block->render("netology.ru", "Hello world");

>> > <a href = netology.ru>Hello world< / a>

Обратите внимание

1. Сигнатура метода `Link::render()` не совпадает с сигнатурой оригинального метода.
2. Для разворота строки используйте функцию `std::reverse` [cppreference](https://en.cppreference.com/w/cpp/algorithm/reverse).

*/

/*
### Задание 2

В дополнение к классам-заместителям `VeryHeavyDatabase`, реализованным на лекции, реализуйте класс
```
class OneShotDB : VeryHeavyDatabase {
  explicit OneShotDB (VeryHeavyDatabase* real_object, size_t shots=1) : ...
}
```
Он должен возвращать данные по ключу из реального объекта то количество раз, которое указано в конструкторе.
Исчерпав лимит получения данных, метод `GetData` всегда возвращает строку error.
Пример использования:
```
auto real_db = VeryHeavyDatabase();
auto limit_db = OneShotDB(std::addressof(real_db), 2);
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;

Output:
>>> value
>>> value
>>> error
```

*/



class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }

    virtual void render(const std::string& data_1, const std::string& data_2) const {
       // std::cout << data_1;
    }
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}

    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}

    void render(const std::string& data)  const override {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

//--->>>
class Paragraph : public DecoratedText {
public:

    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "< / p>";
    }
    // <p>Hello world< / p>
};

class Reversed : public DecoratedText {
public:

    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override {

        std::string rev_text = data;
        std::reverse(rev_text.begin(), rev_text.end());

        text_->render(rev_text);

    }
    // dlrow olleH
};

class Link : public DecoratedText {
public:

    explicit Link(Text* text ) : DecoratedText(text) {}

    void render(const std::string& data_1, const std::string& data_2) const override {

        std::cout << "<a href = ";
        text_->render(data_1);
        std::cout << ">";
        text_->render(data_2);
        std::cout << "< / a>";
    }
    // <a href = netology.ru>Hello world< / a>
};

class Text_1 : public DecoratedText {
public:
    explicit Text_1(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {

        std::cout << "< !!!S!!! > ";

        text_->render(data);

        std::cout << " < !!!S!!! >";
    }
};


//------------------------------------------------------------------------------
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    /*
    auto text_block = new ItalicText(new BoldText(new Text()));
    auto text_var_1 = new ItalicText(new BoldText(new Text_1(new Text())));
    auto text_var_2 = new Text_1(new Text());
    auto text_var_3 = new Text();


    text_block->render("Hello world");
    std::cout << std::endl;
    text_var_1->render("rrrrrrrrrrrrrrrrr");
    std::cout << std::endl;
    text_var_2->render("ddddddddddddddddddd");
    std::cout << std::endl;
    text_var_3->render("zzzzzzzz");
    */

    std::cout << "Задание 1 - декоратор" << std::endl;
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    auto text_block_1 = new Paragraph(new Text());
    text_block_1->render("Hello world");
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    auto text_block_2 = new Reversed(new Text());
    text_block_2->render("Hello world");
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    auto text_block_3 = new Link(new Text());
    text_block_3->render("netology.ru", "Hello world");
    std::cout << std::endl;
}




















