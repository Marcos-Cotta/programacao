using System;
using Domain;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.Entity;
using System.Threading.Tasks;

namespace Data
{
    public class ProductDbContext : DbContext //herdando o System.Data.Entity vamos conseguir herdar do entity framework uma classe para representar o banco de dados dentro da nossa aplicação
    {
        public ProductDbContext() : base("Name=ProductDb") //Definindo o construtor da classe, chamando o construtor da classe pai e passando para ele a string de conexão
        {
            Database.SetInitializer<ProductDbContext>( //inicializador do banco de dados 
                new CreateDatabaseIfNotExists<ProductDbContext>()); //definição de que se o banco de dados não existir, ele deve ser criado
            Database.Initialize(false); //ele so vai ser executado, caso ainda não tenha sido executado dentro desse DbContext
        }
        
        public DbSet<Produto> Produtos { get; set; } //entidades dentro da base de dados no caso para a tabela produtos
        public DbSet<Loja> lojas { get; set; } //entidades dentro da base de dados no caso para a tabela lojas


    }
}
