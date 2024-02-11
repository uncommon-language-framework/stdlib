struct sizeof_System_UInt32 { unsigned char bytebuf[4]; };

void ns1_System_UInt32_ctor(sizeof_System_UInt32* self, sizeof_System_UInt32 other)
{
	*self = other;
}