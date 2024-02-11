#include <stdulr>

#define IntStruct(name, size) \
	"prv[System]" name "$" #size ";\n"


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

char ulrmeta[] =
	// [System]
	IntStruct("Int32", 4)
	IntStruct("SByte", 1)
	IntStruct("Int16", 2)
	IntStruct("Int64", 8)
	IntStruct("UInt32", 4)
	IntStruct("Byte", 1)
	IntStruct("UInt16", 2)
	IntStruct("UInt64", 8)
	"prv[System]Char$2;\n"
	"pc[System]String$16;\n" // sixteen since this should be for a 64-bit build
	// TODO: HRESULT/HelpLink/Data for System.Exception?
	// 8 (type ptr) + 8 (inner exc) + 8 (string message) + 8 (string source) + 8 (string stacktrace) + 8 (MethodBase targetsite)
	"pc[System]Exception$48;.ctor p();.ctor p([System]String);.ctor([System]String, [System]Exception);"
		".fldv [System]String message;.prop pg[System]String Message;"
		".fldv [System]String stacktrace;.prop pg[System]String StackTrace;"
		".fldv [System.Reflection]MethodBase targetsite;.prop pg[System.Reflection]MethodBase TargetSite;\n"

	// END [System]

	// [System.Reflection]
	"pc[System]Type$INSERT_SIZE;ps[System]Type GetType([System]String);"

	// END [System.Reflection]

	// [System.Collections]

	// END [System.Collections]

	// [System.Collections.Generic]

	// for now, here for generic parsing test
	"prv[System.Collections.Generic]List<>$SIZE;.ctor ([System]Int32);"

	// END [System.Collections.Generic]

	// [System.Collections.Concurrent]

	// END [System.Collections.Concurrent]

"";



void* ulraddr[1 /* <- remove this once addrs are added */] = {
	
};

// technically ulrlocalsmapping should be the same length of ulraddr
size_t ulrlocalslen = 0; // we don't use any managed locals rn, change later once used
void* ulrlocals[1]; // if lcls are used, then change to ulrlocals[ulrlocalslen];
size_t ulrlocalsmapping[1][2];  
} /* extern "C" */