using System.Reflection;

class ReflectionTest
{
	public static void Method()
	{
		int[] x = { 1, 2, 3 };

		Console.WriteLine(x.GetType().GetMember("CopyTo").Length);

		Func<object?, object?[]?, object?> func = x.GetType().GetMethod("ToString").Invoke;

		func.GetMethodInfo();
	}

	public static void Method2()
	{
		MethodInfo? main = Type.GetType("Program")?.GetMethod("Main", BindingFlags.Static | BindingFlags.NonPublic, Type.EmptyTypes);

		main?.Invoke(null, Array.Empty<object>());

	}

	public static void Method4() { Console.WriteLine("inside method4"); }

	public static void Method5()
	{
		object? retval = typeof(ReflectionTest)
		.GetMethod("Method4", BindingFlags.Static | BindingFlags.Public)
		.Invoke(null, null);

		Console.WriteLine(retval);
		Console.WriteLine(retval?.GetType());
	}
}