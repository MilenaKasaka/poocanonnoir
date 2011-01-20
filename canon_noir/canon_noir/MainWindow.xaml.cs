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
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        // UTILISER UN TRIGGER POUR LE CHANGEMENT D'ETAT
        enum TypeBateau { CARAVELLE, FREGATE, RADEAU };
        WrapperMoteur moteur;
        Image[,] tabImg;

        public MainWindow(WrapperMoteur m)
        {
            InitializeComponent();
            moteur = m;
            initInfosPartie();
            initMap();
            initBateaux();
        }

        private void initInfosPartie()
        {
            String infos = "DONNEES DE LA PARTIE";
            int nbJoueurs = moteur.getNbJoueurs();
            for (int i = 0; i < nbJoueurs; i++)
            {
                infos += "\nJoueur " + (i+1) + " : " + moteur.getNbTresors(i) + " tresor(s)";
            }
            textBlock1.Text += infos;
        }

        private void initMap()
        {
            int nbLig = moteur.getNbLignes();
            int nbCol = moteur.getNbColonnes();

            tabImg = new Image[nbLig, nbCol];

            for (int i = 0; i < nbLig; i++)
            {
                grid1.RowDefinitions.Add(new RowDefinition());
            }
            for (int i = 0; i < nbCol; i++)
            {
                grid1.ColumnDefinitions.Add(new ColumnDefinition());
            }

            for (int i = 0; i < nbLig; i++)
            {
                for (int j = 0; j < nbCol; j++)
                {
                    tabImg[i, j] = new Image();
                    //tabImg[i, j].Source = new BitmapImage(new Uri("/canon_noir;component/images/plateau.jpg", UriKind.RelativeOrAbsolute));
                    Grid.SetRow(tabImg[i, j], i);
                    Grid.SetColumn(tabImg[i, j], j);
                    grid1.Children.Add(tabImg[i, j]);
                }
            }
        }

        private void initBateaux()
        {
            int nbJoueurs = moteur.getNbJoueurs();
            for (int i = 0; i < nbJoueurs; i++)
            {
                int typeb = moteur.getTypeBateau(i);
                int posX = moteur.getXBateau(i);
                int posY = moteur.getYBateau(i);
                switch (typeb)
                {
                    case (int)TypeBateau.CARAVELLE :
                        Console.WriteLine("Caravelle !");
                        tabImg[posX, posY].Source = new BitmapImage(new Uri("/canon_noir;component/images/cara.png", UriKind.RelativeOrAbsolute));
                        
                        break;
                    case (int)TypeBateau.FREGATE :
                        break;
                    case (int)TypeBateau.RADEAU :
                        break;
                    default :
                        break;
                }
            }
        }
    }
}
