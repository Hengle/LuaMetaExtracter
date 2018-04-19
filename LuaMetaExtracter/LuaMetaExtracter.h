#ifndef __LUA_PARSER_H__
#define __LUA_PARSER_H__

#include "rapidjson/document.h"
#include <string>
using namespace std;

class LuaMetaExtracter
{
public:
	LuaMetaExtracter();
	rapidjson::Document* ParseFile(const char* file_path);
	rapidjson::Document* ParseString(const char* content);

	static void PrintDoc(rapidjson::Document* doc);
	static void SaveDocToFile(rapidjson::Document* doc, const char* file_path);

	//��ӹ�ע�ĺ�������Ĭ����ȫ����ȡ�ģ����ô˺�����ֻ��ȡ��ע�ĺ������ĵ���
	void AddConcernCallFunc(const char* func_name);
};

#endif