struct sizeof_System_Int64 { unsigned char bytebuf[8]; };

void ns1_System_Int64_ctor(sizeof_System_Int64* self, sizeof_System_Int64 other)
{
	*self = other;
}