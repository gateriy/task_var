#ifndef READ_FILE_H
#define READ_FILE_H

#include "Config.h"

template <typename text, typename data>
class Input_Output_Var
{
public:

	data InputVar(const text& A, const  data& B) {
		auto var = B;
		std::cout << text;
		std::cin >> var;
		return var;
	}

	void Output(const int& _first, const text& A, const  data& B, const text& C, const  data& D, const int& _end, const int& color) {

		for (int i = 0; i < _first; ++i) {
			std::cout << std::endl;
		}
			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		std::cout << A << B << C << D;

		for (int i = 0; i < _end; ++i) {
			std::cout << std::endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
private:

};

//С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° ini РїРѕ СЃС‚СЂРѕС‡РЅРѕ Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР° СЃС‚СЂРѕРє
class ReadFileInVector {

public:

	ReadFileInVector() {
		_InputTransformWay();
		_OupenFileWriteVector();
	}

	ReadFileInVector(const std::string& way_file) {
		this->_way_file = way_file;
		_InputTransformWay_2(_way_file);
		_OupenFileWriteVector();
	}

	~ReadFileInVector() {};

	//Р·Р°РїРѕР»РЅРµРЅРёРµ РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	std::vector<std::string> SetVector_2(const std::vector < std::string>& a);

	//РІС‹РІРѕРґ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	std::vector<std::string> GetVector_1();

	//РІС‹РІРѕРґ РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	std::vector<std::string> GetVector_2();

	//Р·Р°РїРёСЃСЊ РґР°РЅРЅС‹С… РІС‚РѕСЂРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР° РІ С„Р°Р№Р»
	bool InFileWriteVetor();

protected:
	int _x_line{};								//РїРѕРґСЃС‡РµС‚ СЃС‚СЂРѕРє РІ С„Р°Р№Р»Рµ
	std::string _x_text{}, _way_file{}, _way{};	//РїРµСЂРµРјРµРЅРЅР°СЏ СЃС‚СЂРѕРєРё, РїСѓС‚СЊ Рє С„Р°Р№Р»Сѓ
	std::vector <std::string> _in_data_file{};	//РІРµРєС‚РѕСЂ СЃС‚СЂРѕРє РёР· С„Р°Р№Р»Р°
	std::vector <std::string> _out_data_file{};	//РІРµРєС‚РѕСЂ СЃС‚СЂРѕРє РїРѕСЃР»Рµ РѕР±СЂР°Р±РѕС‚РєРё (РІС‚РѕСЂРёС‡РЅС‹Р№)

	//С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° Рё С„РѕСЂРјРёСЂРѕРІР°РЅРёРµ РїРµСЂРІРёС‡РЅРѕРіРѕ РІРµРєС‚РѕСЂР°
	bool _OupenFileWriteVector();

	//СЃС‡РёС‹РІР°РЅРёРµ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ Рё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ / РёР»Рё \ РІ "\\" РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ СЃ РєРѕРЅСЃРѕР»Рё
	void _InputTransformWay();

	//РІС‚РѕСЂРѕР№ РІР°СЂРёР°РЅ СЃС‡РёС‹РІР°РЅРёСЏ РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ Рё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ / РёР»Рё \ РІ "\\" РїСѓС‚Рё Рє С„Р°Р№Р»Сѓ СЃ РєРѕРЅСЃРѕР»Рё
	void _InputTransformWay_2(const std::string& way_text);
};

class ParsingIni : public ReadFileInVector {
public:
	
	ParsingIni() {};

	ParsingIni(const std::string& way_file) : ReadFileInVector ( way_file){	};

	~ParsingIni() {};
	
	std::pair<std::string, std::string> Str_Value_Type(const std::string& text_var);

	template<typename Y>
	const Y Get_Value( const std::string& var) {

		Str_Value_Type(var);
		try {
			if (_valu_type.second == "int") {
				auto res = std::stoll(_valu_type.first);
				//std::cout << "[" << res << "]" << typeid(res).name() << "[" << _valu_type.second << "]" << std::endl;
				return res;
			}
			else
				if (_valu_type.second == "double") {
					auto res = std::stold(_valu_type.first);
					//std::cout << "[" << res << "]" << typeid(res).name() << "[" << _valu_type.second << "]" << std::endl;
					return res;
				}			
		}
		catch (...) {
			
			//std::cout << "РќРµ РєРѕСЂРµРєС‚РЅС‹Р№ С‚РёРї РїРµСЂРµРјРµРЅРЅРѕР№ РёР»Рё РїРµСЂРµРјРµРЅРЅР°СЏ РѕС‚СЃСѓС‚СЃРІСѓРµС‚!" << std::endl;
		};
	}

	template<>
	const std::string Get_Value(const std::string& var) {
		
		Str_Value_Type(var);
		try {
			if (_valu_type.second == "string") {
				auto res = std::move(_valu_type.first);
				//std::cout << "[" << res << "]" << typeid(res).name() << "[" << _valu_type.second << "]" << std::endl;
				return res;
			}			
		}
		catch (...) {
			//std::cout << "РќРµ РєРѕСЂРµРєС‚РЅС‹Р№ С‚РёРї РїРµСЂРµРјРµРЅРЅРѕР№ РёР»Рё РїРµСЂРµРјРµРЅРЅР°СЏ РѕС‚СЃСѓС‚СЃРІСѓРµС‚!" << std::endl;
		};
	}
		
private:

	std::pair<std::string, std::string> _section_var;
	void _ReadVar(const std::string& a);
	std::pair<std::string, std::string> _valu_type{};
	
	//С„РѕСЂРјРёСЂСѓРµС‚ РЅР°Р·РІР°РЅРёРµ Рё Р·РЅР°С‡РµРЅРёРµ РїРµСЂРµРјРµРЅРЅРѕР№ РІ СЃС‚СЂРѕРєРѕРІРѕРј С„РѕСЂРјР°С‚Рµ
	std::pair <std::string, std::string> _Read_String(const std::string& var_str);

	//РѕРїСЂРµРґРµР»СЏРµС‚ РІРѕР·РјРѕР¶РЅС‹Р№ С‚РёРї РїРµСЂРµРјРµРЅРЅРѕР№ РЅР° РѕСЃРЅРѕРІРµ Р°РЅР°Р»РёР·Р° РґР°РЅРЅС‹С… РїРѕ СЃС‚СЂРѕРєРµ (string, int, double)
	std::string _Var_Type(const std::string& var);

	//СѓРґР°Р»РµРЅРёРµ РїСЂРѕР±РµР»РѕРІ РІ РЅР°Р·РІР°РЅРёРё СЃРµРєС†РёР№
	void _Transform_Section();
};

void block_1();

void block_2();

#endif;