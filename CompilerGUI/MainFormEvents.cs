using System;
using System.Windows.Forms;

namespace CompilerGUI
{
    public partial class MainForm : Form
    {
        private void tssButton_Click(object sender, EventArgs e)
        {
            ExtraOpts form = new ExtraOpts();
            form.Show();
        }

        private void quietMode_CheckedChanged(object sender, EventArgs e)
        {
            if (quietMode.Checked) ArgumentList.Add("-q");
            else ArgumentList.Remove("-q");
        }

        private void vQuietMode_CheckedChanged(object sender, EventArgs e)
        {
            if (vQuietMode.Checked) ArgumentList.Add("+q");
            else ArgumentList.Remove("+q");
        }

        private void compileOnly_CheckedChanged(object sender, EventArgs e)
        {
            if (compileOnly.Checked) ArgumentList.Add("-c");
            else ArgumentList.Remove("-c");
        }

        private void debugCompile_CheckedChanged(object sender, EventArgs e)
        {
            if (debugCompile.Checked) ArgumentList.Add("-d");
            else ArgumentList.Remove("-d");
        }

        private void dKeywords_CheckedChanged(object sender, EventArgs e)
        {
            if (dKeywords.Checked) ArgumentList.Add("-k");
            else ArgumentList.Remove("-k");
        }

        private void dKeywordsSyntax_CheckedChanged(object sender, EventArgs e)
        {
            if (dKeywordsSyntax.Checked) ArgumentList.Add("+k");
            else ArgumentList.Remove("+k");
        }
    }
}
