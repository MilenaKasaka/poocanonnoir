using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using mWrapper;

namespace canon_noir
{
    /// <summary>
    /// Logique d'interaction pour Initialisation.xaml
    /// </summary>
    public partial class Initialisation : Window
    {
        WrapperMoteur moteur;

        public Initialisation()
        {
            InitializeComponent();
            // Provoque une exception
            moteur = new WrapperMoteur();
        }

        private void comboBox1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {

        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            String ch = ((ComboBoxItem)comboBox1.SelectedItem).Content.ToString();
            moteur.initJoueurs(Int32.Parse(ch));
            MainWindow mw = new MainWindow(moteur);
            mw.Show();
            this.Close();
        }
    }
}
