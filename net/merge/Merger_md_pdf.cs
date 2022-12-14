namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void md_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.md";
            var pathSource2 = @"..\..\TestData\Second\test.md";

            var firstDoc = new Aspose.Pdf.Document(pathSource1, new Aspose.Pdf.MdLoadOptions());
            var secondDoc = new Aspose.Pdf.Document(pathSource2, new Aspose.Pdf.MdLoadOptions());

            //create empty pdf document
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

            //save result pdf to file
            outputDoc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
