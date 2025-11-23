//#pragma once
#ifndef COURSE_PROGECT_3_H
#define COURSE_PROGECT_3_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
#include <functional>
#include <future>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PUR "\033[35m"
#define YEL "\033[33m"

/*
Что нужно сделать:
Создать потокобезопасную очередь, хранящую функции, предназначенные для исполнения.
На основе этой очереди реализовать пул потоков.
Этот пул состоит из фиксированного числа рабочих потоков, равного количеству аппаратных ядер.
Когда у программы появляется какая-то работа, она вызывает функцию,
которая помещает эту работу в очередь.
Рабочий поток забирает работу из очереди, выполняет указанную в ней задачу,
после чего проверяет, есть ли в очереди другие работы.
Реализуемые классы


1. Класс thread_pool — реализация пула потоков.
Минимально требуемые поля класса thread_pool:

вектор потоков, которые инициализируют в конструкторе класса и уничтожают в деструкторе;
потокобезопасная очередь задач для хранения очереди работ;
остальные поля на усмотрение разработчика.
Минимально требуемые методы класса thread_pool:

метод work — выбирает из очереди очередную задачу и исполняет её.
Этот метод передаётся конструктору потоков для исполнения;
метод submit — помещает в очередь задачу. В качестве аргумента
метод может принимать или объект шаблона std::function, или объект шаблона package_task;
остальные методы на усмотрение разработчика.


2. Шаблонный класс safe_queue — реализация очереди, безопасной
относительно одновременного доступа из нескольких потоков.
Минимально требуемые поля класса safe_queue:
	очередь std::queue для хранения задач,
	::mutex для реализации блокировки,
	std::condtional_variables для уведомлений.
Минимально требуемые методы класса safe_queue:
	метод push — записывает в начало очереди новую задачу.
	При этом захватывает мьютекс, а после окончания операции
	нотифицируется условная переменная;
	метод pop — находится в ожидании, пока не придёт уведомление на условную переменную.
При нотификации условной переменной данные считываются из очереди;
остальные методы на усмотрение разработчика.


Алгоритм работы
Объявить объект класса thread_pool.
Описать несколько тестовых функций, выводящих в консоль своё имя.
Раз в секунду класть в пул одновременно 2 функции и проверять их исполнение.
*/

template <typename T>
class safe_queue
{
private:

protected:

	std::queue<T> _queue;
	std::atomic<bool> _flag_done{ false };
	std::condition_variable _flag;
	std::mutex _mutex;

public:

	void push(T item) {
		std::unique_lock<std::mutex> lock(_mutex);
		_queue.push(item);
		//std::cout << "загрузка функции-"<< std::this_thread::get_id() << std::endl;
		_flag.notify_all();
	}

	T pop() {
		std::unique_lock<std::mutex> lock(_mutex);

		_flag.wait(lock, [this] { return (!_queue.empty()); }); //фла остановки по условию

		T item;
		if (!_queue.empty()) {
			item = std::move(_queue.front());
			_queue.pop();
		}
		_flag.notify_one();
		return item;
	}
};

template <typename T>
class thread_pool : public safe_queue <std::function<void(void)>>
{
public:

	thread_pool(int aMaxThreadCount = std::thread::hardware_concurrency()) {

		std::string text{ "<<< Первичная нициализация потоков в вектор - всего потоков: " + std::to_string(aMaxThreadCount) + " >>>" };
		for (auto txt : text) {
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
			std::cout << BLUE << txt;
		}
		std::cout <<  RESET << std::endl;
			
		for (int i = 0; i < aMaxThreadCount - 1; ++i) {
			_thread_vector.emplace_back([this] { work(); });
		}

		text = "<<< Первичная инициализация завершена! >>>";
		for (auto txt : text) {
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
			std::cout << BLUE << txt;
		}
		std::cout << RESET << std::endl;		
	}

	~thread_pool() {
		safe_queue::_flag_done = true;
		
		//for (auto& worker : _thread_vector) {
			//std::cout << YEL <<"Destruction -> queue_empty = "<< safe_queue::_queue.empty() << " get_flag_done = " << safe_queue::_flag_done << " id = " << worker.get_id() << " Поток Join" << RESET << std::endl;
			//safe_queue::_flag.notify_all();
		//}

		for (auto& worker : _thread_vector) {
			worker.join();
		}
	} 

	//void submit(T& aTask) { safe_queue::push(aTask); }

	template<typename F>
	auto submit(F&& f) -> std::future<decltype(f())> {

		using return_type = decltype(f());

		auto task = std::make_shared<std::packaged_task<return_type() >> (std::forward<F>(f));

		std::future<return_type> res = task->get_future();
		safe_queue::push([task] { (*task)(); });

		return res;
	}
		
	void addFuncToPool(T func) {
		if (!safe_queue::_flag_done) {
			submit(func);
		}
		else std::this_thread::yield();
	}
		
	void work() {

		_queue_mutex.lock();
		std::cout << RESET << "Запуск рабочего потока --- id" << std::this_thread::get_id() << std::endl;
		_queue_mutex.unlock();

		while (true) {

			if (safe_queue::_flag_done && safe_queue::_queue.empty()) {
				std::cout << "<<< " << std::this_thread::get_id() << " STOP цикл >>>" << std::endl;
				break;
			}

			auto task = safe_queue::pop();
			_queue_mutex.lock();
			task();
			_queue_mutex.unlock();
		}
		std::this_thread::yield();
	}

private:
	std::mutex _queue_mutex;
	std::vector<std::thread>_thread_vector;
	std::atomic<int> _count{ 0 };
};

#endif


