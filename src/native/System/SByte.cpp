struct sizeof_System_SByte { unsigned char bytebuf[1]; };

void ns1_System_SByte_ctor(sizeof_System_SByte* self, sizeof_System_SByte other)
{
	*self = other;
}