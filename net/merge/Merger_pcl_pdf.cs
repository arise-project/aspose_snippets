namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pcl_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.pcl";
            var pathSource2 = @"..\..\TestData\Second\test.pcl";

            var firstDoc = new Aspose.Pdf.Document(pathSource1, new Aspose.Pdf.PclLoadOptions() { SupressErrors = true });
            var secondDoc = new Aspose.Pdf.Document(pathSource2, new Aspose.Pdf.PclLoadOptions()  { SupressErrors = true });

            var outputDoc = new Aspose.Pdf.Document();
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
