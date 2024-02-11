// #include <System.Runtime.Native.dll>

#pragma region stubs

namespace System
{
	class String {};
	class Object
	{
		public:
			String ToString();
	};

	namespace IO
	{
		class TextWriter
		{
			public:
				TextWriter(ULR::FileSystem::FileHandle handle);
				void Write(string);
				void WriteLine(string);
		};
	}
}

namespace ULR::FileSystem
{
	class FileHandle
	{
		public:
			FileHandle(__INTPTR_TYPE__ fd);
	};
}

typedef System::String string;
typedef System::Object object;

#define typedecl(attr) __attribute__((attr))
#define readonly __attribute__((readonly))
#define new

#pragma endregion stubs

using namespace System;
using namespace System::IO;
using namespace ULR::FileSystem;

namespace System
{
	class
		typedecl(public)
		typedecl(static)
		Console
	{
		public:
			static readonly TextWriter Out = new TextWriter(
				new FileHandle(1)
			);


			void Write(string message)
			{								
				Out.Write(message);
			}

			void WriteLine(string message)
			{
				Out.WriteLine(message);
			}

			void Write(object message)
			{
				Out.Write(message.ToString());
			}

			void WriteLine(object message)
			{
				Out.WriteLine(message.ToString());
			}
	};
}