using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_pdfa()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";
            var pathSource2 = @"..\..\TestData\Second\test.pdf";

            var firstDoc = new Document(pathSource1);
            var secondDoc = new Document(pathSource2);

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

            outputDoc.Save("test.pdf", SaveFormat.P);
        }
    }
}
