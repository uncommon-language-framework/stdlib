#define PTR_WIDTH sizeof(void*)

#include <stdulr>
#include <string>

using ULR::Type;
using char8 = char;

extern ULRAPIImpl* api;
extern Type* CachedSystemStringType;

BEGIN_ULR_EXPORT

int overload0_ns1_System_get_Length(char* self)
{
	// cast void* to ptr to bytes, add ptr size offset, recast to ptr to int to grab length value
	int* sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(self)+PTR_WIDTH);

	return sizeptr[0]; // first four bytes constitute the size value
}

char* special_string_MAKE_FROM_LITERAL(const char8* str, int len)
{
	size_t obj_size = sizeof(CachedSystemStringType)+sizeof(int)+(sizeof(char8)*len);

	void** str_obj = (void**) api->AllocateObject(obj_size);
	
	str_obj[0] = CachedSystemStringType;
	
	int* str_obj_offset_for_len_place = reinterpret_cast<int*>(reinterpret_cast<char*>(str_obj)+sizeof(CachedSystemStringType));

	str_obj_offset_for_len_place[0] = len;

	char8* str_obj_offset_for_char_copy = reinterpret_cast<char8*>(str_obj_offset_for_len_place+1);

	memcpy(str_obj_offset_for_char_copy, str, len*sizeof(char8));

	return (char*) str_obj;
}

char* special_string_overload0_operator_add_ns1_System(char* self, void* otherstr)
{
	int* sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(self)+PTR_WIDTH);

	size_t sizeof_self = sizeptr[0];

	sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(otherstr)+PTR_WIDTH);

	size_t sizeof_other = sizeptr[0];

	size_t new_len = sizeof_self+sizeof_other;

	void** new_obj = (void**) api->AllocateObject(sizeof(CachedSystemStringType)+sizeof(new_len)+(new_len*sizeof(char8)));
	
	new_obj[0] = CachedSystemStringType;
	
	int* str_obj_offset_for_len_place = reinterpret_cast<int*>(reinterpret_cast<char*>(new_obj)+sizeof(CachedSystemStringType));

	str_obj_offset_for_len_place[0] = new_len;

	char8* str_obj_offset_for_char_copy = reinterpret_cast<char8*>(str_obj_offset_for_len_place+1);

	memcpy(str_obj_offset_for_char_copy, ((char*) self)+PTR_WIDTH+sizeof(int), sizeof_self*sizeof(char8));
	memcpy(str_obj_offset_for_char_copy+sizeof_self, ((char*) otherstr)+PTR_WIDTH+sizeof(int), sizeof_other*sizeof(char8));

	return (char*) new_obj;
}

char* special_string_overload1_operator_add_ns1_System(char* self, char8 ch)
{
	int* sizeptr = reinterpret_cast<int*>(reinterpret_cast<char*>(self)+PTR_WIDTH);

	size_t sizeof_self = sizeptr[0];

	size_t new_len = sizeof_self+1;

	void** new_obj = (void**) api->AllocateObject(sizeof(CachedSystemStringType)+sizeof(new_len)+(new_len*sizeof(char8)));
	
	new_obj[0] = CachedSystemStringType;
	
	int* str_obj_offset_for_len_place = reinterpret_cast<int*>(reinterpret_cast<char*>(new_obj)+sizeof(CachedSystemStringType));

	str_obj_offset_for_len_place[0] = new_len;

	char8* str_obj_offset_for_char_copy = reinterpret_cast<char8*>(str_obj_offset_for_len_place+1);

	memcpy(str_obj_offset_for_char_copy, ((char*) self)+PTR_WIDTH+sizeof(int), sizeof_self*sizeof(char8));

	str_obj_offset_for_char_copy[new_len-1] = ch;

	return (char*) new_obj;
}

char* special_string_ns1_System_ToString(char* self)
{
	return self;
}

char* ns1_System_String_Empty;

void ns1_System_String_static_ctor()
{
	ns1_System_String_Empty = special_string_MAKE_FROM_LITERAL("", 0);
}

END_ULR_EXPORT