namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_pptx()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";
            var pathSource2 = @"..\..\TestData\Second\test.pdf";

            //read pdf file to Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1);
            var secondDoc = new Aspose.Pdf.Document(pathSource2);

            var outputDoc = new Aspose.Pdf.Document
            {
                //set less memory usage with unload instead of fast performance
                EnableObjectUnload = true
            };

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

            //save pdf to Microsoft PowerPoint
            outputDoc.Save("test.pptx",
                            new Aspose.Pdf.PptxSaveOptions
                            {
                                //save all content on page as single image
                                SlidesAsImages = true
                            });
        }
    }
}
