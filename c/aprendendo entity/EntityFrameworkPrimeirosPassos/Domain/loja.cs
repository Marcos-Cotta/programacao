using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Domain
{
    [Table("Loja")] //criação da tabela loja para ficar com o nome Loja
    public class Loja
    {
        public Loja()
        {
            Produtos = new List<Produto>(); //evita erros de referencia nulla
        }
        [Key]
        public int id { get; set; }
        [Required]
        [MaxLength(200)]
        public string Nome { get; set; }
        [MaxLength(2000)]
        public string descricao { get; set; }
        public virtual IEnumerable<Produto> Produtos { get; set; }  //é necessário colocar uma lista de produtos para essa loja
    }
}
