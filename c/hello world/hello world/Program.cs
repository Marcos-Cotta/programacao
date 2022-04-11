using System;

namespace hello_world;

    public class HelloWorld 
    {
        string _hello = null;

        public void Sethello (string hello)
        {
            _hello = hello;
        }

        public string Gethello()
        {
            return _hello;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            HelloWorld hello = new();
            hello.Sethello("hello world");
            Console.WriteLine(hello.Gethello());
        }
    }
