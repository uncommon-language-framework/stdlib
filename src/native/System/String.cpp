#define PTR_WIDTH sizeof(void*)

#include "_RebuiltType.hpp"
#include "../../../../ulr/ULR/Lib/ULRAPI.hpp"
#include <string>

using ULR::API::IULRAPI;

extern IULRAPI* api;

// TODO: RIGHT NOW STRINGS ONLY ACCEPT A SINGLE BYTE CHAR 
// WHEN THEY SHOULD ACCEPT A DOUBLE BYTE CHAR

extern "C"
{

int special_string_ns1_System_get_Length(void* self)
{
	// cast void* to ptr to bytes, add ptr size offset, recast to ptr to int to grab length value
	int* sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(self)+PTR_WIDTH);

	return sizeptr[0]; // first four bytes constitute the size value
}

void* special_string_MAKE_FROM_LITERAL(const char* str, int len)
{
	Type* type = (Type*) api->GetType("System.String", "System.Runtime.dll"); // TODO: cache this from InitAssembly

	size_t obj_size = sizeof(type)+sizeof(int)+(PTR_WIDTH*len);

	void** str_obj = (void**) api->AllocateObject(obj_size);
	
	str_obj[0] = type;
	
	int* str_obj_offset_for_len_place = reinterpret_cast<int*>(reinterpret_cast<char*>(str_obj)+sizeof(type));

	str_obj_offset_for_len_place[0] = len;

	char* str_obj_offset_for_char_copy = reinterpret_cast<char*>(str_obj_offset_for_len_place+1);

	memcpy(str_obj_offset_for_char_copy, str, len);

	return str_obj;
}

void* special_string_overload0_operator_add_ns1_System(void* self, void* otherstr)
{
	Type* type = (Type*) api->GetType("System.String", "System.Runtime.dll"); // TODO: cache this from InitAssembly

	int* sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(self)+PTR_WIDTH);

	size_t sizeof_self = sizeptr[0];

	sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(otherstr)+PTR_WIDTH);

	size_t sizeof_other = sizeptr[0];

	size_t new_len = sizeof_self+sizeof_other;

	void** new_obj = (void**) api->AllocateObject(sizeof(type)+sizeof(new_len)+new_len);
	
	new_obj[0] = type;
	
	int* str_obj_offset_for_len_place = reinterpret_cast<int*>(reinterpret_cast<char*>(new_obj)+sizeof(type));

	str_obj_offset_for_len_place[0] = new_len;

	char* str_obj_offset_for_char_copy = reinterpret_cast<char*>(str_obj_offset_for_len_place+1);

	memcpy(str_obj_offset_for_char_copy, ((char*) self)+PTR_WIDTH+sizeof(int), sizeof_self);
	memcpy(str_obj_offset_for_char_copy+sizeof_self, ((char*) otherstr)+PTR_WIDTH+sizeof(int), sizeof_other);

	return new_obj;
}

void* special_string_overload1_operator_add_ns1_System(void* self, short ch)
{
	Type* type = (Type*) api->GetType("System.String", "System.Runtime.dll"); // TODO: cache this from InitAssembly

	int* sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(self)+PTR_WIDTH);

	size_t sizeof_self = sizeptr[0];

	size_t new_len = sizeof_self+1;

	void** new_obj = (void**) api->AllocateObject(sizeof(type)+sizeof(new_len)+new_len);
	
	new_obj[0] = type;
	
	int* str_obj_offset_for_len_place = reinterpret_cast<int*>(reinterpret_cast<char*>(new_obj)+sizeof(type));

	str_obj_offset_for_len_place[0] = new_len;

	char* str_obj_offset_for_char_copy = reinterpret_cast<char*>(str_obj_offset_for_len_place+1);

	memcpy(str_obj_offset_for_char_copy, ((char*) self)+PTR_WIDTH+sizeof(int), sizeof_self);

	str_obj_offset_for_char_copy[new_len-1] = (char) ch;

	return new_obj;
}

void* special_string_ns1_System_ToString(void* self)
{
	return self;
}

}

// #include "../String.hpp"
// #include <codecvt>
// #include <locale>
// #include <array>

// namespace System
// {
// 	String::String(std::wstring string)
// 	{
		
// 		inner = inner;
// 	}

// 	String::String(std::string string)
// 	{
		
// 		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(string);
// 	}

// 	String::String(Char string[])
// 	{
		
// 		size_t arr_size = *(&string + 1) - string;
		
// 		wchar_t arr[arr_size];

// 		for (int i; i < arr_size; i++) { arr[i] = string[i].ToNative(); }

// 		inner = std::wstring(arr);
// 	}

// 	String::String(const wchar_t string[])
// 	{
		
// 		inner = std::wstring(string);
// 	}

// 	String::String(const wchar_t string[], size_t length)
// 	{
		
// 		inner = std::wstring(string, length);
// 	}

// 	String::String(const char string[], size_t length)
// 	{
		
// 		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(std::string(string, length));
// 	}

// 	String::String(const char string[])
// 	{
		
// 		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(string);
// 	}

// 	std::wstring String::ToCpp() const
// 	{
// 		return inner;
// 	}

// 	String* String::ToString() const
// 	{
// 		std::wstring copy = inner;

// 		return new String(copy);
// 	}

// 	String* String::operator+(const String* other) const
// 	{
// 		String* ret = new String(inner+other->inner);

// 		return ret;
// 	}

// 	String* String::operator+(const Char& other) const
// 	{
// 		return new String(inner+other.ToNative());
// 	}

// 	Boolean String::operator==(const String* other) const
// 	{
// 		return Boolean(this->inner == other->inner);
// 	}


// 	String::~String()
// 	{

// 	}

// 	std::shared_ptr<String> String::Empty = std::make_shared<String>("");
// }