namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_xls()
        {
            const string pathSource1 = "../../TestData/test.pdf";
            const string pathSource2 = "../../TestData/Second/test.pdf";

            //read pdf file to Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1);
            var secondDoc = new Aspose.Pdf.Document(pathSource2);

            //create empty pdf document
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

            //save Excel document
            outputDoc.Save("test.xls",
                            new Aspose.Pdf.ExcelSaveOptions()
                            {
                                //set Microsoft document type
                                Format = Aspose.Pdf.ExcelSaveOptions.ExcelFormat.XMLSpreadSheet2003
                            });
        }
    }
}
