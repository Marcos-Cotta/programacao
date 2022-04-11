using System;
using Domain;
using Data;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms
{
    public partial class Form1 : Form
    {

        private ProductDbContext context;
        public Form1()
        {
            InitializeComponent();

            context = new ProductDbContext();//inicializa o banco de dados dentro da aplicação por meio da função ProductDbContext()
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Loja loja = new Loja()
            {
                Nome = "Loja teste DevMedia",
                descricao = "Essa loja é um teste"
            };
            context.lojas.Add(loja);//adiciona como um objeto loja para as varias lojas que existem

            Produto produto = new Produto() //insert um novo produto na tabela produtos pertencendo a loja recem criada
            {
                Nome = "Produto teste Devmedia",
                Valor = 20m,
                Loja = loja
            };

            context.Produtos.Add(produto);//adiciona como um objeto produto para os varios produtos que existem


            context.SaveChanges(); //salva as mudanças no banco de dados
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Loja loja = context.lojas.Find(3); //select por id da loja

            Produto novoproduto = new Produto() //insert um novo produto na tabela de produtos
            {
                Nome = "Novo Produto",
                Valor = 100m,
                LojaId = loja.id,
                Loja = loja
            };

            context.Produtos.Add(novoproduto);//adiciona esse novo produto na base de dados

            context.SaveChanges(); //salva as mudanças no banco de dados
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Produto produto = context.Produtos.Find(4); //select com a loja do produto de id = 4

            Loja lojaProduto = produto.Loja;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            IEnumerable<Produto> produtosComecadosComN =  //select com where pelos produtos que começam com N
                context.Produtos.Where(p => p.Nome.StartsWith("N")); //"expressão lambda" 

            IEnumerable<Produto> ProdutosPorIdLoja3 =  //select com where pelos produtos com LojaId == 3
                context.Produtos.Where(p => p.LojaId == 3); //"expressão lambda"

            IEnumerable<Produto> produtosDaLoja2 =   //select os produtos com lojas com ID == 3 por meio do find
                context.lojas.Find(3).Produtos; 
        }

        private void button5_Click(object sender, EventArgs e) //botão update
        {
            Loja loja = context.lojas.Find(3); //por meio do find id loja 3 mudamos o nome da loja
            loja.Nome = "Teste update DevMedia";

            Produto produto = context.Produtos.Find(4); //por meio do find id produto 4 mudamos o nome do produto e da loja que esse produto esta ligado
            produto.Nome = "Update produto DevMedia";
            produto.Loja.Nome = "Update via prduto";

            loja.Produtos.ToList().ForEach(p => p.Valor += p.Valor * (decimal)0.1); //expressão "lambda" para cada produto da loja 3 ele aumenta 10% o preço

            context.SaveChanges(); //salva as mudanças no banco de dados
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Loja loja = context.lojas.Find(3); //acha a loja de id 3 e guarda em loja
            context.lojas.Remove(loja); //remove a loja com id 3

            Produto produto = context.Produtos.Find(4); //acha o produto de id 4 e o guarda em produto
            context.Produtos.Remove(produto); //remove o produto de id 4

            context.SaveChanges(); //salva as mudanças do banco de dados
        }
    }
}
