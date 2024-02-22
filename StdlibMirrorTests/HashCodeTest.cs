using System.Numerics;

static class HashCodeTest
{
	public static void Method()
	{
		object obj1 = new();
		object obj2 = new();
		int obj3 = new();
		int obj4 = 9;
		long obj5 = long.MaxValue;
		BigInteger obj6 = ulong.MaxValue;

		Console.WriteLine(obj1);
		Console.WriteLine(obj2);
		Console.WriteLine(obj1.GetHashCode());
		Console.WriteLine(obj2.GetHashCode());
		Console.WriteLine(obj3.GetHashCode());
		Console.WriteLine(obj4.GetHashCode());
		Console.WriteLine(obj5.GetHashCode());
		Console.WriteLine(obj6.GetHashCode());
	}
}