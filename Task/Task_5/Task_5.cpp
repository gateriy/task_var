п»ї// Task_5.cpp 

#include "Task_5.h"


std::string utf8_to_cp1251(std::string const& utf8)
{

	if (!utf8.empty())
	{
		int wchlen = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), NULL, 0);
		if (wchlen > 0 && wchlen != 0xFFFD)
		{
			std::vector<wchar_t> wbuf(wchlen);
			int result_u = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), &wbuf[0], wchlen);
			if (!result_u) {
				throw std::runtime_error("utf8_to_cp1251 cannot convert MultiByteToWideChar!");
			}
			std::vector<char> buf(wchlen);
			int result_c = WideCharToMultiByte(1251, 0, &wbuf[0], wchlen, &buf[0], wchlen, 0, 0);
			if (!result_c) {
				throw std::runtime_error("utf8_to_cp1251 cannot convert WideCharToMultiByte!");
			}
			return std::string(&buf[0], wchlen);
		}
	}
	return std::string();
}

std::string cp1251_to_utf8(const std::string& cp1251) {
	std::string res;
	int result_u, result_c;
	enum { CP1251 = 1251 };
	result_u = MultiByteToWideChar(CP1251, 0, cp1251.c_str(), -1, 0, 0);
	if (!result_u) {
		throw std::runtime_error("cp1251_to_utf8 cannot convert MultiByteToWideChar!");
	}
	wchar_t* ures = new wchar_t[result_u];
	if (!MultiByteToWideChar(CP1251, 0, cp1251.c_str(), -1, ures, result_u)) {
		delete[] ures;
		throw std::runtime_error("cp1251_to_utf8 cannot convert MultiByteToWideChar 2!");
	}
	result_c = WideCharToMultiByte(CP_UTF8, 0, ures, -1, 0, 0, 0, 0);
	if (!result_c) {
		delete[] ures;
		throw std::runtime_error("cp1251_to_utf8 cannot convert WideCharToMultiByte!");
	}
	char* cres = new char[result_c];
	if (!WideCharToMultiByte(CP_UTF8, 0, ures, -1, cres, result_c, 0, 0)) {
		delete[] cres;
		throw std::runtime_error("cp1251_to_utf8 cannot convert WideCharToMultiByte 2!");
	}
	delete[] ures;
	res.append(cres);
	delete[] cres;
	return res;
}

void io_db_pq::InteractiveVarTask() {

	ConsolLang1251();

	do {
		std::cout << "\033c";//РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё

		for (auto& t : var_text) {
			std::cout << t << std::endl;
		}

		VarTaskNumber();

	} while (ExitProgram());
}

bool io_db_pq::ExitProgram()
{
	char exit_Y_N{};
	do
	{
		//std::cout << std::endl;
		std::cout << "Exit programm (Y/N): ";
		std::cin >> exit_Y_N;
		std::cout << std::endl;

		if (exit_Y_N == 'Y' || exit_Y_N == 'y') {
			return false;
		}
		else if (exit_Y_N == 'N' || exit_Y_N == 'n') {
			return true;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}
	} while (true);
}

void io_db_pq::ConsolLang1251() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void io_db_pq::VarTaskNumber() {

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ Р·Р°РґР°С‡Сѓ: ";

	do {
		std::cin >> number_task;

		for (auto& n : var_numbe) {
			if (number_task == n) {
				var_correct = true;
				var_n = stoi(number_task);
				break;
			}
			else { var_correct = false; }
		};

		if (var_correct == true) {

			std::cout << "\033c";//РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё
			std::cout << "Р—Р°РґР°С‡Р°: " << var_text.at(var_n + 1) << ":" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;

			switch (var_n)
			{
			case(0):
				std::cout << "\033c";//РѕС‡РёСЃС‚РєР° РєРѕРЅСЃРѕР»Рё
				exit = false;
				break;
			case(1):
				method_1();
				exit = false;
				break;
			case(2):
				method_2();
				exit = false;
				break;
			case(3):
				method_3();
				exit = false;
				break;
			case(4):
				method_4();
				exit = false;
				break;
			case(5):
				method_5();
				exit = false;
				break;
			case(6):
				method_6();
				exit = false;
				break;
			case(7):
				method_7();
				exit = false;
				break;
			case(8):
				method_8();
				exit = false;
				break;
			case(9):
				method_9();
				exit = false;
				break;
			case(10):
				method_10();
				exit = false;
				break;
			case(11):
				method_11();
				exit = false;
				break;
			case(12):
				method_12();
				exit = false;
				break;
			}
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			std::cout << std::endl;
			continue;
		}
	} while (exit);
}

void io_db_pq::check_str_to_int(std::string& text) {

	bool good{ false };
	do {
		for (const auto& t : text) {
			good = false;
			for (const auto& v : std::string{ "0123456789" }) {
				if (t == v) {
					good = true;
					break;
				}
			}
			if (good == false) { break; }
		}
		if (good == false) {
			std::cout << "Р’РІРµРґРµРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ РЅРµ С†РµР»РѕРµ С‡РёСЃР»Рѕ, РїРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ!" << std::endl;
			std::cout << "Р’РІРµРґРёС‚Рµ РЅРѕРІРѕРµ Р·РЅР°С‡РµРЅРёРµ: " << std::endl;
			std::cin >> text;
		}
	} while (good == false);
};

//---------------------
class publisher_tabl {
public:
	std::string name;
	//std::string phone = "";
	//int karma = 0;
	template<class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		//Wt::Dbo::field(a, phone, "phone");
		//Wt::Dbo::field(a, karma, "karma");
	}
};

class shop_tabl {
public:
	std::string name = "";
	template<class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
	}
};

class User {
public:
	std::string name = "";
	std::string phone = "";
	int karma = 0;
	template<class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::field(a, phone, "phone");
		Wt::Dbo::field(a, karma, "karma");
	}
};

//---------------------

//СЃРѕР·РґР°РЅРёРµ СЃС‚СЂСѓРєС‚СѓСЂС‹ Р±Р°Р·С‹ РґР°РЅРЅС‹С… (С‚Р°Р±Р»РёС†)
void io_db_pq::method_1() {

	//SetConsoleOutputCP(CP_UTF8);

	std::string connectionString = "host=localhost user=postgres password=1015 port=5433 dbname=test_2";
	
	//"host=127.0.0.1 user=test password=test port=5432 dbname=test"
	
	//Wt::Dbo::backend::Postgres::Postgres( "test_1");
	//auto postgres = Wt::Dbo::backend::Postgres(connectionString);
	//postgres.connect(connectionString);
	//postgres.executeSql("pg_isready -d test_1 -h localhost -p 5432 -U postgres");

	
	auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
	Wt::Dbo::Session session;
	session.setConnection(std::move(postgres));



	//Wt::Dbo::Transaction transaction(session);
	session.execute("select 1;");
	//session.execute("create table if not exists publisher_tabl (names varchar(200) not null,unique(names)); ");

	

		//session.execute("SET CLIENT_ENCODING TO 'WIN1251';"); // РєРѕСЃС‚С‹Р»СЊ РґР»СЏ РѕС‚РїСЂР°РІРєРё СЂСѓСЃСЃРєРёС… СЃРёРјРІРѕР»РѕРІ РІ Р‘Р”
		//session.mapClass<publisher_tabl>("publisher_tabl");
		//session.mapClass<shop_tabl>("shop_tabl");		
		//session.createTables();
		std::cout << "РўР°Р±Р»РёС†Р° 'publisher_tabl' СЃРѕР·РґР°РЅР° РёР»Рё СѓР¶Рµ СЃСѓС‰РµСЃС‚РІСѓРµС‚." << std::endl;
	
	
	{
		//Wt::Dbo::Transaction transaction(session);
		//auto newRecord = session.add(std::make_unique<publisher_tabl>(publisher_tabl{ "РђСЂРєР°РґРёР№" }));
		//std::cout << "Р—Р°РїРёСЃСЊ РґРѕР±Р°РІР»РµРЅР°: name = " << newRecord->name
		//	<< ", value = "  << std::endl;
		//transaction.commit();
	}

	//session.mapClass<publisher_tabl>("publisher_tabl");
	//session.mapClass<shop_tabl>("shop_tabl");

	//session.createTables();
	


	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };

		tx.exec(
			"create table if not exists FIO"
			"(id_FIO serial primary key,"
			"names varchar(200) not null,"
			"surnames varchar(200) not null,"
			"email varchar(100) not null,"
			"unique(names, surnames, email));"

			"create table if not exists telephone"
			"(id_telephone serial primary key,"
			"id_FIO integer not null references FIO(id_FIO),"
			"telephones_cod varchar(5),"
			"telephones numeric(15, 0),"
			"unique(id_FIO, telephones_cod, telephones));"
		);
		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//СЃРѕР·РґР°РЅРёРµ РЅРѕРІРѕРіРѕ РєР»РёРµРЅС‚Р° Р±РµР· С‚РµР»РµС„РѕРЅР°
void io_db_pq::method_2() {

	std::string var, names, surnames, email;
	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	names = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С„Р°РјРёР»РёСЋ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	surnames = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ email РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	email = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };
		db_1.prepare("insert_1", "insert into FIO (names, surnames, email) VALUES($1, $2, $3)");
		tx.exec_prepared("insert_1", names, surnames, email);
		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//РІРІРѕРґ С‚РµР»РµС„РѕРЅР° РґР»СЏ СЃСѓС‰РµСЃС‚РІСѓСЋС‰РµРіРѕ РєР»РёРµРЅС‚Р°
void io_db_pq::method_3() {

	std::string var, names, surnames, email, telephones_cod, telephones;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	names = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С„Р°РјРёР»РёСЋ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	surnames = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ email РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	email = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ РєРѕРґ С‚РµР»РµС„РѕРЅР° РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	telephones_cod = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С‚РµР»РµС„РѕРЅ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	check_str_to_int(var);
	telephones = cp1251_to_utf8(var);

	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };
		tx.exec("insert into telephone(id_FIO, telephones_cod, telephones) VALUES((select f.id_fio from fio as F where f.names = '" + names + "' and f.surnames = '" + surnames + "' and f.email = '" + email + "'),'" + telephones_cod + "'," + telephones + ");");
		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//РёР·РјРµРЅРµРЅРёРµ РґР°РЅРЅС‹С… Рѕ РєР»РёРµРЅС‚Рµ
void io_db_pq::method_4() {

	std::string var, names, surnames, email, names_n, surnames_n, email_n;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ РєР»РёРЅС‚Р°: ";
	std::cin >> var;
	names = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С„Р°РјРёР»РёСЋ РєР»РёРЅС‚Р°: ";
	std::cin >> var;
	surnames = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ email РєР»РёРЅС‚Р°: ";
	std::cin >> var;
	email = cp1251_to_utf8(var);
	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РЅРѕРІРѕРµ РёРјСЏ РєР»РёРЅС‚Р°: ";
	std::cin >> var;
	names_n = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ РЅРѕРІСѓСЋ С„Р°РјРёР»РёСЋ РєР»РёРЅС‚Р°: ";
	std::cin >> var;
	surnames_n = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ РЅРѕРІС‹Р№ email РєР»РёРЅС‚Р°: ";
	std::cin >> var;
	email_n = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };
		tx.exec("update fio as F set names ='" + tx.esc(names_n) + "', surnames = '" + tx.esc(surnames_n) + "', email = '" + tx.esc(email_n) +
			"'where f.id_fio = (select f.id_fio from fio as F where f.names = '" + tx.esc(names) + "' and f.surnames = '" + tx.esc(surnames) + "' and f.email = '" + tx.esc(email) + "');");
		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//СѓРґР°Р»РµРЅРёРµ С‚РµР»РµС„РѕРЅР° Р·Р°РґР°РЅРЅРѕРіРѕ РєР»РёРµРЅС‚Р°
void io_db_pq::method_5() {
	std::string var, names, surnames, email, telephones_cod, telephones;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	names = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С„Р°РјРёР»РёСЋ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	surnames = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ email РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	email = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ РєРѕРґ С‚РµР»РµС„РѕРЅР° РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	telephones_cod = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С‚РµР»РµС„РѕРЅ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	check_str_to_int(var);
	telephones = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };
		tx.exec("delete from telephone t where t.id_fio = (select f.id_fio from fio as F where f.names = '" + tx.esc(names) + "' and f.surnames = '" + tx.esc(surnames) + "' and f.email = '" + tx.esc(email) + "') and (telephones_cod = '" + tx.esc(telephones_cod) + "' and telephones = " + tx.esc(telephones) + "); ");
		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//СѓРґР°Р»РµРЅРёРµ РєР»РёРµРЅС‚Р° РїРѕР»РЅРѕСЃС‚СЊСЋ
void io_db_pq::method_6() {

	std::string var, names, surnames, email;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	names = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С„Р°РјРёР»РёСЋ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	surnames = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ email РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	email = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };
		tx.exec("delete from telephone t where t.id_fio = (select f.id_fio from fio as F where f.names = '" + tx.esc(names) + "' and f.surnames = '" + tx.esc(surnames) + "' and f.email = '" + tx.esc(email) + "'); ");
		tx.exec("delete from fio f where f.id_fio = (select f.id_fio from fio as F where f.names = '" + tx.esc(names) + "' and f.surnames = '" + tx.esc(surnames) + "' and f.email = '" + tx.esc(email) + "'); ");
		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//РњРµС‚РѕРґ, РїРѕР·РІРѕР»СЏСЋС‰РёР№ РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ РµРіРѕ РґР°РЅРЅС‹Рј вЂ” РёРјРµРЅРё
void io_db_pq::method_7() {

	std::string var, names, surnames, email, telephones_cod, telephones;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	names = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };

		for (auto [id_fio, names, surnames, email] : tx.query<int, std::string, std::string, std::string>(
			"select id_fio, names, surnames, email  from fio where names = '" + tx.esc(names) + "';"))
		{
			std::cout << id_fio << "\t\t" << names << " \t\t" << surnames << "\t\t" << email << ".\n";
		}
		std::cout << std::endl;

		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//РњРµС‚РѕРґ, РїРѕР·РІРѕР»СЏСЋС‰РёР№ РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ РµРіРѕ РґР°РЅРЅС‹Рј вЂ” С„Р°РјРёР»РёРё
void io_db_pq::method_8() {

	std::string var, names, surnames, email, telephones_cod, telephones;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ С„Р°РјРёР»РёСЋ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	surnames = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };

		for (auto [id_fio, names, surnames, email] : tx.query<int, std::string, std::string, std::string>(
			"select id_fio, names, surnames, email  from fio where surnames = '" + tx.esc(surnames) + "';"))
		{
			std::cout << id_fio << "\t\t" << names << " \t\t" << surnames << "\t\t" << email << ".\n";
		}
		std::cout << std::endl;

		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//РњРµС‚РѕРґ, РїРѕР·РІРѕР»СЏСЋС‰РёР№ РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ РµРіРѕ РґР°РЅРЅС‹Рј вЂ” email
void io_db_pq::method_9() {

	std::string var, names, surnames, email, telephones_cod, telephones;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ email РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	email = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };

		for (auto [id_fio, names, surnames, email] : tx.query<int, std::string, std::string, std::string>(
			"select id_fio, names, surnames, email  from fio where email = '" + tx.esc(email) + "';"))
		{
			std::cout << id_fio << "\t\t" << names << " \t\t" << surnames << "\t\t" << email << ".\n";
		}
		std::cout << std::endl;

		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//РњРµС‚РѕРґ, РїРѕР·РІРѕР»СЏСЋС‰РёР№ РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ РµРіРѕ РґР°РЅРЅС‹Рј вЂ” С‚РµР»РµС„РѕРЅСѓ.
void io_db_pq::method_10() {

	std::string var, names, surnames, email, telephones_cod, telephones;

	std::cout << std::endl;
	std::cout << "Р’РІРµРґРёС‚Рµ РєРѕРґ С‚РµР»РµС„РѕРЅР° РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	telephones_cod = cp1251_to_utf8(var);
	std::cout << "Р’РІРµРґРёС‚Рµ С‚РµР»РµС„РѕРЅ РєР»РёРµРЅС‚Р°: ";
	std::cin >> var;
	check_str_to_int(var);
	telephones = cp1251_to_utf8(var);
	std::cout << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };

		//select id_fio, names, surnames, email  from fio
		//where id_FIO = (select t.id_fio from telephone as t where t.telephones_cod = '+7' and t.telephones = 9055774730);

		for (auto [id_fio, names, surnames, email] : tx.query<int, std::string, std::string, std::string>(
			"select id_fio, names, surnames, email  from fio where id_FIO = (select t.id_fio from telephone as t where t.telephones_cod = '" + tx.esc(telephones_cod) + "' and t.telephones = " + tx.esc(telephones) + ");"))
		{
			std::cout << id_fio << "\t\t" << names << " \t\t" << surnames << "\t\t" << email << ".\n";
		}
		std::cout << std::endl;

		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);

};

//СѓРґР°Р»РµРЅРёРµ Р±Р°Р·С‹ РґР°РЅРЅС‹С… (С‚Р°Р±Р»РёС†)
void io_db_pq::method_11() {

	SetConsoleOutputCP(CP_UTF8);
	/*
	pqxx::connection db_1(
		"host=localhost "
		"port=5432 "
		"dbname=test_1 "
		"user=postgres "
		"password=1015");

	if (db_1.is_open()) {

		pqxx::work tx{ db_1 };

		tx.exec("drop table telephone, fio;");

		tx.commit();
	}
	else {
		std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
	}
	*/
	SetConsoleOutputCP(1251);
};

//Р·Р°РїР°СЃ
void io_db_pq::method_12() {};

//-------------------------------------------
int main()
{
	bool check = true;
	std::string v_x{ "y" };

	do {
		try {


			io_db_pq io_db_pq_1;
			io_db_pq_1.InteractiveVarTask();
			check = true;
		}
		
		catch (const Wt::Dbo::Exception& e) {
			std::cerr << e.what() << std::endl;
			SetConsoleOutputCP(1251);
			std::cout << "РџСЂРѕРґРѕР»Р¶РёС‚СЊ РІРІРѕРґ? (y/n): ";
			std::cin >> v_x;
			if (v_x == "n") {
				check = true;
			}
			else {
				check = false;
			}

		}
		
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			SetConsoleOutputCP(1251);
			std::cout << "РџСЂРѕРґРѕР»Р¶РёС‚СЊ РІРІРѕРґ? (y/n): ";
			std::cin >> v_x;
			if (v_x == "n") {
				check = true;
			}
			else {
				check = false;
			}
		}
	} while (!check);

	return 0;
}


