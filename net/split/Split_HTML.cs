using Aspose.Pdf;
using Aspose.Pdf.Facades;

namespace aspose_snippets.net
{
    public static partial class Split
    {
        public static void HTML()
        {
            const string pathSource = "../../TestData/test.html";
            using (var doc = new Document(pathSource, new HtmlLoadOptions()))
            {
                //save input html to pdf to file
                doc.Save("test.pdf", SaveFormat.Pdf);
            }

            var pdfEditor = new PdfFileEditor();
            pdfEditor.SplitFromFirst("test.pdf", 1, "test.pdf");
            using (var doc = new Document("test.pdf"))
            {
                doc.Save("html_first.html", SaveFormat.Html);
            }
        }
    }
}
