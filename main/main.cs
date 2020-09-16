using System;

namespace HelloWorld
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Hello World!");
            NetworkTrainerCS trainer = new NetworkTrainerCS();
            trainer.Init();
            Console.WriteLine("Hello World!");
        }
    }
}