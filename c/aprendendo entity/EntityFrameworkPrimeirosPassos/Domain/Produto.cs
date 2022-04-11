using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Domain
{
    [Table("Produto")] //data annotations criação da tabela Produto para ficar com o nome Produto
    public class Produto
    {
        [Key]
        public int Id { get; set; }
        [MaxLength(200)]
        [Required]
        public string Nome { get; set; }
        [MaxLength(2000)]
        public string Descricao { get; set; }
        [Required]
        public decimal Valor { get; set; }
        [ForeignKey("Loja")]
        public int LojaId { get; set; } //chave estrangeira para ligar tabela produto a tabela loja
        public virtual Loja Loja { get; set; } //criação de uma variavel virtual para servir como objeto que trara loja para ca
                                                //meu produto esta referenciando a loja ao qual pertence
    }
}
