namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void cgm_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.cgm";
            var pathSource2 = @"..\..\TestData\Second\test.cgm";

            //cgm files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1, 
                new Aspose.Pdf.CgmLoadOptions());
            var secondDoc = new Aspose.Pdf.Document(pathSource2, 
                new Aspose.Pdf.CgmLoadOptions());
            
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
            
            //save result pdf to file
            outputDoc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
