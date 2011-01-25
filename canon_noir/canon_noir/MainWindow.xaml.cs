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
        double largeurCase, hauteurCase = 0;

        public MainWindow(WrapperMoteur m)
        {
            InitializeComponent();
            moteur = m;
            initInfosPartie();
            initMap();
            initBateaux();
            initMesuresCases();
        }

        public void mettreAJour()
        {
            initInfosPartie();
            initBateaux();
        }

        private void initInfosPartie()
        {
            String infos = "DONNEES DE LA PARTIE";
            infos += "\nJoueur courant : " + (moteur.getJoueurCourant() + 1);
            int nbJoueurs = moteur.getNbJoueurs();
            for (int i = 0; i < nbJoueurs; i++)
            {
                infos += "\nJoueur " + (i + 1) + " : ";
                infos += "\n - transporte tresor ? ";
                if (moteur.getTransporteTresor(i))
                    infos+= "oui";
                else
                    infos += "non";
                infos += "\n - " + moteur.getNbTresors(i) + " tresor(s) au port"; // problème numéro de joueur
            }
            infos += "\nDés : " + moteur.getDe1() + " - " + moteur.getDe2();
            // a commenter
            //infos += "\nPosition joueur courant : \n(" + moteur.getXBateau(moteur.getJoueurCourant()) + "," + moteur.getYBateau(moteur.getJoueurCourant()) + ")";
            //infos += "\nlargeurCase = " + largeurCase + " - hauteurCase = " + hauteurCase;
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
                // EVITER QU'UN BATEAU PUISSE SE VISER LUI-MEME
                

                switch (typeb)
                {
                    case (int)TypeBateau.CARAVELLE :
                        if (moteur.dispoReglageTir() && i!=moteur.getJoueurCourant())
                            tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/cara" + (i+1) + "_vise.png", UriKind.RelativeOrAbsolute));
                        else
                            tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/cara" + (i+1) +".png", UriKind.RelativeOrAbsolute));
                        break;
                    case (int)TypeBateau.FREGATE :
                        if (moteur.dispoReglageTir() && i != moteur.getJoueurCourant())
                            tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/fre" + (i + 1) + "_vise.png", UriKind.RelativeOrAbsolute));
                        else
                            tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/fre" + (i + 1) + ".png", UriKind.RelativeOrAbsolute));
                        break;
                    case (int)TypeBateau.RADEAU :
                        if (moteur.dispoReglageTir() && i != moteur.getJoueurCourant())
                            tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/ra" + (i + 1) + "_vise.png", UriKind.RelativeOrAbsolute));
                        else
                            tabImg[posX, posY].Source = new BitmapImage(new Uri("/images/ra" + (i + 1) + ".png", UriKind.RelativeOrAbsolute));
                        break;
                    default :
                        break;
                }
            }
        }

        void initMesuresCases()
        {
            largeurCase = grid1.Width / moteur.getNbColonnes();
            hauteurCase = grid1.Height / moteur.getNbLignes();
        }

        private KeyValuePair<int, int> getCase(double x, double y)
        {
            int posX = (int)(x / largeurCase);
            int posY = (int)(y / hauteurCase);
            return new KeyValuePair<int,int>(posX,posY);
        }

        private void afficheCasesAccessibles()
        {
            //MessageBox.Show("Je passe ici !");
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
                            //MessageBox.Show("Case (" + i + "," + j + ")");
                            //MessageBox.Show("Je passe ici !");
                            tabImg[i, j].Source = new BitmapImage(new Uri("/images/cadre.png", UriKind.RelativeOrAbsolute));
                        }
                    }
                }
                
                            
                
            }
            /*else
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
            }*/
        }

        // efface la carte
        private void resetCarte()
        {
            int nbLig = moteur.getNbLignes();
            int nbCol = moteur.getNbColonnes();
            // Remettre toutes les cases normales
            for (int i = 0; i < nbCol; i++)
            {
                for (int j = 0; j < nbLig; j++)
                {
                    tabImg[i, j].Source = null;
                }
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
            if (moteur.getChoixPremier())
                MessageBox.Show("Premier joueur choisi : le joueur " + (moteur.getJoueurCourant() + 1));
            if (!moteur.dispoLancerDe())
                btn_Des.IsEnabled = false;
            initInfosPartie();
            if (moteur.dispoChoixCase())
            {
                moteur.execute();
                afficheCasesAccessibles();
                if (moteur.dispoLancerDe())
                {
                    btn_Des.IsEnabled = true;
                }
            }
            
            
        }

        private void grid1_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            Point p = e.GetPosition(grid1);
            double x = p.X;
            double y = p.Y;
            KeyValuePair<int, int> c = getCase(x, y);

            if (moteur.dispoChoixCase())
            {
                int sauv_joueurCourant = moteur.getJoueurCourant();

                if (moteur.estAccessible(c.Key, c.Value))
                {
                    /*int anc_x = moteur.getXBateau(moteur.getJoueurCourant());
                    int anc_y = moteur.getYBateau(moteur.getJoueurCourant());
                    tabImg[anc_x,anc_y].Source = null;*/
                    resetCarte();
                    moteur.deplacerBateau(c.Key, c.Value);
                    initBateaux();
                    if (moteur.getJeuFini())
                        MessageBox.Show("Félicitations joueur " + (sauv_joueurCourant + 1) + " ! C'est vous le meilleur, vous avez gagné !");
                    if (moteur.getXPort(moteur.getJoueurCourant()) == c.Key && moteur.getYPort(moteur.getJoueurCourant()) == c.Value)
                    {
                        MessageBox.Show("Retour au port !");
                        initInfosPartie();
                    }
                    if (moteur.getRamasseTresor())
                    {
                        MessageBox.Show("Bravo joueur " + (sauv_joueurCourant + 1) + " ! Vous avez trouvé un trésor.");
                        initInfosPartie();
                    }
                    if (moteur.dispoReglageTir())
                    {
                        label1.Visibility = System.Windows.Visibility.Visible;
                        initBateaux();
                    }
                    
                    if (moteur.dispoLancerDe())
                    {
                        btn_Des.IsEnabled = true;
                    }
                }
           
                //MessageBox.Show("X = " + x + " - Y = " + y + "\nCase (" + c.Key + "," + c.Value + ")");
            }
            else if (moteur.dispoReglageTir())
            {
                ReglageTir fenTir = new ReglageTir(moteur,c.Key,c.Value);
                fenTir.Show();
                this.Close();
            }

        }
    }
}
