#define PTR_WIDTH sizeof(void*)
#include <stdulr>
#include <string>

using ULR::Type;

extern ULRAPIImpl* api;
extern Type* CachedSystemStringType;

extern "C"
{

// we can put get_Length right after System_ since we have specified `special array` so it is autobound to arrays
int special_array_ns1_System_get_Length(void* self)
{
	// cast void* to ptr to bytes, add ptr size offset, recast to ptr to int to grab length value
	int* elems = reinterpret_cast<int*>(reinterpret_cast<char*>(self)+PTR_WIDTH);

	return elems[0]; // first four bytes constitute the size value
}

// this generic indexing function will work for arrays of reference types since the pointer size is known at 
// compile time, but compilers will have to generate their own versions of this function for arrays of different value types
void* special_array_ref_overload_operator_idx_ns1_System(void** self, int idx)
{
	// extract out size, add PTR_WIDTH+4 to the char* ptr to skip vtype ptr & size value
	void** elems = reinterpret_cast<void**>(reinterpret_cast<char*>(self)+PTR_WIDTH+4);

	if (idx < 0 || idx > special_array_ns1_System_get_Length(self)-1)
	{
		/* throw idx out of bound exc, optimize later by using prev buff */
	}

	return elems[idx]; // TODO: make this safe to throw index out of bounds exception if idx does not exist
}

void* special_array_ref_overload_ctor_ns1_System(int size, Type* type)
{
	size_t obj_size = sizeof(type)+sizeof(int)+(PTR_WIDTH*size);

	void** arr_obj = (void**) api->AllocateZeroed(obj_size);
	
	arr_obj[0] = type;

	int* arr_obj_place_len = reinterpret_cast<int*>(reinterpret_cast<char*>(arr_obj)+sizeof(type));

	arr_obj_place_len[0] = size;

	return arr_obj;
}

void* special_array_from_ptr(void* ptr, int size, Type* type)
{
	size_t obj_size = sizeof(type)+sizeof(int)+(PTR_WIDTH*size);
	
	void** arr_obj = (void**) api->AllocateZeroed(obj_size);

	arr_obj[0] = type;

	int* arr_obj_place_len = reinterpret_cast<int*>(reinterpret_cast<char*>(arr_obj)+sizeof(type));

	arr_obj_place_len[0] = size;

	char* arr_obj_for_data_place = (char*) (arr_obj_place_len+1);

	memcpy(arr_obj_for_data_place, ptr, size);

	return arr_obj;
}

void* special_array_ns1_System_ToString(void* self)
{
	Type** elems = reinterpret_cast<Type**>(self);
	Type* self_type = elems[0];

	char* type_name = self_type->name;

	int type_name_len = strlen(type_name);

	char16_t* as_ch16 = (char16_t*) api->AllocateObject(type_name_len*sizeof(char16_t));

	for (int i = 0; i < type_name_len; i++)
	{
		as_ch16[i] = type_name[i];
	}

	Type* type_ptr = CachedSystemStringType;

	/* String object layout -- [ptr-to-string-type, length-of-string, chars...] */
	size_t obj_size = sizeof(type_ptr)+sizeof(type_name_len)+(sizeof(char16_t)*type_name_len);

	// we use AllocateObject() here rather than malloc() so this object can be gc-registered in the future
	void** string_object = (void**) api->AllocateObject(obj_size);

	string_object[0] = type_ptr;
	
	int* string_obj_offset_for_len_place = reinterpret_cast<int*>(reinterpret_cast<char*>(string_object)+sizeof(type_ptr));

	string_obj_offset_for_len_place[0] = type_name_len;

	char16_t* string_obj_offset_for_char_copy = reinterpret_cast<char16_t*>(string_obj_offset_for_len_place+1);

	memcpy(string_obj_offset_for_char_copy, type_name, type_name_len*sizeof(char16_t));

	/* The string is complete! */

	return string_object; // important - we return the start pointer to the object
}

} /* extern "C" */