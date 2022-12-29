namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pcl_to_pdf()
        {
            const string pathSource1 = "../../TestData/test.pcl";
            const string pathSource2 = "../../TestData/Second/test.pcl";

            //pcl files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                //suspend not critical errors
                new Aspose.Pdf.PclLoadOptions() { SupressErrors = true });

            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                //suspend not critical errors
                new Aspose.Pdf.PclLoadOptions()  { SupressErrors = true });

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

            //save result pdf to file
            outputDoc.Save("Merger_pcl_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
