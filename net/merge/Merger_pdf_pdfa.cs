using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_pdfa()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";
            var pathSource2 = @"..\..\TestData\Second\test.pdf";

            //read pdf file to Aspose Document
            var firstDoc = new Document(pathSource1);
            var secondDoc = new Document(pathSource2);

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

            //save document as specific pdf standard PDFA 3Y
            outputDoc.Convert(
                "test.pdf", 
                PdfFormat.PDF_A_3U, 
                //delete objects that impossible to convert
                ConvertErrorAction.Delete);
        }
    }
}
