#include "../../../ulr/ULR/Lib/ULRAPI.hpp"

#define \
	IntStruct(name, size) \
	"rv[System]" name "$" #size ";.ctor p(" name ");.ctor p(<native>);\n"

using ULR::API::IULRAPI;

IULRAPI* api;

extern "C"
{

void InitAssembly(IULRAPI* inject_api)
{
	api = inject_api;
}

char ulrmeta[] = IntStruct("Int32", 4)
	// IntStruct("SByte", 1) // may need to chage to "char"?
	// IntStruct("Int16", 2)
	// IntStruct("Int64", 8)
	// IntStruct("UInt32", 4)
	// IntStruct("Byte", 1)
	// IntStruct("UInt16", 2)
	// IntStruct("UInt64", 8)
	// "rv[System]Char$2;.ctor p(<native>);\n"
	// "pc[System]String$16;.ctor p(<native>)\n" // sixteen since this should be for a 64-bit build
"";



void* ulraddr = {

};

} /* extern "C" */