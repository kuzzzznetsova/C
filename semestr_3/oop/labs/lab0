using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_0
{
    //Перегрузка: конструктор, функции, операции и операнды
    class Reestr
    {//КЛАСС РЕЕСТР
        public string brand;
        public int price, year, storage;
        public float size;
        //КОНСТРУКТОР БЕЗ ПЕРЕМЕННЫХ (просто чтобы вывести фразу)
        public Reestr()
        {
            Console.WriteLine("Overloading constructor");
        }
        //КОНСТРУКТОР С ПЕРЕМЕННЫМИ
        public Reestr(string brand, int price, int year, int storage, float size)
        {
            this.brand = brand;
            this.price = price;
            this.year = year;
            this.storage = storage;
            this.size = size;
        }
        //ФУНКЦИЯ ВЫВОДА 
        public void print()
        {
            Console.Write("  {0} ", brand);
            Console.Write("  {0} ", price);
            Console.Write("  {0} ", year);
            Console.Write("  {0} ", storage);
            Console.Write("  {0} ", size);
            Console.WriteLine();
        }
        //ФУНКЦИЯ ВЫВОДА ФРАЗЫ
        public void print(int num)
        {
            Console.WriteLine("Overloading operation");
        }
        //ФУНКЦИЯ СЛОЖЕНИЯ
        public static int operator +(Reestr a, Reestr b)
        {
            return a.price + b.price;
        }
        //ФУНКЦИЯ ВОЗВРАЩЕНИЯ ЛЕТ
        public int years()
        {
            return this.year;
        }
        //ФУНКЦИЯ СЛОЖЕНИЯ ЛЕТ
        public int years(int nan)
        {
            return this.year + nan;
        }
    }
    class Program
    { //ОСНОВНАЯ ЧАСТЬ ПРОГРАММЫ
        static void Main(string[] args)
        {
            Console.WriteLine("Лабораторная работа №0");
            Console.WriteLine("Перегрузка (constructor, function, operator, operation)");

            Reestr a = new Reestr("Iphone", 64990, 2020, 64, 6.4f);
            Reestr b = new Reestr("SAMSUNG", 29990, 2019, 128, 6.1f);
            Reestr c = new Reestr("Xiaomi", 18990, 2019, 256, 6.4f);

            Console.WriteLine("Step 1. Overloading constructors");
            Reestr d = new Reestr(); //ВЫЗОВ КЛАССА РЕЕСТР
            //(ТАМ ЕСТЬ КОНСТРУКТОР БЕЗ ПЕРЕМЕННЫХ И ПОЭТОМУ ВЫВЕДЕТСЯ Overloading constructor
            Console.WriteLine();

            Console.WriteLine("Step 2. Overloading operator");
            Console.WriteLine("Reestr:");
            //ВЫВОД РЕЕСТРА ОСУЩЕСТВЛЯЕТСЯ ТАК:
            //а.- имя класса, print- обращение к функции
            //т.к. никаких переменных не передаём, ВЫЗЫВАЕТСЯ ФУНКЦИЯ ПРОСТО ПРИНТ
            a.print();
            b.print();
            c.print();
            Console.WriteLine("Task print with number:");
            a.print(1);//ЗДЕСЬ УЖЕ ЕСТЬ ПЕРЕМЕННАЯ = 1, ВЫЗЫВАЕТСЯ ФУНКЦИЯ Overloading operation
            Console.WriteLine();

            Console.WriteLine("Step 3. Overloading with +");
            Console.Write("a.price + b.price = ");
            Console.WriteLine("{0}", a + b);
            Console.WriteLine();

            Console.WriteLine("Step 4. Overloading function");
            Console.WriteLine("a.years= {0}", a.years());
            Console.WriteLine("b.years= {0}", b.years());
            Console.WriteLine("c.years= {0}", c.years());
            Console.WriteLine();

            Console.WriteLine("(this.year + nan) a.years(100) = {0}", a.years(100));
            Console.ReadKey();
        }
    }
}
