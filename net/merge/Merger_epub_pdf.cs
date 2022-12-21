namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void epub_to_pdf()
        {
            var pathSource1 = "../../TestData/test.epub";
            var pathSource2 = "../../TestData/Second/test.epub";

            //epub files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                new Aspose.Pdf.EpubLoadOptions
                { 
                    //use algorithm to prevent content to be truncated
                    PageSizeAdjustmentMode = Aspose.Pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain,
                    //usage of margins area during conversion 
                    MarginsAreaUsageMode = Aspose.Pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
                });

            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                new Aspose.Pdf.EpubLoadOptions
                { 
                    //use algorithm to prevent content to be truncated
                    PageSizeAdjustmentMode = Aspose.Pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain,
                    //usage of margins area during conversion 
                    MarginsAreaUsageMode = Aspose.Pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
                });

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
