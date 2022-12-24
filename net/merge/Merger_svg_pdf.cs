namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void svg_to_pdf()
        {
            const string pathSource1 = "../../TestData/test.svg";
            const string pathSource2 = "../../TestData/Second/test.svg";

            //SVG files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                //Adust pdf page size to svg size
                new Aspose.Pdf.SvgLoadOptions { AdjustPageSize = true});
            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                //Use default pdf page size
                new Aspose.Pdf.SvgLoadOptions { AdjustPageSize = false });

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
            outputDoc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
