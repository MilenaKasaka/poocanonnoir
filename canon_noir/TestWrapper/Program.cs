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
            moteur.setNbJoueurs(3);
            while (true) ;
        }
    }
}
