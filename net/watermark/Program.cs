using System;

namespace aspose_snippets.net.watermark
{
    static class Program
    {
        static void Main()
        {
            LicenseProvider.License();

            try
            {
                Watermark.add();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine(ex.ToString());
            }

            try
            {
                Watermark.get();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine(ex.ToString());
            }

            try
            {
                Watermark.remove();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine(ex.ToString());
            }
        }
    }
}
