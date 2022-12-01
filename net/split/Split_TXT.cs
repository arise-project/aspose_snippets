using Aspose.Pdf;
using Aspose.Pdf.Facades;
using Aspose.Pdf.Text;

namespace aspose_snippets.net
{
    public static partial class Split
    {
        public static void TXT()
        {
            var pathSource = @"..\..\test.txt";
            var pdfEditor = new PdfFileEditor();
            int beg = 1, end = 1;

            using (var doc = new Document(pathSource, new TxtLoadOptions()))
            {
                end = doc.Pages.Count;
            }

            MemoryStream [] pages = pdfEditor.SplitToPages(pathSource);
            int index = 1;
            foreach(var ms in pages)
            {
                using(var page = new Document(ms))
                {
                    var textAbsorber = new TextAbsorber();
                    page.Pages.Accept(textAbsorber);
                    string extractedText = textAbsorber.Text;
                    File.WriteAllText("text_"+index+".txt", extractedText);
                    index++;
                }
            }
        }
    }
}
