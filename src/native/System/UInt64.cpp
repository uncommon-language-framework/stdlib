struct sizeof_System_UInt64 { unsigned char bytebuf[8]; };

void ns1_System_UInt64_ctor(sizeof_System_UInt64* self, sizeof_System_UInt64 other)
{
	*self = other;
}