namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void epub_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.epub";
            var pathSource2 = @"..\..\TestData\Second\test.epub";

            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                new Aspose.Pdf.EpubLoadOptions
                { 
                    PageSizeAdjustmentMode = Aspose.Pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain,
                    MarginsAreaUsageMode = Aspose.Pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
                });

            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                new Aspose.Pdf.EpubLoadOptions
                { 
                    PageSizeAdjustmentMode = Aspose.Pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain,
                    MarginsAreaUsageMode = Aspose.Pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
                });

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

            outputDoc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
