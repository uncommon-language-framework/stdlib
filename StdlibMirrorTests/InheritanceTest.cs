using System.Reflection;

namespace InheritanceTest;

public class BaseOne
{
	public int Field;
	public string FieldTwo = string.Empty;
	public bool FieldThree;

	public void Method() { }
}

public class BaseTwo
{
	public int Field;
	public uint FieldInject;
	public string FieldTwo = string.Empty;
	public bool FieldThree;
}

public class Derived : BaseOne
{
}

public class ReflectionInheritanceTest
{
	public static void Test()
	{
		Console.WriteLine("begin reflinherit test");
		
		Console.WriteLine(typeof(Derived).GetMethod("Method")?.DeclaringType);
		Console.WriteLine("end reflinherit test");
	}
}