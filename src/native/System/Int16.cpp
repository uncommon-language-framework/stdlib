struct sizeof_System_Int16 { unsigned char bytebuf[2]; };

void ns1_System_Int16_ctor(sizeof_System_Int16* self, sizeof_System_Int16 other)
{
	*self = other;
}