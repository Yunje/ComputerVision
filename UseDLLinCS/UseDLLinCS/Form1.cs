using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace UseDLLinCS
{
    public partial class Form1 : Form
    {
        [DllImport("C:\\Users\\yunje\\Documents\\GitHub\\ComputerVision\\UseDLLinCS\\UseDLLinCS\\MakeDll.dll")]
        private static extern double Sub(double a, double b);
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double result;
            result = Sub(1.0, 3.0);
            MessageBox.Show(result.ToString());
        }
    }
}
