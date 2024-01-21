#include "../../../ulr/ULR/Lib/Public/StdULR.hpp"

#define \
	IntStruct(name, size) \
	"rv[System]" name "$" #size ";.ctor p([System]" name ");\n"


using ULR::Type;

ULRAPIImpl* api;
Type* CachedSystemStringType;

extern "C"
{

void InitAssembly(ULRAPIImpl* inject_api)
{
	api = inject_api;
	CachedSystemStringType = api->GetType("[System]String", "System.Runtime.Native.dll");
}

char ulrmeta[] = IntStruct("Int32", 4)
	IntStruct("SByte", 1) // may need to chage to "char"?
	IntStruct("Int16", 2)
	IntStruct("Int64", 8)
	IntStruct("UInt32", 4)
	IntStruct("Byte", 1)
	IntStruct("UInt16", 2)
	IntStruct("UInt64", 8)
	"rv[System]Char$2;.ctor p([System]Char);\n"
	"pc[System]String$16;.ctor p([System]String);\n" // sixteen since this should be for a 64-bit build
"";



void* ulraddr = {

};

} /* extern "C" */