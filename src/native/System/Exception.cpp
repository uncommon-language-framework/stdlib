#include <stdulr>
#include <string>
#include <codecvt>
#include <locale>

extern ULRAPIImpl* api;

BEGIN_ULR_EXPORT

extern void* ns1_System_String_Empty;
extern void* special_string_MAKE_FROM_LITERAL(const char* str, int len);

void overload0_ns1_System_Exception_ctor(char* self)
{
	*((void**) (self+8)) = ns1_System_String_Empty;
	// *((void**) (self+16)) =
	// *((void**) (self+24)) = 
	*((void**) (self+32)) = nullptr;
}
	
void overload1_ns1_System_Exception_ctor(char* self, char* msg)
{
	*((void**) (self+8)) = msg;
	// *((void**) (self+16)) =
	// *((void**) (self+24)) = 
	*((void**) (self+32)) = nullptr;
}

void overload2_ns1_System_Exception_ctor(char* self, char* msg, void* innerexc)
{
	*((void**) (self+8)) = msg;
	// *((void**) (self+16)) =
	// *((void**) (self+24)) = 
	*((void**) (self+32)) = innerexc;
}

char* special_exception_prep_for_throw(char* self)
{
	auto stacktrace = api->GetStackTrace(1);
	
	*((void**) (self+16)) = special_string_MAKE_FROM_LITERAL(stacktrace.c_str(), stacktrace.size());
	*((void**) (self+24)) = 0 /* TODO: Construct a MethodBase instance here using a reverse lookup of the current_func addr through ULRAPI to get a ctor/dtor/methodinfo & constructing a [System.Reflection]MethodBase instance with it */;

	return self;
}

char* overload0_ns1_System_Exception_Message_get(char* self)
{
	return *((char**) (self+8));
}

char* overload0_ns1_System_Exception_StackTrace_get(char* self)
{
	return *((char**) (self+16));
}

char* overload0_ns1_System_Exception_TargetSite_get(char* self)
{
	return *((char**) (self+24));
}

char* overload0_ns1_System_Exception_InnerException_get(char* self)
{
	return *((char**) (self+32));
}

END_ULR_EXPORT