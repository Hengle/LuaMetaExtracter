#ifndef __LUA_PARSER_EXPORT_H__
#define __LUA_PARSER_EXPORT_H__

//������c++ʹ�õĽӿڣ�cʹ�õ���cpp�ļ���������
extern void* lparser_get_document();
extern int lparser_init();
extern int lparser_print_all();
//��ӹ�ע�ĺ�����������ӵĻ��Ͳ���������json���
extern int lparser_add_concern_func(const char* func_name);

#endif