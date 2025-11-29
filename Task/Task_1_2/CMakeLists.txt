п»ї# CMakeList.txt: РїСЂРѕРµРєС‚ CMake РґР»СЏ Task_4; РІРєР»СЋС‡РёС‚Рµ РёСЃС…РѕРґРЅС‹Р№ РєРѕРґ Рё РѕРїСЂРµРґРµР»РµРЅРёСЏ,
# СѓРєР°Р¶РёС‚Рµ Р·РґРµСЃСЊ Р»РѕРіРёРєСѓ РґР»СЏ РєРѕРЅРєСЂРµС‚РЅРѕРіРѕ РїСЂРѕРµРєС‚Р°.
#
cmake_minimum_required (VERSION 3.20)

# Р’РєР»СЋС‡РµРЅРёРµ РіРѕСЂСЏС‡РµР№ РїРµСЂРµР·Р°РіСЂСѓР·РєРё РґР»СЏ РєРѕРјРїРёР»СЏС‚РѕСЂРѕРІ MSVC, РµСЃР»Рё РїРѕРґРґРµСЂР¶РёРІР°РµС‚СЃСЏ.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# РёРјСЏ РїСЂРѕРµРєС‚Р°
project (Task_1)

# postgres РІРµСЂСЃРёСЏ
set(PostgreSQL_ADDITIONAL_VERSIONS "17")

# Р”РѕР±Р°РІСЊС‚Рµ РёСЃС‚РѕС‡РЅРёРє РІ РёСЃРїРѕР»РЅСЏРµРјС‹Р№ С„Р°Р№Р» СЌС‚РѕРіРѕ РїСЂРѕРµРєС‚Р°.
add_executable (Task_1 "Task_1.cpp" Task_1.h)

add_subdirectory(C:/dev/libpqxx libpqxx-build) # РЈРєР°Р¶РёС‚Рµ РїСѓС‚СЊ Рє libpq++
#add_subdirectory(C:/dev/libpqxx libpqxx-build) # РЈРєР°Р¶РёС‚Рµ РїСѓС‚СЊ Рє libpq++
target_compile_features(Task_1 PRIVATE cxx_std_20) # Р’РєР»СЋС‡РёС‚Рµ C++17
target_link_libraries(Task_1 pqxx) # РЎР»РёРЅРєСѓР№С‚Рµ libpq++ Рє РїСЂРѕРµРєС‚Сѓ

if (CMAKE_VERSION VERSION_GREATER 3.12)
 set_property(TARGET Task_1 PROPERTY CXX_STANDARD 20)
endif()

