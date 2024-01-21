int[] arr = new int[10];

Console.WriteLine(arr.Length);

var test = new PropTest();

_ = test.Prop;

var testBool = true;

Console.WriteLine(arr);

var str = "123";

Console.WriteLine(ReferenceEquals(str, str.ToString()));

Console.WriteLine(sizeof(char));

ReflectionTest.Method();

struct PropTest
{
	public readonly int Prop {
		get {
			Console.WriteLine();

			return 1+5+6;
		}
	}
}