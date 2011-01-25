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
    /// Logique d'interaction pour ReglageTir.xaml
    /// </summary>
    public partial class ReglageTir : Window
    {
        WrapperMoteur moteur;
        int dirX;
        int dirY;

        public ReglageTir(WrapperMoteur m, int x, int y)
        {
            InitializeComponent();
            moteur = m;
            dirX = x;
            dirY = y;

            // Initialisation des combobox
            for (int i = 0; i < moteur.getAngleMax(); i++)
            {
                comboBox1.Items.Add(i);
            }
            for (int i = 0; i < moteur.getPuissanceMax(); i++)
            {
                comboBox2.Items.Add(i);
            }
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            int angle = (int)comboBox1.SelectedValue;
            int puissance = (int)comboBox2.SelectedValue;
            
            moteur.reglerTir(puissance, angle, dirX, dirY);
            moteur.execute();
            MainWindow mw = new MainWindow(moteur);
            mw.mettreAJour();
            mw.Show();
            if (moteur.getResTir())
                MessageBox.Show("Le tir a réussi !");
            else
                MessageBox.Show("Le tir a échoué !");
            this.Close();
        }
    }
}
