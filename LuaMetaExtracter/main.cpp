#include "LuaMetaExtracter.h"

/*
LuaMetaExtracter��˵��
���ܣ���ȡlua�����Ԫ��Ϣ��ת��Ϊjson��ʽ��Ŀǰֻ֧�ֺ�������ͺ�������(��ȡ�����õĺ������������б�����ֵ�б����Ϣ)���紫��lua���룺
function func1()
	local result_val = self:func2("arge")
end
������json���룺
{
  "func_name": "func1",
  "codes": [
	  {
		"type": "call_func",
		"arges": [
			"arge",
		],
		"rets": [
			"result_val",
		],
		  "call_name": "call_func1",
		  "call_full_name": "self:call_func1"
	  }
  ],
}
func_name���Ƕ���ĺ�������codes�Ǹú�������ı��ʽ�б�
Ϊ�˼���������ֻ��һ����json������ѣ���Ϊlua֧��Ƕ�׵ĺ������壬�磺
function func1()
	local func2 = function (  )
		self:call_func3()
	end
end
����ÿ�����������ֿ��԰��������壬������lua�ļ�����һ����������ʵlua�ڲ�ʵ�ֽ���һ��lua�ļ�ʱҲ�ǰ�������һ���հ��ģ�,����������json�ṹ��ž��ǣ�
{
	"func_name": "outside",
	"codes": [����������Ϣ�б������û���ú�����������Ϊ��],
	"funcs": [
		{
			"func_name": "func1",
			"codes": [func1��������û���ú�������������ҲΪ��]
			"funcs": [
				{
					"func_name": "func2",
					"funcs": [����û�����º����ˣ���������Ϊ��],
					"codes": [
						{
							"type": "call_func",
							"arges": [],
							"rets": [],
							"call_name": "call_func3",
							"call_full_name": "self:call_func3"
						}
					]
				}
			],
		}
	]
}
һ�������������Ϣ�����ֶΣ�������(func_name)����������ִ�еı��ʽ�б�(codes)���������ﶨ��ĺ����б�(funcs)
���ʽ��Ϣ�����ֶΣ�����(type)�����õĺ�����(call_name)�����õĺ���ȫ��(call_full_name)�������б�(arges)������ֵ�б�(rets)
*/
int main()
{
	LuaMetaExtracter extracter;

	//��ȡlua�����еĺ���������Ϣ�������test_simple.lua
	rapidjson::Document* doc = extracter.ParseFile("./test/test_simple.lua");
	LuaMetaExtracter::PrintDoc(doc);
	LuaMetaExtracter::SaveDocToFile(doc, "./test/extract_result_simple.json");
	
	//���Զ�㺯��Ƕ�׶������Ϣ��ȡ
	doc = extracter.ParseFile("./test/test_nested_func.lua");
	LuaMetaExtracter::PrintDoc(doc);
	LuaMetaExtracter::SaveDocToFile(doc, "./test/extract_result_nested_func.json");

	//��������
	doc = extracter.ParseFile("./test/test_all.lua");
	LuaMetaExtracter::PrintDoc(doc);
	LuaMetaExtracter::SaveDocToFile(doc, "./test/extract_result_all.json");

	getchar();
    return 0;
}

