using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void cgm_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.cgm";
            var pathSource2 = @"..\..\TestData\Second\test.cgm";

            var firstDoc = new Document(pathSource1, new CgmLoadOptions());
            var secondDoc = new Document(pathSource2, new CgmLoadOptions());

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

            outputDoc.Save("test.pdf");
        }
    }
}
