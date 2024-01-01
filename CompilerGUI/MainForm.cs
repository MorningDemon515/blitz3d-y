using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Windows.Forms;

namespace CompilerGUI
{
    public partial class MainForm : Form
    {
        public readonly string Execute = "/k blitzcc.exe ";
        public static bool LargeAddressAware = false;
        public static List<string> ArgumentList = new List<string>();

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            if (!File.Exists("blitzcc.exe"))
            {
                MessageBox.Show("blitzcc.exe must be in the same directory as the GUI!",
                    "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                compileButton.Enabled = false;
            }
        }

        private void browseButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "BlitzBasic files (*.bb)|*.bb";
            openFileDialog1.FilterIndex = 0;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                bbFile.Text = openFileDialog1.FileName;
            }
        }

        private void compileButton_Click(object sender, EventArgs e)
        {
            ToggleAllControls(false);
            string FileToCompile = FixStringSpaces(bbFile.Text);
            string Parameters = string.Empty;

            if(FileToCompile == string.Empty)
            {
                MessageBox.Show("Choose a file to compile!",
                    "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                ToggleAllControls(true);
                return;
            }
            if(genExe.Checked == true && exeName.Text == string.Empty)
            {
                MessageBox.Show("Executable name can't be empty!",
                    "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                ToggleAllControls(true);
                return;
            }

            Parameters += string.Join(" ", ArgumentList);
            if(genExe.Checked == true && exeName.Text != string.Empty)
            {
                Parameters += string.Format(" -o {0} ", FixStringSpaces(exeName.Text));
            }
            Parameters += FileToCompile;

            Debug.WriteLine(Parameters);

            try
            {
                //Execute compiler with the arguments.
                Process.Start("CMD.exe", Execute + Parameters);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Exception!\n" + ex.Message,
                    "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            ToggleAllControls(true);
        }

        public void ToggleAllControls(bool state)
        {
            bbFile.Enabled              = state;
            browseButton.Enabled        = state;
            quietMode.Enabled           = state;
            vQuietMode.Enabled          = state;
            compileOnly.Enabled         = state;
            debugCompile.Enabled        = state;
            dKeywords.Enabled           = state;
            dKeywordsSyntax.Enabled     = state;
            genExe.Enabled              = state;
            exeName.Enabled             = state;
            tssButton.Enabled           = state;
            compileButton.Enabled       = state;
        }

        public string FixStringSpaces(string inputString)
        {
            if (inputString.Contains(" ")) return $"\"{inputString}\"";
            else return inputString;
        }
    }
}
