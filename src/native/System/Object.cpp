// namespace System
// {
// 	/* Object */

// 	Boolean Object::ReferenceEquals(std::shared_ptr<Object> a, std::shared_ptr<Object> b)
// 	{
// 		bool res = a == b;

// 		return Boolean(res);
// 	}

// 	// Boolean Object::Equals(Object* a, Object* b)
// 	// {
// 	// 	std::array<byte, sizeof(*a)> a_bytes;

// 	// 	const byte* a_begin = reinterpret_cast<const byte*>(a);
// 	// 	const byte* a_end = a_begin + sizeof(*a) ;

// 	// 	std::copy(a_begin, a_end, std::begin(a_bytes));

// 	// 	std::array<byte, sizeof(*b)> b_bytes;

// 	// 	const byte* b_begin = reinterpret_cast<const byte*>(b);
// 	// 	const byte* b_end = b_begin + sizeof(*b);

// 	// 	std::copy(b_begin, b_end, std::begin(b_bytes));

// 	// 	for (auto elem : a_bytes)
// 	// 	{
// 	// 		std::cout << std::to_string(elem) << " ";
// 	// 	}

// 	// 	std::cout << std::endl;

// 	// 	for (auto elem : b_bytes)
// 	// 	{
// 	// 		std::cout << std::to_string(elem) << " ";
// 	// 	}

// 	// 	std::cout << std::endl;

// 	// 	return Boolean(a_bytes == b_bytes);
// 	// }

// 	Object::Object()
// 	{
		
// 	}

// 	std::shared_ptr<String> Object::ToString()
// 	{
// 		return std::make_shared<String>(L"System.Object");
// 	}

// 	Int32 Object::GetHashCode()
// 	{
// 		int hash = 0;
// 		byte* bytes = reinterpret_cast<byte*>(this);
// 		int size = sizeof(*this);

// 		for (int i = 0; i < size; i++)
// 		{
// 			if (i % 2 == 0)
// 			{
// 				hash^=bytes[i];
// 				continue;
// 			}

// 			hash*=bytes[i];
// 		}

// 		return Int32(hash);
// 	}

// 	unsigned long long Object::GetNativeLongHashCode()
// 	{
// 		unsigned long long hash = 0;
// 		byte* bytes = reinterpret_cast<byte*>(this);
// 		int size = sizeof(*this);

// 		for (int i = 0; i < size; i++)
// 		{
// 			if (i % 2 == 0)
// 			{
// 				hash^=bytes[i];
// 				continue;
// 			}

// 			hash*=bytes[i];
// 		}

// 		return hash;		
// 	}

// 	Object::~Object()
// 	{

// 	}

// 	Boolean Object::Equals(std::shared_ptr<Object> b)
// 	{
// 		return Object::Equals(this, b.get());
// 	}
// }