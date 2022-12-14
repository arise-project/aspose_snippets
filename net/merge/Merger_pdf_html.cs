namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_html()
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

            //save pdf to html page
            outputDoc.Save("Merger_pdf_html.html",
                            new Aspose.Pdf.HtmlSaveOptions
                            {
                                //embed css into a page
                                PartsEmbeddingMode = Aspose.Pdf.HtmlSaveOptions.PartsEmbeddingModes.EmbedAllIntoHtml,
                                //embed images into a page
                                RasterImagesSavingMode = Aspose.Pdf.HtmlSaveOptions.RasterImagesSavingModes.AsEmbeddedPartsOfPngPageBackground,
                                //enhance conversion of documents with backgrounds
                                AntialiasingProcessing = Aspose.Pdf.HtmlSaveOptions.AntialiasingProcessingType.TryCorrectResultHtml,
                                //use fixed layout render
                                FixedLayout = true
                            });
        }
    }
}
