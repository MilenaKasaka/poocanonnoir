using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using mWrapper;

namespace TestWrapper
{
    class Program
    {
        static void Main(string[] args)
        {
            WrapperMoteur moteur = new WrapperMoteur();
            Console.WriteLine("Choix du nombre de joueurs");
            Console.WriteLine("Dispo nb joueurs = " + moteur.dispoNbJoueurs());
            Console.WriteLine("Dispo lancer de = " + moteur.dispoLancerDe());
            moteur.initJoueurs(3);
            Console.WriteLine(moteur.getNbJoueurs());
       
            Console.WriteLine("\nSelection du premier joueur");
            Console.WriteLine("Dispo nb joueurs = " + moteur.dispoNbJoueurs());
            Console.WriteLine("Dispo lancer de = " + moteur.dispoLancerDe());
            moteur.execute();
            Console.WriteLine("de1 : " + moteur.getDe1() + " - de2 = " + moteur.getDe2());

            Console.WriteLine("\nPremier tour");
            Console.WriteLine("Dispo nb joueurs = " + moteur.dispoNbJoueurs());
            Console.WriteLine("Dispo lancer de = " + moteur.dispoLancerDe());
            moteur.execute();
            Console.WriteLine("de1 : " + moteur.getDe1() + " - de2 = " + moteur.getDe2());

            Console.WriteLine("\nDeplacement du bateau");
            Console.WriteLine("Dispo lancer de = " + moteur.dispoLancerDe());
            Console.WriteLine("Dispo choix case = " + moteur.dispoChoixCase());

            while (true) ;
        }
    }
}
