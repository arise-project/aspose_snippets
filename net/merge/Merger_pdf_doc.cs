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

            outputDoc.Save("test.doc", 
                            new Aspose.Pdf.DocSaveOptions
                            { 
                                Format = Aspose.Pdf.DocSaveOptions.DocFormat.Doc, 
                                Mode = Aspose.Pdf.DocSaveOptions.RecognitionMode.Textbox 
                            });
        }
    }
}
