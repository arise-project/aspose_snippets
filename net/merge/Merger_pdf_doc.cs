namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_doc()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";
            var pathSource2 = @"..\..\TestData\Second\test.pdf";

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

            outputDoc.Save("test.doc", 
                            new Aspose.Pdf.DocSaveOptions
                            { 
                                Format = Aspose.Pdf.DocSaveOptions.DocFormat.Doc, 
                                Mode = Aspose.Pdf.DocSaveOptions.RecognitionMode.Textbox 
                            });
        }
    }
}
