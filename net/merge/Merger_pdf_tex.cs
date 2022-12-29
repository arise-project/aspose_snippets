namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_tex()
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

            //save pdf to TeX document
            outputDoc.Save("Merger_pdf_tex.tex",
                            new Aspose.Pdf.TeXSaveOptions
                            {
                                //save parsed artifacts, for example images to a directory
                                OutDirectoryPath = "./test"
                            });
        }
    }
}
