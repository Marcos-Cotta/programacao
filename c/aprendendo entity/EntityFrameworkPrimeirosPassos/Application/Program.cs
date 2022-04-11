using System;
using Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Application
{
    class Program
    {
        static void Main(string[] args)
        {
            ProductDbContext context = new ProductDbContext(); //chamar função para criar base de dados

            Console.ReadKey();
        }
    }
}
