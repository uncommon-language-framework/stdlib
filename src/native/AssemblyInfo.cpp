#include <stdulr>

// technically inherits from System.ValueType but that doesn't exist in the ULR
#define IntStruct(name, size) \
	"prv[System]" name ":[System]Object,$" #size ";\n"

#define ExceptionTypeDefaultMeta "$40;.ctor p();.ctor p([System]String);.ctor p([System]String,[System]Exception);" \
		".fldv [System]String message;.prop pg[System]String Message;" \
		".fldv [System]String stackTrace;.prop pg[System]String StackTrace;" \
		".fldv [System.Reflection]MethodBase targetSite;.prop pg[System.Reflection]MethodBase TargetSite;" \
		".fldv [System]Exception innerExc;.prop pg[System]Exception InnerException;\n"

using ULR::Type;

ULRAPIImpl* api;
Type* CachedSystemStringType;
Type* CachedSystemArtificialBoundViolationException;

BEGIN_ULR_EXPORT

extern void overload0_ns1_System_Object_ctor(char*);
extern void ns1_System_String_static_ctor();
extern int overload0_ns1_System_get_Length(char*);
extern void overload0_ns1_System_Exception_ctor(char*);
extern void overload1_ns1_System_Exception_ctor(char*, char*);
extern void overload2_ns1_System_Exception_ctor(char*, char*, void*);
extern char* overload0_ns1_System_Exception_Message_get(char*);
extern char* overload0_ns1_System_Exception_StackTrace_get(char*);
extern char* overload0_ns1_System_Exception_TargetSite_get(char*);
extern char* overload0_ns1_System_Exception_InnerException_get(char*);
extern void* ns1_System_String_Empty;

void InitAssembly(ULRAPIImpl* inject_api)
{
	api = inject_api;
	internal_api = api;
	CachedSystemStringType = api->GetType("[System]String", "System.Runtime.Native.dll");
	CachedSystemArtificialBoundViolationException = api->GetType("[System]ArtificialBoundViolationException", "System.Runtime.Native.dll");

	ns1_System_String_static_ctor();
}

char ulrmeta[] =
	// [System]
	"pc[System]Object:,$8;.ctor p();\n"
	"pv[System]Void:[System]Object,$0;\n"
	IntStruct("Int32", 4)
	IntStruct("SByte", 1)
	IntStruct("Int16", 2)
	IntStruct("Int64", 8)
	IntStruct("UInt32", 4)
	IntStruct("Byte", 1)
	IntStruct("UInt16", 2)
	IntStruct("UInt64", 8)
	"prv[System]Char:[System]Object,$1;\n"
	"pc[System]String:[System]Object,$0;.fldv psr[System]String Empty;.prop pg[System]Int32 Length;\n" // sixteen since this should be for a 64-bit build
	
	// 8 (type ptr) + 8 (inner exc) + 8 (string message) + 8 (string stacktrace) + 8 (MethodBase targetsite)
	"pc[System]Exception:[System]Object," ExceptionTypeDefaultMeta
	"pc[System]ArtificialBoundViolationException:[System]Exception," ExceptionTypeDefaultMeta
	// END [System]

	// [System.Reflection]
	"pc[System]Type:[System]Object,$8;.ctor ();ps[System]Type GetType([System]String);\n"
	"pc[System.Reflection]MethodBase:[System]Object,$8;.ctor ();\n"

	// END [System.Reflection]

	// [System.Collections]

	// END [System.Collections]

	// [System.Collections.Generic]

	// for now, here for generic parsing test
	"pc[System.Collections.Generic]List<>:[System]Object,$0;.ctor ([System]Int32);"
	".fldv T0[] _data;\n"

	// END [System.Collections.Generic]

	// [System.Collections.Concurrent]

	// END [System.Collections.Concurrent]

"";



void* ulraddr[ /* <- remove this once addrs are added */] = {
	(void*) overload0_ns1_System_Object_ctor,
	(void*) &ns1_System_String_Empty,
	(void*) overload0_ns1_System_get_Length,

	/* System.Exception */
	(void*) overload0_ns1_System_Exception_ctor,
	(void*) overload1_ns1_System_Exception_ctor,
	(void*) overload2_ns1_System_Exception_ctor,
	(void*) 8,
	(void*) overload0_ns1_System_Exception_Message_get,
	(void*) 16,
	(void*) overload0_ns1_System_Exception_StackTrace_get,
	(void*) 24,
	(void*) overload0_ns1_System_Exception_TargetSite_get,
	(void*) 32,
	(void*) overload0_ns1_System_Exception_InnerException_get,
	
	/* System.ArtificialBoundViolationException */
	(void*) overload0_ns1_System_Exception_ctor,
	(void*) overload1_ns1_System_Exception_ctor,
	(void*) overload2_ns1_System_Exception_ctor,
	(void*) 8,
	(void*) overload0_ns1_System_Exception_Message_get,
	(void*) 16,
	(void*) overload0_ns1_System_Exception_StackTrace_get,
	(void*) 24,
	(void*) overload0_ns1_System_Exception_TargetSite_get,
	(void*) 32,
	(void*) overload0_ns1_System_Exception_InnerException_get,
	
	(void*) 0, // overload0_ns1_System_Type_ctor,
	(void*) 0, // overload0_ns1_System_Type_GetType,
	(void*) 0, // overload0_ns2_System_Reflection_MethodBase_ctor
	(void*) "", // <- should be LLVM IR for generic
	(void*) 8
};

char* ulrdeps[] = { nullptr };

END_ULR_EXPORT