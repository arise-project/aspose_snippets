using System;

namespace aspose_snippets.net.split
{
    static class Program
    {
        static void Main()
        {
            LicenseProvider.License();

            try
            {
                Split.PDF();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine(ex.ToString());
            }

            try
            {
                Split.HTML();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine(ex.ToString());
            }

            try
            {
                Split.TXT();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine(ex.ToString());
            }
        }
    }
}
