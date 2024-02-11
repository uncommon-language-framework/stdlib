public class Program
{
	static int Main()
	{
		int[] arr = new int[10];

		Console.WriteLine(arr.Length);

		int[] one = Array.Empty<int>();
		int[] two = Array.Empty<int>();
		Program[] three = Array.Empty<Program>();
		object[] four = Array.Empty<object>();

		Console.WriteLine("------START Array.Empty<T> TESTS--------");
		Console.WriteLine(one.GetType());
		Console.WriteLine(three.GetType());
		Console.WriteLine(four.GetType());
		Console.WriteLine(ReferenceEquals(one, two));
		Console.WriteLine(ReferenceEquals(one, three));
		Console.WriteLine(ReferenceEquals(three, four));
		Console.WriteLine("------END Array.Empty<T> TESTS--------");

		var test = new PropTest();

		_ = test.Prop;

		var testBool = true;

		Console.WriteLine(arr);

		var str = "123";

		Console.WriteLine(ReferenceEquals(str, str.ToString()));

		Console.WriteLine(sizeof(char));

		ReflectionTest.Method();

		object boxedbool = testBool;

		Console.WriteLine(boxedbool);

		unsafe
		{
			Console.WriteLine(sizeof(TestType));
			Console.WriteLine(sizeof(TestTypeTwo));
		}

		Console.WriteLine(typeof(IEnumerable<>));
		Console.WriteLine(typeof(IEnumerable<int>));

		ReflectionTest.Method5();

		return 0;
	}
}

struct PropTest
{
	public readonly int Prop {
		get {
			Console.WriteLine();

			return 1+5+6;
		}
	}
}

class TestType {};
class TestTypeTwo
{
	public ulong val = ulong.MaxValue;

	public void Method()
	{
		Console.WriteLine(val);
	}
};