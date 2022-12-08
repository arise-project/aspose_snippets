using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void epub_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.epub";
            var pathSource2 = @"..\..\TestData\Second\test.epub";

            var firstDoc = new Document(pathSource1,
                new EpubLoadOptions
                { 
                    PageSizeAdjustmentMode = LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain,
                    MarginsAreaUsageMode = LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
                });

            var secondDoc = new Document(pathSource2,
                new EpubLoadOptions
                { 
                    PageSizeAdjustmentMode = LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain,
                    MarginsAreaUsageMode = LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
                });

            var outputDoc = new Document();
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            outputDoc.Save("test.pdf", SaveFormat.Pdf);
        }
    }
}
