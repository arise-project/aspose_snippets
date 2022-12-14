using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void xps_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.xps";
            var pathSource2 = @"..\..\TestData\Second\test.xps";

            var firstDoc = new Document(pathSource1, new XpsLoadOptions());

            var secondDoc = new Document(pathSource2, new XpsLoadOptions());

            var outputDoc = new Document();
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            //save result pdf to file
            outputDoc.Save("test.pdf", SaveFormat.Pdf);
        }
    }
}
