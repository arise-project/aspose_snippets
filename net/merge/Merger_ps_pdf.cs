using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void ps_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.ps";
            var pathSource2 = @"..\..\TestData\Second\test.ps";

           //PostScript files can be parsed and loaded as Aspose Document
            var firstDoc = new Document(pathSource1, new PsLoadOptions());
            var secondDoc = new Document(pathSource2,  new PsLoadOptions());

            //create empty pdf document
            var outputDoc = new Document();

            //set less memory usage with unload instead of fast performance
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            //save result pdf to file
            outputDoc.Save("test.pdf", SaveFormat.Pdf);
        }
    }
}
