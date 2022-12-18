namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pcl_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.pcl";
            var pathSource2 = @"..\..\TestData\Second\test.pcl";

            //pcl files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                //suspend not critical errors
                new Aspose.Pdf.PclLoadOptions() { SupressErrors = true });
                
            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                //suspend not critical errors
                new Aspose.Pdf.PclLoadOptions()  { SupressErrors = true });

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
