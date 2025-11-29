п»ї// Task_4.cpp: РѕРїСЂРµРґРµР»СЏРµС‚ С‚РѕС‡РєСѓ РІС…РѕРґР° РґР»СЏ РїСЂРёР»РѕР¶РµРЅРёСЏ.
#include "Task_1.h"


struct Event_db {

public:

	//СЃРѕР·РґР°РЅРёРµ С‚Р°Р±Р»РёС†С‹
	void CreateTable() {
		SetConsoleOutputCP(CP_UTF8);
		pqxx::connection db = DB_conect();
		if (db.is_open()) {
			pqxx::work tx{ db };
			//СЃРѕР·РґР°РЅРёРµ С‚Р°Р±Р»РёС†С‹ - FIO_students
			tx.exec("CREATE TABLE if not exists " + table_name + "();");
			tx.commit();
		}
		else {
			SetConsoleOutputCP(1251);
			std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
		}
	}
	//РњРµС‚РѕРґ, РїРѕР·РІРѕР»СЏСЋС‰РёР№ РЅР°Р№С‚Рё РєР»РёРµРЅС‚Р° РїРѕ РµРіРѕ РґР°РЅРЅС‹Рј вЂ” РёРјРµРЅРё
	void AddWhere() {

		SetConsoleOutputCP(CP_UTF8);
		pqxx::connection db = DB_conect();
		if (db.is_open()) {

			pqxx::work tx{ db };

			pqxx::result res = tx.exec("select * from " + table_name + " where " + var.first + " = '" + var.second + "'; ");

			for (const auto& row : res) {
				for (const auto& field : row)
				{
					std::cout << field.c_str() << "\t";
				}
				std::cout << std::endl;
			}
			tx.commit();
		}
		else {
			std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
		}
		SetConsoleOutputCP(1251);
		std::cout << std::endl;
	};
	//Р·Р°РїСЂРѕСЃ РїРѕ РґРІСѓРј РїРѕ РґРІСѓРј СѓСЃР»РѕРІРёСЏРј
	void AddWheres() noexcept {

		SetConsoleOutputCP(CP_UTF8);
		pqxx::connection db = DB_conect();
		if (db.is_open()) {

			pqxx::work tx{ db };

			std::string var_x, var_s;
			bool fist_c{ true };

			for (auto& t : map_var) {
				if (fist_c) {
					var_x = " " + t.first + " = '" + t.second + "' ";
					fist_c = false;
				}
				else
				{
					var_x = var_x + if_var + " " + t.first + " = '" + t.second + "' ";
				}
			}

			std::string var_q{ "select * from " + table_name + " where " + var_x + ";" };
			//std::cout << var_q << std::endl;

			pqxx::result res = tx.exec(var_q);

			for (const auto& row : res) {
				for (const auto& field : row)
				{
					std::cout << field.c_str() << "\t";
				}
				std::cout << std::endl;
			}

			tx.commit();
		}
		else {
			std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
		}
		SetConsoleOutputCP(1251);
		std::cout << std::endl;
	};
	//РІСЃС‚Р°РІРєР° СЃС‚РѕР±С†РѕРІ
	void AddColumn() {
		SetConsoleOutputCP(CP_UTF8);

		CreateTable();
		pqxx::connection db = DB_conect();
		if (db.is_open()) {

			pqxx::work tx{ db };

			//РґРѕР±РІР»РµРЅРёРµ СЃС‚РѕР»Р±С†Р°
			tx.exec("ALTER TABLE if exists " + table_name + " ADD COLUMN if not exists " + column_name + " " + parametr + ";");

			tx.commit();
		}
		else {
			SetConsoleOutputCP(1251);
			std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
		}
	}
	//РІСЃС‚Р°РІРєР° СЃС‚РѕР±С†РѕРІ РёР· РІРµРєС‚РѕСЂР°
	void AddColumns() {

		SetConsoleOutputCP(CP_UTF8);

		for (std::string column : columns) {
			column_name = column;
			AddColumn();
		}

		SetConsoleOutputCP(1251);
	};
	//РїРµСЂРµР·Р°РїРёСЃСЊ РЅР°Р·РІР°РЅРёСЏ С‚Р°Р±Р»РёС†С‹
	void AddFrom() {
		SetConsoleOutputCP(CP_UTF8);
		pqxx::connection db = DB_conect();
		if (db.is_open()) {

			pqxx::work tx{ db };

			//РїРµСЂРµРёРјРµРЅРѕРІР°РЅРёРµ С‚Р°Р±Р»РёС†С‹ СЃ FIO_students РЅР° students
			tx.exec("ALTER TABLE if exists " + old_table_name + " RENAME TO " + new_table_name + ";");

			tx.commit();
		}
		else {
			std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
		}
		SetConsoleOutputCP(1251);
	}
	//РІС‹Р±РѕСЂ РІСЃРµРіРѕ СЃРѕРґРµСЂР¶РёРјРѕРіРѕ С‚Р°Р±Р»РёС†С‹
	void AddSelect() {
		try {
			pqxx::connection db = DB_conect();
			pqxx::work tx{ db };

			//Р•СЃР»Рё РјРµС‚РѕРґ `AddColumn` РЅРµ Р±С‹Р» РІС‹Р·РІР°РЅ, Р·Р°РїСЂРѕСЃ РЅР°С‡РёРЅР°РµРј СЃ `SELECT * ...` РІС‹Р±РѕСЂ РІСЃРµРіРѕ СЃРѕРґРµСЂР¶РёРјРѕРіРѕ С‚Р°Р±Р»РёС†С‹.
			pqxx::result res = tx.exec("select * from " + table_name + "; ");

			for (std::size_t i = 0; i < res.columns(); ++i)
			{
				std::cout << res.column_name(i) << "\t";
			}
			std::cout << std::endl;
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cerr << "РћС€РёР±РєР°: " << e.what() << std::endl;
		}
		SetConsoleOutputCP(1251);
		std::cout << std::endl;
	}
	
//======================================

	 std::string host;
	 std::string port;
	 std::string dbname;
	 std::string user;
	 std::string password;	 	
	 std::string table_name;
	 std::pair<std::string, std::string> var;
	 std::map<std::string, std::string> map_var;
	 std::string if_var;
	 std::string column_name;
	 std::string parametr;
	 std::vector<std::string> columns;
	 std::string old_table_name; 
	 std::string new_table_name;

	 private:

	 //РїРѕРґРєР»СЋС‡РµРЅРёРµ Рє Р±Р°Р·Рµ
	 pqxx::connection DB_conect() {

			 SetConsoleOutputCP(CP_UTF8);

			 try {
				 //РїРѕРґРєР»СЋС‡РµРЅРёРµ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С… test_1
				 std::string q{ "host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + password };
				 pqxx::connection db_1(q);


				 if (db_1.is_open()) {
					 return db_1;
				 }
				 else {
					 std::cout << "РќРµС‚ РїРѕРґРєР»СЋС‡РµРЅРёСЏ Рє Р±Р°Р·Рµ РґР°РЅРЅС‹С…, РїРѕРІС‚РѕСЂРёС‚Рµ Р·Р°РїСЂРѕСЃ Р·Р°РЅРѕРІРѕ!" << std::endl;
				 }
			 }
			 catch (const std::exception& e) {
				 std::cerr << "РћС€РёР±РєР°: " << e.what() << std::endl;
			 }
			 SetConsoleOutputCP(1251);
		 }
};


class EventBuilder_db {
public:

	explicit EventBuilder_db( std::string host,
							 std::string port,
							 std::string dbname,
							 std::string user,
							 std::string password) 
	{
		event_db.host = host;
		event_db.port = port;
		event_db.dbname = dbname;
		event_db.user = user;
		event_db.password = password;
	};
		
	EventBuilder_db& CreateTable(const std::string& table_name) {

		event_db.table_name = table_name;
		event_db.CreateTable();
		return *this;
	}

	EventBuilder_db& AddWhere(const std::string& table_name, const std::pair<std::string, std::string>& var) {

		event_db.table_name = table_name;
		event_db.var = var;
		event_db.AddWhere();
		return *this;
	}

	EventBuilder_db& AddWheres(const std::string& table_name, const std::map<std::string, std::string>& map_var, const std::string& if_var) {

		event_db.table_name = table_name;
		event_db.map_var = map_var;
		event_db.if_var = if_var;
		event_db.AddWheres();
		return *this;
	}

	EventBuilder_db& AddColumn(const std::string& table_name, const std::string& column_name, const std::string& parametr) {

		event_db.table_name = table_name;
		event_db.column_name = column_name;
		event_db.parametr = parametr;
		event_db.AddColumn();
		return *this;
	}

	EventBuilder_db& AddColumns(const std::string& table_name,const std::vector<std::string>& columns, const std::string& parametr) {

		event_db.table_name = table_name;
		event_db.columns = columns;
		event_db.parametr = parametr;
		event_db.AddColumns();
		return *this;
	}

	EventBuilder_db& AddFrom(const std::string& old_table_name, const std::string& new_table_name) {

		event_db.old_table_name = old_table_name;
		event_db.new_table_name = new_table_name;
		event_db.AddFrom();
		return *this;
	}

	EventBuilder_db& AddSelect(const std::string& table_name) {

		event_db.table_name = table_name;
		event_db.AddSelect();
		return *this;
	}
	
private:
	Event_db event_db;
};

//---------------------------------------------------------------------------------------------------

int main() {

	std::vector<std::string> _columns{ "a1","a2","a3","a4","a5" };
	std::pair<std::string, std::string> find_1{ "names","asd" };
	std::map<std::string, std::string> find_2{ {"id_fio","2"},{"names","asd"},{"surnames","s"},{"a5","3"} };

	EventBuilder_db builder_db("localhost", "5432", "test_1", "postgres", "1015");		
	builder_db		
		.CreateTable( "FIO_students")
		.AddFrom("FIO_students", "students")
		.AddFrom("students", "FIO_students")
		.AddColumn("FIO_students", "id_FIO", "serial primary key")
		.AddColumn("FIO_students", "names", "varchar(200)")
		.AddColumn("FIO_students", "surnames", "varchar(200)")
		.AddColumn("FIO_students", "email", "varchar(100)")
		.AddColumn("FIO_students", "telephones_cod", "varchar(5)")
		.AddColumn("FIO_students", "phone", "varchar(200)")
		.AddSelect("FIO_students")
		.AddColumns("FIO_students", _columns, "varchar(100)")
		.AddWhere("FIO_students", find_1)
		.AddWheres("FIO_students", find_2, "or")
		.AddSelect("FIO_students");
		

	//AddFrom(db, "FIO_students", "students");
	//AddSelect(db, "students");
	//std::cout << std::endl;
	//AddColumns(db, "students", _columns, "varchar(100)");
	//AddFrom(db, "students","FIO_students");
	//AddSelect(db, "FIO_students");
	//std::cout << std::endl;
	//AddColumn(db, "FIO_students", "id_FIO", "serial primary key");
	//AddColumn(db, "FIO_students", "names", "varchar(200)");
	//AddColumn(db, "FIO_students", "surnames", "varchar(200)");
	//AddColumn(db, "FIO_students", "email", "varchar(100)");
	//AddColumn(db, "FIO_students", "telephones_cod", "varchar(5)");
	//AddColumn(db, "FIO_students", "phone", "varchar(200)");
	//AddSelect(db, "FIO_students");
	//std::cout << std::endl;
	//AddWhere(db, "FIO_students", find_1);
	//std::cout << std::endl;
	//AddWheres(db, "FIO_students", find_2, "or");
}

