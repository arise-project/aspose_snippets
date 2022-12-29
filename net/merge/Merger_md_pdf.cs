namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void md_to_pdf()
        {
            const string pathSource1 = "../../TestData/test.md";
            const string pathSource2 = "../../TestData/Second/test.md";

            //Markdown files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                new Aspose.Pdf.MdLoadOptions());
            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                new Aspose.Pdf.MdLoadOptions());

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
            outputDoc.Save("Merger_md_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
