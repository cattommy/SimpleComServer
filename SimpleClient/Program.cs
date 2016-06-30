using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleClient

{
    class Program
    {
        static void Main(string[] args)
        {

            try

            {

                SimpleCOMServer.SmartControl ctrl = new SimpleCOMServer.SmartControl();

                string s;
                ctrl.GetServices(out s);


                string[] servicesNames = s.Split(',');
                foreach (string word in servicesNames)
                {
                    Console.WriteLine(word);
                }

                Console.WriteLine(servicesNames[99]);

                ctrl.StartMyService(servicesNames[99]);
                ctrl.StopMyService(servicesNames[99]);
            }

            catch (Exception err)

            {

                Console.WriteLine(err.Message);

            }

            Console.ReadLine();
        }

        

    }
    }

