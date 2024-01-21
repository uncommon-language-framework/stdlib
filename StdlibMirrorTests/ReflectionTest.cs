class ReflectionTest
{
	public static void Method()
	{
		int[] x = { 1, 2, 3 };

		Console.WriteLine(x.GetType().GetMember("CopyTo").Length);
	}
}