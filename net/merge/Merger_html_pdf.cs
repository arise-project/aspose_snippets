using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void html_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.html";
            var pathSource2 = @"..\..\TestData\Second\test.html";

            var firstDoc = new Document(pathSource1,
                new HtmlLoadOptions
                { 
                    InputEncoding = "UTF-8",
                    IsRenderToSinglePage = true
                });

            var secondDoc = new Document(pathSource2,
                new HtmlLoadOptions
                { 
                    InputEncoding = "UTF-8",
                    IsRenderToSinglePage = false
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
