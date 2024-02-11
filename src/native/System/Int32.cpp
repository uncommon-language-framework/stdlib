struct sizeof_System_Int32 { unsigned char bytebuf[4]; };

void ns1_System_Int32_ctor(sizeof_System_Int32* self, sizeof_System_Int32 other)
{
	*self = other;
}