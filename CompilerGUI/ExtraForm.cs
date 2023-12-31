using System;
using System.Windows.Forms;

namespace CompilerGUI
{
    public partial class ExtraOpts : Form
    {
        public ExtraOpts()
        {
            InitializeComponent();
            nlaaCheck.Checked = MainForm.LargeAddressAware;
        }

        private void laaCheck_CheckedChanged(object sender, EventArgs e)
        {
            MainForm.LargeAddressAware = nlaaCheck.Checked;
            if (nlaaCheck.Checked) MainForm.ArgumentList.Add("-nlaa");
            else MainForm.ArgumentList.Remove("-nlaa");
        }
    }
}
