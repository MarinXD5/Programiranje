using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ToDo_List
{
    public partial class ToDoList : Form
    {
        public ToDoList()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Add_Click(object sender, EventArgs e)
        {
            ListBox.Items.Add(TaskText.Text.ToString());
        }

        private void RemoveAll_Click(object sender, EventArgs e)
        {
            ListBox.Items.Clear();
        }

        private void TaskText_TextChanged(object sender, EventArgs e)
        {

        }
        private void Remove_Click(object sender, EventArgs e)
        {
            int selectedIndex = ListBox.SelectedIndex;
            ListBox.Items.RemoveAt(selectedIndex);
        }
        private void ListBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        
    }
}
