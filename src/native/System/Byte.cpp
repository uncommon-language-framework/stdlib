struct sizeof_System_Byte { unsigned char bytebuf[1]; };

void ns1_System_Byte_ctor(sizeof_System_Byte* self, sizeof_System_Byte other)
{
	*self = other;
}