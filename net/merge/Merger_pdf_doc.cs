namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_doc()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";
            var pathSource2 = @"..\..\TestData\Second\test.pdf";

            //read pdf file to Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1);
            var secondDoc = new Aspose.Pdf.Document(pathSource2);

            //create empty pdf document
            var outputDoc = new Aspose.Pdf.Document();

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

            //save pdf to Microsoft Word doc format
            outputDoc.Save("test.doc", 
                            new Aspose.Pdf.DocSaveOptions
                            { 
                                //use doc format
                                Format = Aspose.Pdf.DocSaveOptions.DocFormat.Doc, 
                                //This mode is fast and good for maximally preserving original look 
                                Mode = Aspose.Pdf.DocSaveOptions.RecognitionMode.Textbox 
                            });
        }
    }
}
