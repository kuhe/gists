//------------------------------------------------------------------------------
// <auto-generated>
//    This code was generated from a template.
//
//    Manual changes to this file may cause unexpected behavior in your application.
//    Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using WebApplication1.Library.Model;

namespace WebApplication1.Models
{
    using System;
    using System.Collections.Generic;
    
    public partial class Score
    {
        public int Id { get; set; }
        public string UserName { get; set; }
        public Nullable<System.DateTime> QuestionTime { get; set; }
        public string Equation { get; set; }
        public Nullable<double> CorrectAnswer { get; set; }
        public Nullable<double> StudentAnswer { get; set; }
        public Nullable<int> Points { get; set; }
    }
}
