namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void html_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.html";
            var pathSource2 = @"..\..\TestData\Second\test.html";

            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                new Aspose.Pdf.HtmlLoadOptions
                { 
                    InputEncoding = "UTF-8",
                    IsRenderToSinglePage = true
                });

            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                new Aspose.Pdf.HtmlLoadOptions
                { 
                    InputEncoding = "UTF-8",
                    IsRenderToSinglePage = false
                });

            //create empty pdf document
            var outputDoc = new Aspose.Pdf.Document();

            //set less memory usage with unload instead of fast performance
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
