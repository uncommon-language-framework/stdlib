namespace ULR.InterfaceTest;

public class InterfaceTest
{
	public static void Method()
	{
		var type = typeof(int[]);

		var x = typeof(IEnumerable<>);
	}
}

public interface IInterface
{
	void Func();
}

public class Base : IInterface
{
	public void Func() { }
}

public class Derived : Base, IInterface
{
	
}