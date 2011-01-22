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
            infos += "\nJoueur courant : " + (moteur.getJoueurCourant() + 1);
            int nbJoueurs = moteur.getNbJoueurs();
            for (int i = 0; i < nbJoueurs; i++)
            {
                infos += "\nJoueur " + (i+1) + " : " + moteur.getNbTresors(i) + " tresor(s)";
            }
            textBlock1.Text = infos;
        }

        private void initMap()
        {
            int nbLig = moteur.getNbLignes();
            int nbCol = moteur.getNbColonnes();

            Console.WriteLine("nbLig = " + nbLig + " - nbCol = " + nbCol);

            tabImg = new Image[nbCol, nbLig];

            for (int i = 0; i < nbLig; i++)
            {
                grid1.RowDefinitions.Add(new RowDefinition());
            }
            for (int i = 0; i < nbCol; i++)
            {
                grid1.ColumnDefinitions.Add(new ColumnDefinition());
            }

            for (int i = 0; i < nbCol; i++)
            {
                for (int j = 0; j < nbLig; j++)
                {
                    tabImg[i, j] = new Image();
                    //tabImg[i, j].Source = new BitmapImage(new Uri("/canon_noir;component/images/plateau.jpg", UriKind.RelativeOrAbsolute));
                    Grid.SetRow(tabImg[i, j], j);
                    Grid.SetColumn(tabImg[i, j], i);
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
                //Console.WriteLine("X = " + posX + " - Y= " + posY);          
                switch (typeb)
                {
                    case (int)TypeBateau.CARAVELLE :
                        switch(i)
                        {
                            case 0 :
                                tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/cara1.png", UriKind.RelativeOrAbsolute));
                                break;
                            case 1 :
                                tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/cara2.png", UriKind.RelativeOrAbsolute));
                                break;
                            case 2:
                                tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/cara3.png", UriKind.RelativeOrAbsolute));
                                break;
                            case 3:
                                tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/cara4.png", UriKind.RelativeOrAbsolute));
                                break;
                            default:
                                break;
                        }
                        
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

        private void afficheCasesAccessibles()
        {
            int nbLig = moteur.getNbLignes();
            int nbCol = moteur.getNbColonnes();
            if (moteur.dispoChoixCase())
            {
                // Mettre en évidence les cases accessibles
                for (int i = 0; i < nbCol; i++)
                {
                    for (int j = 0; j < nbLig; j++)
                    {
                        if (moteur.estAccessible(i, j))
                        {
                            tabImg[i, j].Source = new BitmapImage(new Uri("/images/cadre.png", UriKind.RelativeOrAbsolute));
                        }
                    }
                }
                
                            
                
            }
            else
            {
                // Remettre toutes les cases normales
                for (int i = 0; i < nbCol; i++)
                {
                    for (int j = 0; j < nbLig; j++)
                    {
                        tabImg[i, j].Source = null;
                    }
                }
                initBateaux();
            }
        }

        private void btn_Des_Click(object sender, RoutedEventArgs e)
        {
            // verifier que les des sont tires le bon nombre de fois
            moteur.execute();
            int de1 = moteur.getDe1();
            int de2 = moteur.getDe2();
            string msg = "de1 = " + de1 + " - de2 = " + de2; 
            MessageBox.Show(msg);
            moteur.execute();
            afficheCasesAccessibles();
            if (!moteur.dispoLancerDe())
                btn_Des.IsEnabled = false;
            if (moteur.getChoixPremier())
                MessageBox.Show("Premier joueur choisi : le joueur " + (moteur.getJoueurCourant() + 1));
            initInfosPartie();
        }
    }
}
