#include "Read_file.h"

//С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° ini РїРѕ СЃС‚СЂРѕС‡РЅРѕ Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР° СЃС‚СЂРѕРє
//С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР° СЃС‚СЂРѕРє
bool ReadFileInVector::_OupenFileWriteVector() {

		_in_data_file.clear();
		bool good = false;

		try {
			do {
				
				_x_line = 0;
				
				std::ifstream  f_in(_way); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° С‡С‚РµРЅРёРµ
				
				if (f_in.is_open()) {

					do {				
						getline(f_in >> std::ws, _x_text);
						++_x_line; //РїСЂРѕС…РѕРґ РїРѕ С„Р°Р№Р»Сѓ РІ СЂРµР¶РёРјРµ СЃС‡РёС‚С‹РІР°РЅРёСЏ Рё РїРѕРґСЃС‡РµС‚ СЃС‚СЂРѕРє
					} while (!f_in.eof());

					f_in.clear(); //РѕС‡РёСЃС‚РєР° РїРѕС‚РѕРєР° РІРІРѕРґР° РёР· С„Р°Р№Р»Р°
					f_in.seekg(0, std::ios::beg);//РІРѕР·РІСЂР°С‚ РєСѓСЂСЃРѕСЂР° РІ РЅР°С‡Р°Р»Рѕ С„Р°Р№Р»Р°

					for (int i = 0; i < _x_line; ++i) {	
						_x_text.clear();
						getline(f_in >> std::ws, _x_text);
						if (!_x_text.empty()) {
							_in_data_file.push_back(_x_text);
						}
					};

					f_in.close();
					good = true;
					break;
				}
				else {
					std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ РёР»Рё РЅРµ РґРѕСЃС‚СѓРїРµРЅ! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
					_InputTransformWay();
				}
			} while (true);

		} catch (...) {
			std::cout << "РќРµ РёР·РІРµСЃС‚РЅР°СЏ РѕС€РёР±РєР°!" << std::endl;
			good = false;
		}
		return good;
	}

//Р·Р°РїРѕР»РЅРµРЅРёРµ РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
std::vector<std::string> ReadFileInVector::SetVector_2(const std::vector < std::string>& a) {

		if (!a.empty()) {
			_out_data_file.clear();

			for (const auto& i : a) {
				_out_data_file.push_back(i);
			}
		}
		return _out_data_file;
	}

//РІС‹РІРѕРґ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
std::vector<std::string> ReadFileInVector::GetVector_1() { return _in_data_file; }

//РІС‹РІРѕРґ РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
std::vector<std::string> ReadFileInVector::GetVector_2() { return _out_data_file;	}

//Р·Р°РїРёСЃСЊ РґР°РЅРЅС‹С… РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР° РІ С„Р°Р№Р»
bool ReadFileInVector::InFileWriteVetor() {
		_InputTransformWay();
		bool good = false;
		try {
			do {
				std::ofstream  f_oupen(_way); // РѕС‚РєСЂС‹Р»Рё С„Р°Р№Р» РїРѕ Р·Р°РґР°РЅРЅРѕРјСѓ РїСѓС‚Рё РЅР° Р·Р°РїРёСЃСЊ
				if (f_oupen.is_open()) {

					for (const auto& i : _out_data_file) {
						f_oupen << i << std::endl;
					};

					f_oupen.close();
					good = true;
					break;
				}
				else {
					std::cout << "Р¤Р°Р№Р» РЅРµ РЅР°Р№РґРµРЅ РёР»Рё РЅРµС‚ РґРѕСЃС‚СѓРїР°! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ." << std::endl;
				}
			} while (true);
		}
		catch(...) {
			std::cout << "РќРµ РёР·РІРµСЃС‚РЅР°СЏ РѕС€РёР±РєР°!" << std::endl;
				good = false;
		}
		return good;
	}

//СЃС‡РёС‹РІР°РЅРёРµ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ Рё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ / РёР»Рё \ РІ "\\" РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ СЃ РєРѕРЅСЃРѕР»Рё
void ReadFileInVector::_InputTransformWay() {
	_way.clear();
	std::string way_file{ "" };

		std::cout << "Р’РІРµРґРёС‚Рµ РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ (РµСЃР»Рё С„Р°Р№Р» РЅРµ РІ РєРѕСЂРЅРµРІРѕРј РєР°С‚Р°Р»РѕРіРµ РїСЂРѕРіСЂР°РјРјС‹): ";
		getline(std::cin >> std::ws, way_file);

		for (auto& ch : way_file) {

			if (ch == '\\' || ch == '/') {

				_way = _way + '\\' + '\\';
			}
			else {
				_way = _way + ch;
			}
		}
	}

//РІС‚РѕСЂРѕР№ РІР°СЂРёР°РЅ СЃС‡РёС‹РІР°РЅРёСЏ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ Рё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ / РёР»Рё \ РІ "\\" РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ СЃ РєРѕРЅСЃРѕР»Рё
void ReadFileInVector::_InputTransformWay_2(const std::string& way_text) {
	_way.clear();
	
	for (auto& ch : way_text) {

		if (ch == '\\' || ch == '/') {

			_way = _way + '\\' + '\\';
		}
		else {
			_way = _way + ch;
		}
	}	 
}

//РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ РїРµСЂРµРјРµРЅРЅС‹С… СЃРµРєС†РёРё Рё РїРµСЂРµРµРјРµРЅРЅРѕР№ 
void ParsingIni::_ReadVar(const std::string& a) {
	bool first = true;
	_section_var.first.clear();
	_section_var.second.clear();

	for (const auto& text_v : a) {

		if (text_v == '.') {
			first = false;
		}

		if (text_v != '.' && first == true) {
			_section_var.first = _section_var.first + text_v;
		}
		if (text_v != '.' && first == false) {
			_section_var.second = _section_var.second + text_v;
		}
	}
}

//С„РѕСЂРјРёСЂСѓРµС‚ РЅР°Р·РІР°РЅРёРµ Рё Р·РЅР°С‡РµРЅРёРµ РїРµСЂРµРјРµРЅРЅРѕР№ РІ СЃС‚СЂРѕРєРѕРІРѕРј С„РѕСЂРјР°С‚Рµ
std::pair <std::string, std::string> ParsingIni::_Read_String(const std::string& var_str) {
	std::string name{}, var{};
	bool first = true;

	for (const auto& i : var_str) {
		if (i != ';') {

			if (first == false) { var = var + i; }

			if (i != '=' && first == true) {
				name = name + i;
			}
			else { first = false; }
		}
		else break;
	}

	for (auto& i : name) {
		if (name.back() == ' ') { name.pop_back(); }
		else break;
	}
	for (auto& i : var) {
		if (var.back() == ' ') { var.pop_back(); }
		else break;
	}
	return { {name},{var} };
}

//РѕРїСЂРµРґРµР»СЏРµС‚ РІРѕР·РјРѕР¶РЅС‹Р№ С‚РёРї РїРµСЂРµРјРµРЅРЅРѕР№ РЅР° РѕСЃРЅРѕРІРµ Р°РЅР°Р»РёР·Р° РґР°РЅРЅС‹С… РїРѕ СЃС‚СЂРѕРєРµ (string, int, double)
std::string ParsingIni::_Var_Type(const std::string& var) {
	int count_point{ 0 }, count_min{ 0 };
	bool str = false;

	if (!var.empty()) {
		for (const auto& i : var) {
			str = true;
			for (const char& f : { '-','0','1','2','3','4','5','6','7','8','9','0','.' }) {

				if (i == f) {
					str = false;
					break;
				}
			}
			if (i == '.') { ++count_point; }
			if (i == '-') { ++count_min; }

			if (str == true) { return "string"; }
		}

		if (str == false) {

			if (count_min == 0 || (count_min == 1 && var.at(0) == '-')) {

				if (count_point == 1) { return "double"; }
				else if (count_point == 0) { return "int"; }
				else { return "string"; }
			}
			else { return "string"; }
		}
	}
	else { return "no data available!"; }
}

//РЅР°С…РѕРґРёС‚ РїРµСЂРµРјРµРЅРЅСѓСЋ РїРѕ Р·Р°РїСЂРѕСЃСѓ Рё РІС‹РґР°РµС‚ РµРµ Р·РЅР°С‡РµРЅРёРµ Рё С‚РёРї РЅР° РѕСЃРЅРѕРІРµ Р°РЅР°Р»РёР·Р° СЃС‚СЂСѓРєС‚СѓСЂС‹ РїРµСЂРµРјРµРЅРЅРѕР№ РІ РІРёРґРµ string
std::pair<std::string, std::string> ParsingIni::Str_Value_Type(const std::string& text_var) {

	_ReadVar(text_var);
	std::string res{}, type_x{};;
	bool begin_section = false;
	bool find_section = false;
	bool first = false;

	if (!_in_data_file.empty()) {

		_Transform_Section();

		for (const auto& str_var : _in_data_file) {

			if (str_var == ('[' + _section_var.first + ']')) {
				//std::cout << "<<< РЎРµРєС†РёСЏ РЅР°Р№РґРµРЅР°! >>>" << std::endl;
				begin_section = true;
				find_section = true;
			}
			else {
				if (begin_section == true) {
					if ((str_var.at(0) == '[') && (str_var != ('[' + _section_var.first + ']'))) {
						begin_section = false;
						//std::cout << "<<< РЎРµРєС†РёСЏ Р·Р°РІРµСЂС€РµРЅР°! >>>" << std::endl;
					}
					else {

						if (_section_var.second == _Read_String(str_var).first) {
							res = _Read_String(str_var).second;
							type_x = _Var_Type(_Read_String(str_var).second);
							first = true;
						}
					}
				}
			}
		}
		if (first == false && find_section==true) {
			std::cout << "РџРµСЂРµРјРµРЅРЅР°СЏ РЅРµ РЅР°Р№РґРµРЅР°! РЎРїРёСЃРѕРє РІСЃРµС… РїРµСЂРµРјРµРЅРЅС‹С… СЃРµРєС†РёРё:" << std::endl;
			for (const auto& str_var : _in_data_file) {

				if (str_var == ('[' + _section_var.first + ']')) {
					//std::cout << "<<< РЎРµРєС†РёСЏ РЅР°Р№РґРµРЅР°! >>>" << std::endl;
					begin_section = true;
				}
				else {
					if (begin_section == true) {
						if ((str_var.at(0) == '[') && (str_var != ('[' + _section_var.first + ']'))) {
							begin_section = false;
							//std::cout << "<<< РЎРµРєС†РёСЏ Р·Р°РІРµСЂС€РµРЅР°! >>>" << std::endl;
						}
						else {
							if (_Read_String(str_var).first != "") {
								std::cout << "? >>> [" << _Read_String(str_var).first << "] = ["
									<< _Read_String(str_var).second << "]" << std::endl;									
							}
						}
					}
				}
			}
		}
		if ( find_section == false) {
			std::cout << "РЎРµРєС†РёСЏ РЅРµ РЅР°Р№РґРµРЅР°! РЎРїРёСЃРѕРє РІСЃРµС… РїРµСЂРµРјРµРЅРЅС‹С… Рё СЃРµРєС†РёР№:" << std::endl;
			for (const auto& str_var : _in_data_file) {
				
				if (!_Read_String(str_var).first.empty()) {
					std::cout << "? >>> " << _Read_String(str_var).first;
					if (!_Read_String(str_var).second.empty()) {
						std::cout << " = [" << _Read_String(str_var).second << "]";
					}
					std::cout << std::endl;
				}
										
			}
		}
	}

	if (res == "" && first==true)
	{
		_valu_type = { {res},{"no data available!"} };
	}
	else
	{
		_valu_type = { {res},{type_x} };
	}
	return _valu_type;
}

//СѓРґР°Р»РµРЅРёРµ РїСЂРѕР±РµР»РѕРІ РІ РЅР°Р·РІР°РЅРёРё СЃРµРєС†РёР№
void ParsingIni::_Transform_Section() {
	std::string text{ "" };
	bool begin_x = false;

	for (auto& i : _in_data_file) {
		begin_x = false;
		text.clear();

		for (auto& x : i) {

			if (x == '[') { begin_x = true; }

			if (begin_x == true) {

				text = text + x;

			}
			if (x == ']') { break; }
		}
		if (begin_x == true) { i = text; }
	}
}


//----------------------------------------------------------------------------------------------
// D:\РЎ++\Project\VSC\prj_netologiy_yandex\Course_1\Cours_parsing_ini\data_x.ini

void block_1() {

	Input_Output_Var<std::string, std::string> i_o_str;	
	ParsingIni parser("data_x.ini");

	do {
		std::string text_var;
		std::cout << "Р’РµРґРёС‚Рµ РїРµСЂРµРјРµРЅРЅСѓСЋ РІ С„РѕСЂРјР°С‚Рµ SectionX.varY: ";
		std::cin >> text_var;
		std::string res = parser.Str_Value_Type(text_var).second;


		if (res == "int") {
			auto s = parser.Get_Value<long long int>(text_var); //С„РѕСЂРјР°С‚ РєР°Рє РІ Р·Р°РґР°РЅРёРё!!!!
			std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
		}
		else if (res == "double") {
			auto s = parser.Get_Value<long double>(text_var);//С„РѕСЂРјР°С‚ РєР°Рє РІ Р·Р°РґР°РЅРёРё!!!!
			std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
		}
		else if (res == "string") {
			auto s = parser.Get_Value<std::string>(text_var);//С„РѕСЂРјР°С‚ РєР°Рє РІ Р·Р°РґР°РЅРёРё!!!!
			std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
		}
		else {
			std::cout << "Р”Р°РЅРЅС‹Рµ РІ Р·Р°РґР°РЅРЅРѕР№ РїРµСЂРµРјРµРЅРЅРѕР№ РѕС‚СЃСѓС‚СЃС‚РІСѓСЋС‚! Р—Р°РґР°Р№С‚Рµ РёРЅРѕРµ РёРјСЏ РїРµСЂРµРјРµРЅРЅРѕР№ РёР»Рё СЃРµРєС†РёРё!" << std::endl;
		}
		std::cout << "Р’РµСЃС‚Рё РґР°РЅРЅС‹Рµ Р·Р°РЅРѕРІРѕ? (0 - РґР°): ";
		char var_y{ '1'};
		std::cin >> var_y;
		if (var_y != '0') { break; }
	} while (true);

};

void block_2() {

	Input_Output_Var<std::string, int> i_o_var;
	ParsingIni parser;

	do {
		std::string text_var;
		std::cout << "Р’РµРґРёС‚Рµ РїРµСЂРµРјРµРЅРЅСѓСЋ РІ С„РѕСЂРјР°С‚Рµ SectionX.varY: ";
		std::cin >> text_var;
		std::string res = parser.Str_Value_Type(text_var).second;


		if (res == "int") {
			auto s = parser.Get_Value<long long int>(text_var);//С„РѕСЂРјР°С‚ РєР°Рє РІ Р·Р°РґР°РЅРёРё!!!!
			std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
		}
		else if (res == "double") {
			auto s = parser.Get_Value<long double>(text_var);//С„РѕСЂРјР°С‚ РєР°Рє РІ Р·Р°РґР°РЅРёРё!!!!
			std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
		}
		else if (res == "string") {
			auto s = parser.Get_Value<std::string>(text_var);//С„РѕСЂРјР°С‚ РєР°Рє РІ Р·Р°РґР°РЅРёРё!!!!
			std::cout << "[" << s << "] <- [" << typeid(s).name() << "]" << std::endl;
		}
		else {
			std::cout << "Р”Р°РЅРЅС‹Рµ РІ Р·Р°РґР°РЅРЅРѕР№ РїРµСЂРµРјРµРЅРЅРѕР№ РѕС‚СЃСѓС‚СЃС‚РІСѓСЋС‚! Р—Р°РґР°Р№С‚Рµ РёРЅРѕРµ РёРјСЏ РїРµСЂРµРјРµРЅРЅРѕР№ РёР»Рё СЃРµРєС†РёРё!" << std::endl;
		}
		std::cout << "Р’РµСЃС‚Рё РґР°РЅРЅС‹Рµ Р·Р°РЅРѕРІРѕ? (0 - РґР°): " ;
		char var_y{ '1' };
		std::cin >> var_y;
		if (var_y != '0') { break; }
	} while (true);

};