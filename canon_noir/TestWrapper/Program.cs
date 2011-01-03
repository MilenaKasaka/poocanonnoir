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
            // INITIALISATION
            WrapperMoteur moteur = new WrapperMoteur();
            moteur.setNbJoueurs(3);

            // SELECTION DU PREMIER JOUEUR

            moteur.execute();
            Console.WriteLine("Lancer des : (%d,%d) ", moteur.getDe1(), moteur.getDe2());

            while (true) ;
        }
    }
}
